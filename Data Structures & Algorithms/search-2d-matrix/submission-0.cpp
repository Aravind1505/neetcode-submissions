class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size(), m;
        int x, y;

        while (l < r) {
            m = (l + r) / 2;

            x = m / matrix[0].size();
            y = m % matrix[0].size();

            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] > target) r = m;
            else l = m + 1;
        }

        return false;
    }
};
