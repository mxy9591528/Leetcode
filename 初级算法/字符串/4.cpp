//����
class Solution {
public:
	bool isAnagram(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if (s == t)
			return true;
		return false;
	}
};

//��ϣ��
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		vector<int>table(26, 0);//�ַ���ͳ�Ƹ���
		for (int i = 0; i < s.size(); i++)
			table[s[i] - 'a']++;
		for (int i = 0; i < t.size(); i++)
		{
			table[t[i] - 'a']--;
			if (table[t[i] - 'a'] < 0)
				return false;
		}
		return true;
	}
};