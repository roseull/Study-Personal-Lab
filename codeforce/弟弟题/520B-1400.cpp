// 520B-1400.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set> 
#include <algorithm> 
#include<math.h>
using namespace std;

//red button: multiple by 2
//blue: -1

void solve(int s, int t) {
	if (s >= t) {
		cout << (s-t) << endl; return;
	}
	//t is larget
	int cnt = 0;
	while (t != s) {
		if (t < s) {
			cnt += (s - t);
			break;
		}
		else {
			if (t % 2 == 0) {
				t /= 2; cnt++;
			}
			else {
				t--; cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int main()
{
	int n, m;
	cin >> n >> m;
	solve(n, m);
    return 0;
}

