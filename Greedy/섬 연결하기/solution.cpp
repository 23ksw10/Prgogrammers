#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int findUnion(vector<int> &parents, int a) {
	if (parents[a] == a)return a;
	else return findUnion(parents, parents[a]);
}


int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	vector<int> parents(n, 0);
	for (int i = 0; i < parents.size(); i++) {
		parents[i] = i;
	}
	sort(costs.begin(), costs.end(), [](const vector<int>&a, const vector<int>&b) {return a[2] < b[2]; });
	for (int i = 0; i < costs.size(); i++) {
		int a = costs[i][0];
		int b = costs[i][1];
		int s = findUnion(parents, a);
		int d = findUnion(parents, b);
		if (s != d) {
			parents[d] = s;

			answer += costs[i][2];

		}


	}
	return answer;
}