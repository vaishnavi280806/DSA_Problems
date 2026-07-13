class Solution {
public:
    int minAddToMakeValid(string s) {
        int op = 0, cl = 0;
        for (char it : s){
            if (it == '(') op++;
            else{
                if (op > 0) op--;
                else cl++;
            }
        }
        return op+cl;
    }
};