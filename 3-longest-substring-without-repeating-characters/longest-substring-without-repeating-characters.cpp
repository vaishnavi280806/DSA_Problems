class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        unordered_set <char> hash;
        int l = 0, maxLen = 0;
        for (int r = 0; r < s.size(); r++){
            while (hash.count(s[r])){
                hash.erase(s[l]);
                l++;
            }

            hash.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
            
        }
        return maxLen;
    }
};