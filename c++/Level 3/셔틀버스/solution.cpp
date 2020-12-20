#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	vector<int>bus_time;
	for (int i = 0; i < n; i++) {
		bus_time.push_back(540 + t * i);
	}
	vector<int>c_time;
	for (int i = 0; i < timetable.size(); i++) {
		int tmp = 0;
		string hour = timetable[i].substr(0, 2);
		string minute = timetable[i].substr(3);
		tmp += stoi(hour) * 60;
		tmp += stoi(minute);
		c_time.push_back(tmp);
	}
	sort(c_time.begin(), c_time.end());
	int k = 0;
	map<int, int>mp;
	map<int, int>mp_max;
	int total = 0;
	for (int i = 0; i < bus_time.size(); i++) {
		int count = 0;
		while (c_time[k] <= bus_time[i] && k < c_time.size()) {
			if (count == m)break;
			mp[bus_time[i]]++;
			mp_max[bus_time[i]] = c_time[k];
			k++;
			count++;
			total++;
		}
	}

	auto it = mp_max.rbegin();
	if (mp_max.size() == 0) {
		int tmp = bus_time[bus_time.size() - 1];
		string ans = "";
		if (to_string(tmp / 60).size() == 1)ans += '0' + to_string(tmp / 60);
		else ans += to_string(tmp / 60);
		ans += ':';
		if (to_string(tmp % 60).size() == 1)ans += '0' + to_string(tmp % 60);
		else ans += to_string(tmp % 60);
		return ans;
	}
	int tmp = it->second - 1;
	cout << tmp;
	if (mp[it->first] < m || mp.find(bus_time[bus_time.size() - 1]) == mp.end()) tmp = bus_time[bus_time.size() - 1];
	string ans = "";
	if (to_string(tmp / 60).size() == 1)ans += '0' + to_string(tmp / 60);
	else ans += to_string(tmp / 60);
	ans += ':';
	if (to_string(tmp % 60).size() == 1)ans += '0' + to_string(tmp % 60);
	else ans += to_string(tmp % 60);
	return ans;

	return answer;
} ans;
}