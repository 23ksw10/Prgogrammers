#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include<iostream>


using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	vector<pair<int, int>>p;
	unordered_set<string>s(gems.begin(), gems.end());
	unordered_map<string, int>m;

	int start = 0;
	int end = 0;
	for (end; end < gems.size(); end++) {

		m[gems[end]]++;
		bool b = false;
		if (m.size() == s.size()) b = true;
		if (b) {
			while (b) {
				m[gems[start++]]--;
				for (auto a : m) {
					if (a.second < 1) {
						b = false;
						break;

					};
				}
			}
			if (end - start == 0) return{ start,end + 1 };
			if (!p.size())p.push_back({ start,end });
			else {
				if (p[0].second - p[0].first > end - start) {
					p.clear();
					p.push_back({ start,end });
				}
			}

		}
	}
	answer = { p[0].first,p[0].second + 1 };
	return answer;
}