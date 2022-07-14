/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

 

Example 1:


Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.
Example 2:

Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites, and each course is independent.
Example 3:


Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
*/
class Solution {
public:
    void dfs_new(vector<vector<int>> &graph, vector<bool> &vis, int source, int c){
        if(source != c){
            graph[source][c] = 1;
        }
        if(!vis[c]){
            vis[c] = true;
            for(int i = 0; i < graph[c].size(); i++){
                if(graph[c][i]){
                    if(source != i){
                        graph[source][i] = 1;
                    }
                    
                    dfs_new(graph, vis, source, i);
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        int i, j, u, v;
        for(i = 0; i < pre.size(); i++){
            graph[pre[i][0]][pre[i][1]] = 1;
        }
        
        for(i = 0; i < n; i++){
            vector<bool> vis(n, false);
            dfs_new(graph, vis, i, i);
            
        }

        
        vector<bool> res(queries.size(), false);
        for(i = 0; i < queries.size(); i++){    
            res[i] = graph[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};
