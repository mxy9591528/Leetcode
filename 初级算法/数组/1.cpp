//双指针解法
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		int slow = 1, fast = 1;
		while (fast < len)
		{
			if (nums[fast] != nums[fast - 1])
				nums[slow++] = nums[fast];
			fast++;
		}
		return slow;
	}
};

//简化双指针
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		int ptr = 0;
		for (int i = 0; i < len; i++)
		{
			if (i == 0 || nums[i] != nums[i - 1])
				nums[ptr++] = nums[i];
		}
		return ptr;
	}
};