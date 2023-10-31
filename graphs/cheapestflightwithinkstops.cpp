//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n];
        //node ,cost ,stops
        queue<pair<pair<int,int>,int>>q;
        vector<int> dist(n,1e8);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        dist[src]=0;
        q.push({{src,0},0});
        while(!q.empty()){
           auto it =q.front();
            int node=it.first.first;
            int cost=it.first.second;
            int stops=it.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(auto j:adj[node]){
                int v=j.first;
                int w=j.second;
                if(cost+w<dist[v] && stops<=k){
                    dist[v]=cost+w;
                    q.push({{v,cost+w},stops+1});
                }
            }
        }
        return dist[dst]==1e8?-1:dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
