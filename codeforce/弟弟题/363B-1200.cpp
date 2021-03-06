// 363B-1200.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set> 
#include <algorithm> 
#include<math.h>
using namespace std;

void solve(vector<int>&nums, int k) {
	int cnt = 0;
	int sum = 0;
	int res = -1;
	int max = INT_MAX;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		cnt++;
		if (cnt < k)continue;
		if (max > sum) {
			max = sum;
			res = i-k+1;
		}
		sum -= nums[i - k + 1];
	}
	cout << max<<endl;
	cout << res << endl;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int>nums;
	for (int i = 0; i < n; i++) {
		int e;
		cin >> e;
		nums.push_back(e);
	}
	solve(nums, k);
    return 0;
}

