#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include <vector>
#include <sstream>
#include<map>
using namespace std;
#define INFILE "testfile.txt"
#define OUTFILE "output.txt"
struct Word {
	
	string CategoryCode;
	string Name;
};
map<string, string> _keyword;  //关键字
map<string, string> _operator; //运算符合
map<string, string> _boundary; //界符
string input;                  //保存输入数据
map<int, Word> output1;        //保存输出数据

int _index = 0;
void initKeyword();//初始化关键字

void initoperator();//初始化运算符

void initboundary();//初始化界符

void readFile();//读文件

bool isboundaryandPrintf(char a);//判断是否为界符，并保存

bool isboundary(char a);//判断是否为界符，不保存

bool isOperatorandPrintf(string tmp);//判断是否为运算符，并保存

bool isOperator(string tmp);//判断是否为运算符，不保存

bool isKeyword(string tmp);//判断是否为关键字，并保持


bool isDegitalandPrintf(string str);//判断是否为整数，并保存

bool isDegital(string str);//判断是否为整数，不保存

bool isLetter(char A);//判断是否为字母

bool isNumber(char A);//判断是否为数字

void lexical();//词法分析

void save();//

