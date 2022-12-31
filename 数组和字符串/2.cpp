class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (target < nums[0] || target == nums[0])
			return 0;
		else if (target > nums[nums.size() - 1])
			return nums.size();
		else if (target == nums[nums.size() - 1])
			return nums.size() - 1;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (target == nums[i])
				return i;
			else if (target > nums[i] && target < nums[i + 1])
				return i + 1;
		}
		return 0;
	}
};

//¶þ·Ö
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] > target)
				r--;
			else if (nums[mid] < target)
				l++;
			else
				return mid;
		}
		return l;
	}
};