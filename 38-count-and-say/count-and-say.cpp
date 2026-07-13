class Solution {
    string helper(int n){
        if (n == 1) return "1";

        string s = helper(n-1) + '#';
        string res = "";
        int prev = 0;
        for (int i = 0; i < s.size() - 1; i++){
            if (s[i] != s[i+1]){
                res += to_string(i - prev + 1) + s[i];
                prev = i+1;
            }
        }
        //cout << res << endl;
        return res.substr(0, res.size());
    }
public:
    string countAndSay(int n) {
        return helper(n);
    }
};