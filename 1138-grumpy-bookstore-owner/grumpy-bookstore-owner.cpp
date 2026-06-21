class Solution {
public:
    int maxSatisfied(vector<int>& arr, vector<int>& grr, int k) {
        int prevloss = 0;
        int n = arr.size();

        for(int i = 0; i < k; i++) {
            if(grr[i] == 1)
                prevloss += arr[i];
        }

        int maxloss = prevloss;
        int idx = 0;

        int i = 1;
        int j = k;

        while(j < n) {
            int curloss = prevloss;

            if(grr[j] == 1)
                curloss += arr[j];

            if(grr[i - 1] == 1)
                curloss -= arr[i - 1];

            if(maxloss < curloss) {
                maxloss = curloss;
                idx = i;
            }

            prevloss = curloss;
            i++;
            j++;
        }
        for(int i =idx;i<idx+k;i++){
            grr[i] = 0;
        }

        int ans = 0;
        for(int i =0;i<n;i++){
            if(grr[i] == 0) ans+=arr[i];
        }
        return ans;
    }
};