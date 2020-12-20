#include <string>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;


int solution(vector<int> food_times, long long k) {
	int answer = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	long long total = 0;
	for (int i = 0; i < food_times.size(); i++) {
		q.push(make_pair(food_times[i], i + 1));
		total += food_times[i];
	}
	if (total <= k)return -1;
	long long sum = 0;

	while ((long long)(q.top().first - sum)*q.size() <= k) {
		k -= (long long)(q.top().first - sum)*q.size();


		sum = q.top().first;
		q.pop();


	}
	int n = q.size();
	vector<pair<int, int>>v;
	while (!q.empty()) {
		v.push_back({ q.top().second,q.top().first });
		q.pop();
	}
	sort(v.begin(), v.end());
	return v[k%n].first;
}