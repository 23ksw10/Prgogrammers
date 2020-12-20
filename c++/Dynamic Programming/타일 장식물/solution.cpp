#include <string>
#include <vector>


using namespace std;

#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
	long long answer = 0;
	vector<vector<long>>dp(81, vector<long>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 1;
	dp[1][1] = 4;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + 2 * dp[i][0];
	}
	return dp[N][1];
}