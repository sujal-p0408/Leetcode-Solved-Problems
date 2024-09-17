class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string res="";

        int i=0;
        int j=0;
        while(i<n)
        {
            while(i<n && s[i] == ' ') i++;

            if(i>=n) break;
            j=i+1;

            while(j<n && s[j]!=' ') j++;

            string sub= s.substr(i,j-i);

            if(!res.empty()) 
            res= sub + " " + res;

            else
            res=sub;

            i=j+1;
        }

        return res;
    }
};