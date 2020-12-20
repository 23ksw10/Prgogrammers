#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int answer = 0;
void help(string s, int l, int r) {
	while (l >= 0 && r < s.size() && s[l] == s[r]) {
		answer = max(answer, r - l + 1);
		l--;
		r++;

	}
}

int solution(string s)
{

	int n = s.size();
	for (int i = 0; i < n; i++) {
		help(s, i, i);
		help(s, i, i + 1);
	}


	return answer;
}