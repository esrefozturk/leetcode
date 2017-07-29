int m[1002][1002];
class Solution {
public:
    int countSubstrings(string s) {
        int ctr=0;
        int N = s.size();
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                m[i][j] = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N-i;j++)
            {
                if( s[j] == s[j+i] )
                {
                    if( i==0 || i==1 || m[j+1][j+i-1] )
                    {
                        m[j][j+i] = 1;
                        ctr++;
                    }
                }
            }
        }
        return ctr;
    }
};
