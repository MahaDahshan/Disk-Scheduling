// ConsoleApplication18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list> 
#include <iterator> 
#include <string>
using namespace std;

void sstf( int*, int, int, int, int);
void fcfs(int *, int, int, int, int, bool);
void scan(int *, int, int, int, int, bool);

int main()
{

	//INPUTS
	cout << "enter the head" << endl;
	int head;
	cin >> head;
	cout << "enter the limit of the disks" << endl;
	int end;
	cin >> end;
	int requests_count;
	cout << "enter number of processes" << endl;
	cin >> requests_count;
	int *requests = new int[requests_count];
	cout << "enter processes" << endl;
	for (int i = 0; i < requests_count; i++) {
		cin >> requests[i];
	}
	cout << "enter the seek time" << endl;
	int seek_time;
	cin >> seek_time;
	cout << "choose direction: ";
	bool upper = false;
	cout << "1-right" << " | " << "0-left" << endl;
	cin >> upper;
	
	bool cont = 1;
	while (cont != 0) {


		////////////////
		int algorithm;
		cout << "Choose an algorithm\n";
		cout << "1 - FCFS\n";
		cout << "2 - SCAN\n";
		cout << "3 - SSTF\n";

		cout << endl;
		cout << ": ";
		cin >> algorithm;

		switch (algorithm) {
			case 1:
				fcfs(requests, head, requests_count, seek_time, end, upper);
				break;
			case 2:
				scan(requests, head, requests_count, seek_time, end, upper);
				break;
			case 3:
				sstf(requests, head, requests_count, seek_time, end);
				break;
			dafault:
				cout << "This is not a valid option, please try again";
		}

		cout << "\n\nType 1 to continue or 0 to exit: ";
		cin >> cont;
	}
}
///////////////////////
///////////////////////

//SSTF
void sstf(int *requests_,int head,int requests_count,int seek_time, int end) {
	cout << "SSTF: " << endl;

	int * requests = new int[requests_count];
	for (int i = 0; i < requests_count; i++) {
		requests[i] = requests_[i];
	}

	int*sstf_requests = new int[requests_count];
	for (int i = 0; i < requests_count; i++) {
		sstf_requests[i] = requests[i];
	}
	int current_request = head;
	int current_request_index = -1;
	int least_distance = 99999;
	int least_distance_index = 0;
	for (int i = 0; i < requests_count; i++) {
		for (int j = 0; j < requests_count; j++) {
			if (j == current_request_index) {
				continue;
			}
			if (least_distance > abs(current_request - requests[j]) ) {
				least_distance = abs(current_request - requests[j]);
				least_distance_index = j;
			}
		}
		least_distance = 99999;
		sstf_requests[i] = requests[least_distance_index];
		current_request = requests[least_distance_index];
		requests[least_distance_index] = 99999;
	}
	
	for (int i = 0; i < requests_count; i++) {
		string arrow = " -> ";
		if (i == requests_count - 1) {
			arrow = "";
		}
		cout << sstf_requests[i] << arrow;
	}

	int total_distance = abs(head - sstf_requests[0]);
	for (int i = 0; i < requests_count - 1; i++) {
		total_distance += abs(sstf_requests[i] - sstf_requests[i + 1]);
	}
	cout << "\n" << "Seek: " << total_distance << " cylinders, " << total_distance * seek_time << "ms";
	cout << endl << endl;
}
///////////////////////
///////////////////////

//SCAN
void scan(int *requests_, int head, int requests_count, int seek_time,int end, bool upper) {
	cout << "Scan: " << endl;

	int * requests = new int[requests_count];
	for (int i = 0; i < requests_count; i++) {
		requests[i] = requests_[i];
	}

	sort(requests, requests + requests_count);
	
	list<int>left;
	list<int>right;
	for (int i = 0; i < requests_count; i++)
	{
		if (requests[i] > head)
			right.push_back(requests[i]);
		else
			left.push_back(requests[i]);
	}
	list<int> SCAN_requests;
	SCAN_requests.push_back(head);
	for (int i = 0; i < 2; i++)
	{
		if (upper)
		{
			for (list <int> ::iterator i = right.begin(); i != (right.end()); i++)
			{
				SCAN_requests.push_back(*i);
			}

		}
		else
		{
			for (auto i = left.rbegin(); i != (left.rend()); i++)
			{
				SCAN_requests.push_back(*i);
			}
		}
		if (i == 0)
		{
			SCAN_requests.push_back((end - 1)*upper);
		}
		upper = !upper;
	}


	int total_distance = 0;
	cout << "Order: ";
	for (list <int> ::iterator i = SCAN_requests.begin(); i != prev(SCAN_requests.end()); i++) {
		cout << *i << " -> ";
		//cout << *i << " - " << *next(i) << " = " << abs(*i - *next(i)) << endl;
		total_distance += abs(*i - *next(i));

	}
	cout << *prev(SCAN_requests.end());
	cout << "\n" << "Seek: " << total_distance << " cylinders, " << total_distance * seek_time << "ms";
	cout << endl << endl;

}
////////////////////////
///////////////////////

//FCFS
void fcfs(int *requests, int head, int requests_count, int seek_time, int end, bool upper) {
	cout << "FCFS: " << endl;
	int total_distance = abs(head - requests[0]);
	for (int i = 0; i < requests_count - 1; i++) {
		//cout << requests[i] << " - " << requests[i+1] << " = " << abs(requests[i] - requests[i + 1]) << endl;
		total_distance += abs(requests[i] - requests[i + 1]);
	}

	cout << "Order: " << head << " -> ";
	for (int i = 0; i < requests_count; i++) {
		string arrow = " -> ";
		if (i == requests_count - 1) {
			arrow = "";
		}
		cout << requests[i] << arrow;
	}
	cout << "\n" << "Seek: " << total_distance << " cylinders, " << total_distance * seek_time << "ms";
	cout << endl << endl;
}
