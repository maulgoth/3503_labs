// Jeremy DePoyster - COP3503 Summer 2020 - UF Online
// All code completely original or inspired by Professor Joshua Fox's lectures

#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class ABS {
public:
	ABS();
	ABS(int capacity);
	ABS(const ABS &d);
	ABS& operator=(const ABS& d);
	~ABS();

	void push(T data);
	T pop();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
private:
	unsigned int currSize; // track no T's in stack
	unsigned int maxCapacity; // track stack capacity
	T* stack; // stack pointer
	const float scaleFactor = 2.0f; // what to * or / by when full
};

// default constructor
template<typename T>
ABS<T>::ABS() {
	currSize = 0;
	maxCapacity = 1;
	stack = new T[1];
}

// constructor
template<typename T>
ABS<T>::ABS(int capacity) {
	currSize = 0;
	maxCapacity = capacity;
	stack = new T[capacity];
}

// copy constructor
template<typename T>
ABS<T>::ABS(const ABS& d) {
	currSize = d.currSize;
	maxCapacity = d.maxCapacity;

	stack = new T[maxCapacity];
	for (unsigned int i = 0; i < currSize; i++) {
		stack[i] = d.stack[i];
	}
}

// copy assignment operator
template<typename T>
ABS<T>& ABS<T>::operator=(const ABS& d) {
	if (this != d) {
		delete[] stack;
		currSize = d.currSize;
		maxCapacity = d.maxCapacity;

		stack = new T[maxCapacity];
		for (unsigned int i = 0; i < currSize; i++) {
			stack[i] = d.stack[i];
		}
	}
	return *this;
}

// destructor
template<typename T>
ABS<T>::~ABS() {
	delete[] stack;
}

// push
template<typename T>
void ABS<T>::push(T data) {

	// check if full
	if (currSize == maxCapacity) {

		// change capacity
		maxCapacity = maxCapacity * scaleFactor;

		// make temp stack with new capacity
		T* newStack = new T[maxCapacity];

		// fill temp stack
		for (unsigned int i = 0; i < currSize; i++) {
			newStack[i] = stack[i];
		}

		// delete old stack
		delete[] stack;

		// replace with temp stack
		stack = newStack;

		// push
		stack[currSize] = data;

		// update size
		currSize++;
	}

	// otherwise, push and update size
	else {
		stack[currSize] = data;
		currSize++;
	}
}

// pop / delete top of stack
template<typename T>
T ABS<T>::pop() {

	if (currSize == 0) {
		throw runtime_error("An error has occured");
	}

	// check if stack is half full
	else if (((float)(currSize-1)/maxCapacity) < (1/scaleFactor)) {

		// store top for later return
		T top = stack[currSize-1];

		// resize maxCapacity
		maxCapacity = maxCapacity / scaleFactor;

		// make temp stack with new capacity
		T* newStack = new T[maxCapacity];

		// fill temp stack
		for (unsigned int i = 0; i < currSize-1; i++) {
			newStack[i] = stack[i];
		}

		// delete old stack
		delete[] stack;

		// replace with temp stack
		stack = newStack;

		// update size
		currSize--;

		// return deleted top
		return top;
	}

	// otherwise, pop the top
	else {

		// store top for later return
		T top = stack[currSize-1];

		// make temp stack with new capacity
		T* newStack = new T[maxCapacity];

		// fill temp stack
		for (unsigned int i = 0; i < currSize - 1; i++) {
			newStack[i] = stack[i];
		}

		// delete old stack
		delete[] stack;

		// replace with temp stack
		stack = newStack;

		// update size
		currSize--;

		// return deleted top
		return top;
	}
}

// return top of stack
template<typename T>
T ABS<T>::peek() {
	if (currSize == 0) {
		throw runtime_error("An error has occured");
	}
	else {
		return stack[currSize-1];
	}
}

// return size
template<typename T>
unsigned int ABS<T>::getSize() {
	return currSize;
}

// return capacity
template<typename T>
unsigned int ABS<T>::getMaxCapacity() {
	return maxCapacity;
}

// return stack array
template<typename T>
T* ABS<T>::getData() {
	return stack;
}