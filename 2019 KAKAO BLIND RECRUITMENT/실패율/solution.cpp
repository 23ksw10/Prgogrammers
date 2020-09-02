#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include<iostream>
#include<map>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int total = stages.size();
	int people = 0;
	map<float, vector<int>>m;
	sort(stages.begin(), stages.end());
	int count = 0;
	for (int i = 0; i < stages.size(); i++) {
		if (stages[i] > N)continue;
		count++;
		if (stages[i] != stages[i + 1]) {
			cout << (float)count / (float)total << ' ';
			m[(float)count / (float)total].push_back(stages[i]);
			total -= count;
			count = 0;
		}
	}
	for (auto it = m.rbegin(); it != m.rend(); it++) {
		auto n = it->second;
		for (auto i : n)answer.push_back(i);


	}
	set<int>s(answer.begin(), answer.end());
	for (int i = 1; i <= N; i++) {
		if (s.find(i) == s.end())answer.push_back(i);
	}
	return answer;
}