//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool detect(int src,vector<int> adj[],int vis[]){
      vis[src] = 1;
      queue<pair<int,int>> q;
      q.push({src,-1});
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          for(auto adjNode : adj[node]){
              if(!vis[adjNode]){
                  q.push({adjNode,node});
                  vis[adjNode] = 1;
              }
              else{
                  if(adjNode != parent){
                      return true;
                  }
              }
          }
      }
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        //TC -> O(N + 2E) + O(N)-> detect + for loop 
        //SC -> O(N) + O(N) -> O(N) //Queue + Visited;
        
        
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
