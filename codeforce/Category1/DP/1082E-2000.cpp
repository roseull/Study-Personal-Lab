// 1082E-2000.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set> 
#include <unordered_map> 
#include <algorithm> 
#include<math.h>

//解法： 变种 maximum subarray

using namespace std;

int mymax(int n1, int n2) {
	if (n1 > n2)return n1;
	return n2;
}

void solve(vector<int>&nums, int c) {
	int total = 0; int max = 0; int sum = 0; int maxkey = -1;
	int res = 0;
	int cnt = 0;
	int pre = 0;
	vector<int>counts;
	for (int n : nums) {
		if (n == c)total++;//total c
		counts.push_back(total);
	}
	unordered_map<int, vector<int>>map;
	for (int i = 0; i < nums.size();i++) {
		int n = nums[i];
		if (n == c)continue;
		map[n].push_back(i);
	}
	for (auto& elem : map) {
		sum = 0;
		pre = 0;
		for (int &i : elem.second) {
			if (sum - (counts[i] - pre)<=0) {
				sum = 0;
				pre = counts[i];
			}
			sum++;
			max = mymax(max, sum-(counts[i] - pre));
		}
	}
	cout << (total + max) << endl;

}

int main()
{
	int n, c;
	cin >> n >> c;
	vector<int>nums;
	for (int i = 0; i < n; i++) {
		int e;
		cin >> e;
		nums.push_back(e);
	}
	solve(nums, c);
    return 0;
}
//13 3
//1 1 1 3 3 3 2 2 2 3 2 2 2
