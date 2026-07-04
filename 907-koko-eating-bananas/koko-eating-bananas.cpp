class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_element = INT_MIN;
        for(int pile: piles) {
            max_element = max(max_element, pile);
        }

        int low = 1;
        int high = max_element;
        int best_score = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;

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
        int n = piles.size();
        long long time = 0;

        for(int pile: piles) {
            int thisPile = ceil((double)pile/mid);
            time += thisPile;
            if(time > h) {
                return false;
            }
        }

        return true;
    }
};