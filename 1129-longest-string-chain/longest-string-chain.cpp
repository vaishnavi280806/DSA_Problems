class Solution {
    static bool compare(string s1, string s2){
        return s1.size() < s2.size();
    }
    bool check(string word1, string word2){
        int n1 = word1.size();
        int n2 = word2.size();
        if (n2 - n1 != 1) return false;
        int i = 0;
        int flag = 0;
        for (int j = 0; j < n2; j++){
            if (i == n1) return true;
            if (word1[i] == word2[j]) i++;
            else if (word1[i] != word2[j] && flag == 0){
                flag = 1;
            }
            else if (word1[i] != word2[j] && flag == 1){
                return false;
            }
            
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (check(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;

    }
};