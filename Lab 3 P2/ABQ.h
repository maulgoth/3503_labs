// Jeremy DePoyster - COP3503 Summer 2020 - UF Online
// All code completely original or inspired by Professor Joshua Fox's lectures

#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "leaker.h"

template<typename T>
class ABQ {
public:
	ABQ();
	ABQ(int capacity);
	ABQ(int capacity, float scale_factor);
	ABQ(const ABQ& d);
	ABQ& operator=(const ABQ& d);
	~ABQ();

	void enqueue(T data);
	T dequeue();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
	unsigned int getTotalResizes();
private:
	unsigned int currSize; // track no T's in stack
	unsigned int maxCapacity; // track stack capacity
	T* queue; // stack pointer
	float scaleFactor; // what to * or / by when full
	unsigned int total_resizes;
	// This COUNTER variable inspired by Akash Patel on the COP3503 channel 
	// to avoid duplicating the queue on each dequeue:
	unsigned int counter;
};

// default constructor
template<typename T>
ABQ<T>::ABQ() {
	currSize = 0;
	maxCapacity = 1;
	queue = new T[1];
	scaleFactor = 2.0f;
	total_resizes = 0;
	counter = 0;
}

// constructor
template<typename T>
ABQ<T>::ABQ(int capacity) {
	currSize = 0;
	maxCapacity = capacity;
	queue = new T[capacity];
	scaleFactor = 2.0f;
	total_resizes = 0;
	counter = 0;
}

// constructor NEW with updated scale_factor
template<typename T>
ABQ<T>::ABQ(int capacity, float scale_factor) {
	currSize = 0;
	maxCapacity = capacity;
	queue = new T[capacity];
	scaleFactor = scale_factor;
	total_resizes = 0;
	counter = 0;
}

// copy constructor
template<typename T>
ABQ<T>::ABQ(const ABQ& d) {
	currSize = d.currSize;
	maxCapacity = d.maxCapacity;
	scaleFactor = d.scaleFactor;
	total_resizes = d.total_resizes;
	counter = d.counter;

	queue = new T[maxCapacity];
	for (unsigned int i = 0; i < currSize; i++) {
		queue[i] = d.queue[i];
	}
}

// copy assignment operator
template<typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ& d) {
	if (this != d) {
		delete[] queue;
		currSize = d.currSize;
		maxCapacity = d.maxCapacity;
		scaleFactor = d.scaleFactor;
		total_resizes = d.total_resizes;
		counter = d.counter;

		queue = new T[maxCapacity];
		for (unsigned int i = 0; i < currSize; i++) {
			queue[i] = d.queue[i];
		}
	}
	return *this;
}

// destructor
template<typename T>
ABQ<T>::~ABQ() {
	delete[] queue;
}

// get total resizes
template<typename T>
unsigned int ABQ<T>::getTotalResizes() {
	return total_resizes;
}

// push
template<typename T>
void ABQ<T>::enqueue(T data) {

	// check if full
	if (currSize == maxCapacity) {

		// change capacity
		maxCapacity = maxCapacity * scaleFactor;

		// make temp queue with new capacity
		T* newQueue = new T[maxCapacity];

		// fill temp queue
		for (unsigned int i = 0; i < currSize; i++) {
			newQueue[i] = queue[i];
		}

		// delete old queue
		delete[] queue;

		// replace with temp queue
		queue = newQueue;

		// push
		queue[currSize] = data;

		// update size
		currSize++;
		total_resizes++;
	}

	// otherwise, push and update size
	else {
		queue[currSize] = data;
		currSize++;
	}
}

// pop / delete top of stack
template<typename T>
T ABQ<T>::dequeue() {

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
		// store first for later return
		T firstIn = queue[counter];

		// resize maxCapacity
		maxCapacity = maxCapacity / scaleFactor;

		// make temp queue with new capacity
		T* newQueue = new T[maxCapacity];

		// fill temp queue
		for (unsigned int i = 1; i < currSize; i++) {
			newQueue[i-1] = queue[i];
		}

		// delete old queue
		delete[] queue;

		// replace with temp queue
		queue = newQueue;

		// update size
		currSize--;

		total_resizes++;

		counter = 0;

		// return deleted first
		return firstIn;
	}

	// otherwise, delete the first
	else {
		T firstIn = queue[counter];
		currSize--;
		counter++;
		return firstIn;
	}
	
}

// return first of queue
template<typename T>
T ABQ<T>::peek() {
	if (currSize == 0) {
		throw runtime_error("An error has occured");
	}
	else {
		return queue[0];
	}
}

// return size
template<typename T>
unsigned int ABQ<T>::getSize() {
	return currSize;
}

// return capacity
template<typename T>
unsigned int ABQ<T>::getMaxCapacity() {
	return maxCapacity;
}

// return queue array
template<typename T>
T* ABQ<T>::getData() {
	return queue;
}