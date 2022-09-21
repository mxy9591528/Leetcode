//常规
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n == 1)
			return true;
		if (n % 3 != 0)
			return false;
		for (int i = 1;; i *= 3)
		{
			if (i == n)
				return true;
			if (i > n)
				break;
		}
		return false;
	}
};

//优化
class Solution {
public:
	bool isPowerOfThree(int n) {
		while (n&&n % 3 == 0)
		{
			n /= 3;
		}
		return n == 1;
	}
};

class Solution {
public:
	bool isPowerOfThree(int n) {
		return n > 0 && (int)pow(3, 19) % n == 0;//数据范围内三的最高次幂数
	}
};