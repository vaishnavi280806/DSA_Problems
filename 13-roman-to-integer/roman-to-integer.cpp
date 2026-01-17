class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> hash;
        hash = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        int i = 0;
        int n = s.size();
        while (i < n){
            if (s[i] == 'I' && (i+1 < n && (s[i+1] == 'V' || s[i+1] == 'X'))){
                sum += hash[s[i+1]] - hash[s[i]];
                i += 2;
            }
            else if (s[i] == 'X' && (i+1 < n && (s[i+1] == 'L' || s[i+1] == 'C'))){
                sum += hash[s[i+1]] - hash[s[i]];
                i += 2;
            }
            else if (s[i] == 'C' && (i+1 < n && (s[i+1] == 'D' || s[i+1] == 'M'))){
                sum += hash[s[i+1]] - hash[s[i]];
                i += 2;
            }
            else{
                sum += hash[s[i]];
                i++;
            }       
        }
        return sum;
    }
};