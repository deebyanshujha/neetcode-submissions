class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<vector<int>> q;
        q.push({0, src, 0}); // stops, node, cost

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            int stops = curr[0];
            int node = curr[1];
            int cost = curr[2];

            if(stops > k) continue;

            for(auto &it : adj[node]) {

                int next = it.first;
                int wt = it.second;

                if(cost + wt < dist[next]) {
                    dist[next] = cost + wt;
                    q.push({stops + 1, next, cost + wt});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};