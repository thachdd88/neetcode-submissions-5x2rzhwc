class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        printGrid(grid);
        int freshCnt{0};
        for (auto &row : grid)
            for (auto &cell : row) { freshCnt += (cell == 1)? 1 : 0; }
        
        int rottened{-1};
        int minutes{3};
        while (rottened != 0 && freshCnt > 0)
        {
            rottened = 0;
            for (int row = 0; row < grid.size(); row++) {
                for (int col = 0; col < grid[0].size(); col++) {
                    if (grid[row][col] == 1)
                    {
                        // printf("Cell: %d, %d [%d], %d\n", row, col, minutes, grid[2][2]);
                        if ((row-1 >= 0) && (grid[row-1][col] >= 2) && (grid[row-1][col] < minutes)) { 
                            // printf("Neighbor 1: %d, %d [%d]\n", row-1, col, grid[row-1][col]);
                            // if (grid[row-1][col] < minutes) { grid[row][col] = minutes; rottened++; freshCnt--; }
                            grid[row][col] = minutes; rottened++; freshCnt--;
                        }
                        else if ((row+1 < grid.size()) && (grid[row+1][col] >= 2) && (grid[row+1][col] < minutes)) { 
                        // if ((row+1 < grid.size()) && (grid[row+1][col] >= 2)) { 
                            // printf("Neighbor 2: %d, %d [%d]\n", row+1, col, grid[row+1][col]);
                            // if (grid[row+1][col] < minutes) { grid[row][col] = minutes; rottened++; freshCnt--; }
                            grid[row][col] = minutes; rottened++; freshCnt--;
                        }
                        else if ((col-1 >= 0) && (grid[row][col-1] >= 2) && (grid[row][col-1] < minutes)) { 
                        // if ((col-1 >= 0) && (grid[row][col-1] >= 2)) { 
                            // printf("Neighbor 3: %d, %d [%d]\n", row, col-1, grid[row][col-1]);
                            // if (grid[row][col-1] < minutes) { grid[row][col] = minutes; rottened++; freshCnt--; }
                            grid[row][col] = minutes; rottened++; freshCnt--;
                        }
                        else if ((col+1 < grid[0].size()) && (grid[row][col+1] >= 2) && (grid[row][col+1] < minutes)) { 
                        // if ((col+1 < grid[0].size()) && (grid[row][col+1] >= minutes)) {
                            // printf("Neighbor 4: %d, %d [%d]\n", row, col+1, grid[row][col+1]);
                            // if (grid[row][col+1] < minutes) { grid[row][col] = minutes; rottened++; freshCnt--; }
                            grid[row][col] = minutes; rottened++; freshCnt--;
                        }
                    }
                }
            }            
            printGrid(grid);
            printf("Rotten: %d, Fresh: %d\n", rottened, freshCnt);
            minutes += 1;
        }
        return (freshCnt > 0)? -1 : minutes-3;
    }
    void printGrid(vector<vector<int>>& grid)
    {
        printf("Grid:\n");
        for (auto &row : grid)
        {
            for (auto &cell : row) { printf("%d\t", cell); }
            printf("\n");;
        }
    }
};
