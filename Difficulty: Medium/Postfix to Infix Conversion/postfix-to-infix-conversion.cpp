// User function Template for C++

class Solution {
  public:
    string postToInfix(string &exp) {
        string res = "";
        stack <string> stk;
        for (auto x : exp){
            if (isalnum(x)) stk.push(string(1,x));
            else{
                string top1 = stk.top();
                stk.pop();
                string top2 = stk.top();
                stk.pop();
                stk.push('(' + top2 + x + top1 + ')');
            }
        }
        return stk.top();
    }
};