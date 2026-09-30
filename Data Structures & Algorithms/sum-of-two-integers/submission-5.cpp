class Solution {
public:
    int getSum(int a, int b) {
        uint32_t a32 = a;
        uint32_t b32 = b;
        while (b32) {
            uint32_t carry = (a32 & b32) << 1;
            a32 = a32 ^ b32;
            b32 = carry;
        }
        int res = static_cast<int>(a32);
        return res;
    }
};