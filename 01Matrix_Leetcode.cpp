class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            int d = dis[row][col];
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0
                && !vis[nrow][ncol])
                {
                    if(mat[nrow][ncol] == 0) continue;
                    if(mat[nrow][ncol] == 1){
                        dis[nrow][ncol] = d + 1;
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return dis;
    }
};
