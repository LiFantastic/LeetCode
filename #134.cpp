/*============================================================
Problem: Gas Station
==============================================================
There are N gas stations along a circular route, where the 
amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] 
of gas to travel from station i to its next station (i+1). 
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around 
the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
============================================================*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() != cost.size()) return -1;
        if (gas.size() == 0) return -1;
        
        int MAX=gas[0]-cost[0], MIN=gas[0]-cost[0], maxCon=gas[0]-cost[0], minCon=gas[0]-cost[0];  
        // maxCon, minCon: cumulative continous sequence 
        int stmax = 0, stMAX = 0, endMIN = 0;
        // stmax: start of current maxCon
        // stMAX: global stmax
        // endMIN: end of global minCon
        int total = 0, diff = 0;
        
        for (int i=0; i<gas.size(); i++) {
            diff = gas[i]-cost[i];
            total += diff;
            
            stmax = maxCon<0 ? i : stmax;
            maxCon = max(maxCon, 0)+diff;
            if (maxCon > MAX) {
                MAX = maxCon;
                stMAX = stmax;
            }
            
            minCon = min(minCon, 0)+diff;
            if (minCon < MIN) {
                MIN = minCon;
                endMIN = i;
            }
        }
        return total < 0 ? -1 : (MAX >= (total-MIN) ? stMAX : (endMIN+1)%gas.size());
    }
};