//µÝ¹é
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)
			return "1";
		string res = "", s = countAndSay(n - 1);
		int cnt = 1;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != s[i + 1])
			{
				res += (cnt + '0');
				res += s[i];
				cnt = 1;
			}
			else
				cnt++;
		}
		return res;
	}
};

//·ÇµÝ¹é
class Solution {
public:
	string countAndSay(int n) {
		string res = "1";
		for (int i = 2; i <= n; i++)
		{
			int start = 0, pos = 0;
			string cur = "";
			while (pos < res.size())
			{
				while (pos < res.size() && res[pos] == res[start])
					pos++;
				cur += to_string(pos - start) + res[start];
				start = pos;
			}
			res = cur;
		}
		return res;
	}
};