//动态规划
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int>dp(n, 0);
		int res = dp[0] = nums[0];
		for (int i = 1; i < n; i++)
		{
			dp[i] = max(nums[i], dp[i - 1] + nums[i]);
			res = max(res, dp[i]);
		}
		return res;
	}
};

//分治
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (!n)
			return 0;
		return maxsubarrlength(nums, 0, n - 1);
	}
	int maxsubarrlength(vector<int>&nums, int l, int r)
	{
		if (l == r)
			return nums[l];
		int mid = l + (r - l) / 2;
		return maxfor3(maxCrossingSum(nums, l, mid, r), maxsubarrlength(nums, l, mid), maxsubarrlength(nums, mid + 1, r));
	}
	int maxCrossingSum(vector<int>&nums, int l, int m, int r)
	{
		int sum = 0, leftsum = -0x3f3f3f3f;
		for (int i = m; i >= l; i--)
		{
			sum += nums[i];
			if (sum > leftsum)
				leftsum = sum;
		}
		sum = 0;
		int rightsum = -0x3f3f3f3f;
		for (int i = m + 1; i <= r; i++)
		{
			sum += nums[i];
			if (sum > rightsum)
				rightsum = sum;
		}
		return leftsum + rightsum;
	}
	int maxfor3(int num1, int num2, int num3)
	{
		return max(num1, max(num2, num3));
	}
};