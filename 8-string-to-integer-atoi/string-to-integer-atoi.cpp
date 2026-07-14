class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ') i++;
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        int res = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }
};