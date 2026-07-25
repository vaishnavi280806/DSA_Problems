class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int secMax = 0;
        while (n){
            int d = n%10;
            if (d >= maxi){
                secMax =  maxi;
                maxi = d;
            }
            else if (d > secMax) secMax = d;
            n /= 10;
        }

        return maxi * secMax;
    }
};