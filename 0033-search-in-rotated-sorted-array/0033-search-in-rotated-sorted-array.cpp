class Solution {
public:
     int findMin(vector<int>& arr, int n) {
	    // code here
	    int low=0;
	    int high=n-1;
	    if(arr[low]<=arr[high]) return low;
	    while(low<=high)
	    {
	        int mid=low+(high-low)/2;
	        
	        int prev=(n+mid-1)%n;
	        int next=(mid+1)%n;
	        
	        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]) return mid;
	        
	         if(arr[0]<=arr[mid]) low=mid+1;
	        
	        else if(arr[mid]<=arr[n-1]) high=mid-1;
	    }
	    
	    return -1;
	}
    
    int Binary_search(vector<int>& nums, int target,int low,int high)
    {
       while(low<=high)
       {
        int mid=low+(high-low)/2;

        if(nums[mid]==target) return mid;

        else if(nums[mid]<target) low=mid+1;

        else high=mid-1;
       }

       return -1;
    }
    int search(vector<int>& nums, int target) {
        int min_idx=findMin(nums,nums.size());

        int x=Binary_search(nums,target,0,min_idx-1);
        int y=Binary_search(nums,target,min_idx,nums.size()-1);
        cout<<min_idx<<" "<<x<<" "<<y<<endl;
        if(x==-1 && y==-1) return -1;

        if(x>=0) return x;

        return y;
        
    }
};