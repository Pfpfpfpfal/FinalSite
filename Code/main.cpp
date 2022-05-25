#include <iostream>
#include <string>
#include <fstream>


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

int main() {
//	Brakets();
//	Task2();
//	Task3();
//	Task4();
	Task5();
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


	/*
	string name;
	string sex;
	int age;
	string workPlace;
	int income;
	string goal;
	*/

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

















void Brakets() {
	elem* root = nullptr;

	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i) {
		if (empty(root)) {
			// ( [ {
			if (open[0] == s[i] || open[1] == s[i] || open[2] == s[i]) {
				push(root, s[i], i);
			}
			else {
				// error )}]
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
	/// <summary>
	/// ()()[]((
	/// </summary>
	/// <returns></returns>
	if (!empty(root)) {
		cout << "error3 " << topPos(root);
		return;
	}
	cout << "good";
}