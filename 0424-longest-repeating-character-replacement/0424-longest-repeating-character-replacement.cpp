class Solution {
public:
     int characterReplacement(string s, int k) {
        int map[26]={0};
        int n=s.size();
        int max_len = 0;
        int l = 0;
        int r = 0;
        int maxf = 0;

       while(r<n)
       {
        map[s[r]-'A']++;
        maxf=max(maxf,map[s[r]-'A']);

        if((r-l+1-maxf) > k)
        {
             map[s[l]-'A']--;
             l++;
        }

        // if((r-l+1-maxf) <= k)
        // {
            max_len=max(max_len,r-l+1);
        // }

        r++;
       }

        return max_len;
    }
};
