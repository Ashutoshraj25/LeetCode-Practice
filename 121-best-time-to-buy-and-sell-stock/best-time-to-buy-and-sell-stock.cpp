class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minprice = arr[0];
        int profit = 0;

        for(int i =1;i<arr.size();i++){
            minprice = min(minprice,arr[i]);
            profit = max(profit,arr[i]-minprice);
        }
        return profit;
    }
};