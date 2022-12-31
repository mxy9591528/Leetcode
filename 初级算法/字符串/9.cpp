//横向扫描比较
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int cnt = strs.size();
		if (!cnt)
			return "";
		string prefix = strs[0];
		for (int i = 1; i < cnt; i++)
		{
			prefix = getcommonfix(prefix, strs[i]);
			if (!prefix.size())
				break;
		}
		return prefix;
	}
	string getcommonfix(const string&s1, const string&s2)
	{
		int len = min(s1.size(), s2.size()), index = 0;
		while (index < len&&s1[index] == s2[index])
			index++;
		return s1.substr(0, index);
	}
};

//纵向扫描
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int cnt = strs.size();
		if (!cnt)
			return "";
		for (int i = 0; i < strs[0].size(); i++)
		{
			char c = strs[0][i];
			for (int j = 1; j < cnt; j++)
			{
				if (strs[j].size() == i || strs[j][i] != c)
					return strs[0].substr(0, i);
			}
		}
		return strs[0]; 
	}
};

//分治法
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size())
			return "";
		return dividePrefix(strs, 0, strs.size() - 1);
	}
	string dividePrefix(const vector<string>&s, int l, int r)
	{
		if (l == r)
			return s[l];
		int mid = (l + r) / 2;
		string left = dividePrefix(s, l, mid), right = dividePrefix(s, mid + 1, r);
		return getprefix(left, right);
	}
	string getprefix(const string&s1, const string&s2)
	{
		int len = min(s1.size(), s2.size()), index = 0;
		while (index < len&&s1[index] == s2[index])
			index++;
		return s1.substr(0, index);
	}
};

//二分法
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size())
			return "";
		//仿函数直接写法
		int minlen = min_element(strs.begin(), strs.end(), [](const string&s1, const string&s2) {return s1.size() < s2.size(); })->size();
		int low = 0, high = minlen;
		while (low < high)
		{
			int mid = (high - low + 1) / 2 + low;
			if (isprefix(strs, mid))
				low = mid;
			else
				high = mid - 1;
		}
		return strs[0].substr(0, low);
	}
	bool isprefix(const vector<string>&s, int len)
	{
		string str0 = s[0].substr(0, len);
		int cnt = s.size();
		for (int i = 1; i < cnt; i++)
		{
			string str1 = s[i];
			for (int j = 0; j < len; j++)
				if (str0[j] != str1[j])
					return false;
		}
		return true;
	}
};

//排序法
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