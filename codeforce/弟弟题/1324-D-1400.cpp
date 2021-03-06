// 1323-A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int len, vector<int>&teacher, vector<int>&student) {
	long long res = 0;
	vector<int>dif;
	for (int i = 0; i < len; i++) {
		dif.push_back(teacher[i] - student[i]);
	}
	sort(dif.begin(), dif.end());
	for (int i = 0; i < dif.size(); i++) {
		int n = dif[i];
		if (n > 0) {
			res += (dif.size()-1-i);
		}
		else {//bin search
			int target = 0 - dif[i]; //find the index larger than target
			int left = i + 1; int right = dif.size() - 1;
			int index = -1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (dif[mid] > target) {
					index = mid;
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			if (index != -1) {
				cout << n<<" index"<<index<<" "<<(dif.size() - index) << endl;
				res += (dif.size()-index);
			}
		}
	}
	cout << res << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int>teacher;
	vector<int>student;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		teacher.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		student.push_back(x);
	}
	solve(n, teacher, student);
    return 0;
}

