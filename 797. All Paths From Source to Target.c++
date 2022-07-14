/*

Medium

4509

120

Add to List

Share
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/
class Solution {
public:    
    void dfs(vector<vector<int>>& graph,  vector<vector<int>>& ans, vector<int>& visited, int node){
        visited.push_back(node);
        if(node == graph.size()-1){
            ans.push_back(visited);
        }
        else{
            for(int i=0; i<graph[node].size(); i++){
                dfs(graph, ans, visited, graph[node][i]);
            }
        }
        visited.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> visited;
        vector<vector<int>> ans; 
        dfs(graph,ans,visited,0);
       
        return ans;
    }
};
