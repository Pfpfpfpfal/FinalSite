#include "Queue.h"
#include <iostream>

using namespace std;

void push(Queue& tmp, Man inf) {
	ElemQueue* NewElem = new ElemQueue();
	
	NewElem->value = inf;
	if (tmp.size == 0) {
		tmp.head = NewElem;
		tmp.end = NewElem;
	}
	else {
		tmp.end->next = NewElem;
		tmp.end = tmp.end->next;
	}
	tmp.size++;
}

void pop(Queue& tmp) {
	if (tmp.size == 0) return;

	ElemQueue* dl = tmp.head;
	tmp.head = tmp.head->next;
	delete dl;

	if (tmp.head == nullptr)
		tmp.end = nullptr;
	tmp.size--;
}

Man front(Queue& tmp) {
	return tmp.head->value;
}

void show(Queue& tmp) {
	while (tmp.size > 0){
		cout << front(tmp).name << ' ' << front(tmp).age << ' ' << front(tmp).sex << ' ' << front(tmp).income << endl;
		pop(tmp);
	}
}

