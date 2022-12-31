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
	vector<int>res;
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (root)
		{
			res.push_back(root->val);
			preorderTraversal(root->left);
			preorderTraversal(root->right);
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
//µü´ú
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>res;
		if (!root)
			return res;
		stack<TreeNode*>s;
		while (!s.empty() || root)
		{
			while (root)
			{
				s.push(root);
				res.emplace_back(root->val);
				root = root->left;
			}
			root = s.top();
			s.pop();
			root = root->right;
		}
		return res;
	}
};

//Morris±éÀú
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		if (!root)
			return res;
		TreeNode *p1 = root, *p2 = nullptr;
		while (p1)
		{
			p2 = p1->left;
			if (p2)
			{
				while (p2->right  && p2->right != p1) {
					p2 = p2->right;
				}
				if (!p2->right) {
					res.emplace_back(p1->val);
					p2->right = p1;
					p1 = p1->left;
					continue;
				}
				else
					p2->right = nullptr;
			}
			else
				res.emplace_back(p1->val);
			p1 = p1->right;
		}
		return res;
	}
};