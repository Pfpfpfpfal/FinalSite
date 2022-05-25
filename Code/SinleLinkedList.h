#pragma once


struct ElemSlist {
	int key;
	ElemSlist* next = nullptr;
};


bool search(ElemSlist*& root, int value);
void add(ElemSlist*& root, int value);
void save(ElemSlist*& root);
void readFile(ElemSlist*& root);
