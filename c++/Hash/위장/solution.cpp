#include<iostream>
#include <string>
#include <vector>
#include <map>
#include<set>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, vector<string>>m;
	set<string> s;
	for (int i = 0; i < clothes.size(); i++) {
		s.insert(clothes[i][1]);

	
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		m[*it] = {};
	}
	for (int i = 0; i < clothes.size(); i++) {
		m[clothes[i][1]].push_back(clothes[i][0]);


	}
	for (auto it = m.begin(); it != m.end(); it++) {
		answer = answer * (it->second.size()+1);
	}
	answer -= 1;
	return answer;
}