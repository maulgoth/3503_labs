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
	ABS(int capacity, float scale_factor);
	ABS(const ABS &d);
	ABS& operator=(const ABS& d);
	~ABS();

	void push(T data);
	T pop();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
	unsigned int getTotalResizes();
private:
	unsigned int currSize; // track no T's in stack
	unsigned int maxCapacity; // track stack capacity
	T* stack; // stack pointer
	float scaleFactor; // what to * or / by when full
	unsigned int total_resizes;
};

// default constructor
template<typename T>
ABS<T>::ABS() {
	currSize = 0;
	maxCapacity = 1;
	stack = new T[1];
	scaleFactor = 2.0f;
	total_resizes = 0;
}

// constructor
template<typename T>
ABS<T>::ABS(int capacity) {
	currSize = 0;
	maxCapacity = capacity;
	stack = new T[capacity];
	scaleFactor = 2.0f;
	total_resizes = 0;
}

// constructor NEW with updated scale_factor
template<typename T>
ABS<T>::ABS(int capacity, float scale_factor) {
	currSize = 0;
	maxCapacity = capacity;
	stack = new T[capacity];
	scaleFactor = scale_factor;
	total_resizes = 0;
}

// copy constructor
template<typename T>
ABS<T>::ABS(const ABS& d) {
	currSize = d.currSize;
	maxCapacity = d.maxCapacity;
	scaleFactor = d.scaleFactor;
	total_resizes = d.total_resizes;

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
		scaleFactor = d.scaleFactor;
		total_resizes = d.total_resizes;

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

// get total resizes
template<typename T>
unsigned int ABS<T>::getTotalResizes() {
	return total_resizes;
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

		total_resizes++;
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

	// This segment inspired by the comments from Akash Patel in the COP3503 Slack Channel:
	//
	// Check for floating comparison errors:
	float x;
	if (fabs((((float)(currSize - 1) / maxCapacity) - (1 / scaleFactor))) < 0.00001)
		x = (1 / scaleFactor);
	else
		x = (((float)(currSize - 1) / maxCapacity));

	// check if queue is half full
	if (x < (1 / scaleFactor)) {
		
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

		total_resizes++;

		// return deleted top
		return top;
	}

	// Otherwise delete the last
	else {
		T top = stack[currSize-1];
		currSize--;
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