//#include"lexical.h"
#include<iostream>
#include <string>
#include<fstream>
#include <vector>
#include <sstream>
#include<map>
#include<stack>
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
map<int, Word> output1; 
stack<string> temp;
stack<string> output2;//保存输出数据

int _index = 0;
bool isStatement();
bool isExpression();
bool isFunctionCallStatementWithReturn();
bool isStatementColumn();
void initKeyword()
{
	_keyword.insert(make_pair("CONSTTK", "const"));
	_keyword.insert(make_pair("INTTK", "int"));
	_keyword.insert(make_pair("CHARTK", "char"));
	_keyword.insert(make_pair("VOIDTK", "void"));
	_keyword.insert(make_pair("MAINTK", "main"));
	_keyword.insert(make_pair("IFTK", "if"));
	_keyword.insert(make_pair("ELSETK", "else"));
	_keyword.insert(make_pair("DOTK", "do"));
	_keyword.insert(make_pair("WHILETK", "while"));
	_keyword.insert(make_pair("FORTK", "for"));
	_keyword.insert(make_pair("SCANFTK", "scanf"));
	_keyword.insert(make_pair("PRINTFTK", "printf"));
	_keyword.insert(make_pair("RETURNTK", "return"));

}
void initoperator()
{
	_operator.insert(make_pair("PLUS", "+"));
	_operator.insert(make_pair("MINU", "-"));
	_operator.insert(make_pair("MULT", "*"));
	_operator.insert(make_pair("DIV", "/"));
	_operator.insert(make_pair("LSS", "<"));
	_operator.insert(make_pair("LEQ", "<="));
	_operator.insert(make_pair("GRE", ">"));
	_operator.insert(make_pair("GEQ", ">="));
	_operator.insert(make_pair("EQL", "=="));
	_operator.insert(make_pair("NEQ", "!="));
	_operator.insert(make_pair("ASSIGN", "="));




}
void initboundary()
{
	_boundary.insert(make_pair("SEMICN", ";"));
	_boundary.insert(make_pair("COMMA", ","));
	_boundary.insert(make_pair("LPARENT", "("));
	_boundary.insert(make_pair("RPARENT", ")"));
	_boundary.insert(make_pair("LBRACK", "["));
	_boundary.insert(make_pair("RBRACK", "]"));
	_boundary.insert(make_pair("LBRACE", "{"));
	_boundary.insert(make_pair("RBRACE", "}"));
}
void readFile()
{

	char str;
	ifstream myfile(INFILE);
	string tmp;
	if (myfile.is_open())
	{
		while (getline(myfile, tmp))
		{



			input.append(tmp);
			//output.push_back(tmp);

		}


	}

	myfile.close();

}
bool isboundaryandPrintf(char a)
{
	string tmp(1, a);
	for (map<string, string>::iterator k = _boundary.begin(); k != _boundary.end(); k++)
	{
		if ((*k).second == tmp)
		{

			Word newWord;
			newWord.CategoryCode = (*k).first;
			newWord.Name = (*k).second;
			output1.insert(make_pair(_index, newWord));
			_index++;

			//cout << (*k).first << " " << (*k).second << endl;
			return true;
		}
	}
	return false;
}
bool isboundary(char a)
{
	string tmp(1, a);
	for (map<string, string>::iterator k = _boundary.begin(); k != _boundary.end(); k++)
	{
		if ((*k).second == tmp)
		{

			return true;
		}
	}
	return false;
}
bool isOperatorandPrintf(string tmp)
{

	for (map<string, string>::iterator k = _operator.begin(); k != _operator.end(); k++)
	{
		if ((*k).second == tmp)
		{
			Word newWord;
			newWord.CategoryCode = (*k).first;
			newWord.Name = (*k).second;
			output1.insert(make_pair(_index, newWord));
			_index++;
			//cout << (*k).first << " " << (*k).second << endl;
			return true;
		}
	}
	return false;
}
bool isOperator(string tmp)
{
	for (map<string, string>::iterator k = _operator.begin(); k != _operator.end(); k++)
	{
		if ((*k).second == tmp)
		{

			return true;
		}
	}
	return false;
}
bool isKeyword(string tmp) {
	for (map<string, string>::iterator k = _keyword.begin(); k != _keyword.end(); k++)
	{
		if ((*k).second == tmp)
		{
			
			//cout << (*k).first << " " << (*k).second << endl;
			return true;
		}
	}
	return false;

}
bool isKeywordandPrintf(string tmp)
{
	for (map<string, string>::iterator k = _keyword.begin(); k != _keyword.end(); k++)
	{
		if ((*k).second == tmp)
		{
			Word newWord;
			newWord.CategoryCode = (*k).first;
			newWord.Name = (*k).second;
			output1.insert(make_pair(_index, newWord));
			_index++;
			//cout << (*k).first << " " << (*k).second << endl;
			return true;
		}
	}
	return false;




}
bool isDegitalandPrintf(string str) {
	if (str == "")return false;
	for (int i = 0; i < str.size(); i++) {
		
		if (str.at(i) > '9' || str.at(i) < '0')
			return false;
	}

	Word newWord;
	newWord.CategoryCode = "INTCON";
	newWord.Name = str;
	output1.insert(make_pair(_index, newWord));
	_index++;

	//cout << "INTCON " << str << endl;
	return true;
}
bool isDegital(string str) {
	if (str.at(0) == '0')return false;
	for (int i = 0; i < str.size(); i++) {
		
		if (str.at(i) > '9' || str.at(i) < '0')
			return false;
	}

	

	//cout << "INTCON " << str << endl;
	return true;
}
bool isLetter(char A)
{
	if ((A >= 'A' && A <= 'Z') || A >= 'a' && A <= 'z')
		return true;
	return false;
}
bool isNumber(char A)
{
	if ((A >= '0' && A <= '9'))
		return true;
	return false;
}
void lexical()
{
	char token[120];
	int index = 0;


	while ( index < input.size())
	{

		string b(1, input[index]);

		if (isLetter(input[index]) || input[index] == '_')//第一个字符为字母
		{

			int k = 0;
			string _opr;
			do {
				token[k] = input[index];
				k++;
				index++;
				char op = input[index];
				string opr(1, op);
				_opr = opr;
			} while (input[index] != ' ' && index < input.size() - 1 && !isboundary(input[index]) && !isOperator(_opr));
			string str(token, k);
			if (!isKeywordandPrintf(str))
			{

				Word newWord;
				newWord.CategoryCode = "IDENFR";
				newWord.Name = str;
				output1.insert(make_pair(_index, newWord));
				_index++;
				//cout << "IDENFR " << a << endl;
			}


			if (index < input.size() - 1 && isboundaryandPrintf(input[index]))index++;
		}
		if (isNumber(input[index]))//第一个字符为数字
		{

			int k = 0;
			do {
				token[k] = input[index];
				k++;
				index++;
			} while (input[index] != ' ' && index < input.size() - 1 && !isboundary(input[index]));
			string num(token, k);
			Word newWord;
			newWord.CategoryCode = "INTCON";
			newWord.Name = num;
			output1.insert(make_pair(_index, newWord));
			//if (isDegital(num)) {
			_index++;
			isboundaryandPrintf(input[index]);
			index++;
			//}


		}
		if (input[index] == '\'')//第一个字符为‘
		{

			int k = 0;
			index++;
			do {
				token[k] = input[index];
				k++;
				index++;
			} while (input[index] != '\'');
			string str(token, k);

			Word newWord;
			newWord.CategoryCode = "CHARCON";
			newWord.Name = str;
			output1.insert(make_pair(_index, newWord));
			_index++;
			//cout << "CHARCON " << a << endl;
			index++;

		}
		if (input[index] == '\"')//第一个字符为“
		{

			int k = 0;
			index++;
			do {
				token[k] = input[index];
				k++;
				index++;
			} while (input[index] != '\"');
string str(token, k);

Word newWord;
newWord.CategoryCode = "STRCON";
newWord.Name = str;
output1.insert(make_pair(_index, newWord));
_index++;
//cout << "STRCON " << a << endl;
index++;
		}

		if (isOperator(b) || b == "!")//第一个字符为运算符
		{

			int k = 0;
			index++;
			string c(1, input[index]);
			if (isOperator(c))
			{
				b.append(c);
				index++;

			}
			isOperatorandPrintf(b);


		}
		if (isboundaryandPrintf(input[index]))index++;//遇到分界符
		if (index < input.size() - 1 && (input[index] == ' ' || input[index] == '\t' || input[index] == '\r'))//遇到空格
		{
			do {
				index++;

			} while (index < input.size() - 1 && (input[index] == ' ' || input[index] == '\t' || input[index] == '\r'));
		}






	}





}
//写入文件
void save()
{
	while (!temp.empty()) {
		string t = temp.top();
		output2.push(t);
		temp.pop();
	}
	ofstream myfile;
	myfile.open(OUTFILE);
	if (myfile.is_open())
	{
	/*	for (map<int, Word>::iterator k = output1.begin(); k != output1.end(); k++)
		{
			myfile << (*k).second.CategoryCode << " " << (*k).second.Name << endl;
		}*/
		/*for (int i = 0; i < input.size(); i++)
		{
			if((int)input[i]<32||(int)input[i]>125)
				myfile << (int)input[i] << endl;
		}*/
		while (!output2.empty()) {
			myfile << output2.top() << endl;
			output2.pop();
		}

	}
	myfile.close();
}
string find1(int a) {
	map<int, Word>::iterator pos = output1.find(a);
	return (*pos).second.CategoryCode;
}

