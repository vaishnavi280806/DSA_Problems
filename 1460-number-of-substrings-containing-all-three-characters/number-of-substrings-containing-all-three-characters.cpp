class Solution {
public:
    int numberOfSubstrings(string s) {
        vector <int> lastSeen = {-1, -1, -1};
        int c = 0;
        for (int r = 0; r < s.size(); r++){
            lastSeen[s[r] - 'a'] = r;
            c += 1 + min(min(lastSeen[0], lastSeen[1]), lastSeen[2]);
        }
        return c;
    }
};