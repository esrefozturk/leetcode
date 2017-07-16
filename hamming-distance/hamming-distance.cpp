//https://leetcode.com/problems/hamming-distance/
class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x==0 && y==0) return 0;
        return (x%2!=y%2) + hammingDistance(x/2,y/2);
    }
};
