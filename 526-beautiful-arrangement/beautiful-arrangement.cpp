class Solution {
    int helper(int pos, int mask, int n){
        if(pos == n+1) return 1;

        int res = 0;
        for(int i = 1; i <= n; i++){
            if ((mask & (1 << i)) == 0) if(i % pos == 0 || pos % i == 0) res += helper(pos+1, mask | (1 << i), n);
        }
        return res;
    }
public:
    int countArrangement(int n) {
        return helper(1, 0, n);
    }
};