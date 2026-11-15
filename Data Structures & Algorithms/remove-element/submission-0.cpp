class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int front = 0;
        int rear = nums.size()-1;
        while (rear >= front) {
            if (nums[rear] == val) { rear--; }
            else if (nums[front] != val) { front++; }
            else {
                int tmp = nums[rear];
                nums[rear] = nums[front];
                nums[front] = tmp;
                front++;
                rear--;
            }
        }
        return rear+1;
    }
};