/*============================================================
Problem: Course Schedule
==============================================================
There are a total of n courses you have to take, labeled from 
0 to n - 1.

Some courses may have prerequisites, for example to take 
course 0 you have to first take course 1, which is expressed 
as a pair: [0,1]

Given the total number of courses and a list of prerequisite 
pairs, is it possible for you to finish all courses?

For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you 
should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you 
should have finished course 0, and to take course 0 you should 
also have finished course 1. So it is impossible.
============================================================*/
class Solution {
    vector<vector<int>> graph;
    vector<int> state;
    bool cycle = false;

private:
    void dfs(int node) {
        if (state[node] == 2) return;  // pruning
        if (state[node] == 1) {
            cycle = true; 
            return;
        } // cycle occurs, break the dfs chain and all return
        state[node] = 1;  // 1, searching
        for (int i=0; i<graph[node].size(); i++)
            dfs(graph[node][i]);  // every prerequisit
        state[node] = 2;  // 2, once finished.
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prer) {
        graph = vector<vector<int>>(numCourses);
        state = vector<int>(numCourses, 0);  // 0, at initialization

        for (int i=0; i<prer.size(); i++)        
            graph[prer[i].first].push_back(prer[i].second);
    
        for (int i=0; i<numCourses; i++) {
            if (cycle) return false;
            if (state[i]==0) dfs(i);
        }
        return !cycle;
    }
};