class Solution {
public:
    int minimizeXor(int num1, int num2) {
        auto bit1 = bitset<32>(num1), bit2 = bitset<32>(num2);

        for (int i = 0; bit1.count() < bit2.count(); i++) {
            bit1.set(i);
        }

        for (int i = 0; bit1.count() > bit2.count(); i++) {
            bit1.reset(i);
        }

        return bit1.to_ulong();
    }
};