class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int prev = 1;
        int prev2 = 1;
        int res;
        for (int i = 2;  i <= n; i++){
            res = prev2 + prev;
            prev = prev2;
            prev2 = res;
        }
        return res;

    }
};