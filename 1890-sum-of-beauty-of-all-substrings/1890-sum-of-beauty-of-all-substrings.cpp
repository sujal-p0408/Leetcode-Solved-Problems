class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> u_map;
            for(int j=i;j<n;j++)
            {
                u_map[s[j]]++;
            

            int maxi=0;
            int mini=INT_MAX;
            for(auto i: u_map)
            {
                maxi=max(maxi,i.second);
                mini=min(mini,i.second);
            }
            sum+=maxi-mini;
            }
        }
       return sum;
    }
};