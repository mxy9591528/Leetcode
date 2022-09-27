//辅助数组
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<vector<int>>res(n, vector<int>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				res[j][n - i - 1] = matrix[i][j];
		}
		matrix = res;
	}
};

//对角翻转，上下翻转
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
				swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
		}
		for (int i = 0; i < (n + 1) / 2; i++)
		{
			for (int j = 0; j < n; j++)
				swap(matrix[i][j], matrix[n - i - 1][j]);
		}
	}
};

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < (n + 1) / 2; j++)
			{
				int ret = matrix[i][j];
				matrix[i][j] = matrix[n - j - 1][i];
				matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
				matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
				matrix[j][n - i - 1] = ret;
			}
		}
	}
};