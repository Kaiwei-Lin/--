//#include"lexical.h"
//void initKeyword()
//{
//	_keyword.insert(make_pair("CONSTTK", "const"));
//	_keyword.insert(make_pair("INTTK", "int"));
//	_keyword.insert(make_pair("CHARTK", "char"));
//	_keyword.insert(make_pair("VOIDTK", "void"));
//	_keyword.insert(make_pair("MAINTK", "main"));
//	_keyword.insert(make_pair("IFTK", "if"));
//	_keyword.insert(make_pair("ELSETK", "else"));
//	_keyword.insert(make_pair("DOTK", "do"));
//	_keyword.insert(make_pair("WHILETK", "while"));
//	_keyword.insert(make_pair("FORTK", "for"));
//	_keyword.insert(make_pair("SCANFTK", "scanf"));
//	_keyword.insert(make_pair("PRINTFTK", "printf"));
//	_keyword.insert(make_pair("RETURNTK", "return"));
//
//}
//void initoperator()
//{
//	_operator.insert(make_pair("PLUS", "+"));
//	_operator.insert(make_pair("MINU", "-"));
//	_operator.insert(make_pair("MULT", "*"));
//	_operator.insert(make_pair("DIV", "/"));
//	_operator.insert(make_pair("LSS", "<"));
//	_operator.insert(make_pair("LEQ", "<="));
//	_operator.insert(make_pair("GRE", ">"));
//	_operator.insert(make_pair("GEQ", ">="));
//	_operator.insert(make_pair("EQL", "=="));
//	_operator.insert(make_pair("NEQ", "!="));
//	_operator.insert(make_pair("ASSIGN", "="));
//
//
//
//
//}
//void initboundary()
//{
//	_boundary.insert(make_pair("SEMICN", ";"));
//	_boundary.insert(make_pair("COMMA", ","));
//	_boundary.insert(make_pair("LPARENT", "("));
//	_boundary.insert(make_pair("RPARENT", ")"));
//	_boundary.insert(make_pair("LBRACK", "["));
//	_boundary.insert(make_pair("RBRACK", "]"));
//	_boundary.insert(make_pair("LBRACE", "{"));
//	_boundary.insert(make_pair("RBRACE", "}"));
//}
//void readFile()
//{
//
//	char str;
//	ifstream myfile(INFILE);
//	string tmp;
//	if (myfile.is_open())
//	{
//		while (getline(myfile, tmp))
//		{
//
//
//
//			input.append(tmp);
//			//output.push_back(tmp);
//
//		}
//
//
//	}
//
//	myfile.close();
//
//}
//bool isboundaryandPrintf(char a)
//{
//	string tmp(1, a);
//	for (map<string, string>::iterator k = _boundary.begin(); k != _boundary.end(); k++)
//	{
//		if ((*k).second == tmp)
//		{
//
//			Word newWord;
//			newWord.CategoryCode = (*k).first;
//			newWord.Name = (*k).second;
//			output.insert(make_pair(_index, newWord));
//			_index++;
//
//			//cout << (*k).first << " " << (*k).second << endl;
//			return true;
//		}
//	}
//	return false;
//}
//bool isboundary(char a)
//{
//	string tmp(1, a);
//	for (map<string, string>::iterator k = _boundary.begin(); k != _boundary.end(); k++)
//	{
//		if ((*k).second == tmp)
//		{
//
//			return true;
//		}
//	}
//	return false;
//}
//bool isOperatorandPrintf(string tmp)
//{
//
//	for (map<string, string>::iterator k = _operator.begin(); k != _operator.end(); k++)
//	{
//		if ((*k).second == tmp)
//		{
//			Word newWord;
//			newWord.CategoryCode = (*k).first;
//			newWord.Name = (*k).second;
//			output.insert(make_pair(_index, newWord));
//			_index++;
//			//cout << (*k).first << " " << (*k).second << endl;
//			return true;
//		}
//	}
//	return false;
//}
//bool isOperator(string tmp)
//{
//	for (map<string, string>::iterator k = _operator.begin(); k != _operator.end(); k++)
//	{
//		if ((*k).second == tmp)
//		{
//
//			return true;
//		}
//	}
//	return false;
//}
//bool isKeyword(string tmp)
//{
//	for (map<string, string>::iterator k = _keyword.begin(); k != _keyword.end(); k++)
//	{
//		if ((*k).second == tmp)
//		{
//			Word newWord;
//			newWord.CategoryCode = (*k).first;
//			newWord.Name = (*k).second;
//			output.insert(make_pair(_index, newWord));
//			_index++;
//			//cout << (*k).first << " " << (*k).second << endl;
//			return true;
//		}
//	}
//	return false;
//
//
//
//
//}
//bool isDegital(string str) {
//	if (str == "")return false;
//	for (int i = 0; i < str.size(); i++) {
//		if (str.at(i) == '-' && str.size() > 1)  // 有可能出现负数
//			continue;
//		if (str.at(i) > '9' || str.at(i) < '0')
//			return false;
//	}
//
//	Word newWord;
//	newWord.CategoryCode = "INTCON";
//	newWord.Name = str;
//	output.insert(make_pair(_index, newWord));
//	_index++;
//
//	//cout << "INTCON " << str << endl;
//	return true;
//}
//bool isLetter(char A)
//{
//	if ((A >= 'A' && A <= 'Z') || A >= 'a' && A <= 'z')
//		return true;
//	return false;
//}
//bool isNumber(char A)
//{
//	if ((A >= '0' && A <= '9'))
//		return true;
//	return false;
//}
//void lexical()
//{
//	char token[120];
//	int index = 0;
//
//
//	while (input[index] != ' ' && index < input.size())
//	{
//
//		string b(1, input[index]);
//
//		if (isLetter(input[index]) || input[index] == '_')//第一个字符为字母
//		{
//
//			int k = 0;
//			string _opr;
//			do {
//				token[k] = input[index];
//				k++;
//				index++;
//				char op = input[index];
//				string opr(1, op);
//				_opr = opr;
//			} while (input[index] != ' ' && index < input.size() - 1 && !isboundary(input[index]) && !isOperator(_opr));
//			string str(token, k);
//			if (!isKeyword(str))
//			{
//
//				Word newWord;
//				newWord.CategoryCode = "IDENFR";
//				newWord.Name = str;
//				output.insert(make_pair(_index, newWord));
//				_index++;
//				//cout << "IDENFR " << a << endl;
//			}
//
//
//			if (index < input.size() - 1 && isboundaryandPrintf(input[index]))index++;
//		}
//		if (isNumber(input[index]))//第一个字符为数字
//		{
//
//			int k = 0;
//			do {
//				token[k] = input[index];
//				k++;
//				index++;
//			} while (input[index] != ' ' && index < input.size() - 1 && !isboundary(input[index]));
//			string num(token, k);
//			if (isDegital(num)) {
//				isboundaryandPrintf(input[index]);
//				index++;
//			}
//
//
//		}
//		if (input[index] == '\'')//第一个字符为‘
//		{
//
//			int k = 0;
//			index++;
//			do {
//				token[k] = input[index];
//				k++;
//				index++;
//			} while (input[index] != '\'');
//			string str(token, k);
//
//			Word newWord;
//			newWord.CategoryCode = "CHARON";
//			newWord.Name = str;
//			output.insert(make_pair(_index, newWord));
//			_index++;
//			//cout << "CHARCON " << a << endl;
//			index++;
//
//		}
//		if (input[index] == '\"')//第一个字符为“
//		{
//
//			int k = 0;
//			index++;
//			do {
//				token[k] = input[index];
//				k++;
//				index++;
//			} while (input[index] != '\"');
//			string str(token, k);
//
//			Word newWord;
//			newWord.CategoryCode = "STRCON";
//			newWord.Name = str;
//			output.insert(make_pair(_index, newWord));
//			_index++;
//			//cout << "STRCON " << a << endl;
//			index++;
//		}
//
//		if (isOperator(b) || b == "!")//第一个字符为运算符
//		{
//
//			int k = 0;
//			index++;
//			string c(1, input[index]);
//			if (isOperator(c))
//			{
//				b.append(c);
//				index++;
//
//			}
//			isOperatorandPrintf(b);
//
//
//		}
//		if (isboundaryandPrintf(input[index]))index++;//遇到分界符
//		if (index < input.size() - 1 && (input[index] == ' ' || input[index] == '\t' || input[index] == '\r'))//遇到空格
//		{
//			do {
//				index++;
//
//			} while (index < input.size() - 1 && (input[index] == ' ' || input[index] == '\t' || input[index] == '\r'));
//		}
//
//
//
//
//
//
//	}
//
//
//
//
//
//}
////写入文件
//void save()
//{
//	ofstream myfile;
//	myfile.open(OUTFILE);
//	if (myfile.is_open())
//	{
//		for (map<int, Word>::iterator k = output.begin(); k != output.end(); k++)
//		{
//			myfile << (*k).second.CategoryCode << " " << (*k).second.Name << endl;
//		}
//		/*for (int i = 0; i < input.size(); i++)
//		{
//			if((int)input[i]<32||(int)input[i]>125)
//				myfile << (int)input[i] << endl;
//		}*/
//
//	}
//	myfile.close();
//}