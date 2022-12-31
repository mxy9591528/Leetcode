//我的思路
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		digits[len - 1] += 1;
		int ret = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			digits[i] += ret;
			if (digits[i] > 9)
			{
				ret = digits[i] / 10;
				digits[i] %= 10;
			}
			else
				ret = 0;
		}
		if (ret)
		{
			vector<int>v;
			v.push_back(ret);
			for (auto i : digits)
				v.push_back(i);
			return v;
		}
		else
			return digits;
	}
};
//简洁算法
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		for (int i = len - 1; i >= 0; i--)
		{
			digits[i]++;
			digits[i] %= 10;
			if (digits[i] != 0)//不进位就返回，反之循环下一位+1
				return digits;
		}
		vector<int>res(len + 1);//还有进位，扩充数组
		res[0] = 1;
		return res;
	}
};