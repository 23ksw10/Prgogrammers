#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void hanoi(int n, int start, int mid, int end) {
	if (n == 1) {
		answer.push_back({ start,end });
	}
	else {

		hanoi(n - 1, start, end, mid);
		answer.push_back({ start,end });
		hanoi(n - 1, mid, start, end);
	}
}
vector<vector<int>> solution(int n) {
	hanoi(n, 1, 2, 3);
	return answer;
}