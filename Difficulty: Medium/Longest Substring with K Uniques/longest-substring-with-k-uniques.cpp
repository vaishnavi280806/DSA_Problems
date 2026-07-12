class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map <char,int> hash;
        int l = 0, maxLen = 0;
        
        for (int r = 0; r < s.size(); r++){
            hash[s[r]]++;
            
            while (hash.size() > k){
                hash[s[l]]--;
                if (hash[s[l]] == 0){
                    hash.erase(s[l]);
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        if (hash.size() != k) return -1;
        return maxLen;
    }
};