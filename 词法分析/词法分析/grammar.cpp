//#include"lexical.h"
//#include<stack>
//stack<string> _str;
//stack<string> _function;
//
//Word find(int index) {
//	map<int, Word>::iterator k = output.find(index);
//	Word word=(*k).second;
//
//}
//
//
//int Max(int a, int b)
//{
//	if (a > b)return a;
//	return b;
//}
//int Max(int a, int b, int c) {
//	int temp = Max(a, b);
//	if (temp > c)return temp;
//	return c;
//}
//void grammar()
//{
//	int index = -1;
//	int lastCOMMA = -1;//,
//	int lastSEMICN = -1;//;
//	int lastRBRACE=-1;//}
//	int lastLBRACE = -1;//{
//	while (index++) {
//		string _CategoryCode = find(index).CategoryCode;
//		string _Name = find(index).Name;
//		if (_CategoryCode == "COMMA") {
//			Word word = find(index - 1);
//			
//			if (word.CategoryCode== "INTCON" ) {
//				cout << "<�޷�������>" << endl;
//				cout << "<����>" << endl;
//			}
//			
//			lastCOMMA = index;
//			/*int lastBoundary = Max(lastCOMMA, lastRBRACE, lastSEMICN);
//			map<int, Word>::iterator begin = output.find(lastBoundary + 1);
//			map<int, Word>::iterator end = output.find(index);
//			for (map<int, Word>::iterator j = begin; j != end; j++) {
//				_str.push((*j).second.CategoryCode);
//			}
//			while (!_str.empty()) {
//				
//				int a = 0;
//				string str = _str.top();
//				_str.pop();
//				a++;
//				if (str == "INTCON" && a == 1) {
//					cout << "<�޷�������>" << endl;
//					cout << "<����>" << endl;
//				}
//				if (str == "CHARCON" && a == 1) {
//					cout << "���ַ�����" << endl;
//				}
//			}*/
//			
//		}
//		if (_CategoryCode=="SEMICN") {
//			Word word1 = find(index - 1);
//			if (word1.CategoryCode == "INTCON") {
//				cout << "<�޷�������>" << endl;
//				cout << "<����>" << endl;
//			}
//			
//			int lastBoundary = Max(lastSEMICN, lastRBRACE,lastLBRACE);
//			Word word2 = find(lastBoundary + 1);
//			if (word2.CategoryCode == "CONSTTK")
//			{
//				cout << "<��������>" << endl;
//				cout << "<����˵��>" << endl;
//			}
//			if (word2.CategoryCode == "INTTK"||word2.CategoryCode=="CHARTK") {
//				cout << "<��������>" << endl;
//				cout << "<����˵��>" << endl;
//			}
//			lastSEMICN = index;
//			
//		}
//		if (_CategoryCode == "LPARENT") {
//			int lastBoundary = Max(lastSEMICN, lastRBRACE);
//			Word word1 = find(lastBoundary + 1);
//			if (word1.CategoryCode == "INTTK" || word1.CategoryCode == "CHARTK") {
//				cout << "<����ͷ��>" << endl;
//				_function.push("<�з���ֵ��������");
//			}
//			int a = index;
//			while (_CategoryCode != "RPARENT") {
//				index++;
//			}
//			if (index - a > 1) {
//				cout << "<������>" << endl;
//			}
//		}
//		if(_CategoryCode==""){}
//	}
//}
//
