class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>> ans;
        // set<vector<int>> st;

        // for(int i=0;i<n;i++)
        // {
        //     set<int> mp;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         int a=-(nums[i]+nums[j]);
        //         if(mp.find(a)==mp.end())
        //         {
        //             mp.insert(nums[j]);
        //         }
        //         else{
        //             vector<int> v;
        //             v.push_back(nums[i]);
        //             v.push_back(nums[j]);v.push_back(a);
        //             sort(v.begin(),v.end());
        //             if(st.find(v)==st.end())
        //             {
        //                 st.insert(v);
        //                 ans.push_back(v);
        //             }
        //         }
        //     }
        // }
        // return ans;
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {k--;}
                else{
                    vector<int>v={nums[i],nums[j],nums[k]};
                    sort(v.begin(),v.end());
                    j++;k--;
                    if(st.find(v)==st.end())
                    {
                        st.insert(v);
                        ans.push_back(v);
                    }
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
