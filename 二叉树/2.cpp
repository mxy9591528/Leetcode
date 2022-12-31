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
	int pre_index;
	unordered_map<int, int>m;
public:
	TreeNode*dfs(int l, int r, vector<int>&preorder, vector<int>&inorder)
	{
		if (l > r)
			return NULL;
		int val = preorder[pre_index];
		pre_index++;
		TreeNode*root = new TreeNode(val);
		int index = m[val];
		root->left = dfs(l, index - 1, preorder, inorder);
		root->right = dfs(index + 1, r, preorder, inorder);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		pre_index = 0;
		int index = 0;
		for (auto&val : inorder)
			m[val] = index++;
		return dfs(0, inorder.size() - 1, preorder, inorder);
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (!preorder.size())
			return NULL;
		auto root = new TreeNode(preorder[0]);
		stack<TreeNode*>s;
		int inorder_index = 0;
		s.push(root);
		for (int i = 1; i < preorder.size(); i++)
		{
			auto pre_val = preorder[i];
			auto node = s.top();
			if (node->val != inorder[inorder_index])
			{
				node->left = new TreeNode(pre_val);
				s.push(node->left);
			}
			else
			{
				while (!s.empty() && s.top()->val == inorder[inorder_index])
				{
					node = s.top();
					s.pop();
					inorder_index++;
				}
				node->right = new TreeNode(pre_val);
				s.push(node->right);
			}
		}
		return root;
	}
};