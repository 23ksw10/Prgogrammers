#include <vector>
#include<queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<vector<bool>>b(m, vector<bool>(n, false));
	queue<pair<int, int>>q;
	vector<int>area;


	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	for (int i = 0; i < picture.size(); i++) {
		for (int j = 0; j < picture[i].size(); j++) {
			if (picture[i][j] && !b[i][j]) {
				q.push({ i,j });
				b[i][j] = true;
				int size_area = 1;
				while (!q.empty()) {
					int size = q.size();
					for (int i = 0; i < size; i++) {
						auto it = q.front();
						q.pop();
						auto l = make_pair(it.first, max(it.second - 1, 0));
						auto r = make_pair(it.first, min(it.second + 1, n - 1));
						auto u = make_pair(max(it.first - 1, 0), it.second);
						auto d = make_pair(min(it.first + 1, m - 1), it.second);
						if (!b[l.first][l.second] && picture[l.first][l.second] == picture[it.first][it.second]) {
							b[l.first][l.second] = true;
							q.push(l);
							size_area++;
						}
						if (!b[r.first][r.second] && picture[r.first][r.second] == picture[it.first][it.second]) {
							b[r.first][r.second] = true;
							q.push(r);
							size_area++;
						}
						if (!b[u.first][u.second] && picture[u.first][u.second] == picture[it.first][it.second]) {
							b[u.first][u.second] = true;
							q.push(u);
							size_area++;
						}
						if (!b[d.first][d.second] && picture[d.first][d.second] == picture[it.first][it.second]) {
							b[d.first][d.second] = true;
							q.push(d);
							size_area++;
						}
					}
				}
				area.push_back(size_area);



			}
		}
	}
	sort(area.begin(), area.end());
	answer[0] = area.size();
	answer[1] = area[area.size() - 1];
	return answer;
}
