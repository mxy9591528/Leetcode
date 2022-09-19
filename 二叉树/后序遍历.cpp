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
	vector<int>res;
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (root)
		{
			postorderTraversal(root->left);
			postorderTraversal(root->right);
			res.push_back(root->val);
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
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int>res;
		if (!root)
			return res;
		stack<TreeNode*>s;
		TreeNode*prev = NULL;
		while (!s.empty() || root)
		{
			while (root)
			{
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			if (!root->right || root->right == prev)
			{
				res.emplace_back(root->val);
				prev = root;
				root = NULL;
			}
			else
			{
				s.push(root);
				root = root->right;
			}
		}
		return res;
	}
};


class Solution {
public:
	void addPath(vector<int> &vec, TreeNode *node) {
		int count = 0;
		while (node)
		{
			++count;
			vec.emplace_back(node->val);
			node = node->right;
		}
		reverse(vec.end() - count, vec.end());
	}
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		if (!root)
			return res;
		TreeNode *p1 = root, *p2 = nullptr;

		while (p1)
		{
			p2 = p1->left;
			if (p2)
			{
				while (p2->right && p2->right != p1) {
					p2 = p2->right;
				}
				if (!p2->right)
				{
					p2->right = p1;
					p1 = p1->left;
					continue;
				}
				else
				{
					p2->right = nullptr;
					addPath(res, p1->left);
				}
			}
			p1 = p1->right;
		}
		addPath(res, root);
		return res;
	}
};