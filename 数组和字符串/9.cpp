//istringstream流
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string t,res;
        istringstream ss(s);
        while(ss>>t)
        {
            reverse(t.begin(),t.end());
            res+=t+" ";
        }
        return string(res.begin(),res.end()-1);
    }
};

//两字符串
class Solution {
public:
    string reverseWords(string s) {
        string s1,s2;
        for(int i=0;i<=s.size();i++)
        {
            if(s[i]!='\0'&&s[i]!=' ')
                s1.push_back(s[i]);
            else if(!s1.empty())
            {
                if(!s2.empty())
                    s2.insert(s2.begin(),' ');
                    s2.insert(0,s1);
                    s1.clear();
            }
        }
        return s2;
    }
};

//原地修改
class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		int n = s.size();
		int index = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != ' ')
			{
				if (index)
					s[index++] = ' ';
				int j = i;
				while (j < n&&s[j] != ' ')
					s[index++] = s[j++];
				reverse(s.begin() + index - (j - i), s.begin() + index);
				i = j;
			}
		}
		s.erase(s.begin() + index, s.end());
		return s;
	}
};

//双端队列
class Solution {
public:
	string reverseWords(string s) {
		int left = 0, right = s.size() - 1;
		// 去掉字符串开头的空白字符
		while (left <= right && s[left] == ' ') ++left;

		// 去掉字符串末尾的空白字符
		while (left <= right && s[right] == ' ') --right;

		deque<string> d;
		string word;

		while (left <= right) {
			char c = s[left];
			if (word.size() && c == ' ') {
				// 将单词 push 到队列的头部
				d.push_front(move(word));//move将左值转右值
				//左值是表达式结束后依然存在的持久对象(代表一个在内存中占有确定位置的对象)

				//右值是表达式结束时不再存在的临时对象(不在内存中占有确定位置的表达式）

				//便携方法：对表达式取地址，如果能，则为左值，否则为右值
				word = "";
			}
			else if (c != ' ')
				word += c;
			++left;
		}
		d.push_front(move(word));

		string ans;
		while (!d.empty()) {
			ans += d.front();
			d.pop_front();
			if (!d.empty()) ans += ' ';
		}
		return ans;
	}
};

