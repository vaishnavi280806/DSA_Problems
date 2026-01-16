class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int sum = 0;
        int prev = -1;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') sum += -1;
            else sum += 1;
            if (sum == 0){
                res += s.substr(prev+2, i-prev-2);
                prev = i;
            }
        }
        return res;
    }
};