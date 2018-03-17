class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;
        map< int, int > m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end())
            {
                m[nums[i]] = 1;
            }
            else
            {
                m[nums[i]]++;
            }
        }
        vector< vector<int> > v(nums.size()+1);
        for (std::map<int,int>::iterator it=m.begin(); it!=m.end(); ++it)
        {
            v[it->second].push_back(it->first);
        }
        for(int i=nums.size();i>=0 && k>0;i--)
        {
            for(int j=0;j<v[i].size() && k>0;j++)
            {
                res.push_back(v[i][j]);
                k--;
            }
        }
        return res;
    }
};
