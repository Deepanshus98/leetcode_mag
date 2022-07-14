/*

Medium

5325

246

Add to List

Share
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using ip = pair<int, int>;
        vector<vector<ip>> adj(n);
        for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});
        using arr = array<int, 3>;
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        vector<int> dist(n, INT_MAX);
        pq.push({0, src, 0});
        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();
            if (node == dst) return cost; // if we found destination -> return current cost.
            if (stops > k) continue;
			// Optimization: if we already visit this node and it has fewer stops in 
			// dist array than in pq we don't need to explore it again.
            if (dist[node] != INT_MAX && dist[node] < stops) continue;
            dist[node] = stops;
            for (auto& [next, price] : adj[node]) {
                pq.push({cost + price, next, stops + 1});
            }
        }
        return -1;
    }
};
