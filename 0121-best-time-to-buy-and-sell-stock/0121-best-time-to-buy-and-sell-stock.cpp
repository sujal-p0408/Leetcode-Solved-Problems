class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MinSoFar=INT_MAX;
        int profit=0;

        for(int i=0;i<prices.size();i++)
    {
        MinSoFar=min(MinSoFar,prices[i]);
        profit=max(profit, prices[i]-MinSoFar);
    }

    return profit;
    }
};