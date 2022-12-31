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
	bool check(TreeNode*p1, TreeNode*p2)
	{
		if (p1 == p2)
			return true;
		if (!p1 || !p2)
			return false;
		return p1->val == p2->val&&check(p1->left, p2->right) && check(p1->right, p2->left);
	}
	bool isSymmetric(TreeNode* root) {
		return check(root->left, root->right);
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
	bool check(TreeNode*p1, TreeNode*p2)
	{
		queue<TreeNode*>q;
		q.push(p1);
		q.push(p2);
		while (!q.empty())
		{
			auto l = q.front();
			q.pop();
			auto r = q.front();
			q.pop();
			if (!l && !r)
				continue;
			if (!l || !r || l->val != r->val)
				return false;
			q.push(l->left);
			q.push(r->right);
			q.push(l->right);
			q.push(r->left);
		}
		return true;
	}
	bool isSymmetric(TreeNode* root) {
		return check(root->left, root->right);
	}
};