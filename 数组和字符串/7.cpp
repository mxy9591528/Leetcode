//我的方法，横向遍历
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 1)
			return strs[0];
		string res = "";
		int maxprefix = 0x3f3f3f3f;
		for (int i = 0; i < strs.size() - 1; i++)
			maxprefix = min(maxprefix, prefix(strs[i], strs[i + 1]));
		res.assign(strs[0].begin(), strs[0].begin() + maxprefix);
		return res;
	}
	int prefix(string&s1, string&s2)
	{
		int len = 0;
		for (int i = 0; i < min(s1.size(), s2.size()); i++)
		{
			if (s1[i] == s2[i])
				len++;
			else
				break;
		}
		return len;
	}
};

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = strs[0];
		for (int i = 1; i < strs.size(); i++)
			res = prefix(res, strs[i]);
		return res;
	}
	string prefix(string&s1, string&s2)
	{
		string tmp = "";
		for (int i = 0; i < min(s1.size(), s2.size()); i++)
		{
			if (s1[i] == s2[i])
				tmp += s1[i];
			else
				break;
		}
		return tmp;
	}
};

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size())
			return "";
		sort(strs.begin(), strs.end());
		string begin = strs.front(), end = strs.back();
		int len = min(begin.size(), end.size()), i;
		for (i = 0; i < len; i++)
		{
			if (begin[i] != end[i])
				break;
		}
		return strs[0].substr(0, i);
	}
};

//纵向遍历
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size() || strs.size() == 1)
			return strs[0];
		char c;
		for (int i = 0; i < strs[0].size(); i++)
		{
			c = strs[0][i];
			for (int j = 1; j < strs.size(); j++)
				if (i == strs[j].size() || c != strs[j][i])
					return strs[0].substr(0, i);
		}
		return strs[0];
	}
};