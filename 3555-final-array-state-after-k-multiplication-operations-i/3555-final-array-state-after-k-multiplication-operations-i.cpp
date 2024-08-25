class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        int n=nums.size();
        while(k--)
        {
            // Find the index of the minimum element using std::min_element
            auto minIt = std::min_element(nums.begin(), nums.end());
            // Multiply the minimum element by multi
            *minIt *= multi;
        }

        return nums;
    }
};