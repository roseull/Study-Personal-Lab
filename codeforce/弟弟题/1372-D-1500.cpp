// 1323-A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getmax(int n1, int n2) {
	if (n1 > n2)return n1;
	return n2;
}
void print(vector<int>&nums) {
	for (int n : nums)cout << n << " ";
	cout << endl;
}

void solve(vector<int>&nums) {
	int len = nums.size();
	vector<int>dp;
	vector<bool>check;
	dp.push_back(1);
	check.push_back(false);
	int res = 1;
	for (int i = 1; i < len; i++) {
		if (nums[i] > nums[i - 1]) {
			dp.push_back(1+dp[i-1]);
		}
		else {
			dp.push_back(1);
		}
		check.push_back(false);
		res = getmax(res, dp[i]);
	}//withoutremovement	
	print(dp);
	for (int i = 2; i < len; i++) {
		if (nums[i] > nums[i - 2]&&check[i-2]==false) { //we can remove one ele
			if (1 + dp[i - 2] > dp[i]) {
				dp[i] = 1 + dp[i - 2];
				check[i] = true;;
			}
		}
		if (nums[i] > nums[i - 1]) {
			if (1 + dp[i - 1] > dp[i]) {
				dp[i] = 1 + dp[i - 1]; 
				check[i] = check[i - 1];
			}
		}
		res = getmax(res, dp[i]);
	}//remove one element
	print(dp);
	cout << res << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int>nums;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		nums.push_back(a);
	}
	//print(nums);
	solve(nums);

    return 0;
}

