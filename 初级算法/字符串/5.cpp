//��ת�Ƚ�
class Solution {
public:
	bool isPalindrome(string s) {
		string res;
		for (auto i : s)
		{
			if (isalnum(i))
				res += tolower(i);
		}
		string rres(res.rbegin(), res.rend());
		return rres == res;
	}
};

//˫ָ���ж�
class Solution {
public:
	bool isPalindrome(string s) {
		string res;
		for (auto i : s)
		{
			if (isalnum(i))
				res += tolower(i);
		}
		for (int i = 0; i < res.size() / 2; i++)
		{
			if (res[i] != res[res.size() - i - 1])
				return false;
		}
		return true;
	}
};

//ջ
class Solution {
public:
	bool isPalindrome(string s) {
		stack<char>st;
		for (int i = 0; i < s.size(); i++)
		{
			if (isalnum(s[i]))
			{
				s[i] = tolower(s[i]);
				st.push(s[i]);
			}
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (isalnum(s[i]))
			{
				if (s[i] != st.top())
					return false;
				else
					st.pop();
			}
		}
		return true;
	}
};

//ԭ�����жϣ���ʹ�ö���ռ�
class Solution {
public:
	bool isPalindrome(string s) {
		int n = s.size();
		int l = 0, r = n - 1;
		while (l < r)
		{
			while (l < r && !isalnum(s[l]))
				l++;
			while (l < r && !isalnum(s[r]))
				r--;
			if (l < r)
			{
				if (tolower(s[l]) != tolower(s[r]))
					return false;
				l++;
				r--;
			}
		}
		return true;
	}
};