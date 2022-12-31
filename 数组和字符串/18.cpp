//istringstream流
class Solution {
public:
	string reverseWords(string s) {
		istringstream ss(s);
		string tmp, res;
		while (ss >> tmp)
		{
			reverse(tmp.begin(), tmp.end());
			res += tmp + " ";
		}
		return string(res.begin(), res.end() - 1);
	}
};

//辅助数组
class Solution {
public:
	string reverseWords(string s) {
		int len = s.size();
		int i = 0;
		string res;
		while (i < len)
		{
			int start = i;
			while (i < len&&s[i] != ' ')
				i++;
			for (int p = start; p < i; p++)
				res += s[i + start - p - 1];
			while (i < len&&s[i] == ' ')
				i++;
			res += ' ';
		}
		return string(res.begin(), res.end() - 1);
	}
};

//原地翻转
class Solution {
public:
	string reverseWords(string s) {
		int len = s.size();
		int i = 0;
		while (i < len)
		{
			int start = i;
			while (i < len&&s[i] != ' ')
				i++;
			reverse(s.begin() + start, s.begin() + i);
			while (i < len&&s[i] == ' ')
				i++;
		}
		return s;
	}
};
//swap交换
class Solution {
public:
	string reverseWords(string s) {
		int len = s.size();
		int i = 0;
		while (i < len)
		{
			int start = i;
			while (i < len&&s[i] != ' ')
				i++;
			int l = start, r = i - 1;
			while (l < r)
				swap(s[l++], s[r--]);
			while (i < len&&s[i] == ' ')
				i++;
		}
		return s;
	}
};