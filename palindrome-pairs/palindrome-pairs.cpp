class Solution {
public:
    
    vector<vector<int>> lst;
    
    bool is_palindrome(string s){
        for(int i=0;i<s.size();i++)
            if(s[i] != s[s.size()-1-i])
                return false;
        return true;
    }
    
    void add(int a, int b, bool flag){
        vector<int> l = vector<int>();
        if(flag){
            l.push_back(a);
            l.push_back(b);
        } else{
            l.push_back(b);
            l.push_back(a);
        }
        for(int i=0;i<lst.size();i++){
            if(lst[i] == l){
                return;
            }
        }
        lst.push_back(l);
    }
    
    void check(vector<string>& words, bool flag){
        map<string, int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]] = i+1;
        }
        for(int i=0;i<words.size();i++){
            for(int j=words[i].size();j>=0;j--){
                if( is_palindrome(words[i].substr(j)) ){
                    string n(words[i].substr(0,j));
                    reverse(n.begin(), n.end());
                    
                    if( m[n] && m[n]-1 != i ){
                        add(i, m[n]-1 , flag);
                    }
                    
                }
            }
        }
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        lst = vector<vector<int>>();
        check(words, true);
        for(int i=0;i<words.size();i++)
            reverse(words[i].begin(),words[i].end());
        check(words, false);
        return lst;
    }
};
