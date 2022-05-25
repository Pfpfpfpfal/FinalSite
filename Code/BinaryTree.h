#pragma once
#include <string>
#include <iostream>
using namespace std;
struct student {
	string name;
	double mark;
};

struct node {
	student value;
	node* left = nullptr, * right = nullptr;
};


struct BinTree {
	node* root = nullptr;
	
	bool (*cmp)(student x, student y);
	BinTree(bool (*it)(student x, student y)) {
		cmp = it;
	}
};

node* add(node* cur, student x, bool (*cmp)(student x, student y));
void add(BinTree& t, student x);
void _show(node* t);
void show(BinTree t);
void _showSymbol(node* t, char c);
void showSymbol(BinTree t, char c);