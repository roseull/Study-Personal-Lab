// 1220A-600.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set> 
#include <unordered_map> 
#include <algorithm> 
#include<math.h>
#include<string>
using namespace std;

void solve(int n) {
	unordered_set<int>nums;//store all different divisors
	for (int i = 2; i * i <= n; i++) {
		if (n%i == 0) {
			nums.insert(i);
			n /= i; break;
		}
	}
	for (int i = 2; i * i <= n; i++) {
		if (n%i == 0&&nums.count(i)==0) {
			nums.insert(i);
			n /= i; 
			break;
		}
	}
	if (nums.size() < 2 || nums.count(n) != 0) {
		cout << "No"<<endl;
		return;
	}
	cout << "Yes" << endl;
	vector<int>v;
	for (auto i : nums)v.push_back(i);
	sort(v.begin(), v.end());
	for (int n : v) {
		cout << n << " ";
	}
	cout << endl;

	// ab=(n/c)
	//
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		solve(n);
	}
    return 0;
}

