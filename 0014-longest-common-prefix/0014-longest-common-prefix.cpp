class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
    //      std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {
    //     return a.size() < b.size();
    // }); // sorts by size
    
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