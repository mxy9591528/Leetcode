class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return nums[0];
		vector<int>dp(n, 0);
		dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n; i++)
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		return dp[n - 1];
	}
};

//¿Õ¼äÓÅ»¯
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return nums[0];
		int dp1 = nums[0], dp2 = max(nums[0], nums[1]);
		for (int i = 2; i < n; i++)
		{
			int tmp = dp2;
			dp2 = max(dp2, nums[i] + dp1);
			dp1 = tmp;
		}
		return dp2;
	}
};