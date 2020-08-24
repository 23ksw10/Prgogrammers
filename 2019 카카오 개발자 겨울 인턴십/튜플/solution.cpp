#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<int> solution(string s) {
	string tmp = s.substr(1, s.size() - 2);
	vector<vector<int>>v;
	unordered_set<int>set;
	vector<int> answer;
	vector<int>a;
	bool b = false;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '{') {
			string tmp1 = tmp.substr(i + 1);
			int k = stoi(tmp1);
			a.push_back(k);
			b = true;
		}
		if (tmp[i] == ','&&b) {
			string tmp1 = tmp.substr(i + 1);
			int k = stoi(tmp1);
			a.push_back(k);
		}
		if (tmp[i] == '}') {
			v.push_back(a);
			a = {};
			b = false;
		}
	}
	sort(v.begin(), v.end(), [](const vector<int>&a, const vector<int>&b) {return a.size() < b.size(); });
	for (auto i : v) {
		for (auto j : i) {
			if (set.find(j) == set.end()) {
				answer.push_back(j);
				set.insert(j);
			}
		}
	}

	return answer;
}