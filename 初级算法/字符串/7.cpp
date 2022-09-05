class Solution {
public:
	int BF(string s, string t)//�����㷨
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
	int shift[maxNum];//ƫ�Ʊ�
	int Sunday(string s, string t) //Sunday�㷨
	{
		int lens = s.size(), lent = t.size();
		// Ĭ��ֵ���ƶ�m+1λ
		for (int i = 0; i < maxNum; i++)
			shift[i] = lent + 1;
		// ģʽ��t��ÿ����ĸ���ֵ������±�
		// ����Ӧ����������ƥ�����ĩλ�ַ�����һλ�ַ��ƶ�����λ������Ҫ���ƶ�λ��
		for (int i = 0; i < lent; i++)
			shift[t[i]] = lent - i;
		// ģʽ����ʼλ��������������
		int index = 0;
		// ģʽ���Ѿ�ƥ�䵽��λ��
		int j;
		while (index <= lens - lent) {
			j = 0;
			while (s[index + j] == t[j]) {
				j++;
				// ƥ��ɹ�
				if (j >= lent) {
					return index;
				}
			}
			// �ҵ������е�ǰ��ģʽ��ƥ�����ĩ�ַ�����һ���ַ�
			// ��ģʽ���г�������λ��
			// ����Ҫ��(ģʽ��ĩβ+1)�ƶ�����λ�õĲ���
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
	int BM(string s, string t)//BM�㷨
	{
		int lens = s.size(), lent = t.size();//ģʽ���ĳ���
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
	//�ַ���Ϣ��
	vector<int> build_bad_table(string s) {
		int table_size = 256, lens = s.size();
		vector<int> bad_table(table_size, lens);//����һ�����飬������¼���ַ�����ʱ��Ӧ���������ַ���
		for (int i = 0; i < lens - 1; i++) {
			int k = s[i];//��¼�µ�ǰ���ַ�ASCII��ֵ
			bad_table[k] = lens - 1 - i;
		}
		return bad_table;
	}
	//ƥ��ƫ�Ʊ�
	vector<int>build_good_table(string s) {
		int lens = s.size();//ģʽ������
		vector<int>good_table(lens);//����һ�����飬��ú�׺��ֵ
		int lastPrefixPosition = lens;
		for (int i = lens - 1; i >= 0; --i) {
			if (isPrefix(s, i + 1))
				lastPrefixPosition = i + 1;
			good_table[lens - 1 - i] = lastPrefixPosition - i + lens - 1;
		}
		for (int i = 0; i < lens - 1; ++i) {
			//�����ָ��λ��ƥ��ĺ�׺���ַ�������
			int len = suffixLength(s, i);
			good_table[len] = lens - 1 - i + len;
		}
		return good_table;
	}
	//ǰ׺ƥ��
	bool isPrefix(string s, int pos) {
		int lens = s.size();
		for (int i = pos, j = 0; i < lens; ++i, ++j) {
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
	//��׺ƥ��
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
	int Horspool(string t, string s)//BM�㷨��
	{
		int lent = t.size();
		int lens = s.size();
		vector<int> table(96, lens);//����ĸ���пɴ�ӡ�ַ�Ϊ����������
		for (int i = 0; i < lens - 1; i++)
			table[s[i] - 32] = lens - 1 - i;
		int i = lens - 1;
		while (i <= lent - 1)
		{
			int k = 0;
			while (k <= lens - 1 && s[lens - 1 - k] == t[i - k])
				k++;

			if (k == lens)
				return i - lens + 1;//ƥ��ɹ�����������
			else
				i += table[t[i] - 32];//ģʽ�������ƶ�
		}

		return -1;//ƥ��ʧ��
	}
	int strStr(string haystack, string needle) {
		if (!needle.size())
			return 0;
		return Horspool(haystack, needle);
	}
};