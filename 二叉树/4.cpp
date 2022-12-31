class Solution {
public:
	TreeNode* res;
	bool dfs(TreeNode* root, int p, int q) {
		if (root == nullptr) return false;
		bool l = dfs(root->left, p, q), r = dfs(root->right, p, q);
		if ((l && r) || ((root->val == p || root->val == q) && (l || r)))
			res = root;
		return l || r || (root->val == p || root->val == q);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		dfs(root, p->val, q->val);
		return res;
	}
};
