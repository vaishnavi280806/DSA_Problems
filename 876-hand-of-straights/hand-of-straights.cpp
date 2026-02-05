class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map <int, int> hash;
        for (int x : hand){
            hash[x]++;
        }
        auto it = hash.begin();
        while (it != hash.end()){
            if (it->second == 0){
                it++;
            }
            else{
                int start = it->first;
                int c = it->second;
                for (int i = 0; i < groupSize; i++){
                    if (hash[start + i] < c) return false;
                    hash[start + i] -= c;
                }
                it++;
            }

        }
        return true;
    }
};