class Solution {
public:
    int subarraysWithKDistinct(vector<int>& s, int k) {
       int x=solve(s,k);
       int y=solve(s,k-1);
       cout<<x<<" "<<y<<endl;
       return x-y;
    }

    int solve(vector<int>& s, int k)
    {
    int n=s.size();
    int l=0;
    int r=0;
    int cnt=0;
    unordered_map<int,int> map(26);
    
    while(r<n)
    {
        map[s[r]]++;
        
        while(map.size()>k)
        {
            map[s[l]]--;
            if(map[s[l]]==0) map.erase(s[l]);
            l++;
        }
        
     cnt+=r-l+1;
        r++;
    }
    return cnt;
    }
};