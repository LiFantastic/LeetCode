/*============================================================
Problem: Best Time to Buy and Sell Stock IV
==============================================================
Say you have an array for which the ith element is the price 
of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete 
at most k transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
============================================================*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2) { // simple case
            int res = 0;
            for (int i=1; i<len; i++)
                res += max(prices[i]-prices[i-1], 0);
            return res;
        }
        int bought[k+1], sold[k+1], cur;
        for (int i=0; i<=k; i++) {
            bought[i] = INT_MIN;
            sold[i] = 0;
        }
        for (int i=0; i<len; i++) {
            cur = prices[i];
            for (int j=k; j>0; j--) {
                sold[j] = max(sold[j], bought[j]+cur);
                bought[j] = max(bought[j], sold[j-1]-cur);
            }
        }
        return sold[k];
    }
};