class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> map1(26);
	    unordered_map<char,int> map2(26);
        vector<int> ans;
	    
	    for(int i=0;i<p.size();i++)
	    {
	        map1[p[i]]++;
	    }
	    
	    int l=0;
	    int r=p.size()-1;
	    int cnt=0;
	    
	    for(int i=l;i<=r;i++)
	    {
	        map2[s[i]]++;
	    }
	    // int startIndex=l;

	    while(r<s.size())
	    {
            if(map1.size()==map2.size())
            {
              if(map1==map2){
                ans.push_back(l);
            }
            }
	        
	        
	        map2[s[l]]--;
	         if (map2[s[l]] == 0) {
            map2.erase(s[l]); // Remove the key if its value is zero to keep map clean
        }
	        l++;
	        r++;
	        if (r < s.size()) {
            map2[s[r]]++;
        }
	    }
	    
	    return ans;
    }
};