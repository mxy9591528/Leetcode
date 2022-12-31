class Solution {
public:
	int BF(string s, string t)//朴素算法
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
	vector<int>getnext(string t)
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
	int KMP(string s, string t, vector<int>next)//KMP
	{
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
	static const int maxNum = 1005;
	int shift[maxNum];//偏移表
	int Sunday(string s, string t) //Sunday算法
	{
		int lens = s.size(), lent = t.size();
		// 默认值，移动m+1位
		for (int i = 0; i < maxNum; i++)
			shift[i] = lent + 1;
		// 模式串t中每个字母出现的最后的下标
		// 所对应的主串参与匹配的最末位字符的下一位字符移动到该位，所需要的移动位数
		for (int i = 0; i < lent; i++)
			shift[t[i]] = lent - i;
		// 模式串开始位置在主串的哪里
		int index = 0;
		// 模式串已经匹配到的位置
		int j;
		while (index <= lens - lent) {
			j = 0;
			while (s[index + j] == t[j]) {
				j++;
				// 匹配成功
				if (j >= lent) {
					return index;
				}
			}
			// 找到主串中当前跟模式串匹配的最末字符的下一个字符
			// 在模式串中出现最后的位置
			// 所需要从(模式串末尾+1)移动到该位置的步数
			index += shift[s[index + lent]];
		}
		return -1;
	}
	int strStr(string haystack, string needle) {
		if (needle == "")
			return 0;
		//return BF(haystack,needle);
		//return KMP(haystack,needle,getnext(needle));
		return Sunday(haystack, needle);
	}
};

class Solution {
public:
	int BM(string s, string t)//BM算法
	{
		int lens = s.size(), lent = t.size();//模式串的长度
		if (lens > lent)
			return -1;
		vector<int>bad_table = build_bad_table(s), good_table = build_good_table(s);
		for (int i = lens - 1, j; i < lent;) {
			for (j = lens - 1; t[i] == s[j]; i--, j--) {
				if (j == 0)
					return i;
			}
			i += max(good_table[lens - j - 1], bad_table[t[i]]);
		}
		return -1;
	}
	//字符信息表
	vector<int> build_bad_table(string s) {
		int table_size = 256, lens = s.size();
		vector<int> bad_table(table_size, lens);//创建一个数组，用来记录坏字符出现时，应该跳过的字符数
		for (int i = 0; i < lens - 1; i++) {
			int k = s[i];//记录下当前的字符ASCII码值
			bad_table[k] = lens - 1 - i;
		}
		return bad_table;
	}
	//匹配偏移表
	vector<int>build_good_table(string s) {
		int lens = s.size();//模式串长度
		vector<int>good_table(lens);//创建一个数组，存好后缀数值
		int lastPrefixPosition = lens;
		for (int i = lens - 1; i >= 0; --i) {
			if (isPrefix(s, i + 1))
				lastPrefixPosition = i + 1;
			good_table[lens - 1 - i] = lastPrefixPosition - i + lens - 1;
		}
		for (int i = 0; i < lens - 1; ++i) {
			//计算出指定位置匹配的后缀的字符串长度
			int len = suffixLength(s, i);
			good_table[len] = lens - 1 - i + len;
		}
		return good_table;
	}
	//前缀匹配
	bool isPrefix(string s, int pos) {
		int lens = s.size();
		for (int i = pos, j = 0; i < lens; ++i, ++j) {
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
	//后缀匹配
	int suffixLength(string s, int pos) {
		int lens = s.size();
		int len = 0;
		for (int i = pos, j = lens - 1; i >= 0 && s[i] == s[j]; i--, j--)
			len += 1;
		return len;
	}
	int strStr(string haystack, string needle) {
		if (!needle.size())
			return 0;
		return BM(needle, haystack);
	}
};

class Solution {
public:
	int Horspool(string t, string s)//BM算法简化
	{
		int lent = t.size();
		int lens = s.size();
		vector<int> table(96, lens);//以字母表中可打印字符为索引的数组
		for (int i = 0; i < lens - 1; i++)
			table[s[i] - 32] = lens - 1 - i;
		int i = lens - 1;
		while (i <= lent - 1)
		{
			int k = 0;
			while (k <= lens - 1 && s[lens - 1 - k] == t[i - k])
				k++;

			if (k == lens)
				return i - lens + 1;//匹配成功，返回索引
			else
				i += table[t[i] - 32];//模式串向右移动
		}

		return -1;//匹配失败
	}
	int strStr(string haystack, string needle) {
		if (!needle.size())
			return 0;
		return Horspool(haystack, needle);
	}
};