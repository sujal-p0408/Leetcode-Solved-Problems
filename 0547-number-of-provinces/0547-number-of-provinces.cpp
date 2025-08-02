class Solution {
public:


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
                queue<int> q;
                q.push(i);

                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();

                    for(int j=0;j<n;j++)
                    {
                        if(M[node][j]==1 && !visited[j])
                        {
                            visited[j]=1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return cnt;
    }

   
};