#include <string>
#include <vector>



using namespace std;


void dfs(vector<bool>&b, vector<vector<int>> &computers, int r) {

	for (auto i = 0; i < computers.size(); i++) {
		if (!b[i] && r != i && computers[r][i]) {
			b[i] = true;
			dfs(b, computers, i);
		}



	}


}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<bool>b(computers.size(), false);
	for (int i = 0; i < computers.size(); i++) {

		if (b[i])continue;

		b[i] = true;
		answer++;
		dfs(b, computers, i);

	}
	return answer;
}
