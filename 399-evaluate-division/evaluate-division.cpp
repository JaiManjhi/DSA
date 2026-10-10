class Solution {
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build the weighted graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;

        for (auto& q : queries) {
            string start = q[0];
            string end = q[1];

            if (!graph.count(start) || !graph.count(end)) {
                ans.push_back(-1.0);
            } else if (start == end) {
                ans.push_back(1.0);
            } else {
                unordered_set<string> visited;
                ans.push_back(dfs(start, end, 1.0, graph, visited));
            }
        }

        return ans;
    }

private:
    double dfs(
        string curr,
        string target,
        double product,
        unordered_map<string, vector<pair<string, double>>>& graph,
        unordered_set<string>& visited
    ) {
        if (curr == target) {
            return product;
        }

        visited.insert(curr);

        for (auto& edge : graph[curr]) {
            string next = edge.first;
            double weight = edge.second;

            if (!visited.count(next)) {
                double result = dfs(
                    next, target, product * weight, graph, visited
                );

                if (result != -1.0) {
                    return result;
                }
            }
        }

        return -1.0;
    }
};