#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int ans = 0;
	int size = w * 2 + 1;
	if (n == 0)return 0;
	vector<pair<int, int>>v;
	for (auto &a : stations) {
		if (v.size() == 0) v.push_back({ max(a - w,1),min(a + w,n) });
		else {
			if (v[v.size() - 1].second >= a - w)v[v.size() - 1].second = min(a + w, n);
			else v.push_back({ max(a - w,1),min(a + w,n) });
		}
	}
	if (v.size() == 0) {
		if (n%size == 0)return n / size;
		else return n / size + 1;
	}
	int first = v[0].first - 1;
	if (first != 0) {
		if (first%size != 0)ans += first / size + 1;
		else ans += first / size;
	}
	for (int i = 1; i < v.size(); i++) {
		int len = v[i].first - v[i - 1].second - 1;
		if (len != 0) {
			if (len%size != 0)ans += len / size + 1;
			else ans += len / size;
		}
	}
	int last = n - v[v.size() - 1].second;
	if (last != 0) {
		if (last%size != 0)ans += last / size + 1;
		else ans += last / size;
	}
	return ans;
}