//
//  Arithmetic.h
//  Arithmetic
//
//

#ifndef Arithmetic_h
#define Arithmetic_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <wchar.h>
using namespace std;

class Arithmetic
{
public:
	string FileAddress;
	int TotalNumber = 0;  
	int NumList[2] = {0};   
	long double ProbaList[2] = {0.0};   
	long double P[2] = {0.0};     
	Arithmetic();   //
	void open(string input);
	void Press();   
	void Decode(string sourcefile, string dstfile); //

};

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;


Arithmetic::Arithmetic()
{

}


void Arithmetic::open(string input)   //讀入文件地址
{
	FileAddress = input;
}


void Arithmetic::Press()  //進行壓縮
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(10);    // 定義書出小數為小數後10位

	ifstream read;
	read.open(FileAddress, ios::in | ios::binary);
	if (!read)
	{
		cout << "文件無法讀取" << endl << endl;
		return;
	}

	ofstream write;
	write.open(FileAddress + ".ari", ios::out | ios::binary);
	if (!write)
	{
		cout << "輸出文件不能建立(*.lz)" << endl;
		return;
	}

	char *InChar = new char;
	
	int len(0);
	int BitList[8];
	long int reg(0);
	long double C(0.0);
	long double B(0.0);
	long double A(1);

	read.read((char*)InChar, sizeof(unsigned char));    
	while (!read.eof()) 
	{
		TotalNumber += 8;   
		BitList[0] = (*InChar & 0x80) == 0x80 ? 1 : 0;
		BitList[1] = (*InChar & 0x40) == 0x40 ? 1 : 0;
		BitList[2] = (*InChar & 0x20) == 0x20 ? 1 : 0;
		BitList[3] = (*InChar & 0x10) == 0x10 ? 1 : 0;
		BitList[4] = (*InChar & 0x08) == 0x08 ? 1 : 0;
		BitList[5] = (*InChar & 0x04) == 0x04 ? 1 : 0;
		BitList[6] = (*InChar & 0x02) == 0x02 ? 1 : 0;
		BitList[7] = (*InChar & 0x01) == 0x01 ? 1 : 0;   

		for (int i(0); i < 8; i++)       
		{
			if (BitList[i] == 0)
			{
				NumList[0] ++;
			}
			if (BitList[i] == 1)
			{
				NumList[1] ++;
			}
		}

		read.read((char*)InChar, sizeof(unsigned char));   
	}

	cout <<endl<< "壓縮總bit數" << TotalNumber << endl;
	cout << "其中為0的數為" << NumList[0] << endl;
	cout << "  其中為1的數為" << NumList[1] << endl;
	
	ProbaList[0] =double(NumList[0]) / TotalNumber;   
	ProbaList[1] =double(NumList[1]) / TotalNumber;
	
	P[0] = 0;    
	P[1] = ProbaList[0];   

	cout << endl << "bit0出現的機率" << "	" << ProbaList[0];
	cout << endl << "bit1出現的機率" << "	" << ProbaList[1];
	


	read.clear();    
	read.seekg(0);

	read.read((char*)InChar, sizeof(unsigned char)); 
	while (!read.eof())
	{	
		for (int i(0); i < 1; i++)
		{
			BitList[0] = (*InChar & 0x80) == 0x80 ? 1 : 0;
			BitList[1] = (*InChar & 0x40) == 0x40 ? 1 : 0;
			BitList[2] = (*InChar & 0x20) == 0x20 ? 1 : 0;
			BitList[3] = (*InChar & 0x10) == 0x10 ? 1 : 0;
			BitList[4] = (*InChar & 0x08) == 0x08 ? 1 : 0;
			BitList[5] = (*InChar & 0x04) == 0x04 ? 1 : 0;
			BitList[6] = (*InChar & 0x02) == 0x02 ? 1 : 0;
			BitList[7] = (*InChar & 0x01) == 0x01 ? 1 : 0;
			
			for (int j(0); j < 8; j++)  
			{
				if (BitList[j] == 0)
				{
					C = C;
					A = A * ProbaList[0];
				}

				else
				{
					C = C + A * P[1];
					A = A * ProbaList[1];
				}
			}

			read.read((char*)InChar, sizeof(unsigned char)); 
			if (read.eof())  break;
		}
		
		len = -log(A) / log(2) + 1;  
		B = C * (pow(10, len));
		B += 0.5;
		C = B / (pow(10, len));

		write << setiosflags(ios::fixed) << setprecision(len) << C;  
		write << "	";
		C = 0;   
		A = 1;
		
	}

	read.close();
	write.close();
}





void Arithmetic::Decode(string sourcefile, string dstfile)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(10);

	ifstream readfile;
	ofstream putfile;
	readfile.open(sourcefile);
	if (!readfile)
	{
		cout << "解壓文件讀取錯誤(*.ari)" << endl << endl;
		return;
	}

	putfile.open(dstfile);
	if (!putfile)
	{
		cout << "解壓文件建立錯誤" << endl;
	}

	long double temp(0);   
	int OutList[8];
	int count(0);
	int OutChar(0);

	count = TotalNumber;
	readfile >> temp; 

	while (!readfile.eof())
	{
		for (int i(0); i < 1; i++)
		{
			if (count == 0)		break;  

			for (int j(0); j < 8; j++)
			{
				if (temp >= P[1])
				{
					count -= 1;
					OutList[j] = 1;
					temp = (temp - P[1]) / ProbaList[1];				
				}

				else
				{
					count -= 1;
					OutList[j] = 0;
					temp = (temp - P[0]) / ProbaList[0];
				}
			}

			OutChar = OutList[7] + OutList[6] * 2 + OutList[5] * 4 + OutList[4] * 8 + OutList[3] * 16 + OutList[2] * 32 + OutList[1] * 64 - OutList[0];
			putfile << char(OutChar);   
		}

		
		readfile >> temp;   
	}

	readfile.close();
	putfile.close();
}



#endif /* Arithmetic.h */
#pragma once
#pragma once
