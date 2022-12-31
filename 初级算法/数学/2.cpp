//±©Á¦
class Solution {
public:
	bool isPrime(int x) {
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}

	int countPrimes(int n) {
		int ans = 0;
		for (int i = 2; i < n; ++i) {
			ans += isPrime(i);
		}
		return ans;
	}
};
//ÊÔ³ý
class Solution {
public:
	bool isprime(int n)
	{
		for (int i = 2; i <= n / i; i++)
		{
			if (n%i == 0)
				return false;
		}
		return true;
	}
	int countPrimes(int n) {
		int cnt = 0;
		for (int i = 2; i < n; i++)
		{
			if (isprime(i))
				cnt++;
		}
		return cnt;
	}
};

//°£ÊÏÉ¸
class Solution {
public:
	int countPrimes(int n) {
		int cnt = 0;
		vector<int>prime(n, 1);
		for (int i = 2; i < n; i++) {
			if (prime[i])
				cnt++;
			if ((long long)i*i < n)
			{
				for (int j = i * i; j < n; j += i)
					prime[j] = 0;
			}
		}
		return cnt;
	}
};

//ÏßÐÔÉ¸
class Solution {
public:
	int countPrimes(int n) {
		vector<int>prime;
		vector<int>isprime(n, 1);
		for (int i = 2; i < n; i++)
		{
			if (isprime[i])
				prime.push_back(i);
			for (int j = 0; j < prime.size() && i*prime[j] < n; j++)
				isprime[i*prime[j]] = 0;
		}
		return prime.size();
	}
};

//Å·À­É¸
class Solution {
public:
	int countPrimes(int n) {
		vector<int>isprime(n + 1, 1);
		int cnt = 0;
		for (int i = 2; i < n; i++)
		{
			if (isprime[i])
			{
				cnt++;
				for (int j = i; j <= n / i; j++)
					isprime[i*j] = 0;
			}
		}
		return cnt;
	}
};