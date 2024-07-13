class Solution {
public:
    int find_days(vector<int>& weights, int x)
    {
        int days=1;
        int load=0;

        for(auto i: weights)
        {
            load+=i;

            if(load>x)
            {
                days++;
                load=i;
            }
        }

        return days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high)
        {
           int mid=(low+high)/2;
           int day=find_days(weights,mid);
           if(day<=days) high=mid-1;
           else low=mid+1;
        }

        return low;
    }
};