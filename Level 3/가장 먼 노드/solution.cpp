#include <string>
#include <vector>
#include<queue>
#include<set>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	queue<int>q;
	vector<int>ans;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
	vector<bool>b(n + 1, false);
	for (int i = 0; i < edge.size(); i++) {
		v[edge[i][0]][edge[i][1]] = 1;
		v[edge[i][1]][edge[i][0]] = 1;
	}
	b[1] = true;
	int a = 0;
	for (int j = 1; j <= n; j++) {
		if (v[1][j] && !b[j]) {
			b[j] = true;
			q.push(j);
			a++;
		}


	}
	ans.push_back(a);
	a = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int k = 0; k < size; k++) {
			int i = q.front();
			for (int j = 1; j <= n; j++) {
				if (v[i][j] && !b[j]) {
					b[j] = true;
					q.push(j);
					a++;
				}
			}
			q.pop();


		}
		ans.push_back(a);
		a = 0;
	}

	return ans[ans.size() - 2];
}