void add(int index) {
	map<int, Word>::iterator pos = output1.find(index);
	string str=(*pos).second.CategoryCode;
	str.append(" ").append((*pos).second.Name);
	temp.push(str);
	
}
bool isfind(string str) {
	if (find1(_index) == str) {
		add(_index);
		_index++;
		return true;
	}
	return false;

}
//＜加法运算符＞ ::= +｜-
bool isAddandSub() {
	if (find1(_index) == "PLUS" || find1(_index) == "MINU") {//+||-
		add(_index);
		_index++;
		return true;
	}
	return false;
}
//＜乘法运算符＞  ::= *｜/
bool isMul() {
	if (find1(_index) == "MULT" || find1(_index) == "DIV") {//*||/
		add(_index);
		_index++;
		return true;
	}
	return false;
}
//＜关系运算符＞  ::=  <｜<=｜>｜>=｜!=｜==
bool isRelation() {
	if (find1(_index) == "LSS" || find1(_index) == "LEQ" || find1(_index) == "GRE" || find1(_index) == "GEQ" || find1(_index) == "EQL" || find1(_index) == "NEQ") {
		add(_index);
		_index++;
		return true;
	}
	return false;
}
//＜类型标识符＞      ::=  int | char
bool isTypeIdentifier() {
	if (find1(_index) == "CHARTK" || find1(_index) == "INTTK") {//类型标识符
		add(_index);
		_index++;
		return true;
	}
	return false;
}

