class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();

        istringstream ss(s);
        vector<string> words;
        string word;

        while(ss>>word)
        {
            words.push_back(word);
        }

        reverse(words.begin(),words.end());
        
        ostringstream res;
        for(int i=0;i<words.size();i++)
        {
            if(i>0)
            {
                res<<" ";
            }
          res<<words[i];
        }
        return res.str();
    }
};