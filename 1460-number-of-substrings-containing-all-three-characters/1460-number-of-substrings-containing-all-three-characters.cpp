class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> map(3);

        int l=0;
        int r=0;
        int ans=0;

        while(r<n)
        {
            map[s[r]]++;

            while(map['a'] && map['b'] && map['c'])
            {
                ans+=n-r;
                map[s[l]]--;
                l++;
            }

            r++;
        }
     return ans;
    }
};