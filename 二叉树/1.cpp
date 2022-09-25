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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (!postorder.size())
			return NULL;
		auto root = new TreeNode(postorder[postorder.size() - 1]);
		stack<TreeNode*>s;
		s.push(root);
		int inorder_index = inorder.size() - 1;
		for (int i = postorder.size() - 2; i >= 0; i--)
		{
			auto post_val = postorder[i];
			auto node = s.top();
			if (node->val != inorder[inorder_index])
			{
				node->right = new TreeNode(post_val);
				s.push(node->right);
			}
			else
			{
				while (!s.empty() && s.top()->val == inorder[inorder_index])
				{
					node = s.top();
					s.pop();
					inorder_index--;
				}
				node->left = new TreeNode(post_val);
				s.push(node->left);
			}
		}
		return root;
	}
};