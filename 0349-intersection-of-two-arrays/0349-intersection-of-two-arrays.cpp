class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
    int i=0;
	int j=0;
    int n=arr1.size();
    int m=arr2.size();
    vector<int> ans;
    unordered_set<int> u_set;
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
	while(i<n && j<m)
	{
      if(arr1[i]==arr2[j]) 
	  {
		  u_set.insert(arr1[i]);
		  i++;
		  j++;
	  }

	  else if(arr1[i]<arr2[j]) i++;
	  else j++;
	}

    for(auto i: u_set)
    {
        ans.push_back(i);
    }
	return ans;
    }
};