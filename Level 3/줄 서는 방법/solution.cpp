#include <vector>
#include <algorithm>
using namespace std;
int factorial(int n) {
	if (n == 1)return 1;
	else return n * factorial(n - 1);


}
vector<int> solution(int n, long long k) {
	vector<int> answer;
	int size = k;
	vector<int>v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	while (n) {
		if (n == 0) break;
		int i = (k - 1) / (factorial(n) / n);
		answer.push_back(v[i]);
		v.erase(v.begin() + i);
		k = k % (factorial(n) / n);
		n--;
		if (k == 0)k = factorial(n) / n;
	}


	return answer;
}