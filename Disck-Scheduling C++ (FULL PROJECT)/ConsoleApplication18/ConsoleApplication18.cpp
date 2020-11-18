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

	int total_distance = 0;

	//FCFS
	cout << "FCFS: " << endl;
	total_distance = abs(head - requests[0]);
	for (int i = 0; i < requests_count - 1; i++){
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
    cout << "\n" << "Seek: " << total_distance << " cylinders, " << total_distance*seek_time << "ms";
	cout << endl << endl;

	////////////////////////////
	////////////////////////////

	//SCAN
	cout << "Scan: " << endl;
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
	SCAN_requests.push_back (head);
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
	
	
	total_distance = 0;
	cout << "Order: ";
	for (list <int> ::iterator i = SCAN_requests.begin(); i != prev(SCAN_requests.end()); i++) {
		cout << *i << " -> " ;
		//cout << *i << " - " << *next(i) << " = " << abs(*i - *next(i)) << endl;
		total_distance += abs(*i - *next(i));

	}
	cout << *prev(SCAN_requests.end());
	cout << "\n" << "Seek: " << total_distance << " cylinders, " << total_distance * seek_time << "ms";
	cout << endl << endl;
}
