
#include <string>
#include <vector>
#include <queue>


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int>progressesQ;
	for (int i = 0; i < progresses.size(); i++) {
		progressesQ.push(1 + (100 - progresses[i] - 1) / speeds[i]);
	}
	while (!progressesQ.empty()) {
		int num = 1;
		auto f = progressesQ.front();
		progressesQ.pop();
		while (f >= progressesQ.front() && !progressesQ.empty()) {
			num++;
			progressesQ.pop();
		}
		answer.push_back(num);
	}

	return answer;
}