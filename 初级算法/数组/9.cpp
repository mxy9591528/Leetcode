//Ë«²ãÑ­»·ÕÒÆ¥ÅäÖµ
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		vector<int>res;
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (nums[i] + nums[j] == target)
					return vector<int>({ i,j });
			}
		}
		return {};
	}
};

//¹şÏ£±í
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		unordered_map<int, int>m;
		for (int i = 0; i < len; i++)
		{
			auto it = m.find(target - nums[i]);
			if (it != m.end())
				return { it->second,i };
			m[nums[i]] = i;
		}
		return {};
	}
};