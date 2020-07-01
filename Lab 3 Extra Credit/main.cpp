#include <iostream>
#include "ABS.h"
#include "ABQ.h"
#include "SimpleTimer.h"
using namespace std;

// In Test, ABQ or ABS is run with ',' delimiter 
// For easy copy to .csv file, while still outputting in terminal
// To allow for easy diagnostics as the program progresses.

void Test(int choice, int n, float scale_factor) {
	// ABQ
	if (choice == 1) {
		cout << "ABQ," << scale_factor << "," << n << ",";
		ABQ<int> test(2, scale_factor);
		{
			SimpleTimer timer("TEST");
			for (unsigned int i = 0; i < n; i++) {
				test.enqueue(i);
			}
		}
		cout << test.getTotalResizes() << ",";
		{
			SimpleTimer timer("TEST");
			for (unsigned int i = 0; i < n; i++) {
				test.dequeue();
			}
		}
		cout << test.getTotalResizes() << endl;
	}

	// ABS
	else if (choice == 2) {
		cout << "ABS," << scale_factor << "," << n << ",";
		ABS<int> test(2, scale_factor);
		{
			SimpleTimer timer("TEST");
			for (unsigned int i = 0; i < n; i++) {
				test.push(i);
			}
		}
		cout << test.getTotalResizes() << ",";
		{
			SimpleTimer timer("TEST");
			for (unsigned int i = 0; i < n; i++) {
				test.pop();
			}
		}
		cout << test.getTotalResizes() << endl;
	}

	// JUNK
	else {
		cout << "Invalid Test ID, Please use VALID CHOICE." << endl;
	}
}

int main()
{

	// Test takes (ABS or ABQ, N, Scale Factor)
	int testNumbers[] = { 1000, 3000, 5000, 7500, 10000 };
	//int testNumbers[] = { 10000000, 30000000, 50000000, 75000000, 100000000 };
	float testScales[] = { 1.5, 2.0, 3.0, 10.0, 100.0 };
	unsigned int i;
	unsigned int j;
	
	cout << "Tests beginning: " << endl;
	
	// ABQ Tests
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			Test(1, testNumbers[j], testScales[i]);
		}
	}
	
	// ABS Tests
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			Test(2, testNumbers[j], testScales[i]);
	}

	return 0;
}