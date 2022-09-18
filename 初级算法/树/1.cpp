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
//�ݹ飬DFS
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		return max(maxDepth(root->right), maxDepth(root->left)) + 1;
	}
};

//BFS
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
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		queue<TreeNode*>q;
		q.push(root);
		int depth = 0;
		while (!q.empty())
		{
			int size = q.size();
			depth++;
			for (int i = 0; i < size; i++)
			{
				TreeNode*tmp = q.front();
				if (tmp->left)
					q.push(tmp->left);
				if (tmp->right)
					q.push(tmp->right);
				q.pop();
			}
		}
		return depth;
	}
};