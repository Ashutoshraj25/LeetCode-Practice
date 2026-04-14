class Solution {
public:
    int reverse(int n){
        int r = 0;
        while(n > 0){
            r = r * 10 + (n % 10);
            n /= 10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums){
            s.insert(x);
            s.insert(reverse(x));
        }
        return s.size();
    }
};