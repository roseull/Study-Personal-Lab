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

int main()
{
	//zero one
	int n;
	int z = 0; 
	int N = 0;
	string s;
	cin >> n>>s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'z')z++;
		if (s[i] == 'n')N++;
	}
	for (int i = 0; i < N; i++)cout << "1 ";
	for (int i = 0; i < z; i++)cout << "0 ";
    return 0;
}

