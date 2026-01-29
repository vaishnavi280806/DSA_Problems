// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        stack <string> stk;
        for (char x : s){
            if (isalnum(x)) stk.push(string(1, x));
            else{
                string tp1 = stk.top(); stk.pop();
                string tp2 = stk.top(); stk.pop();
                stk.push(x + tp2 + tp1);
            }
        }
        return stk.top();
    }
};