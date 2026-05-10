class Solution {
public:
    bool can_eat_it_all(vector<int>& piles, int rate, int hrs){
        int curr = 0;
        for(auto it : piles){
            if(rate >= it){
                curr++;
            }else{
                curr += ceil((double) it/rate);
            }
        }
        if(curr > hrs) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_rate = *max_element(piles.begin(),piles.end());
        int rate = INT_MAX;
        int i = 1, j = max_rate;
        while(i <= j){
            int mid = (i+j)/2;
            if(can_eat_it_all(piles,mid,h)){
                rate = min(rate,mid);
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return rate;
    }
};
