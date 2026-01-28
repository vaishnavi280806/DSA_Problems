class Solution {
    int priority(char& c){
        if (c == '^') return 3;
        else if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        else return -1;
    }
  public:
    string infixToPrefix(string &s) {
        string res;
        stack <char> stk;
        reverse(s.begin(), s.end());
        for (char x : s){
            if (isalnum(x)) res += x;
            else if (x == ')') stk.push('(');
            else if (x == '('){
                while (stk.top() != '('){
                    res += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else{
                while (!stk.empty() && ((x == '^' && priority(x) <= priority(stk.top())) ||
                (priority(x) < priority(stk.top())))){
                    res += stk.top();
                    stk.pop();
                }
                stk.push(x);
            }
        }
        while (!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
