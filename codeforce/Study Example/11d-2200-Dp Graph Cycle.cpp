// 11d-2200.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set> 
#include <unordered_map> 
#include <algorithm> 
#include<math.h>
using namespace std;
int n, m;
typedef long long LL;
LL dp[1 << 19][19];
bool visit[1 << 19][19];
int graph[19][19];

bool revisit(int path, int cur) {
	return path & (1 << cur);
}

LL dfs(int path, int cur, int root) {
	if (visit[path][cur])return dp[path][cur];
	LL res = 0;
	for (int i = root; i < n; i++) {
		if (graph[cur][i] == 1) {
			int child = i;
			if (child == root && path != ((1 << child) | (1 << cur))) {
				res++;
			}
			else if ((path&(1 << child)) == 0 && child != root) {
				res += dfs((path | (1 << child)), child, root);
			}
		}
	}
	visit[path][cur] = true;
	dp[path][cur] = res;
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	LL res = 0;
	for (int i = 0; i < n; i++) {//starting node
		res += dfs((1 << i), i, i);
	}
	cout << res / 2 << endl;
	return 0;
}

