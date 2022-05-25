#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;


void _add(ElemLinkedList*& beg, int k) {
	ElemLinkedList* cur = new ElemLinkedList();
	cur->x = k;

	cur->prev = cur->next = cur;
	if (beg == nullptr) {
		beg = cur;
		return;
	}

	ElemLinkedList* end = beg->prev;
	end->next = cur;
	beg->prev = cur;

	cur->next = beg;
	cur->prev = end;
}

void add(LinkedList& lnkl, int k) {
	lnkl.size++;
	_add(lnkl.root, k);
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

LinkedList CreateNumber(string s) {
	LinkedList cur;

	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i += 9) {
		string block = s.substr(i, min(9, (int)s.size() - i));
		reverse(block.begin(), block.end());

		add(cur, stoi(block));
	}
	return cur;
}

LinkedList Sum(LinkedList x, LinkedList y) {
	LinkedList sm;

	if (x.size > y.size)
		swap(x, y);

	ElemLinkedList* ItX = x.root;
	ElemLinkedList* ItY = y.root;
	int over = 0;
	for (int i = 0; i < x.size; ++i) {
		int tmpSum = (ItX->x + ItY->x + over) % 1000000000;
		over = (ItX->x + ItY->x + over) / 1000000000;

		add(sm, tmpSum);

		ItX = ItX->next;
		ItY = ItY->next;
	}

	for (int i = x.size; i < y.size; ++i) {
		int tmpSum = (ItY->x + over) % 1000000000;
		over = (ItY->x + over) / 1000000000;

		add(sm, tmpSum);
		ItY = ItY->next;
	}

	if (over > 0) {
		add(sm, over);
	}

	return sm;
}

void Show(LinkedList x) {
	ElemLinkedList* cur = x.root->prev;
	for (int i = 0; i < x.size; ++i) {
		cout << cur->x;
		cur = cur->prev;
	}
}