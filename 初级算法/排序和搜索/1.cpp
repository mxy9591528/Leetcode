//先合并再排序
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; i++)
			nums1[m + i] = nums2[i];
		sort(nums1.begin(), nums1.end());
	}
};

//顺序双指针
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p1 = 0, p2 = 0;
		vector<int>res(m + n);
		int cur;
		while (p1 < m || p2 < n)
		{
			if (p1 == m)
				cur = nums2[p2++];
			else if (p2 == n)
				cur = nums1[p1++];
			else if (nums1[p1] < nums2[p2])
				cur = nums1[p1++];
			else
				cur = nums2[p2++];
			res[p1 + p2 - 1] = cur;
		}
		nums1 = res;
	}
};

//逆向双指针
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p1 = m - 1, p2 = n - 1, tail = m + n;
		vector<int>res(tail);
		int cur;
		while (p1 >= 0 || p2 >= 0)
		{
			if (p1 == -1)
				cur = nums2[p2--];
			else if (p2 == -1)
				cur = nums1[p1--];
			else if (nums1[p1] > nums2[p2])
				cur = nums1[p1--];
			else
				cur = nums2[p2--];
			res[--tail] = cur;
		}
		nums1 = res;
	}
};