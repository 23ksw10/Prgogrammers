#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

map<vector<int>, int>m;
map<int, vector<int>>p;
TreeNode *ans = nullptr;
void help(TreeNode *&ans, vector<int>n) {
	if (!ans) ans = new TreeNode(m[n]);
	else {
		vector<int>q = p[ans->val];
		if (n[0] < q[0] && n[1] < q[1])help(ans->left, n);
		else help(ans->right, n);
	}
}
void preorder(TreeNode *ans, vector<int>&ans1) {
	if (!ans)return;
	if (ans) {
		ans1.push_back(ans->val);
	}
	preorder(ans->left, ans1);
	preorder(ans->right, ans1);
}
void postorder(TreeNode *ans, vector<int>&ans2) {
	if (!ans)return;
	postorder(ans->left, ans2);
	postorder(ans->right, ans2);
	ans2.push_back(ans->val);

}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	int i = 1;
	for (auto n : nodeinfo) {
		p[i] = n;
		m[n] = i;
		i++;
	}
	sort(nodeinfo.begin(), nodeinfo.end(), [](const vector<int>&a, const vector<int>&b) {return a[1] > b[1] || (a[1] == b[1] && a[0] < b[0]); });
	for (auto n : nodeinfo) {
		help(ans, n);
	}
	vector<int>ans1;
	preorder(ans, ans1);
	answer.push_back(ans1);
	vector<int>ans2;
	postorder(ans, ans2);
	answer.push_back(ans2);
	return answer;
}