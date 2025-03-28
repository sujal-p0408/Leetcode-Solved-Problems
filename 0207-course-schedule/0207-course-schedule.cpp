class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph and compute indegrees
        for (auto& pre : prerequisites) {
            int u = pre[1], v = pre[0];
            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        // Push all courses with no prerequisites (indegree 0)
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            count++;
            for (int neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If we were able to process all courses
        return count == numCourses;
    }
};
