class Solution {
public:

    int ans = 0;

    void dfs(int node,
             int parent,
             vector<vector<pair<int,int>>>& graph)
    {
        for(auto &it : graph[node])
        {
            int next = it.first;
            int cost = it.second;

            if(next == parent)
                continue;

            ans += cost;

            dfs(next, node, graph);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto &e : connections)
        {
            int a = e[0];
            int b = e[1];

            graph[a].push_back({b,1});
            graph[b].push_back({a,0});
        }

        dfs(0, -1, graph);

        return ans;
    }
};