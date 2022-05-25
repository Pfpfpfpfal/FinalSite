#pragma once
#include <string>

using namespace std;
//Фамилия И.О. | пол | возраст | место работы 
//| размер дохода(при наличии) | цель обращения(кредит / вклад)
struct Man{
	string name;
	string sex;
	int age;
	string workPlace;
	int income;
	string goal;
};

struct ElemQueue {
	Man value;
	ElemQueue* next = nullptr;
};

struct Queue {
	ElemQueue* head = nullptr;
	ElemQueue* end = nullptr;
	int size = 0;
};

void push(Queue& tmp, Man inf);
void pop(Queue& tmp);
Man front(Queue& tmp);
void show(Queue& tmp);