//＜字符＞    ::=  '＜加法运算符＞'｜'＜乘法运算符＞'｜'＜字母＞'｜'＜数字＞'
bool isChar() {
	if (find1(_index) == "CHARCON") {//字符
		add(_index);
		_index++;
		return true;
	}
	return false;
}
//＜字符串＞   ::=  "｛十进制编码为32,33,35-126的ASCII字符｝"
bool isCharacter() {
	if (find1(_index) == "STRCON") {
		add(_index);
		temp.push("<字符串>");
		_index++;
		return true;
	}
	return false;
}
//‎＜无符号整数＞  ::= ＜非零数字＞｛＜数字＞｝| 0
bool isUnsignedNum() {
	if (isfind( "INTCON")) {
		temp.push("<无符号整数>");
		return true;
	}
	return false;
}
//＜整数＞        ::= ［＋｜－］＜无符号整数＞
bool isNum() {
	if (isAddandSub()) {
		isUnsignedNum();
		temp.push("<整数>");
		
		return true;
	}
	if (isfind("INTCON")) {
		
		temp.push("<无符号整数>");
		temp.push("<整数>");
		
		return true;
	}
	return false;
}


//＜常量定义＞   ::=   int＜标识符＞＝＜整数＞{,＜标识符＞＝＜整数＞} | char＜标识符＞＝＜字符＞{,＜标识符＞＝＜字符＞}
bool isConstant() {
	if (isfind("INTTK")) {//int

		isfind("IDENFR");//标识符

		if (find1(_index) == "ASSIGN") {//=
			add(_index);
			_index++;
		}
		else {
			temp.pop();
			temp.pop();
			_index--;
			_index--;
			return false;
		}

		if (!isNum()) temp.push("缺少整数");//整数
		while (isfind( "COMMA")) {//,

			isfind("IDENFR");

			if (isfind("ASSIGN"));

			if (!isNum()) temp.push("缺少整数");

		}
		temp.push("<常量定义>");
		return true;
	}
	if (isfind("CHARTK")) {

		isfind("IDENFR"); //标识符

		if (find1(_index) == "ASSIGN") {//=
			add(_index);
			_index++;
		}
		else {
			temp.pop();
			temp.pop();
			_index--;
			_index--;
			return false;
		}
		if (!isChar()) temp.push("缺少字符");//字符
		while (find1(_index) == "COMMA") {//,
			add(_index);
			_index++;
			if (find1(_index) == "IDENFR") {
				add(_index);
				_index++;
			}
			if (find1(_index) == "ASSIGN") {
				add(_index);
				_index++;
			}
			if (!isChar()) temp.push("缺少字符");

		}
		temp.push("<常量定义>");
		return true;

	}
	return false;
}
//＜常量说明＞ ::=  const＜常量定义＞;{ const＜常量定义＞;}
bool isConst() {
	if (isfind( "CONSTTK")) {//const

		if (!isConstant()) {//<常量定义>
			temp.push("常量说明错误,无常量定义");
			return false;
			
		}
		isfind("SEMICN"); //;

		while (isfind( "CONSTTK")) {//const

			if (!isConstant()) {//常量定义
				temp.push("常量说明错误,无常量定义");
				return false;

			}
			isfind("SEMICN");//;


		}
		temp.push("<常量说明>");
		return true;
		
	}
	return false;
}
//＜声明头部＞   ::=  int＜标识符＞ |char＜标识符＞
bool isHeader() {
	if (isfind( "INTTK")||isfind("CHARTK")) {//int||char

		if (isfind( "IDENFR")) {//标识符

			if (find1(_index) == "LPARENT") {//(
				temp.push("<头部声明>");
				return true;
			}
			else {
				temp.pop();
				temp.pop();
				_index--;
				_index--;
				return false;
			}
			
		}
	}
	return false;
}
//＜变量定义＞  ::= ＜类型标识符＞(＜标识符＞|＜标识符＞'['＜无符号整数＞']'){,(＜标识符＞|＜标识符＞'['＜无符号整数＞']' )}
bool isVariableDefinition() {
	if (isfind("CHARTK")|| isfind( "INTTK")) {//类型标识符

		isfind("IDENFR"); //标识符

		if (isfind( "LBRACK")) {//[,有可能定义数组

			isUnsignedNum();//无符号数
			isfind("RBRACK"); //]

		}
		if (!isfind( "COMMA") && !isfind("SEMICN")) {//,||;
			temp.pop();
			temp.pop();
			_index--;
			_index--;
			return false;
		}
		temp.pop();
		_index--;
		while (isfind( "COMMA")) {

			isfind("IDENFR");//标识符

			if (isfind( "LBRACK")) {//[,有可能定义数组
				isUnsignedNum();//无符号数
				isfind("RBRACK");//]

			}
		}
		temp.push("<变量定义>");
		return true;
	}
	return false;

}
//＜变量说明＞  :: = ＜变量定义＞; {＜变量定义＞; }‎
bool isVariableDescription() {
	if (isVariableDefinition()) {//变量定义
		if (isfind("SEMICN")) {//;

			while (isVariableDefinition()) {//变量定义
				isfind("SEMICN"); //;
			}
			temp.push("<变量说明>");
			return true;
		}
	}
	return false;
}
//＜参数表＞    ::=  ＜类型标识符＞＜标识符＞{,＜类型标识符＞＜标识符＞}| ＜空＞
bool isParameter() {
	if (isTypeIdentifier()) {//类型标识符
		if (isfind("IDENFR")) {//标识符

			while (isfind("COMMA")) {//,

				isTypeIdentifier();//类型标识符
				isfind("IDENFR");//标识符
			}
			temp.push("<参数表>");
			return true;
		}
	}
	if (isfind( "RPARENT")) {//),为空的情况
		temp.pop();
		_index--;
		return true;
	}
	return false;
	
}

