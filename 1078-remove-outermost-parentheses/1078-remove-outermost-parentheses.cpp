class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int cnt=0;
        string ans="";
        // int startIdx=0;
        // int endIdx=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(cnt>0) ans+=s[i];

                cnt++;
            }
            else
            {
                cnt--;
                if(cnt>0) ans+=s[i];
            }
        }

        return ans;
    }
};