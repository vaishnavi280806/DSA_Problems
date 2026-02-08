class Solution {
public:
    int minimumDeletions(string s) {
        //abba
        int a = 0, b = 0;
        for (char x : s){
            if (x == 'a') a = min(a+1, b);
            else b++;
        }
        return a;
    }
};