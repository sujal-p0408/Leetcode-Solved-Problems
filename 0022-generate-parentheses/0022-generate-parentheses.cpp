class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       addPara(ans,"",n,n);
       return ans;
    }

     void addPara(vector<string>& ans,string str,int n,int m)
     {
        if(n==0 && m==0)
       {
        ans.push_back(str);
        return; 
       } 
      
      if(n>0)
       {
        string temp_str=str+'(';
        addPara(ans,temp_str,n-1,m);
       }

        if(m>0 && m!=n)
       {
         string temp_str=str+')';
        addPara(ans,temp_str,n,m-1);
       }
     }
};
