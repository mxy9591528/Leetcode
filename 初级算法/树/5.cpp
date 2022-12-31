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
	TreeNode*fun(vector<int>&v, int left, int right)
	{
		if (left > right)
			return NULL;
		int mid = (left + right) / 2;//中点左侧为基准
		TreeNode*root = new TreeNode(v[mid]);
		root->left = fun(v, left, mid - 1);
		root->right = fun(v, mid + 1, right);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return fun(nums, 0, nums.size() - 1);
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
	TreeNode*helper(vector<int>&v, int left, int right)
	{
		if (left > right)
			return NULL;
		int mid = (left + right + 1) / 2;//以中点右侧为基准
		TreeNode*root = new TreeNode(v[mid]);
		root->left = helper(v, left, mid - 1);
		root->right = helper(v, mid + 1, right);
		return root;
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
	TreeNode*helper(vector<int>&v, int left, int right)
	{
		if (left > right)
			return NULL;
		int mid = ((left + right + rand() % 2)) / 2;//随机中间两点为基准
		TreeNode*root = new TreeNode(v[mid]);
		root->left = helper(v, left, mid - 1);
		root->right = helper(v, mid + 1, right);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};