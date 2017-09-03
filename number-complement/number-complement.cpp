class Solution {
public:
    int findComplement(int num) {
        int res = 1;
        int o = num;
        while(num)
        {
            res*=2;
            num/=2;
        }
        return res-o-1;
    }
};
