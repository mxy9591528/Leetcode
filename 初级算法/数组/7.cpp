//�ҵ�˼·
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
//����㷨
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		for (int i = len - 1; i >= 0; i--)
		{
			digits[i]++;
			digits[i] %= 10;
			if (digits[i] != 0)//����λ�ͷ��أ���֮ѭ����һλ+1
				return digits;
		}
		vector<int>res(len + 1);//���н�λ����������
		res[0] = 1;
		return res;
	}
};