#include <string>
#include <vector>
#include <set>


using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	set<pair<int, int>>s;
	for (int i = 0; i < puddles.size(); i++) {
		s.insert({ puddles[i][1],puddles[i][0] });
	}
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s.find({ i,j }) == s.end()) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;

		}
	}
	return dp[n][m];
}