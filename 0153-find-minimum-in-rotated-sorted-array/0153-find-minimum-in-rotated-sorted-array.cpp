class Solution {
public:
    int findMin(vector<int>& arr) {
         int n=arr.size();
         int low=0;
	    int high=n-1;
	    if(arr[low]<=arr[high]) return arr[low];
	    while(low<=high)
	    {
	        int mid=low+(high-low)/2;
	        
	        int prev=(n+mid-1)%n;
	        int next=(mid+1)%n;
	        
	        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]) return arr[mid];
	        
	         if(arr[0]<=arr[mid]) low=mid+1;
	        
	        else if(arr[mid]<=arr[n-1]) high=mid-1;
	    }
	    
	    return -1;
    }
};