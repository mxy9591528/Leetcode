//动态规划
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2)
			return s;
		int end = 1, begin = 0;
		vector<vector<bool>>dp(n, vector<bool>(n, true));
		for (int l = 2; l <= n; l++)
		{
			for (int i = 0; i < n; i++)
			{
				int j = l + i - 1;
				if (j >= n)
					break;
				if (s[i] != s[j])
					dp[i][j] = false;
				else
				{
					if (j - i < 3)
						dp[i][j] = true;
					else
						dp[i][j] = dp[i + 1][j - 1];
				}
				if (dp[i][j] && j - i + 1 > end)
				{
					end = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, end);
	}
};

//中心扩展法
class Solution {
public:
	pair<int, int>extendAroundCenter(string&s, int l, int r)
	{
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			l--;
			r++;
		}
		return { l + 1,r - 1 };
	}
	string longestPalindrome(string s) {
		int begin = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			auto[l1, r1] = extendAroundCenter(s, i, i);
			auto[l2, r2] = extendAroundCenter(s, i, i + 1);
			if (r1 - l1 > end - begin)
			{
				begin = l1;
				end = r1;
			}
			if (r2 - l2 > end - begin)
			{
				begin = l2;
				end = r2;
			}
		}
		return s.substr(begin, end - begin + 1);
	}
};

