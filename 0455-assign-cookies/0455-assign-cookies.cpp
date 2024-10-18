class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int l=0,r=0;
        int ans=0;
        while(r<n && l<m)
        {
            if(g[r]<=s[l])
            {
                ans++;
                r++;
            }
            l++;
        }

        return ans;
    }
};