class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < board.size(); i++) {
            set<char> rowcheck;
            set<char> columncheck;
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.' && rowcheck.contains(board[i][j])) {
                    cout << "Entered here row" << endl;
                    return false;
                }
                rowcheck.insert(board[i][j]);

                if (board[j][i] != '.' && columncheck.contains(board[j][i])) {
                    cout << "Entered here column" << endl;
                    return false;
                }
                columncheck.insert(board[j][i]);
            }

            rowcheck.clear();
            columncheck.clear();
        }

        int ctr = 0, ctr1 = 0;

        while (ctr <= 2) {
            while (ctr1 <= 2) {
                set<char> boxcheck;
                for (int i = ctr * 3; i < ctr * 3 + 3; i++) {
                    for (int j = ctr1 * 3; j < ctr1 * 3 + 3; j++) {
                        if (board[i][j] != '.' && boxcheck.contains(board[i][j])) {
                            cout << "Entered here box" << endl;
                            return false;
                        }
                        boxcheck.insert(board[i][j]);
                    }
                }
                boxcheck.clear();
                ctr1++;
            }
            ctr++;
        }

        return true;

    }
};
