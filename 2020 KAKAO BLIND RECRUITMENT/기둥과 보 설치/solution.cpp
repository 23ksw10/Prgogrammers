#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include<set>
using namespace std;


set<vector<int>>s;
bool check() {
	for (auto it = s.begin(); it != s.end(); it++) {
		vector<int>b = *it;
		if (!b[2]) {
			if (!b[1] || s.find({ b[0],b[1] - 1,0 }) != s.end() || s.find({ b[0] - 1,b[1],1 }) != s.end() || s.find({ b[0],b[1],1 }) != s.end()) {
				continue;
			}
			return false;
		}
		else {
			if (s.find({ b[0],b[1] - 1,0 }) != s.end() || s.find({ b[0] + 1,b[1] - 1,0 }) != s.end() || (s.find({ b[0] - 1,b[1],1 }) != s.end() && s.find({ b[0] + 1,b[1],1 }) != s.end())) {
				continue;
			}
			return false;

		}
	}
	return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (auto b : build_frame) {
		if (b[3] == 1) {

			s.insert({ b[0],b[1],b[2] });
			if (check())continue;
			s.erase({ b[0],b[1],b[2] });
		}
		else {
			if (s.find({ b[0],b[1],b[2] }) != s.end()) {
				s.erase({ b[0],b[1],b[2] });
				if (check())continue;
				s.insert({ b[0],b[1],b[2] });
			}
		}
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		answer.push_back(*it);
	}
	return answer;
}