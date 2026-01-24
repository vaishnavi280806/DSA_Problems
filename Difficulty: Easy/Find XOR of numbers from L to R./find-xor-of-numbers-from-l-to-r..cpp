// User function Template for C++

class Solution {
    int helper(int n){
        if (n % 4 == 0) return n;
        else if (n % 4 == 1) return 1;
        else if (n % 4 == 2) return n+1;
        else return 0;
    }
  public:
    int findXOR(int l, int r) {
        return helper(l-1) ^ helper(r);
    }
};