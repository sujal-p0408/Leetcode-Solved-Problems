class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++)
        {
            if(minHeap.size()>k) minHeap.pop();
            
            else if(minHeap.size()==k && nums[i]>minHeap.top())
            {
                minHeap.push(nums[i]);
                minHeap.pop();
            }
            if(minHeap.size()<k)
            minHeap.push(nums[i]);
        }
    }
    
    int add(int val) {
        if(minHeap.size()>K) minHeap.pop();
            
            else if(minHeap.size()==K && val>minHeap.top())
            {
                minHeap.push(val);
                minHeap.pop();
            }
            if(minHeap.size()<K)
            minHeap.push(val);

            return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */