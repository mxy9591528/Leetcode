//Ë«Ö¸Õë
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int p = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i])
				nums[p++] = nums[i];
		}
		for (int i = p; i < nums.size(); i++)
			nums[i] = 0;
	}
};

//ÓÅ»¯
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int len = nums.size(), slow = 0, fast = 0;
		while (fast < len)
		{
			if (nums[fast])
				swap(nums[slow++], nums[fast]);
			fast++;
		}
	}
};