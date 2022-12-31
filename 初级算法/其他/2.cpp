class Solution {
public:
	int hammingDistance(int x, int y) {
		return __builtin_popcount(x ^ y);//ͳ�ƶ�������1�ĸ���
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

//�Ż�
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