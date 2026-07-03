class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) { return; }
        // printLand(board);

        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 'O') { scanOpenRegion(board, i, 0); }
            if (board[i][board[i].size()-1] == 'O')  { scanOpenRegion(board, i, board[i].size()-1); }
        }
        // printLand(board);
        for (int i = 0; i < board[0].size(); i++)
        {
            if (board[0][i] == 'O') { scanOpenRegion(board, 0, i); }
            if (board[board.size()-1][i] == 'O')  { scanOpenRegion(board, board.size()-1, i); }

        }
        // printLand(board);
#if 1
        for (auto &row : board)
            for (auto &cell : row) 
                if (cell == 'O') { cell = 'X'; }

        for (auto &row : board)
            for (auto &cell : row) 
                if (cell == 'T') { cell = 'O'; }
#endif
    }

    void scanOpenRegion(vector<vector<char>> &board, int row, int col)
    {
        board[row][col] = 'T';
        if (row-1 >= 0 && board[row-1][col] == 'O') { scanOpenRegion(board, row-1, col); }
        if (row+1 < board.size() && board[row+1][col] == 'O') { scanOpenRegion(board, row+1, col); }
        if (col-1 >= 0 && board[row][col-1] == 'O') { scanOpenRegion(board, row, col-1); }
        if (col+1 < board[row].size() && board[row][col+1] == 'O') { scanOpenRegion(board, row, col+1); }
    }

    void printLand(vector<vector<char>> &land)
    {
        printf("Land:\n");
        for (auto &row : land)
        {
            for (auto &cell : row) { printf("%c\t", cell); }
            printf("\n");
        }
    }
};
