class Solution {
public:
vector<int> getRow(int n) {
        vector<int> ans;
        long long res=1;
        ans.push_back(res);

        for(int i=1;i<=n;i++)
        {
            res*=(n-i+1);
            res/=i;
            ans.push_back(res);
        }

        return ans;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for(int row=1;row<=n;row++)
        {
          res.push_back(getRow(row-1));
        }

        return res;
    }
};