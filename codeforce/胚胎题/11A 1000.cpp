// 11A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set> 
#include <algorithm> 
#include<math.h>
using namespace std;

void solve(vector<long>&nums, int d) {
	int cnt = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > nums[i - 1])continue;
		int dif = nums[i - 1] - nums[i];
		int t = dif / d + 1;
		cnt += t;
		nums[i] += (t*d);
	}
	cout << cnt << endl;
}

int main()
{
	int n, d;
	cin >> n >> d;
	vector<long>nums;
	for (int i = 0; i < n; i++) {
		int e;
		cin >> e;
		nums.push_back(e);
	}
	solve(nums, d);
    return 0;
}

