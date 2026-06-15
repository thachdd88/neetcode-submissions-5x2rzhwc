class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {   
        bool found{false};
        // Search row
        int start{0}, end{static_cast<int>(matrix.size())-1};
        int rowIdx = (target >= matrix[end][0])? end : -1;
        if (rowIdx < 0)
        {
            while (end > (start+1))
            {
                int middle = (start+end)/2;
                if (target < matrix[middle][0]) { end = middle; }
                else { start = middle; }                     
            }
            if ((target >= matrix[start][0]) && ((start == end) || target <= matrix[end][0])) { rowIdx = start; }            
        }


        if (rowIdx >= 0)
        {
            int startCol{0}, endCol{static_cast<int>(matrix[rowIdx].size())-1};
            while (!found && endCol >= startCol)
            {
                int middle = (startCol+endCol)/2;
                if (target == matrix[rowIdx][startCol]) { found = true; }
                else if (target == matrix[rowIdx][endCol]) { found = true; }
                else if (target == matrix[rowIdx][middle]) { found = true; }
                else
                {
                    if (target < matrix[rowIdx][middle]) { endCol = middle-1; }
                    else { startCol = middle+1; }
                }            
            }
        }
        return found;
    }
};
