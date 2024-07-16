class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();

        for(auto x:arr)
        {
            if(x <= k) k++;
            else return k;
        }

        return k;
    }
};