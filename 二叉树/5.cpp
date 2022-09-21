/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root)
			return "#";
		return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
	}
	TreeNode*mydeserialize(istringstream&s)
	{
		string tmp;
		s >> tmp;
		if (tmp == "#")
			return NULL;
		TreeNode*node = new TreeNode(stoi(tmp));
		node->left = mydeserialize(s);
		node->right = mydeserialize(s);
		return node;
	}
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream s(data);
		return mydeserialize(s);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));