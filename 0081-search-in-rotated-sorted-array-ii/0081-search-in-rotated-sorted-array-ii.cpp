class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        if(nums[0]==target || nums[n-1]==target) return true;
        while(low<=high)
        {
           mid=(low+high)/2;
           if(nums[mid]==target) return true;
            
           if(nums[low]==nums[mid] && nums[mid]==nums[high]) // new condition to handle duplicates
           {
               low++;
               high--;
               continue;
           }
           
           // here we are first checking for sorted array if the array is sorted then only we can apply binary search
           // after getting the sorted part we check if the target exists between them if yes then apply binary search if not then exclude the sorted array 
           if(nums[low]<=nums[mid]) // checking if the left half is sorted
           {
            if(nums[low]<=target && nums[mid]>=target) high=mid-1; // checking if the target lies in the range of sorted array
             // excluding mid as we have already checked if target is equal to nums[mid]
            else low=mid+1;
           }
           
           else   // for sure the right part will be sorted
           {
                if(nums[mid]<=target && target<=nums[high]) low=mid+1;
                else high=mid-1;
           }

        }
        return false;
    }
};