//数学
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		return nums.size()*(1 + nums.size()) / 2 - accumulate(nums.begin(), nums.end(), 0);
	}
};
//排序
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != i)
				return i;
		return nums.size();
	}
};
//哈希
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		unordered_map<int, int>m;
		for (auto val : nums)
			m[val]++;
		for (int i = 0; i < nums.size(); i++)
		{
			if (!m.count(i))
				return i;
		}
		return nums.size();
	}
};
//位运算
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int res = 0;
		for (auto val : nums)
			res ^= val;
		for (int i = 0; i <= nums.size(); i++)
			res ^= i;
		return res;
	}
};