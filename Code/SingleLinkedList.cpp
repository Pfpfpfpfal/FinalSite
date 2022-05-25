#include "SinleLinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


bool search(ElemSlist*& root, int value) {
	ElemSlist* cur = root;
	while (cur != nullptr) {
		if (cur->key == value)
			return true;
		cur = cur->next;
	}
	return false;
}

void add(ElemSlist*& root, int value) {
	if (search(root, value))
		return;

	ElemSlist* NewElem = new ElemSlist();
	NewElem->key = value;

	if (root == nullptr) {
		root = NewElem;
		return;
	}

	ElemSlist* cur = root;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = NewElem;
}


void readFile(ElemSlist*& root) {
	ifstream fin("UnicList.txt");
	if (!fin.is_open()) {
		cout << "<p>file not open</p>";
		return;
	}

	string x;
	while (getline(fin, x)){
		add(root, stoi(x));
	}

	fin.close();
}

void save(ElemSlist*& root) {
	ofstream fout("UnicList.txt");
	if (!fout.is_open()) {
		cout << "<p>file not open</p>";
		return;
	}

	ElemSlist* cur = root;
	while (cur != nullptr){
		fout << cur->key << "\n";
		cur = cur->next;
	}

	fout.close();
}

