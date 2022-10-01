//暴力超时
class Solution {
public:
	const int inf = 0x3f3f3f3f;
	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		if (!n)
			return 0;
		int res = inf;
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = i; j < n; j++)
			{
				sum += nums[j];
				if (sum >= target)
					res = min(res, j - i + 1);
			}
		}
		return res == inf ? 0 : res;
	}
};

//前缀和+二分
class Solution {
public:
	const int inf = 0x3f3f3f3f;
	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		if (!n)
			return 0;
		int res = inf;
		vector<int>sums(n + 1, 0);
		for (int i = 1; i <= n; i++)
			sums[i] = sums[i - 1] + nums[i - 1];
		for (int i = 1; i <= n; i++)
		{
			int tmp = target + sums[i - 1];
			auto bound = lower_bound(sums.begin(), sums.end(), tmp);
			if (bound != sums.end())
				res = min(res, static_cast<int>(bound - sums.begin()) - i + 1);
		}
		return res == inf ? 0 : res;
	}
};

//滑动窗口
class Solution {
public:
	const int inf = 0x3f3f3f3f;
	int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		if (!n)
			return 0;
		int res = inf, start = 0, end = 0, sum = 0;
		while (end < n)
		{
			sum += nums[end];
			while (sum >= target)
			{
				res = min(res, end - start + 1);
				sum -= nums[start++];
			}
			end++;
		}
		return res == inf ? 0 : res;
	}
};