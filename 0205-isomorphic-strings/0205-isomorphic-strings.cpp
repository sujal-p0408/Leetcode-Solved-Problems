class Solution {
public:
    bool isIsomorphic(string s, string t) {
     vector<int> m1(128,0);
     vector<int> m2(128,0);
     int n=s.size();
     for(int i=0;i<n;i++)
     {
        if( m1[s[i]] !=  m2[t[i]]) return false;

        m1[s[i]]=i+1;
        m2[t[i]]=i+1;
     }

     return true;
    }
};