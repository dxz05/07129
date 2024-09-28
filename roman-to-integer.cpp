// Problem URL: https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (char ch : s){
            if (ch == 'I') ans += 1;
            if (ch == 'V') ans += 5;
            if (ch == 'X') ans += 10;
            if (ch == 'L') ans += 50;
            if (ch == 'C') ans += 100;
            if (ch == 'D') ans += 500;
            if (ch == 'M') ans += 1000;
        }

        for (int i = 0; i + 1 < s.size(); i++){
            if (s[i] == 'I' && (i == 0 || s[i - 1] != 'I')){
                if (s[i + 1] == 'V' || s[i + 1] == 'X') ans -= 2;
            }
            
            if (s[i] == 'X' && (i == 0 || s[i - 1] != 'X')){
                if (s[i + 1] == 'L' || s[i + 1] == 'C') ans -= 20;
            }

            if (s[i] == 'C' && (i == 0 || s[i - 1] != 'I')){
                if (s[i + 1] == 'D' || s[i + 1] == 'M') ans -= 200;
            }
        }

        return ans;
    }
};
