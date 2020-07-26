#include <string>
#include <vector>
#include <set>



using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	multiset<int>s;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'I') {
			answer.push_back(stoi(operations[i].substr(2)));
			s.insert(stoi(operations[i].substr(2)));
		}
		else {
			if (s.empty())continue;

			if (stoi(operations[i].substr(2)) == -1) {
				for (int i = 0; i < answer.size(); i++) {
					if (answer[i] == *s.begin()) {
						auto it = answer.begin();
						answer.erase(it + i);
						s.erase(s.begin());
						break;
					}
				}
			}
			else {
				for (int i = 0; i < answer.size(); i++) {
					if (answer[i] == *s.rbegin()) {
						auto it = answer.begin();
						answer.erase(it + i);
						s.erase(*s.rbegin());
						break;
					}
				}
			}

		}
	}
	if (answer.empty())answer = { 0,0 };
	else {
		answer = {};
		answer.push_back(*s.rbegin());
		answer.push_back(*s.begin());
	}
	return answer;
}