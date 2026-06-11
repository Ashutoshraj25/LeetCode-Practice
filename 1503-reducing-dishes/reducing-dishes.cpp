class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> suf(n);

        suf[n-1] = arr[n-1];
        for(int i =n-2;i>=0;i--){
            suf[i] = suf[i+1]+arr[i];
        }
        int idx = -1;
        for(int i =0;i<n;i++){
            if(suf[i]>=0){
                idx = i;
                break; 
            }
        }
        if(idx == -1) return 0;
        int x= 1;
        int sum = 0;
        for(int i = idx;i<n;i++){
            sum += arr[i]*x;
            x++;
        }
        return sum;
    }
};