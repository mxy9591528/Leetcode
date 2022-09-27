class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int suml = 0, sum = accumulate(nums.begin(), nums.end(), 0), len = nums.size();
		for (int i = 0; i < len; i++)
		{
			if (sum - nums[i] == 2 * suml)
				return i;
			suml += nums[i];
		}
		return -1;
	}
};