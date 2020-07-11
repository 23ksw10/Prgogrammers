#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
	int ans = 0;
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] && i&&j) board[i][j] += min({ board[i - 1][j], board[i][j - 1], board[i - 1][j - 1] });
			ans =max(board[i][j],ans);

		}
	return ans*ans;

}