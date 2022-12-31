//BF∆”ÀÿÀ„∑®
class Solution {
public:
	int BF(string&s, string&t)
	{
		int i = 0, j = 0;
		while (s[i] && t[j])
		{
			if (s[i] == t[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
		if (t[j])
			return -1;
		else
			return i - j;
	}
	int strStr(string haystack, string needle) {
		return BF(haystack, needle);
	}
};

//KMPÀ„∑®
class Solution {
public:
	vector<int>getnext(string&t)
	{
		int len = t.size();
		vector<int>next(len, 0);
		for (int i = 1, j = 0; i < len; i++)
		{
			while (j > 0 && t[i] != t[j])
				j = next[j - 1];
			if (t[i] == t[j])
				j++;
			next[i] = j;
		}
		return next;
	}
	int KMP(string&s, string&t)
	{
		vector<int>next = getnext(t);
		int lens = s.size(), lent = t.size();
		for (int i = 0, j = 0; i < lens; i++)
		{
			while (j > 0 && s[i] != t[j])
				j = next[j - 1];
			if (s[i] == t[j])
				j++;
			if (j == lent)
				return i - lent + 1;
		}
		return -1;
	}
	int strStr(string haystack, string needle) {
		return KMP(haystack, needle);
	}
};