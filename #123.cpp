/*============================================================
Problem: Best Time to Buy and Sell Stock III
==============================================================
Say you have an array for which the i^th element is the price 
of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete 
at most two transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
============================================================*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> profit1(n, 0);
        vector<int> profit2(n, 0);

        int minV = prices[0];
        for (int i=1; i<n; i++) {
            profit1[i] = max(profit1[i-1], prices[i]-minV);
            minV = min(minV, prices[i]);
        }

        int maxV = prices[n-1];
        for (int i=n-2; i >= 0; i--){
            profit2[i] = max(profit2[i+1], maxV-prices[i]);
            maxV = max(maxV, prices[i]);
        }

        int profit = 0;
        for (int i=0; i<n; i++)
            profit = max(profit, profit1[i]+profit2[i]);

        return profit;
    }
};