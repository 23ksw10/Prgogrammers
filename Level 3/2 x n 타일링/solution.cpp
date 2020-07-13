#include <string>
#include <vector>

using namespace std;

vector<int>check(60000, 0);


int solution(int n) {
	int answer = 0;
	check[1] = 1;
	check[2] = 2;
	if (check[n]) {
		return check[n];
	}
	check[n] = (solution(n - 1) + solution(n - 2)) % 1000000007;
	return check[n];
}