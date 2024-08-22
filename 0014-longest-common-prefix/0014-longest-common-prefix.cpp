class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(),strs.end());
        for(auto s: strs)
        {
            cout<<s<<" ";
        }
        cout<<endl;
        string res = "";

        for (int i = 0; i < strs[0].size(); i++) {
            for (auto& s : strs) {
                if (i >= s.size() || s[i] != strs[0][i]) {
                    return res;
                }
            }
            res += strs[0][i];
        }
        
        return res;
    }
};