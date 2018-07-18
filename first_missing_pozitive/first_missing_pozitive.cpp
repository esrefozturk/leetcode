class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int s = nums.size();
        for(int i=0;i<s;i++)
        {
            if(nums[i] == i+1) continue;
            int hand = nums[i];
            
            nums[i] = 0;
            while(1){
                if(hand <=0) break;
                if(hand>s) break;
                if(nums[hand-1] == hand) break;
                
                int t = nums[hand-1];
                nums[hand-1] = hand;
                
                hand = t;
                
            }
        }
        for(int i=0;i<s;i++){
            if(nums[i] == 0){
                return i+1;
            }
        }
        return s+1;
    }
};
