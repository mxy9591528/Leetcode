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
//BFS
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>res;
		if (!root)
			return res;
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			res.push_back({});
			for (int i = 0; i < size; i++)
			{
				auto node = q.front();
				q.pop();
				res.back().emplace_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
		return res;
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
//dfs
class Solution {
public:
	void dfs(vector<vector<int>>&v, TreeNode*root, int depth)
	{
		if (root)
		{
			if (v.size() < depth)
				v.push_back({});
			v[depth - 1].emplace_back(root->val);
			dfs(v, root->left, depth + 1);
			dfs(v, root->right, depth + 1);
		}
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>res;
		dfs(res, root, 1);
		return res;
	}
};