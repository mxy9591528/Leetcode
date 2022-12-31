class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int>dp(n, 0);
		int minprices = prices[0];
		for (int i = 1; i < n; i++)
		{
			minprices = min(minprices, prices[i]);
			dp[i] = max(dp[i - 1], prices[i] - minprices);
		}
		return dp[n - 1];
	}
};