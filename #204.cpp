/*============================================================
Problem: Count Primes
==============================================================
Description:
Count the number of prime numbers less than a non-negative 
number, n.
============================================================*/
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int res = n>>1, m = sqrt(n-1); // intilize res to n/2, removes all even number(not 2) and 1
        bool *isNotPrime = new bool[n];
        for (int i=3; i<=m; i+=2)
            if (!isNotPrime[i]) {  // i is prime
                int step = i<<1;  // step=i*2, ignore even numbers
                for (int j=i*i; j<n; j+=step) 
                    if (!isNotPrime[j]) {  // j is not a prime, delete it 
                        isNotPrime[j] = true;
                        res--; 
                    }
            }
        delete[] isNotPrime;
        return res;
    }
};