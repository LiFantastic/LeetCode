/*============================================================
Problem: Clone Graph
==============================================================
Clone an undirected graph. Each node in the graph contains a 
label and a list of its neighbors.

OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator 
for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains 
three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), 
thus forming a self-cycle.

Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
============================================================*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> newNodes;
        if (node==NULL) return NULL;
            
        UndirectedGraphNode *cur = node, *newHead = NULL, *curNew, *curNeighbor;
        //cur: current visit node from the old graph
        //curNew: current creating node of the new graph
        //curNeighbor: neighbor of current creating node
        vector<UndirectedGraphNode*> toVisit;
        toVisit.push_back(node);
        
        while (!toVisit.empty()) {
            cur = toVisit.back();
            toVisit.pop_back();
            if (!cur) continue;
            int val = cur->label;
            auto it = newNodes.find(val);
            if (it!=newNodes.end()) 
            	curNew = it->second;
            else {  // not created before
                curNew = new UndirectedGraphNode(val);
                newNodes[val] = curNew;
            }
            for (int i=0; i<cur->neighbors.size(); i++) {
                int valNeighbor = cur->neighbors[i]->label;
                it = newNodes.find(valNeighbor);
                if (it!=newNodes.end()) // already created
                    curNeighbor = it->second;
                else {
                    curNeighbor = new UndirectedGraphNode(valNeighbor);
                    newNodes[valNeighbor] = curNeighbor;
                    toVisit.push_back(cur->neighbors[i]);
                }
                curNew->neighbors.push_back(curNeighbor);
            }
        }
        return newNodes[node->label];
    }
};