//＜因子＞    ::= ＜标识符＞｜＜标识符＞'['＜表达式＞']'|'('＜表达式＞')'｜＜整数＞|＜字符＞｜＜有返回值函数调用语句＞
bool isFactor() {
	if (isfind("IDENFR")) {//标识符

		if (isfind("LBRACK")) {//[      可能是数组

			isExpression();//表达式
			isfind("RBRACK"); //]

		}
		temp.push("<因子>");
		return true;
	}
	if (isfind("LPARENT")) {//(           后面跟表达式
		isExpression();//表达式
		isfind("RPARENT");//)
		temp.push("<因子>");
		return true;
	}
		
	if (isNum() || isChar() || isFunctionCallStatementWithReturn()) {//整数|字符|有返回值函数调用
		temp.push("<因子>");
		return true;
	}
	return false;
}
//＜项＞     ::= ＜因子＞{＜乘法运算符＞＜因子＞}
bool isTerm() {
	if (isFactor()) {//因子
		temp.push("<项>");
		while (isMul()||isAddandSub()) {//乘法运算符
			isFactor();//因子	
			temp.push("<项>");
		}
		
		return true;
	}
	return false;
}
//＜表达式＞    ::= ［＋｜－］＜项＞{＜加法运算符＞＜项＞}
bool isExpression() {
	isAddandSub();//[+||-]
	if (isTerm()) {
		while (isAddandSub()) {
			isTerm();
		}
		temp.push("<表达式>");
		return true;
	}
	return false;
}
//＜赋值语句＞   ::=  ＜标识符＞＝＜表达式＞|＜标识符＞'['＜表达式＞']'=＜表达式＞
bool isAssignmentStatement() {
	if (isfind("IDENFR")) {//标识符

		if (isfind( "ASSIGN")) {//=

			isExpression();//表达式

		}
		if (isfind( "LBRACK")) {//[
	
			isExpression();//表达式
			isfind("RBRACK");//]

			isfind("ASSIGN");//=

			isExpression();//表达式

			
		}
		return true;
	}
	return false;
}
//＜条件＞    ::=  ＜表达式＞＜关系运算符＞＜表达式＞｜＜表达式＞
bool isConditional() {
	if (isExpression()) {
		isRelation();//关系运算符
		isExpression();//表达式
		return true;
	}
	return false;
}
//＜条件语句＞  ::= if '('＜条件＞')'＜语句＞［else＜语句＞］
bool isConditionalStatement() {
	if (isfind( "IFTK")) {//if

		isfind("LPARENT"); //(

		isConditional();//条件
		isfind("RPARENT"); //)
		isStatement();//语句
		if (isfind( "ELSETK")) {//else

			isStatement();//语句
		}
		temp.push("<条件语句>");
		return true;

	}
	return false;
}
//＜步长＞::= ＜无符号整数＞
bool isStep() {
	if (isUnsignedNum()) {
		temp.push("<步长>");
		return true;
	}
	return false;
}
//＜循环语句＞   ::=  while '('＜条件＞')'＜语句＞| do＜语句＞while '('＜条件＞')' |for'('＜标识符＞＝＜表达式＞;＜条件＞;＜标识符＞＝＜标识符＞(+|-)＜步长＞')'＜语句＞
bool isCircularStatement() {
	if (isfind("WHILETK")) {//while
		
		isfind("LPARENT");//(
		isConditional();//条件
		isfind("RPARENT");//)
		isStatement();//语句
		temp.push("<循环语句>");
		return true;
	}
	if (isfind("DOTK")) {//do
		isStatement();//语句
		isfind("WHILETK");//while
		isfind("LPARENT");//(
		isConditional();//条件
		isfind("RPARENT");//)
		temp.push("<循环语句>");
		return true;
	}
	if (isfind("FORTK")) {//for
		isfind("LPARENT");//(
		isfind("IDENFR");//标识符
		isfind("ASSIGN");//=
		isExpression();//表达式
		isfind("SEMICN");//;
		isConditional();//条件
		isfind("SEMICN");//;
		isfind("IDENFR");//标识符
		isfind("ASSIGN");//=
		isfind("IDENFR");//标识符
		isAddandSub();//(+|-)
		isStep();//步长
		isfind("RPARENT");//)
		isStatement();//语句
		temp.push("<循环语句>");
		return true;


	}
	return false;
}
//＜值参数表＞   ::= ＜表达式＞{,＜表达式＞}｜＜空＞
bool isValueParameter() {
	if (isExpression()) {//表达式
		while (isfind("COMMA")) {//,
			isExpression();//表达式
		}
		temp.push("<值参数表>");
		return true;
	}
	if (isfind("RPARENT")) {//表为空
		temp.pop();
		_index--;
		temp.push("<值参数表>");
		return true;
	}
	return false;

	
}
//＜有返回值函数调用语句＞ ::= ＜标识符＞'('＜值参数表＞')'
bool isFunctionCallStatementWithReturn() {
	if (isfind("IDENFR")) {//标识符
		if (find1(_index) == "ASSIGN") {
			temp.pop();
			_index--;
			return false;
		}
		isfind("LPARENT");//（
		isValueParameter();//值参数表
		isfind("RPARENT");//）
		temp.push("<有返回值函数调用语句>");
		return true;
	}
	return false;
}
//＜无返回值函数调用语句＞ ::= ＜标识符＞'('＜值参数表＞')'
bool isFunctionCallStatementWithoutReturn() {
	if (isfind("IDENFR")) {//标识符
		isfind("LPARENT");//（
		isValueParameter();//值参数表
		isfind("RPARENT");//）
		temp.push("<有返回值函数调用语句>");
		return true;
	}
	return false;
}


