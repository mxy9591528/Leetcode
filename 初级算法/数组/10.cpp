//Ïàµ±ÓÚ¹þÏ£ÅÐ¶Ï
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int>v(9, 0);
		vector<vector<int>>row(9, v), col(9, v);
		vector<vector<vector<int>>>subbox(3, row);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				char c = board[i][j];
				if (c != '.')
				{
					int index = c - '0' - 1;
					row[i][index]++;
					col[j][index]++;
					subbox[i / 3][j / 3][index]++;
					if (row[i][index] > 1 || col[j][index] > 1 || subbox[i / 3][j / 3][index] > 1)
						return false;
				}
			}
		}
		return true;
	}
};