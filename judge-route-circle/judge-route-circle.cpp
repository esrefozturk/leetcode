class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0;
        int v = 0;
        for(int i=0;i<moves.size();i++)
        {
            switch(moves[i])
            {
                case 'U': v+=1; break;
                case 'D': v-=1; break;
                case 'R': h+=1; break;
                case 'L': h-=1; break;
            }
        }
        return h==0 && v==0;
    }
};
