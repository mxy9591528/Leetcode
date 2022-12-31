//使用辅助数组
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int len = matrix.size();
		auto newmatrix = matrix;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
				newmatrix[j][len - i - 1] = matrix[i][j];//规律
		}
		matrix = newmatrix;
	}
};

//原地旋转数组，顺时针
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int len = matrix.size();
		for (int i = 0; i < len / 2; i++)
		{
			for (int j = 0; j < (len + 1) / 2; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[len - j - 1][i];
				matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
				matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
				matrix[j][len - i - 1] = temp;
			}
		}
	}
};

//两次翻转法
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int len = matrix.size();
		for (int i = 0; i < len / 2; i++)//先上下翻转
		{
			for (int j = 0; j < len; j++)
				swap(matrix[i][j], matrix[len - i - 1][j]);
		}
		for (int i = 0; i < len; i++)//再主对角翻转
		{
			for (int j = 0; j <= i; j++)
				swap(matrix[i][j], matrix[j][i]);
		}
	}
};