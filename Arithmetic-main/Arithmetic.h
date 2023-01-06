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




#endif /* Arithmetic.h */
#pragma once
#pragma once
