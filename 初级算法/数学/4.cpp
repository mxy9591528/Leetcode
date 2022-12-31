class Solution {
public:
    unordered_map<char,int>m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int romanToInt(string s) {
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            int value=m[s[i]];
            if(i+1<s.size()&&value<m[s[i+1]])
                res-=value;
            else
                res+=value;
        }
        return res;
    }
};