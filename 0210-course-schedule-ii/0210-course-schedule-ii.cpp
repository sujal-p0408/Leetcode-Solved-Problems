class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
         vector<int> indegree(V);
       vector<vector<int>> adj(V);
       for(auto it: prerequisites)
       {
        adj[it[1]].push_back(it[0]);
       }

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
    // Queue to store vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        // Decrease indegree of adjacent vertices as the
        // current node is in topological order
        for (auto it : adj[node]) {
            indegree[it]--;

            // If indegree becomes 0, push it to the queue
            if (indegree[it] == 0)
                q.push(it);
        }
    }
         return result.size() == V ? result : vector<int>();  // <-- DAG check
    }
};