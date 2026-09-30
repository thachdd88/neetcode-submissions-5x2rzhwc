class Solution {
public:
    int getSum(int a, int b) {
        uint32_t a32 = a;
        uint32_t b32 = b;
        uint32_t carry{0};
        uint32_t res{0};
        for (int i = 0; i < 32; i++) {
            uint32_t mask = 0x1 << i;
            res = res | ((a32&mask) ^ (b32&mask) ^ carry);
            carry = (a32 & b32 & mask) | (a32 & carry) | (b32 & carry);
            carry = carry << 1;
        }
        return static_cast<int>(res);
    }
};