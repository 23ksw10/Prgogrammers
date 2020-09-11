#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string>v;
void help(int n, int start, string tmp) {
	for (int i = start; i < n; i++) {
		tmp.push_back('0' + i);
		v.push_back(tmp);
		help(n, i + 1, tmp);
		tmp.pop_back();
	}
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int n = relation[0].size();
	help(n, 0, "");


	set<vector<int>>make;
	set<int>not_make;
	sort(v.begin(), v.end(), [](const string&a, const string&b) {return a.size() < b.size(); });
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	for (int k = 0; k < v.size(); k++) {
		vector<int>tmp;
		unordered_map<string, int>m;
		bool check = true;
		for (int c = 0; c < v[k].size(); c++) {
			tmp.push_back(v[k][c] - '0');
		}
		bool is_happen = false;
		for (auto it = make.begin(); it != make.end(); it++) {
			vector<int>check_list = *it;
			int same = 0;
			for (int i = 0; i < check_list.size(); i++) {

				for (int j = 0; j < tmp.size(); j++) {
					if (check_list[i] == tmp[j])same++;
					if (same == check_list.size()) {
						is_happen = true;
						break;
					}
				}
				if (is_happen)break;

			}
			if (is_happen)break;
		}
		if (is_happen)continue;
		for (int i = 0; i < relation.size(); i++) {
			string pr;
			for (int j = 0; j < tmp.size(); j++) {
				pr += relation[i][tmp[j]];
			}
			m[pr]++;
			if (m[pr] > 1) {
				check = false;
				break;
			}
		}
		if (check) {
			vector<int>list;
			for (auto t : tmp) {
				list.push_back(t);
			}
			make.insert(list);
			answer++;
		}

	}
	return answer;
}