//使用辅助数组
class Solution {
public:
	void clear(vector<vector<int>>& matrix, int x, int y)
	{
		for (int i = 0; i < matrix.size(); i++)
			matrix[i][y] = 0;
		for (int i = 0; i < matrix[0].size(); i++)
			matrix[x][i] = 0;
	}
	void setZeroes(vector<vector<int>>& matrix) {
		vector<vector<int>>coor;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
				if (!matrix[i][j])
					coor.push_back({ i,j });
		}
		for (int i = 0; i < coor.size(); i++)
			clear(matrix, coor[i][0], coor[i][1]);
	}
};

//一个变量标记
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		bool flag = false;
		for (int i = 0; i < m; i++)
		{
			if (!matrix[i][0])
				flag = true;
			for (int j = 1; j < n; j++)
				if (!matrix[i][j])
					matrix[i][0] = matrix[0][j] = 0;
		}
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = 1; j < n; j++)
			{
				if (!matrix[i][0] || !matrix[0][j])
					matrix[i][j] = 0;
			}
			if (flag)
				matrix[i][0] = 0;
		}
	}
};