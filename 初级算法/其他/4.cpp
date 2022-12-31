class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>v;
		for (int i = 0; i < numRows; i++)
		{
			vector<int>tmp;
			for (int j = 0; j <= i; j++)
			{
				if (i == j || j == 0)
					tmp.push_back(1);
				else
					tmp.push_back(v[i - 1][j] + v[i - 1][j - 1]);
			}
			v.push_back(tmp);
		}
		return v;
	}
};