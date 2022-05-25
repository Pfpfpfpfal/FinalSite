#include "BinaryTree.h"


node* add(node* cur, student x, bool (*cmp)(student x, student y)) {
	if (cur == nullptr) {
		node* NewNode = new node();
		NewNode->value = x;
		return NewNode;
	}

	if (cmp(cur->value, x)) {
		cur->right = add(cur->right, x, cmp);
	}
	else {
		cur->left = add(cur->left, x, cmp);
	}

	return cur;
}

void add(BinTree& t, student x) {
	t.root = add(t.root, x, t.cmp);
}

//BinTree sgt(CmpMark);

void _show(node* t) {
	if (t == nullptr) return;
	_show(t->left);
	cout << t->value.name << ' ' << t->value.mark << endl;
	_show(t->right);
}

void show(BinTree t) {
	_show(t.root);
}

void _showSymbol(node* t, char c) {
	if (t == nullptr) return;
	_showSymbol(t->left, c);
	if (t->value.name[0] == c)
		cout << t->value.name << ' ' << t->value.mark << endl;
	_showSymbol(t->right, c);
}

void showSymbol(BinTree t, char c) {
	_showSymbol(t.root, c);
}
