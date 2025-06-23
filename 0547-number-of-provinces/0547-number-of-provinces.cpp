class Solution {
public:
void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
        for (int j = 0; j < M.size(); j++) {
            if (M[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
         int cnt=0;
           int n=M.size();
           vector<int> visited(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                visited[i]=1;
                cnt++;
                dfs(M,visited,i);
            }
        }

        return cnt;
    }

   
};