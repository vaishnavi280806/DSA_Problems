class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int res = 0;
        int cnt = 0;
        int maxi = 0;
        unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); r++){
            mp[s[r]]++;
            maxi = max(maxi, mp[s[r]]);
            while (r -l+1 - maxi > k){
                mp[s[l]]--;
                l++;
                maxi = max(maxi, mp[s[r]]);
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};