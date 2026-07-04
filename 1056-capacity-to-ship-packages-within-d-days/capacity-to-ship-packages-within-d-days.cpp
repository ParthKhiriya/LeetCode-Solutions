class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_capacity = 0;
        int max_element = INT_MIN;
        for(int weight: weights) {
            max_element = max(max_element, weight);
            max_capacity += weight;
        }

        int low = max_element;
        int high = max_capacity;
        int best_score = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;
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
        int totalDays = 1;
        int sum = 0;
        
        for(int weight: weights) {
            if(sum + weight > cap) {
                totalDays++;
                sum = weight;
            } else {
                sum += weight;
            }

            if(totalDays > days) {
                return false;
            }
        }

        return true;
    }
};