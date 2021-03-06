// 1278B-1500.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set> 
#include <unordered_map> 
#include <algorithm> 
#include<math.h>
using namespace std;
/*	You are given two integers a and b. You can perform a sequence of operations: during the first operation you choose one of these numbers and increase it by 1; during the second operation you choose one of these numbers and increase it by 2, and so on. You choose the number of these operations yourself.
	For example, if a=1 and b=3, you can perform the following sequence of three operations:
	add 1 to a, then a=2 and b=3;
	add 2 to b, then a=2 and b=5;
	add 3 to a, then a=5 and b=5.
*/
void solve(int a, int b) {
	//	((1+n)*n)/2=dif*x
	int dif = abs(a-b);
	if (dif == 0) {
		cout << 0 << endl; 
		return;
	}
	long long n = 1;
	while (((n*(n + 1) / 2)-dif)%2!=0|| ((n*(n + 1) / 2) - dif)<0)n++;
	cout << n << endl;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		solve(a, b);
	}
    return 0;
}

