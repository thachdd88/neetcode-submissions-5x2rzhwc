class Solution {
    typedef unordered_set<int> NumSet;
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       array<NumSet, 9U> rowSets, colSets;
       array<array<NumSet, 3U>, 3U> cellSets; 
       bool valid = true;
       for (unsigned int row = 0U; valid && (row < 9U); row++)
       {
        for (unsigned int col = 0U; valid && (col < 9U); col++)
        {
            char ch = board[row][col];
            switch (ch)
            {
                case '0'...'9':
                {
                    int num = ch-'0';
                    if (rowSets[row].find(num) != rowSets[row].end())
                    {
                        valid = false;
                        break;
                    }
                    else { rowSets[row].insert(num); }

                    if (colSets[col].find(num) != colSets[col].end())
                    {
                        valid = false;
                        break;
                    }
                    else { colSets[col].insert(num); }

                    if (cellSets[row/3U][col/3U].find(num) != cellSets[row/3U][col/3U].end())
                    {
                        valid = false;
                        break;
                    }
                    else { cellSets[row/3U][col/3U].insert(num); }
                }                
                    break;                    
                default:
                    break;
            }
        }
       }
       return valid;
    }
};
