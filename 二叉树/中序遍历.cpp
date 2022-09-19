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
	vector<int> inorderTraversal(TreeNode* root) {
		if (root)
		{
			inorderTraversal(root->left);
			res.push_back(root->val);
			inorderTraversal(root->right);
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>res;
		if (!root)
			return res;
		stack<TreeNode*>s;
		while (!s.empty() || root)
		{
			while (root)
			{
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			res.emplace_back(root->val);
			root = root->right;
		}
		return res;
	}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode *predecessor = nullptr;

		while (root)
		{
			if (root->left) {
				// predecessor �ڵ���ǵ�ǰ root �ڵ�������һ����Ȼ��һֱ���������޷���Ϊֹ
				predecessor = root->left;
				while (predecessor->right  && predecessor->right != root) {
					predecessor = predecessor->right;
				}
				// �� predecessor ����ָ��ָ�� root����������������
				if (!predecessor->right)
				{
					predecessor->right = root;
					root = root->left;
				}
				// ˵���������Ѿ��������ˣ�������Ҫ�Ͽ�����
				else {
					res.push_back(root->val);
					predecessor->right = nullptr;
					root = root->right;
				}
			}
			// ���û�����ӣ���ֱ�ӷ����Һ���
			else {
				res.push_back(root->val);
				root = root->right;
			}
		}
		return res;
	}
};