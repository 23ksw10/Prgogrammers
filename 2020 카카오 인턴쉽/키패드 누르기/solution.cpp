#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	vector<pair<int, int>>keypad;
	pair<int, int>left = { 3,0 };
	pair<int, int>right = { 3,2 };
	keypad.push_back({ 3,1 });
	for (int i = 0; i < 9; i++) {
		if (i < 3) {
			keypad.push_back({ 0,i });
		}
		else if (i < 6 && i >= 3) {
			keypad.push_back({ 1,i - 3 });
		}
		else {
			keypad.push_back({ 2,i - 6 });
		}
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer.push_back('L');
			left = keypad[numbers[i]];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer.push_back('R');
			right = keypad[numbers[i]];
		}
		else {
			int ldis = abs(left.first - keypad[numbers[i]].first) + abs(left.second - keypad[numbers[i]].second);
			int rdis = abs(right.first - keypad[numbers[i]].first) + abs(right.second - keypad[numbers[i]].second);
			if (ldis < rdis) {
				answer.push_back('L');
				left = keypad[numbers[i]];
			}
			else if (ldis > rdis) {
				answer.push_back('R');
				right = keypad[numbers[i]];
			}
			else {
				if (hand == "right") {
					answer.push_back('R');
					right = keypad[numbers[i]];

				}
				else {
					answer.push_back('L');
					left = keypad[numbers[i]];
				}
			}

		}
	}
	return answer;
}