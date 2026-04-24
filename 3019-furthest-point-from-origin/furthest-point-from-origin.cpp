class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0;
        int R = 0;
        int dash = 0;
        int n = moves.size();
        for (int i = 0; i < n; i++){
            if (moves[i] == 'L') L++;
            else if (moves[i] == 'R') R++;
            else dash++;
        }
        if (L >= R) L+= dash;
        else R += dash;

        return abs(L-R);
    }
};