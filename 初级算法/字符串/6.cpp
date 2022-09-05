//常规思路
class Solution {
public:
	int myAtoi(string s) {
		int res = 0;
		bool flag = true;
		int index = 0;
		int len = s.size();
		while (index < len&& s[index] == ' ')
			++index;
		if (index < len&&s[index] == '-')
		{
			flag = false;
			index++;
		}
		if (index < len&&s[index] == '+')
		{
			if (flag)
				index++;
			else
				return 0;
		}
		while (index < len && isdigit(s[index]))
		{
			int num = s[index] - '0';
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > INT_MAX % 10))//注意要模10
			{
				return flag ? INT_MAX : INT_MIN;
			}
			res = res * 10 + num;
			index++;
		}
		return flag ? res : -res;
	}
};

//自动机(不会)
class Automaton {
	string state = "start";
	unordered_map<string, vector<string>> table = {
		{"start", {"start", "signed", "in_number", "end"}},
		{"signed", {"end", "end", "in_number", "end"}},
		{"in_number", {"end", "end", "in_number", "end"}},
		{"end", {"end", "end", "end", "end"}}
	};

	int get_col(char c) {
		if (isspace(c)) return 0;
		if (c == '+' or c == '-') return 1;
		if (isdigit(c)) return 2;
		return 3;
	}
public:
	int sign = 1;
	long long ans = 0;

	void get(char c) {
		state = table[state][get_col(c)];
		if (state == "in_number") {
			ans = ans * 10 + c - '0';
			ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
		}
		else if (state == "signed")
			sign = c == '+' ? 1 : -1;
	}
};

class Solution {
public:
	int myAtoi(string str) {
		Automaton automaton;
		for (char c : str)
			automaton.get(c);
		return automaton.sign * automaton.ans;
	}
};

//流输入(取巧)
class Solution {
public:
	int myAtoi(string s) {
		stringstream in(s);
		int n = 0;
		in >> n;
		return n;
	}
};