//＜读语句＞    ::=  scanf '('＜标识符＞{,＜标识符＞}')'
bool isReadStatement() {
	if (isfind("SCANFTK")) {//scanft
		isfind("LPARENT");//(
		isfind("IDENFR");//标识符
		while (isfind("COMMA")) {//,
			isfind("IDENFR");//标识符
		}
		isfind("RPARENT");//)
		temp.push("<读语句>");
		return true;
	}
	return false;
}
//＜写语句＞    ::= printf '(' ＜字符串＞,＜表达式＞ ')'| printf '('＜字符串＞ ')'| printf '('＜表达式＞')'
bool isWriteStatement() {
	if (isfind("PRINTFTK")) {//printf
		isfind("LPARENT");//(
		if (isCharacter()) {//字符串
			if (isfind("COMMA")) {//,
				isExpression();//表达式
			}
			isfind("RPARENT");//)
			temp.push("<写语句>");
			return true;
		}
		if (isFunctionCallStatementWithReturn()) {
			isfind("RPARENT");//)
			temp.push("<写语句>");
			return true;
		}
		if (isExpression()) {
			isfind("RPARENT");//)
			temp.push("<写语句>");
			return true;
		}
		
		
		isfind("RPARENT");//)
		temp.push("<写语句>");
		return true;
		
	}
	return false;
}
//＜返回语句＞   ::=  return['('＜表达式＞')']   
bool isReturnStatement() {
	if (isfind("RETURNTK")) {//return
		if (isfind("LPARENT")) {//(
			isExpression();//表达式
			isfind("RPARENT");//)
		}
		temp.push("<返回语句>");
		return true;
	}
	return false;
}
//＜语句＞    ::= ＜条件语句＞｜＜循环语句＞| '{'＜语句列＞'}'| ＜有返回值函数调用语句＞;  |＜无返回值函数调用语句＞;｜＜赋值语句＞;｜＜读语句＞;｜＜写语句＞;｜＜空＞;|＜返回语句＞;
bool isStatement() {
	if (isConditionalStatement() || isCircularStatement()) {
		temp.push("<语句>");
		return true;
	}
	if (isfind("LBRACE")) {//{
		isStatementColumn();//语句列
		isfind("RBRACE");//}
		temp.push("<语句>");
		return true;
	}
	if (isFunctionCallStatementWithReturn() || isAssignmentStatement() || isReadStatement() || isWriteStatement() || isReturnStatement()) {
		isfind("SEMICN");//;
		temp.push("<语句>");
		return true;
	}
	if (isfind("SEMICN")) {//为空
		temp.push("<语句>");
		return true;
	}
	return false;
}
//＜语句列＞   ::= ｛＜语句＞｝
bool isStatementColumn() {
	if (isStatement()) {
		while (isStatement());
		temp.push("<语句列>");
		return true;
	}
	return false;

}
//＜复合语句＞   ::=  ［＜常量说明＞］［＜变量说明＞］＜语句列＞
bool isCompoundStatement() {
	isConst();//常量说明
	isVariableDescription();//变量说明
	if (isStatementColumn()) {
		temp.push("<复合语句>");
		return true;
	}
	return false;

}
//‎＜有返回值函数定义＞  ::=  ＜声明头部＞'('＜参数表＞')' '{'＜复合语句＞'}'
bool isFunctionWithReturn() {
	if (isHeader()) {//头部声明
		isfind("LPARENT");//（
		isParameter();//参数表
		isfind("RPARENT");//）
		isfind("LBRACE");//{
		isCompoundStatement();//复合语句
		isfind("RBRACE");//}
		temp.push("<有返回值函数定义");
		return true;
	}
	return false;
}
//＜无返回值函数定义＞  ::= void＜标识符＞'('＜参数表＞')''{'＜复合语句＞'}'
bool isFunctionWithoutReturn() {
	if (isfind("VOIDTK")) {//void
		if (!isfind("IDENFR")) {//标识符        与主函数区分
			temp.pop();
			_index--;
			return false;
		}
		isfind("LPARENT");//(
		isParameter();//参数表
		isfind("RPARENT");//)
		isfind("LBRACE");//{
		isCompoundStatement();//复合语句
		isfind("RBRACE");//}
		temp.push("<无返回值函数定义");
		return true;
	}
	return false;
}
//＜主函数＞    ::= void main‘(’‘)’ ‘{’＜复合语句＞‘}’
bool isMain() {
	if (isfind("VOIDTK")) {//void
		isfind("MAINTK");//main
		isfind("LPARENT");//(
		isfind("RPARENT");//)
		isfind("LBRACE");//{
		isCompoundStatement();//复合函数
		isfind("RBRACE");
		temp.push("<主函数>");
		return true;
	}
	return false;
}
//＜程序＞    ::= ［＜常量说明＞］［＜变量说明＞］{＜有返回值函数定义＞|＜无返回值函数定义＞}＜主函数＞
bool isProgram() {
	isConst();
	isVariableDescription();
	while (isFunctionWithReturn() || isFunctionWithoutReturn());
	if (isMain()) {
		temp.push("<程序>");
		return true;
	}
	return false;
}
int main()
{
	initKeyword();
	initoperator();
	initboundary();
	readFile();
	lexical();
	_index = 0;
	isProgram();
	save();
	
	
	return 0;
}