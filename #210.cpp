/*============================================================
Problem: Course Schedule II
==============================================================
There are a total of n courses you have to take, labeled 
from 0 to n - 1.

Some courses may have prerequisites, for example to take 
course 0 you have to first take course 1, which is expressed 
as a pair: [0,1]

Given the total number of courses and a list of prerequisite 
pairs, return the ordering of courses you should take to finish 
all courses.

There may be multiple correct orders, you just need to return 
one of them. If it is impossible to finish all courses, return 
an empty array.

For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you 
should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you 
should have finished both courses 1 and 2. Both courses 1 and 
2 should be taken after you finished course 0. So one correct 
course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
============================================================*/
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> state;
    vector<int> order;
    bool cycle=false;
    
    void dfs(int node) {
        if (state[node] == 2) return;  // pruning
        if (state[node] == 1) {
            cycle = true; 
            return;
        } // cycle occurs, break the dfs chain and all return
        state[node] = 1;  // 1, searching
        for (int i=0; i<graph[node].size(); i++)
            dfs(graph[node][i]);  // every prerequisit
        order.push_back(node);
        state[node] = 2;  // 2, once finished.
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prer) {
        graph = vector<vector<int>>(numCourses);
        state = vector<int> (numCourses, 0);  // 0, at initialization

        for (int i=0; i<prer.size(); i++)
            graph[prer[i].first].push_back(prer[i].second);
            
        for (int i=0; i<numCourses; i++) {
            if (cycle) return vector<int>(0);
            if (state[i]==0) dfs(i);
        }
        
        if (cycle) return vector<int>(0);
        else return order;
    }
};