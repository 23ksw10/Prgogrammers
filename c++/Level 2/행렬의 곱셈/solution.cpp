#include <string>
#include <vector>


using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	for (int i = 0; i < arr1.size(); i++) {
		vector<int> v;
		int mul=0;
		for (int k = 0; k < arr2[0].size(); k++) {
			for (int j = 0; j < arr1[0].size(); j++) {
				mul += arr1[i][j] * arr2[j][k];
			}
			v.push_back(mul);
			mul = 0;
		}
		answer.push_back(v);
	}
	return answer;
}