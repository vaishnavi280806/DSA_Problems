class Solution {
    bool valid(stack<char>& stk){
        stack<char> temp = stk;
        string str = "abc";
        for (int i = 2; i >= 0; i--){
            if (temp.top() != str[i]) return false;
            temp.pop();
        }
        return true;
    }
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;

        for (int i = 0; i < n; i++){
            stk.push(s[i]);

            if (stk.size() >= 3 && valid(stk)){
                for (int i = 0; i < 3; i++) stk.pop();
            }
        }
        if (stk.empty()) return true;
        return false;
    }
};