class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            if (s1[i] == s2[i]) continue;
            if (s1[i] == '0' && s2[i] == '1'){ //0->1
                res++;
                s1[i] = '1';
            }
            else{ //1->0
                if (i != n-1 && s1[i+1] == '1'){ //x11 -> x00
                    res += 1;
                    s1[i+1] = '0';
                    s1[i] = '0';
                }
                else if (i != 0 && s1[i-1] == '1'){ //11x -> 00x -> 10x
                    res += 2;
                    s1[i] = '0';
                }
                else if (i != n-1 || i != 0){ //010 -> 011 -> 000 or 010 -> 110 -> 000
                    res += 2;
                    s1[i] = '0';
                }
            }
        }
        if (s1 == s2) return res;
        return -1;
    }
};