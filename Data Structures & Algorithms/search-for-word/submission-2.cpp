class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if (board.empty()) { return false; }
        bool exist = false;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n && !exist; i++)
        {
            for (int j = 0; j < m && !exist; j++)
            {
                exist = verify(board, i, j, word);
            }
        }
        return exist; 
    }
    bool verify(vector<vector<char>>& board, int x, int y, string word) 
    {        
        if (word.empty()) { return true; }
        if ((x >= board.size()) || (y >= board[0].size())) { return false; }
        
        if (word[0] != board[x][y]) { return false; }        
        char tmp = board[x][y];
        board[x][y] = '*';

        string sub = word.substr(1, word.length()-1);        
        bool valid = verify(board, x+1, y, sub) || verify(board, x-1, y, sub) || 
                verify(board, x, y+1, sub) || verify(board, x, y-1, sub);
        board[x][y] = tmp;
        return valid;
    }
};
