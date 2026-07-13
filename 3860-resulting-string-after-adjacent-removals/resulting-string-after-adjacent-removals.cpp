class Solution {
public:
    string resultingString(string s) {
        stack<char>  stk;
        int n = s.size();
        int flag = 0;
        for (int i = 0; i < n; i++){
            //stk.push(s[i]);
            if (!stk.empty()){
                if (s[i] != 'a' && s[i] != 'z'){
                    if (stk.top() == (char)(s[i] + 1) || stk.top() == (char)(s[i] - 1)){
                        stk.pop();
                        flag = 1;
                    }
                }
                else if (s[i] == 'a' && (stk.top() == 'b' || stk.top() == 'z')){
                    stk.pop(); 
                    flag = 1;
                }
                else if (s[i] == 'z' && (stk.top() == 'y' || stk.top() == 'a')){
                    stk.pop();
                    flag = 1;
                }

            }
            if (flag == 0) stk.push(s[i]);
            flag = 0;
        }

        string res = "";
        while (!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};