// 1325-B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set> 
using namespace std;

int getmin(int n1, int n2) {
	if (n1 < n2)return n1;
	return n2;
}
void solve(vector<int> &nums) {
	if (nums.size() == 0)cout << 0 << endl;
	int res = 0;
	unordered_set<int>myset;
	for (int n : nums)myset.insert(n);
	res = myset.size();
	cout << res << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> nums;
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			nums.push_back(num);
		}
		solve(nums);
	}
    return 0;
}

