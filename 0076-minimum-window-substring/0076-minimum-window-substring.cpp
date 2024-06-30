class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> t_map;
        for(auto c: t) t_map[c]++;

        int n=s.length();
        int l=0;
        int r=0;

        int minLen=INT_MAX;
        int minStart=0;

        int counter=t.size();

        while(r<n)
        {
            if(t_map[s[r]]>0) counter--;
            t_map[s[r]]--;

            while(counter==0)
            {
                if(r-l+1 < minLen)
                {
                    minLen=r-l+1;
                    minStart=l;
                }

                t_map[s[l]]++;
                if(t_map[s[l]]>0) counter++;
                l++;
            }
            r++;
        }

        return minLen==INT_MAX? "": s.substr(minStart,minLen);
    }
};