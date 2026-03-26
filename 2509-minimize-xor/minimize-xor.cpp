class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0;
        int n = __builtin_popcount(num2);
        int cur;
        for (int i = 31; i >= 0; i--){
            if (n == 0) break;
            cur = 1 << i;
            if (num1 & cur){
                n--;
                x = x | cur;
            }
        }
        for (int i = 0; i < 32; i++){
            if (n == 0) break;
            cur = 1 << i;
            if ((num1 & cur) == 0){
                n--;
                x = x | cur;
            }
        }
        return x;
    }
};