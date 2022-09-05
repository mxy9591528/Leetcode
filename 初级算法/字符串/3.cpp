//哈希表计次数
class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int>m;
		for (int i = 0; i < s.length(); i++)
			m[s[i]]++;
		for (int i = 0; i < s.length(); i++)
			if (m[s[i]] == 1)
				return i;
		return -1;
	}
};

//哈希映射
class Solution {
public:
	int firstUniqChar(string s) {
		int n = s.length();
		unordered_map<char, int>m;
		for (int i = 0; i < n; i++)
		{
			if (m.count(s[i]))
				m[s[i]] = -1;
			else
				m[s[i]] = i;
		}
		int first = n;
		for (auto[_, pos] : m)//取哈希键值对
		{
			if (pos != -1 && pos < first)
				first = pos;
		}
		if (first == n)
			first = -1;
		return first;
	}
};

//队列
class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int>m;
		queue<pair<char, int>>q;
		for (int i = 0; i < s.size(); i++)
		{
			if (m.count(s[i]))
			{
				m[s[i]] = -1;
				while (!q.empty() && m[q.front().first] == -1)
				{
					q.pop();
				}
			}
			else
			{
				m[s[i]] = i;
				q.emplace(s[i], i);
			}
		}
		return q.empty() ? -1 : q.front().second;
	}
};