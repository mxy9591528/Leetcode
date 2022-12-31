//杨辉三角
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>res;
		for (int i = 0; i < numRows; i++)
		{
			vector<int>tmp;
			for (int j = 0; j <= i; j++)
			{
				if (!j || i == j)
					tmp.emplace_back(1);
				else
					tmp.emplace_back(res[i - 1][j] + res[i - 1][j - 1]);
			}
			res.push_back(tmp);
		}
		return res;
	}
};

//单独求某一行
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int>res(rowIndex + 1, 1);
		for (int i = 1; i < rowIndex; i++)
			for (int j = i; j > 0; j--)
				res[j] += res[j - 1];
		return res;
	}
};

//对称求解
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans(rowIndex + 1, 0);
		long cur = 1;
		for (int i = 0; i <= rowIndex / 2; ++i) {
			ans[i]=ans[rowIndex - i] = cur;
			cur = cur * (rowIndex - i) / (i + 1);
		}
		return ans;
	}
};

