//STL
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		return unique(nums.begin(), nums.end()) - nums.begin();
	}
};
//Ë«Ö¸Õë
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int p = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (!i || nums[i] != nums[i - 1])
				nums[p++] = nums[i];
		}
		return p;
	}
};