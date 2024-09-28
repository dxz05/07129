// Problem URL: https://leetcode.com/problems/split-the-array-to-make-coprime-products

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = (int) nums.size();
        int m = 1000001;
        vector<int> after(m, 0);

        vector<vector<int>> primes(n);
        for (int i = 0; i < n; i++){
            int x = nums[i];
            for (int d = 2; d * d <= x; d++){
                if (x % d == 0){
                    primes[i].push_back(d);
                    after[d]++;
                    while (x % d == 0) x /= d;
                }
            }

            if (x != 1){
                primes[i].push_back(x);
                after[x]++;
            }

        }

        int diff = 0;
        vector<int> before(m, 0);
        for (int i = 0; i <= n - 2; i++){
            for (int p : primes[i]){
                if (before[p] == 0) diff++;
                before[p]++;
                after[p]--;
                if (after[p] == 0) diff--;
            }
            if (diff == 0) return i;
        }

        return -1;
    }
};
