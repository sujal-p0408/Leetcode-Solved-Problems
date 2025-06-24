class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int oldclr, int color)
    {
          int n=image.size();
        int m=image[0].size();

        if(i<0 || j<0 || i>=n || j>=m || image[i][j]!=oldclr || image[i][j]==color) return;
         
        //  vis[i][j]=1;
        image[i][j]=color;

        dfs(image, i-1, j, oldclr, color);
        dfs(image, i+1, j, oldclr,  color);
        dfs(image, i, j-1, oldclr,  color);
        dfs(image, i, j+1, oldclr,  color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int color) {
        int n=image.size();
        int m=image[0].size();

        // vector<vector<int>> vis(n, vector<int>(m, 0)); {no need of visited array}
        
        int oldclr=image[i][j];
       
                if( oldclr!=color)
                {
                    // vis[i][j]=1;
                    
                    dfs(image, i, j,oldclr, color);
                }
     

        return image;
    }
};