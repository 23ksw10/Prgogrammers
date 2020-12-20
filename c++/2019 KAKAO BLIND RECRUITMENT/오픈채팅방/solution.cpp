#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string>m;
	vector<vector<string>>tmp;
	for (int i = 0; i < record.size(); i++) {
		int start = 6;
		if (record[i][0] == 'L')continue;
		if (record[i][0] == 'C')start = 7;
		string id;
		int k;
		for (int j = start; j < record[i].size(); j++) {
			if (record[i][j] == ' ') {
				k = j + 1;
				break;
			}
			id += record[i][j];
		}
		string name;
		for (k; k < record[i].size(); k++) {
			name += record[i][k];
		}
		m[id] = name;
	}
	for (int i = 0; i < record.size(); i++) {
		string end = "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
		if (record[i][0] == 'L')end = "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
		if (record[i][0] == 'C')continue;
		string id;
		for (int j = 6; j < record[i].size(); j++) {
			if (record[i][j] == ' ') {
				break;
			}
			id += record[i][j];
		}
		string final = m[id] + end;
		answer.push_back(final);

	}
	return answer;
}