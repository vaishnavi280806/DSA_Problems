class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0;
        int res = 0;
        unordered_map<char, int> hash;
        for (int r = 0; r < n; r++){
            hash[s[r]]++;
            while (hash.size() == 3){
                res += n - r;
                hash[s[l]]--;
                if (hash[s[l]] == 0) hash.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};