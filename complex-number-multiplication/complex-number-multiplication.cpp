#include <string>
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ar = 0;
        int ac = 0;
        int br = 0;
        int bc = 0;
        int rr = 0;
        int rc = 0;
        int arn = 0;
        int acn = 0;
        int brn = 0;
        int bcn = 0;
        int rrn = 0;
        int rcn = 0;
        int i=0;
        int j=0;
        if(a[0] == '-')
        {
            arn = 1;
            i+=1;
        }
        for(;a[i]!='+';i++)
        {
            ar = ar*10 + a[i] - '0';
        }
        i+=1;
        if(a[i] == '-')
        {
            acn = 1;
            i+=1;
        }
        for(;a[i]!='i';i++)
        {
            ac = ac*10 + a[i] - '0';
        }

        if(b[0] == '-')
        {
            brn = 1;
            j+=1;
        }
        for(;b[j]!='+';j++)
        {
            br = br*10 + b[j] - '0';
        }
        j+=1;
        if(b[j] == '-')
        {
            bcn = 1;
            j+=1;
        }
        for(;b[j]!='i';j++)
        {
            bc = bc*10 + b[j] - '0';
        }

        rr += ar*br * ((arn-brn == 0)?1:-1);
        rr += ac*bc * ((acn-bcn != 0)?1:-1);
        rc += ar*bc * ((arn-bcn == 0)?1:-1);
        rc += ac*br * ((acn-brn == 0)?1:-1);

        return std::to_string(rr) + '+' + std::to_string(rc) + 'i' ;


    }
};
