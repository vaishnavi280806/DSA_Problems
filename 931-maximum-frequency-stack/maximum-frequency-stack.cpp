class FreqStack {
public:
    unordered_map <int, int> freq;
    unordered_map <int, stack <int>> hash;
    int maxi = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxi = max(maxi, freq[val]);
        hash[freq[val]].push(val);
    }
    
    int pop() {
        int x = hash[maxi].top();
        hash[maxi].pop();
        freq[x]--;
        if (hash[maxi].empty()) maxi--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */