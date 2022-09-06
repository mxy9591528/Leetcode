//¹şÏ£±í
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int>m;
		vector<int>res;
		for (auto i : nums1)
		{
			if (m.find(i) == m.end())
				m[i] = 1;
			else
				m[i]++;
		}
		for (auto i : nums2)
		{
			if (m.find(i) != m.end() && m[i] > 0)
			{
				m[i]--;
				res.push_back(i);
			}
		}
		return res;
	}
};

//ÅÅĞò+Ë«Ö¸Õë
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		vector<int>res;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int index1 = 0, index2 = 0;
		while (index1 < len1&&index2 < len2)
		{
			if (nums1[index1] > nums2[index2])
				index2++;
			else if (nums1[index1] < nums2[index2])
				index1++;
			else { res.push_back(nums1[index1]); index1++, index2++; }
		}
		return res;
	}
};