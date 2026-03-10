class Solution {
public:
    int minFlips(string s) {
        int ans = INT_MAX;
        int a1=0, a2=0, l = 0, n = s.size();
        s=s+s;

        string s1, s2;
        int add = 0;
        for(int i=0;i< s.size();i++){
            s1+=('0'+add);
            s2+=('1'-add);
            add^=1;
        }
        cout << s1 << " " << s2 << endl;

        for(int i=0;i<n;i++){
            char b = s[i];
            if(b!=s1[i]) a1++;
             if(b!=s2[i]) a2++;
        }
        cout << a1 << a2;
        ans = min(a1, a2);
        for(int r=n;r<s.size();r++){
            
            char b = s[l];
            if(b!=s1[l]) a1--;
            if(b!=s2[l]) a2--;

            l++;

            b = s[r];
            if(b!=s1[r]) a1++;
            if(b!=s2[r]) a2++;
            ans = min(ans, a1);
            ans = min(ans, a2);
           
        }
        

        return ans;

    }
};