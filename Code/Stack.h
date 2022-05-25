#pragma once

struct elem {
	char c;
	int pos;
	elem* next = nullptr;
};

void push(elem*& tmp, char c, int _pos);
bool empty(elem * tmp);
char topChar(elem* tmp);
int topPos(elem * tmp);
void pop(elem * &tmp);