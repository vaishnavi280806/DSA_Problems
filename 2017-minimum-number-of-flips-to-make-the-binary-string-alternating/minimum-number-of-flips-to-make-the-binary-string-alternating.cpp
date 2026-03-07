class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        int c = 0;
        int res = INT_MAX;
        //odd - 1
        //even - 0
        for (int i = 0; i < s.size(); i++){
            if (i % 2 == 1 && s[i] != '1') c++;
            else if (i % 2 == 0 && s[i] != '0') c++;
            if (i >= n && (i-n) % 2 == 1 && s[i-n] != '1' ) c--;
            else if (i >= n && (i-n) % 2 == 0 && s[i-n] != '0' ) c--;
            if (i >= n-1) res = min(res, min(c, n-c));
        }
        return res;
    }
};