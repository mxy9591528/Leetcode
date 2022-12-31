//��������
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		vector<int>v(len);
		for (int i = 0; i < len; i++)
			v[(i + k) % len] = nums[i];
		nums.assign(v.begin(), v.end());
	}
};

//������ת��
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();//ע��k�Ĵ�С
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.size() - 1);
	}
	void reverse(vector<int>&v, int l, int r)
	{
		while (l < r)
			swap(v[l++], v[r--]);
	}
};

//��״�滻
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k %= len;
		int cnt = gcd(len, k);
		for (int i = 0; i < cnt; i++)
		{
			int cur = i, pre = nums[i];
			do {
				int next = (cur + k) % len;//��һ����λ��
				swap(nums[next], pre);
				cur = next;
			} while (i != cur);
		}
	}
};