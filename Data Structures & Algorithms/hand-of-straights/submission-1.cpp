class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int nGp = n / groupSize;
        map<int, int> deck;
        for (auto card : hand) { deck[card]++; }
        bool valid = (n % groupSize) == 0;
        for (int gp = 0; valid && gp < nGp; gp++) {
            int fsCard = deck.begin()->first;
            for (int card = 0; valid && card < groupSize; card++) {
                if (deck[fsCard+card] > 0) { 
                    deck[fsCard+card]--; 
                    if (deck[fsCard+card] == 0) { deck.erase(fsCard+card); }
                }
                else { valid = false; }
            }
        }        
        return valid;
    }
};
