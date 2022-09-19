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
	bool dfs(TreeNode*node, int val)
	{
		if (node)
		{
			val -= node->val;
			if (!val && !node->left && !node->right)
				return true;
			return dfs(node->left, val) || dfs(node->right, val);
		}
		return false;
	}
	bool hasPathSum(TreeNode* root, int targetSum) {
		return dfs(root, targetSum);
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
class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root)
			return false;
		queue<TreeNode*>q;
		queue<int>val;
		q.push(root);
		val.push(root->val);
		while (!q.empty())
		{
			auto node = q.front();
			auto tmp = val.front();
			q.pop();
			val.pop();
			if (!node->left && !node->right)
			{
				if (tmp == targetSum)
					return true;
				continue;
			}
			if (node->left)
			{
				q.push(node->left);
				val.push(tmp + node->left->val);
			}
			if (node->right)
			{
				q.push(node->right);
				val.push(tmp + node->right->val);
			}
		}
		return false;
	}
};