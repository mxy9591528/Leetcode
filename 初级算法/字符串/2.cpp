//自己的想法
class Solution {
public:
	int reverse(int x) {
		vector<int>v;
		while (x)
		{
			v.push_back(x % 10);
			x /= 10;
		}
		long res = 0;//用long暂存
		for (int i = 0; i < v.size(); i++)
		{
			res = res * 10 + v[i];
			if (res > INT_MAX || res < INT_MIN)//注意极小与极大
				return 0;
		}
		return res;
	}
};

//官方解答
class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while (x != 0) {
			if (res < INT_MIN / 10 || res > INT_MAX / 10) {//用个除十判断防超限
				return 0;
			}
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};
