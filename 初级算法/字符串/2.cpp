//�Լ����뷨
class Solution {
public:
	int reverse(int x) {
		vector<int>v;
		while (x)
		{
			v.push_back(x % 10);
			x /= 10;
		}
		long res = 0;//��long�ݴ�
		for (int i = 0; i < v.size(); i++)
		{
			res = res * 10 + v[i];
			if (res > INT_MAX || res < INT_MIN)//ע�⼫С�뼫��
				return 0;
		}
		return res;
	}
};

//�ٷ����
class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while (x != 0) {
			if (res < INT_MIN / 10 || res > INT_MAX / 10) {//�ø���ʮ�жϷ�����
				return 0;
			}
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};
