#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	vector<char>skill_seq;
	set<char>s;
	for (int i = 0; i < skill.size(); i++) {
		skill_seq.push_back(skill[i]);
		s.insert(skill[i]);
	}
	for (int i = 0; i < skill_trees.size(); i++) {
		int locate = 0;
		bool check = false;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			if (s.find(skill_trees[i][j]) != s.end()) {
				if (skill_trees[i][j] == skill_seq[locate]) {
					locate++;
					check = true;
				}
				else {
					check = false;
					break;
				}

			}
			else
				check = true;

		}
		if (check)answer++;
	}
	return answer;
}