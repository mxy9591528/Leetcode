class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int cnt = 0, res = 0;
		for (auto&val : nums)
		{
			if (val == 1)
				cnt++;
			else
			{
				res = max(res, cnt);
				cnt = 0;
			}
		}
		return max(res, cnt);
	}
};