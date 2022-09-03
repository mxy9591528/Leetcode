//��̬�滮��
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		int dp[len][2];
		dp[0][0] = 0;//�����޹�Ʊʣ���Ǯ
		dp[0][1] = -prices[0];//�����ֳֹ�Ʊʣ���Ǯ
		for (int i = 1; i < len; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return max(dp[len - 1][0], dp[len - 1][1]);
	}
};

//�򻯶�̬�滮
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		int dp1 = 0, dp2 = -prices[0];//�ñ�����������
		for (int i = 1; i < len; i++)
		{
			int newdp1 = max(dp1, dp2 + prices[i]);
			int newdp2 = max(dp2, dp1 - prices[i]);
			dp1 = newdp1, dp2 = newdp2;//����
		}
		return max(dp1, dp2);
	}
};

//̰���㷨
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sum = 0, len = prices.size();
		for (int i = 1; i < len; i++)
			sum += max(0, prices[i] - prices[i - 1]);//����Ľ��ǽ������ʾ���˹���
		return sum;
	}
};