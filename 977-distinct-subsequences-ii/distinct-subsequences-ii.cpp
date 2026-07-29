class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int mod = 1e9 + 7;

        vector<long long> dp(n+1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            dp[i] = 2LL * dp[i-1] % mod;

            int c = s[i-1] - 'a';
            if (last[c] != -1){
                dp[i] = (dp[i] -  dp[last[c] -1] + mod) % mod;
            }
            last[c] = i;
        }
        return (dp[n] - 1 + mod) % mod;
    }
};