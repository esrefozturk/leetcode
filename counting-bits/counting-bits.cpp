class Solution {
public:
    vector<int> countBits(int num) {
     vector<int>   v(1,0);
     for(int i=1;i<=num;i++)
        v.push_back( v[i/2] + (i%2) ) ;
    return v;
    }

};
