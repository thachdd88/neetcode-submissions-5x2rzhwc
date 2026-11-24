class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int front = 0, rear = people.size()-1;
        int numBoats = 0;
        while (front < rear) {
            int weight = people[front]+people[rear];
            if (weight > limit) {
                numBoats++; rear--;
            }
            else {
                numBoats++;
                front++; rear--;
            }
        }
        if (front == rear) { numBoats++; }
        return numBoats;
    }
};