#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void permutation(vector<int> dist, vector<vector<int>>&p_dist) {
	do {
		p_dist.push_back(dist);
	} while (std::next_permutation(dist.begin(), dist.end()));
}
int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 100000;
	int s = weak.size();
	sort(dist.begin(), dist.end());
	vector<vector<int>>all_weak(s);
	vector<vector<int>>p_dist;
	permutation(dist, p_dist);
	for (int i = 0; i < s; i++) {
		cout << weak[i] << ' ';
	}

	for (int i = 0; i < s; i++) {
		vector<int>tmp;
		for (int k = i; k < s; k++) {
			tmp.push_back(weak[k]);
		}
		int e = 0;
		while (tmp.size() != s) {
			tmp.push_back(weak[e++] + n);
		}
		all_weak[i] = tmp;
	}
	int people = 0;
	for (int a = 0; a < p_dist.size(); a++) {
		for (int i = 0; i < s; i++) {
			int tmp = -1;
			int k = 0;
			int j = 0;
			for (j; j < s; j++) {
				if (all_weak[i][j] > tmp) {
					if (k >= dist.size())break;
					tmp = all_weak[i][j] + p_dist[a][k++];
					people++;
				}
			}
			if (tmp >= all_weak[i][s - 1]) {
				answer = min(people, answer);
			}
			people = 0;
		}
	}
	if (answer == 100000)return -1;
	return answer;
}