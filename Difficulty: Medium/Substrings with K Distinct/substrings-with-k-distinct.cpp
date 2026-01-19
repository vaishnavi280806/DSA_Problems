class Solution {
    int helper(string& s, int k){
        if (k == 0) return 0;
        int ans = 0;
        vector<int> freq(26);
        int l = 0, distinct = 0;
        for (int r = 0; r < s.size(); r++){
            if (freq[s[r] - 'a'] == 0) distinct++;
            freq[s[r] - 'a']++;
            while (distinct > k){
                freq[s[l] - 'a']--;
                if (freq[s[l] - 'a'] == 0) distinct--;
                l++;
            }
            if (distinct <= k) ans += r - l + 1;
        }
        return ans;
    }
  public:
    int countSubstr(string& s, int k) {
        return helper(s, k) - helper(s, k-1);
    }
};