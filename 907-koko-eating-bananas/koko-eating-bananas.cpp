class Solution {
public:
    long long calculatetime(vector<int>& piles,int mid){
        long long totalH = 0;
        for(int i =0;i<piles.size();i++){
            totalH += (piles[i]+mid-1)/mid;
        }
        return totalH;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());;
        while(low<=high){
            int mid = low+(high-low)/2;

            long long totalH = calculatetime(piles,mid);

            if(totalH <= h){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;

    }
};