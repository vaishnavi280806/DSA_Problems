class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto x : s){
            if (x == '(' || x== '[' || x == '{') stk.push(x);
            else if (x == ')'){
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else return false;
            }
            else if (!stk.empty() && x == ']'){
                if (stk.top() == '[') stk.pop();
                else return false;
            }
            else{
                if (!stk.empty() && stk.top() == '{') stk.pop();
                else return false;
            }
        }
        if (stk.empty()) return true;
        else return false;
    }
};