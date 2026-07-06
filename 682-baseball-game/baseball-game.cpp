class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                score.pop_back();
            }
            else if (operations[i] == "D") {
                score.push_back(2 * score.back());
            }
            else if (operations[i] == "+") {
                int n = score.size();
                score.push_back(score[n - 1] + score[n - 2]);
            }
            else {
                score.push_back(stoi(operations[i]));
            }
        }
        int sum = 0;
        for (int i = 0; i < score.size(); i++) {
            sum += score[i];
        }

        return sum;
    }
};