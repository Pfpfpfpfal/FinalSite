#include <iostream>
#include <string>
#include <fstream>


#include "Header.h"
#include "Stack.h"
#include "Queue.h"
#include "SinleLinkedList.h"
#include "LinkedList.h"
#include "BinaryTree.h"


using namespace std;


string open = "([{";
string close = ")]}";

void Brakets();
void Task2();
void Task3();
void Task4();
void Task5();
void show_content_stack();

int main() {
//	Brakets();
//	Task2();
//	Task3();
//	Task4();
//	Task5();
	cout << "Content-type: text/html; charset=Windows-1251\n\n";
	ifstream f("main.html");
	if (f.is_open())
	{
		auto sz = 65536;
		auto buf = new char[sz];
		while (!f.eof()) {
			f.getline(buf, sz);
			if (!strcmp(buf, "<!--#stack#-->")) {
				show_content_stack();
			}
/*			else if (!strcmp(buf, "<!--#queue#-->")) {
				show_content_queue();
			}
			else if (!strcmp(buf, "<!--#SingleLinkedList#-->")) {
				show_content_SingleLinkedList();
			}
			else if (!strcmp(buf, "<!--#LinkedList#-->")) {
				show_content_LinkedList();
			}*/
			cout << buf;
		}
		delete[] buf;
		f.close();
	}
	else {
		cout << "Can`t show page.";
	}
}

bool CmpMark(student x, student y) {
	return x.mark < y.mark;
}

bool CmpName(student x, student y) {
	return x.name < y.name;
}

void readFile(BinTree& root) {
	ifstream fin("stud.txt");
	if (!fin.is_open()) {
		cout << "<p>file not open</p>";
		return;
	}

	string x, y;
	while (fin >> x >> y) {
		student st;
		st.name = x;
		st.mark = stod(y);
		add(root, st);
	}
	fin.close();
}

void Task5() {
	int t;
	cin >> t;

	if (t == 1) {
		string s;
		cin >> s;
		BinTree sgt = nullptr;
		if (s == "name") {
			sgt = BinTree(CmpName);
		}else {
			sgt = BinTree(CmpMark);
		}

		readFile(sgt);
		show(sgt);
	}
	else {
		char c;
		cin >> c;

		BinTree sgt(CmpName);

		readFile(sgt);
		showSymbol(sgt, c);
	}
}


void Task4() {
	string x, y;
	cin >> x;
	cin >> y;

	LinkedList FirstNum = CreateNumber(x);
	LinkedList SecondNum = CreateNumber(y);

	LinkedList SumNum = Sum(FirstNum, SecondNum);
	Show(SumNum);
}


void Task3() {
	ElemSlist* root = nullptr;

	int x;
	readFile(root);
	cin >> x;
	if (search(root, x)) {
		cout << "not add\n";
		return;
	}

	cout << "add\n";
	add(root, x);
	save(root);
}

void Task2() {
	string res;
	getline(cin, res);

	ifstream fin(res);
	if (!fin.is_open()) {
		cout << "<p>file not open</p>";
		return;
	}


	Queue credit, deposit;
	string s;
	while (getline(fin, s)) {
		s += ' ';

		Man cur;
		int step = 0;
		string t = "";
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == ' ') {

				if (step == 0) {
					cur.name = t;
				}
				else if (step == 1) {
					cur.sex = t;
				}
				else if (step == 2) {
					cur.age = stoi(t);
				}
				else if (step == 3) {
					cur.workPlace = t;
				}
				else if (step == 4) {
					cur.income = stoi(t);
				}
				else if (step == 5) {
					cur.goal = t;
				}
				++step;
				t = "";
				continue;
			}
			t += s[i];
		}

		if (cur.goal == "credit") {
			push(credit, cur);
		}
		else {
			push(deposit, cur);
		}
	}

	cout << "CREDIT\n";
	show(credit);

	cout << "DEPOSIT\n";
	show(deposit);
}


void Brakets(string s) {
	elem* root = nullptr;

	getline(cin, s);
	for (int i = 0; i < s.size(); ++i) {
		if (empty(root)) {
			if (open[0] == s[i] || open[1] == s[i] || open[2] == s[i]) {
				push(root, s[i], i);
			}
			else {
				cout << "error1 " << i + 1;
				return;
			}
		}
		else {
			if (open[0] == s[i] || open[1] == s[i] || open[2] == s[i]) {
				push(root, s[i], i);
			}
			else {
				if (close[0] == s[i] && topChar(root) == '(') {
					pop(root);
				}
				else if (close[1] == s[i] && topChar(root) == '[') {
					pop(root);
				}
				else if (close[2] == s[i] && topChar(root) == '{') {
					pop(root);
				}
				else {
					cout << "error2 " << i + 1;
					return;
				}
			}
		}
	}
	if (!empty(root)) {
		cout << "error3 " << topPos(root);
		return;
	}
	cout << "good";
}


