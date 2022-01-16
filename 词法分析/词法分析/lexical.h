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
map<string, string> _keyword;  //�ؼ���
map<string, string> _operator; //�������
map<string, string> _boundary; //���
string input;                  //������������
map<int, Word> output1;        //�����������

int _index = 0;
void initKeyword();//��ʼ���ؼ���

void initoperator();//��ʼ�������

void initboundary();//��ʼ�����

void readFile();//���ļ�

bool isboundaryandPrintf(char a);//�ж��Ƿ�Ϊ�����������

bool isboundary(char a);//�ж��Ƿ�Ϊ�����������

bool isOperatorandPrintf(string tmp);//�ж��Ƿ�Ϊ�������������

bool isOperator(string tmp);//�ж��Ƿ�Ϊ�������������

bool isKeyword(string tmp);//�ж��Ƿ�Ϊ�ؼ��֣�������


bool isDegitalandPrintf(string str);//�ж��Ƿ�Ϊ������������

bool isDegital(string str);//�ж��Ƿ�Ϊ������������

bool isLetter(char A);//�ж��Ƿ�Ϊ��ĸ

bool isNumber(char A);//�ж��Ƿ�Ϊ����

void lexical();//�ʷ�����

void save();//

