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
	int post_index;
	unordered_map<int, int>m;
public:
	TreeNode*dfs(int l, int r, vector<int>&inorder, vector<int>&postorder)
	{
		if (l > r)
			return NULL;
		int root_val = postorder[post_index];
		TreeNode*root = new TreeNode(root_val);
		post_index--;
		int index = m[root->val];
		root->right = dfs(index + 1, r, inorder, postorder);
		root->left = dfs(l, index - 1, inorder, postorder);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		post_index = postorder.size() - 1;
		int index = 0;
		for (auto&val : inorder)
			m[val] = index++;
		return dfs(0, inorder.size() - 1, inorder, postorder);
	}

};