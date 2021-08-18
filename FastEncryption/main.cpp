#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <array>
#include "code.h"

using namespace std;

int main ()
{
	string data1,data2,key,mode,check;
	Core Function;
	cout << "Enter a mode E/D" << endl;
	getline(cin,mode);
	cout << "Please Enter your key" << endl;
	getline(cin,key);
	cout << "Please Enter your key again" << endl;
	getline(cin,check);
	system("CLS");
	if(key != check)
	{
		exit(0);
	}
	else
	{
		
		cout << "Enter the file input name" << endl;
		getline(cin,data1);
		cout << "Enter the output file name" << endl;
		getline(cin,data2);
		Function.setMode(mode);
		Function.setKey(key);
		Function.readFile(data1,data2);
		system("pause");
		
	}
	return 0;
}
