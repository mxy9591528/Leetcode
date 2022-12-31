/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//istringstream��
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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//����
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		rserialize(root, res);
		return res;
	}
	void rserialize(TreeNode*node, string&s)
	{
		if (!node)
			s += "#,";
		else
		{
			s += to_string(node->val) + ",";
			rserialize(node->left, s);
			rserialize(node->right, s);
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		list<string>datalist;
		string tmp;
		for (auto&val : data)
		{
			if (val == ',')
			{
				datalist.emplace_back(tmp);
				tmp.clear();
			}
			else
				tmp += val;
		}
		if (!tmp.empty())
			datalist.emplace_back(tmp);
		return rdeserialize(datalist);
	}
	TreeNode*rdeserialize(list<string>&l)
	{
		if (l.front() == "#")
		{
			l.erase(l.begin());
			return NULL;
		}
		auto root = new TreeNode(stoi(l.front()));
		l.erase(l.begin());
		root->left = rdeserialize(l);
		root->right = rdeserialize(l);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

//���ű�ʾ���� + �ݹ��½�����
class Codec {
public:
	string serialize(TreeNode* root) {
		if (!root)
			return "X";
		auto left = "(" + serialize(root->left) + ")";
		auto right = "(" + serialize(root->right) + ")";
		return left + to_string(root->val) + right;
	}
	inline TreeNode* parseSubtree(const string &data, int &ptr) {
		++ptr; // ����������
		auto subtree = parse(data, ptr);
		++ptr; // ����������
		return subtree;
	}
	inline int parseInt(const string &data, int &ptr) {
		int x = 0, sgn = 1;
		if (!isdigit(data[ptr])) {
			sgn = -1;
			++ptr;
		}
		while (isdigit(data[ptr]))
			x = x * 10 + data[ptr++] - '0';
		return x * sgn;
	}
	TreeNode* parse(const string &data, int &ptr) {
		if (data[ptr] == 'X') {
			++ptr;
			return nullptr;
		}
		auto cur = new TreeNode();
		cur->left = parseSubtree(data, ptr);
		cur->val = parseInt(data, ptr);
		cur->right = parseSubtree(data, ptr);
		return cur;
	}
	TreeNode* deserialize(string data) {
		int ptr = 0;
		return parse(data, ptr);
	}
};