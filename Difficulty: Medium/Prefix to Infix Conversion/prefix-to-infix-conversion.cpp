// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        reverse(s.begin(), s.end());
        stack <string> stk;
        for (char x : s){
            if (isalnum(x)) stk.push(string(1,x));
            else{
                string tp1 = stk.top(); stk.pop();
                string tp2 = stk.top(); stk.pop();
                stk.push('(' + tp1 + x + tp2 + ')');
            }
        }
        return stk.top();
    }
};