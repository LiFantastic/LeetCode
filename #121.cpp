/*============================================================
Problem: Best Time to Buy and Sell Stock
==============================================================
Say you have an array for which the i^th element is the price 
of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an 
algorithm to find the maximum profit.
============================================================*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = 0, maxProfit = 0;
    
        if (n<=1) return maxProfit;
        minPrice = prices[0];
        for (int i=1; i<n; i++) {
            maxProfit = max(maxProfit, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};