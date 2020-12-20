#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int solution(vector<vector<int>> routes) {
	int answer = 1;
	sort(routes.begin(), routes.end());
	int end = routes[0][1];
	for (int i = 0; i < routes.size(); i++) {
		if (end >= routes[i][0]) {
			end = min(routes[i][1], end);
		}
		else {
			end = routes[i][1];
			answer++;
		}
	}
	return answer;
}