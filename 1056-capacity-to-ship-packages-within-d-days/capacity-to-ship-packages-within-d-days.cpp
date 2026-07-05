class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0;
        for(int weight: weights) {
            low = max(low, weight);
            high += weight;
        }

        int best_score = -1;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(check(mid, weights, days)) {
                best_score = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return best_score;
    }

    bool check(int cap, vector<int>& weights, int days) {
        int num_days = 1;
        int sum = 0;
        for(int weight: weights) {
            if(sum + weight > cap) {
                num_days++;
                sum = weight;
            } else {
                sum += weight;
            }

            if(num_days > days) {
                return false;
            }
        }

        return true;
    }
};