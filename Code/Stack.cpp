#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;



void push(elem*& tmp, char c, int _pos) {
	if (tmp == nullptr) {
		tmp = new elem();
		tmp->c = c;
		tmp->pos = _pos;
		return;
	}

	elem* NewElem = new elem();
	NewElem->c = c;
	NewElem->next = tmp;
	NewElem->pos = _pos;
	tmp = NewElem;
}


bool empty(elem* tmp) {
	if (tmp == nullptr)
		return true;
	return false;
}

char topChar(elem* tmp) {
	return tmp->c;
}

int topPos(elem* tmp) {
	return tmp->pos;
}

void pop(elem*& tmp) {
	elem* dl = tmp;
	tmp = tmp->next;
	delete dl;
}


//int main() {
	
	//return 0;
//}