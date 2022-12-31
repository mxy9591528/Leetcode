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
//µ›πÈ
class Solution {
public:
	bool check(TreeNode*t1, TreeNode*t2)
	{
		if (!t1 && !t2)
			return true;
		if (!t1 || !t2)
			return false;
		return t1->val == t2->val&&check(t1->left, t2->right) && check(t1->right, t2->left);
	}
	bool isSymmetric(TreeNode* root) {
		return check(root, root);
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
//∂”¡–
class Solution {
public:
	bool check(TreeNode*t1, TreeNode*t2)
	{
		queue<TreeNode*>q;
		q.push(t1), q.push(t2);
		while (!q.empty())
		{
			t1 = q.front(), q.pop();
			t2 = q.front(), q.pop();
			if (!t1 && !t2)
				continue;
			if (!t1 || !t2 || t1->val != t2->val)
				return false;
			q.push(t1->left);
			q.push(t2->right);
			q.push(t1->right);
			q.push(t2->left);
		}
		return true;
	}
	bool isSymmetric(TreeNode* root) {
		return check(root, root);
	}
};
