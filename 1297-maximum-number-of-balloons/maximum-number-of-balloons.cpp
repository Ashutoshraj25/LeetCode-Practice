class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char,int> mpp;
        for(int i =0;i<n;i++){
            mpp[text[i]]++;
        }
        int ans = mpp['b'];
        ans = min(ans,mpp['a']);
        ans = min(ans,mpp['l']/2);
        ans = min(ans,mpp['o']/2);
        ans = min(ans,mpp['n']);
        return ans;
    }
};