class Solution {
public:
    int hash[128];
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1) return n;
        int l=0;
        int r=0;

        int max_len=0;
       
        while(r<n)
        {
            
            if(hash[s[r]]==0)
            {
                max_len=max(max_len,r-l+1);
                hash[s[r]]++;
                 r++;
            }

            else
            {
               hash[s[l]]--;
                l++;
            }
            
        }
        return max_len;
    }
};