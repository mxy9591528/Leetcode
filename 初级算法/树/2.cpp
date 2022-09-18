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
//µÝ¹é
class Solution {
public:
	bool recursion(TreeNode*root, long long max, long long min)
	{
		if (!root)
			return true;
		if (root->val <= min || root->val >= max)
			return false;
		return recursion(root->left, root->val, min) && recursion(root->right, max, root->val);
	}
	bool isValidBST(TreeNode* root) {
		return recursion(root, LONG_MAX, LONG_MIN);
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
//ÖÐÐò±éÀú+µÝ¹é
class Solution {
public:
	long long pre = LONG_MAX;
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		if (!isValidBST(root->right))
			return false;
		if (root->val >= pre)
			return false;
		pre = root->val;
		return isValidBST(root->left);
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
//ÖÐÐò±éÀú·ÇµÝ¹é
class Solution {
public:
	long long pre = LONG_MIN;
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		stack<TreeNode*>s;
		while (!s.empty() || root)
		{
			while (root)
			{
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			if (root->val <= pre)
				return false;
			pre = root->val;
			root = root->right;
		}
		return true;
	}
};