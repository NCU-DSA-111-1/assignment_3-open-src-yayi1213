//  main.cpp
//  Arithmetic

#include <iostream>
#include "Arithmetic.h"
#include <string>
#include <time.h>
using namespace std;

int main()
{
	Arithmetic test;   
	clock_t start, end;  
	start = clock();
	test.open("test2.txt");  
	test.Press();  
	end = clock();
	cout << endl<<endl<<"time cost of arithmeric encoding :";
	cout << double (end - start)/CLOCKS_PER_SEC<< "/s" << endl << endl; 
	start = clock();
	test.Decode("C:/Users/User/OneDrive - 國立中央大學/桌面/大二上hw/資結/110503507_assignment_3_opensource/Arithmetic-main/test2.txt.ari","C:/Users/User/OneDrive - 國立中央大學/桌面/大二上hw/資結/110503507_assignment_3_opensource/Arithmetic-main/test2.txt");
	cout << "time cost of arithmeric decoding :" ;   
	cout << double (start - end)/CLOCKS_PER_SEC << "/s" << endl << endl;  
	getchar();
	return 0;
}


