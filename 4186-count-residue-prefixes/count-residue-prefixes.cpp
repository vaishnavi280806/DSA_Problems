class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> hash;
        int count = 0;
        for (int i = 0; i < s.size(); i++){
            hash.insert(s[i]);
            if ((i+1)%3 == hash.size()) count++;
        }
        return count;
    }
};