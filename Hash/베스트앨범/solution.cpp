#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	unordered_map<string, int>m;
	vector<tuple<string, int, int>>a;
	for (int i = 0; i < genres.size(); i++) {
		m[genres[i]] += plays[i];
		a.push_back(make_tuple(genres[i], plays[i], i));
	}
	vector<pair<string, int>>pv(m.begin(), m.end());
	sort(pv.begin(), pv.end(), [](const pair<string, int>&a, const pair<string, int>&b) {return a.second > b.second; });
	sort(a.begin(), a.end(), [](const tuple<string, int, int>&a, const tuple<string, int, int> &b) {return get<1>(a) > get<1>(b); });
	for (int i = 0; i < pv.size(); i++) {
		int check = 0;
		for (int j = 0; j < a.size(); j++) {
			if (check == 2)break;
			if (pv[i].first == get<0>(a[j])) {
				answer.push_back(get<2>(a[j]));
				check++;
			}
		}
	}
	return answer;
}