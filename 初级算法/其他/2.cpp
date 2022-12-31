class Solution {
public:
	int hammingDistance(int x, int y) {
		return __builtin_popcount(x ^ y);//统计二进制上1的个数
	}
};

class Solution {
public:
	int hammingDistance(int x, int y) {
		int ret = x ^ y, cnt = 0;
		while (ret)
		{
			cnt += ret & 1;
			ret >>= 1;
		}
		return cnt;
	}
};

//优化
class Solution {
public:
	int hammingDistance(int x, int y) {
		int ret = x ^ y, cnt = 0;
		while (ret)
		{
			cnt++;
			ret &= ret - 1;
		}
		return cnt;
	}
};