class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));
        queue<pair<int,int>> qp, qa;
        // Pacific borders
        for (int i=0; i<m; i++) {
            qp.push({i,0});
            pac[i][0]=1;
        }
        for (int j=0; j<n; j++) {
            qp.push({0,j});
            pac[0][j]=1;
        }
        // Atlantic borders
        for (int i=0; i<m; i++) {
            qa.push({i,n-1});
            atl[i][n-1]=1;
        }
        for (int j=0; j<n; j++) {
            qa.push({m-1,j});
            atl[m-1][j]=1;
        }
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        auto bfs=[&](queue<pair<int,int>>& q, vector<vector<int>>& vis) {
            while (!q.empty()) {
                auto [x,y]=q.front();
                q.pop();
                for (int k=0; k<4; k++) {
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if (nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny]&& heights[nx][ny] >= heights[x][y]) {
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        };
        bfs(qp,pac);
        bfs(qa,atl);
        vector<vector<int>> ans;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};