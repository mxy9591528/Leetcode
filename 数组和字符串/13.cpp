//¶þ·Ö
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		for (int i = 0; i < numbers.size(); i++)
		{
			int l = i + 1, r = numbers.size() - 1;
			while (l <= r)
			{
				int mid = l + ((r - l) >> 1);
				if (numbers[mid] == target - numbers[i])
					return { i + 1,mid + 1 };
				else if (numbers[mid] < target - numbers[i])
					l = mid + 1;
				else
					r = mid - 1;
			}
		}
		return { -1,-1 };
	}
};

//Ë«Ö¸Õë
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int l = 0, r = numbers.size() - 1;
		while (l <= r)
		{
			int sum = numbers[l] + numbers[r];
			if (sum == target)
				return { l + 1,r + 1 };
			else if (sum < target)
				l++;
			else
				r--;
		}
		return { -1,-1 };
	}
};