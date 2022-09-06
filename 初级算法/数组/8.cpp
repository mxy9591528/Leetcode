//双指针，二次遍历
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int len = nums.size();
		if (len == 1)
			return;
		int slow = 0, fast = 0;
		while (fast < len)
		{
			if (nums[fast] != 0)
				nums[slow++] = nums[fast];
			fast++;
		}
		for (int i = slow; i < len; i++)
			nums[i] = 0;
	}
};

//一次遍历
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