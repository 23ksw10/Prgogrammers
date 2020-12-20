#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int weight_on_bridge = 0;
	queue<int>truck;
	queue<int>truck_time;
	queue<int>s;
	for (int i = 0; i < truck_weights.size(); i++) {
		truck.push(truck_weights[i]);
		s.push(truck_weights[i]);


	}
	while (!truck.empty()) {
		if (!s.empty())weight_on_bridge += s.front();
		if (!truck_time.empty() && answer > truck_time.front()) {
			weight_on_bridge -= truck.front();

			truck.pop();
			truck_time.pop();
		}
		if (weight_on_bridge <= weight) {

			truck_time.push(answer + bridge_length - 1);

			answer++;
			if (!s.empty())s.pop();

		}
		else {
			if (!s.empty())weight_on_bridge -= s.front();
			answer++;
		}

	}

	return answer;
}