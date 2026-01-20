class Solution {
  public:
    int setBits(int n) {
        int c = 0;
        while (n != 0){
            if (n % 2) c++;
            n = n/2;
        }
        return c;
    }
};