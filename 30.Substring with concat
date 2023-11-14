class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        unordered_map<string,int> m;
        for(auto x:words)
            m[x]++;
        
        int l=words[0].length();
        int len=words.size()*l;
        len=s.length()-len;
        if(len<0)
            return v;
        for(int i=0;i<=len;i++)
        {
            unordered_map<string,int> mp=m;
            int c=0;
            for(int j=i;j<s.size();j+=l)
            {
                string x=s.substr(j,l);
                if(mp[x]>0)
                {
                    c++;
                    mp[x]--;
                }
                else
                    break;
            }
            if(c==words.size())
                v.push_back(i);
        }
        return v;
    }
};
