class Solution {
public:
    int findSum(vector<int>& nums, int x)
    {
        int sum=0;
        for(auto i: nums)
        {
            sum+=ceil((double)i/(double)x);
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int sum=INT_MAX;
        while(l<=r)
        {
            int mid=(l+r)/2;

            int curr_sum=findSum(nums,mid);
           
            if(curr_sum<=threshold)
            {
                r=mid-1;
                // sum=min(sum,curr_sum);
            }

            else l=mid+1;
        }

        return l;
    }
};