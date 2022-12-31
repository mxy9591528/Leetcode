//Ë«Ö¸Õë
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int p = 0;
		for (auto&n : nums)
			if (n^val)
				nums[p++] = n;
		return p;
	}
};

//STL
class Solution {
public:
	int removeElement(vector<int>& nums, int val)
	{
		return remove(nums.begin(), nums.end(), val) - nums.begin();
	}
};