class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();

        if(n<=1) return s;
        
        auto expand_from_center= [&](int l, int r)
        {
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
            return s.substr(l+1,r-l-1);
        };

        string maxi=s.substr(0,1);

        for(int i=0;i<n-1;i++)
        {
           string odd=expand_from_center(i,i);
           string even=expand_from_center(i,i+1);
           
           if(odd.length()>maxi.length())
           {
            maxi=odd;
           }

            if(even.length()>maxi.length())
           {
            maxi=even;
           }

        }

        return maxi;
    }
};