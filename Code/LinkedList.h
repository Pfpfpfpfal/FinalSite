#pragma once
#include <string>
struct ElemLinkedList
{
	int x = 0;
	ElemLinkedList *next, *prev;
};

struct LinkedList{
	ElemLinkedList* root = nullptr;
	int size = 0;
};

void _add(ElemLinkedList*& beg, int k);
void add(LinkedList& lnkl, int k);
int min(int a, int b);
LinkedList CreateNumber(std::string s);
LinkedList Sum(LinkedList x, LinkedList y);
void Show(LinkedList x);