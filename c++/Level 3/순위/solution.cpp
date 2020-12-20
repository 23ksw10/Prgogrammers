#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>>results_table(n + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < results.size(); i++) {
		results_table[results[i][0]][results[i][1]] = true;

	}
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (results_table[i][k] && results_table[k][j]) {
					results_table[i][j] = true;
				}
			}

		}
	}
	for (int i = 1; i < n + 1; i++) {
		int count = 0;
		for (int j = 1; j < n + 1; j++) {
			if (results_table[i][j] || results_table[j][i]) {
				count++;
			}
		}
		if (count == n - 1)answer++;

	}
	return answer;
}