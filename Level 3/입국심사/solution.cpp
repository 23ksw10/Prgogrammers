#include <string>
#include <vector>
#include <algorithm>


using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long right = 0;
	for (int i = 0; i < times.size(); i++) {
		right = max((long long)times[i], right);
	}
	right *= n;
	long long left = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long people = 0;
		for (int i = 0; i < times.size(); i++) {
			people += mid / times[i];
		}
		if (people < n)left = mid + 1;
		else right = mid - 1;

	}
	return left;
}