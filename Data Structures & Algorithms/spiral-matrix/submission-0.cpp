class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i{0}, j{0};
        int width, height, cnt{0};
        width = matrix[0].size();
        height = matrix.size()-1;
        
        int direction{0};

        bool done{false};
        vector<int> res{};
        while (!done) {
            // printf("%d, %d, %d, %d\n", matrix[i][j], width, height, direction);
            res.push_back(matrix[i][j]);
            cnt++;
            switch (direction) {
                case 0: // right
                    if (cnt < width) { j++; } 
                    else {
                        direction = 1;
                        width--;
                        i++;
                        cnt = 0;
                        done = height <= 0;
                    }
                    break;
                case 1: // down
                    if (cnt < height) { i++; }
                    else {
                        direction = 2;
                        height--;
                        j--;
                        cnt = 0;
                        done = width <= 0;
                    }                    
                    break;
                case 2: // left
                    if (cnt < width) { j--; }
                    else { 
                        direction = 3;
                        width--;
                        i--;
                        cnt = 0;
                        done = height <= 0;
                    }
                    break;
                case 3: // up
                    if (cnt < height) { i--; }
                    else {
                        direction = 0;
                        height--;
                        j++;
                        cnt = 0;
                        done = width <= 0;
                    }
                    break;
            }
        }

        return res;
    }
};