void show_content_stack() {
	char* data = nullptr;
	get_form_data(data);
	char* str = new char[50];


	if (data && strlen(data) > 0)
	{
		char* value = nullptr;
		get_param_value(value, "expression", data);
		str = value;
	}

	cout << "<h5> ¬ведите математическре выражение: </h5>";
	cout << "<form method='get' action='HW.cgi'>";
	cout << "<input type='text' name='expression' maxlength='50' size='50'>";
	cout << "<input type='submit' value='ќтправить'>";
	cout << "</form>";
	string res = "";
	for (int i = 0; i <= strlen(str); i++)
		res += str[i];

	Brakets(res);
	delete[] data;
}

/*string Packing(string x) {
	return "<div>" + x + "</div>";
}*/

/*void show_content_queue() {
	char* data = nullptr;
	get_form_data(data);
	char* str = new char[50];


	if (data && strlen(data) > 0)
	{
		char* value = nullptr;
		get_param_value(value, "NameFile", data);
		str = value;
	}

	cout << "<h5>¬ведите название файла из которого надо считать список: </h5>";
	cout << "<form method='get' action='HW.cgi'>";
	cout << "<input type='text' name='NameFile' maxlength='50' size='50'>";
	cout << "<input type='submit' value='ќтправить'>";
	cout << "</form>";
	string res = "";
	for (int i = 0; i <= strlen(str); i++)
		res += str[i];

	ifstream fin(res);
	if (!fin.is_open()) {
		cout << "<p>file not open</p>";
		return;
	}

	queue credit, contribution;
	string dt;
	men tmp;
	while (!fin.eof()) {
		getline(fin, dt);
		tmp = Parse(dt);
		if (tmp.goal == "credit")
			credit.push(tmp);
		else
			contribution.push(tmp);
	}
	credit.show();
	contribution.show();

	credit.clear();
	contribution.clear();
	dt.clear();
	delete[] data;
}

void show_content_SingleLinkedList() {
	char* data = nullptr;
	get_form_data(data);
	char* str = new char[50];

	if (data && strlen(data) > 0) {
		char* value = nullptr;
		get_param_value(value, "UnicNumber", data);
		str = value;
	}
	cout << "<h5> ¬ведите число чтобы проверить в списке ли оно: </h5>";
	cout << "<form method='get' action='HW.cgi'>";
	cout << "<input type='text' name='UnicNumber' maxlength='50' size='50'>";
	cout << "<input type='submit' value='ќтправить'>";
	cout << "</form>";
	string res = "";
	for (int i = 0; i <= strlen(str); i++)
		res += str[i];
	int num = atoi(res.c_str());

	SingleLinkedList q;
	ifstream fin("UnicList.txt");
	q.ReadData(fin);

	if (!('0' <= res[0] && res[0] <= '9')) {
		cout << Packing("∆дем числа");
	}
	else {
		if (!q.count(num)) {
			q.add(num);
			cout << Packing("The number " + res + " was not in the list");
		}
		else {
			cout << Packing("The number " + res + " was in the list");
		}
	}
	cout << "List of numbers: ";
	q.Show();

	ofstream fout("UnicList.txt");
	q.SaveData(fout);
	q.clear();
	delete[] data;
}

void show_content_LinkedList() {
	char* data = nullptr;
	get_form_data(data);
	char* str = new char[50];

	if (data && strlen(data) > 0) {
		char* value = nullptr;
		get_param_value(value, "Sum", data);
		str = value;
	}
	cout << "<h5> ¬ведите два числа через пробел, которые нужно сложить: </h5>";
	cout << "<form method='get' action='HW.cgi'>";
	cout << "<input type='text' name='Sum' maxlength='50' size='50'>";
	cout << "<input type='submit' value='ќтправить'>";
	cout << "</form>";
	string x = "", y = "";
	int pos = 0;
	for (pos = 0; pos < strlen(str) && str[pos] != ' '; ++pos)
		x += str[pos];
	pos++;
	for (; pos <= strlen(str) && str[pos] != '\0'; ++pos)
		y += str[pos];

	LinkedList ans = CreateNumber(x) + CreateNumber(y);
	cout << "<div>";
	ans.Show();
	cout << "</div";
	return;
}*/