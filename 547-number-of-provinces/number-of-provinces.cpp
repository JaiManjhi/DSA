class Solution {
public:

    void dfs(int city,
             vector<vector<int>>& isConnected,
             vector<int>& visited)
    {
        visited[city] = 1;

        for(int neighbor = 0;
            neighbor < isConnected.size();
            neighbor++)
        {
            if(isConnected[city][neighbor] == 1
               && !visited[neighbor])
            {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> visited(n,0);

        int provinces = 0;

        for(int city=0; city<n; city++)
        {
            if(!visited[city])
            {
                dfs(city,isConnected,visited);
                provinces++;
            }
        }

        return provinces;
    }
};
