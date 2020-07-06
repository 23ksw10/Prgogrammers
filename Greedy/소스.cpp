#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	char max = '0';
	int locate;
	for (int i = 0; i <= k; i++) {
		if (number[i] > max) {
			max = number[i];
			locate = i;
		}
	}
	answer.push_back(max);
	k = k - locate;
	string number1 = number;
	while (k) {
		string s = number1.substr(locate + 1, number.size());
		if (s.size() == k)break;
		char max = '0';
		for (int i = 0; i <= k; i++) {
			if (s[i] > max) {
				max = s[i];
				locate = i;
			}
		}
		answer.push_back(max);
		number1 = s;
		k = k - locate;
		if (!k) {
			if (locate + 1 <= s.size())answer += s.substr(locate + 1, number.size());
		}


	}
	return answer;
}