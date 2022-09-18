/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//╤сап
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root)
			return {};
		vector<vector<int>>v;
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			vector<int>tmp;
			while (size--)
			{
				TreeNode*node = q.front();
				q.pop();
				tmp.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			v.push_back(tmp);
		}
		return v;
	}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//DFS
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>res;
		dfs(res, 1, root);
		return res;
	}
	void dfs(vector<vector<int>>&v, int depth, TreeNode*root)
	{
		if (!root)
			return;
		if (v.size() < depth)
			v.push_back({});
		v[depth - 1].push_back(root->val);
		dfs(v, depth + 1, root->left);
		dfs(v, depth + 1, root->right);
	}
};