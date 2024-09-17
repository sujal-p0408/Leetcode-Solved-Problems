class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        
        reverse(s.begin(),s.end());
        
        int start=0;
        for(int i=0;i<=n;i++)   
        {
          if(i>=n || s[i]==' ')
          {
            reverse(s.begin()+start,s.begin()+i);
            start=i+1;
          }
        }

        int idx=0,i=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ' || (i>0 && s[i-1]!=' ')) 
            {
                s[idx]=s[i];
                idx++;
            }
        } 
         if (idx > 0 && s[idx - 1] == ' ')  idx--;
       s.resize(idx); 
      return s;
    }
};