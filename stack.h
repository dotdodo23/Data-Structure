#pragma once

struct Node {
	int data = 0;
	Node* next = nullptr;
};

class stack {
private:
	Node* head = nullptr;
	int size = 0;
public:
	stack();
	~stack();
	void push(int);
	void pop();
	int top();
	int getsize();
	void swap(stack);
};

stack::stack() {
	head = nullptr;
	size = 0;
}

stack::~stack() {
	Node* tmp = head;
	while (head != nullptr) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

void stack::push(int item) {
	head = new Node{ item, head };
	size++;
}

void stack::pop() {
	Node* tmp = head;
	head = head->next;
	delete tmp;
	size--;
}

int stack::top() {
	return head->data;
}

int stack::getsize() {
	return size;
}

void stack::swap(stack S) {
	Node* _head = S.head;
	int _size = S.size;
	S.head = head;
	S.size = size;
	head = _head;
	size = _size;
}
