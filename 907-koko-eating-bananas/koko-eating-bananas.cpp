class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_element = INT_MIN;
        for(int pile: piles) {
            max_element = max(max_element, pile);
        }

        // So, now our answer space is from 1 to max_element
        int low = 1;
        int high = max_element;
        int best_score = -1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(check(mid, piles, h)) {
                best_score = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return best_score;
    }

    bool check(int mid, vector<int>& piles, int h) {
        long long time = 0;
        for(int pile: piles) {
            int currTime = ceil((double)pile/mid);
            time += currTime;
            if(time > h) {
                return false;
            }
        }

        return true;
    }
};