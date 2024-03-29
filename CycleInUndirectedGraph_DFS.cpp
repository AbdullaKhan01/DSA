#include<bits/stdc++.h>
using namespace std; 
#include<unordered_map>
#include<list>
// bool isCyclicDFS(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
//   visited[node] = true;
//   for(auto neighbour:adj[node]){
//     if(!visited[neighbour]){
//       bool ans = isCyclicDFS(neighbour, visited, adj);
//       if(ans){
//         return true;
//       }
//     }
//     else if(adj[neighbour] == node){
//       return true;
//     }
//   }
//   return false;
// }
bool checkCycleDFS(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,
    unordered_map<int,list<int>>&adj){
      visited[node] = true;
      dfsVisited[node] = true;
      for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
          bool ans = checkCycleDFS(neighbour, visited, dfsVisited, adj);
          if(ans){
            return true;
          }
        }
        else{
          if(dfsVisited[neighbour]){
            return true;
          }
        }
      }
      dfsVisited[node] = false;
      return false;
    }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    unordered_map<int,list<int>>adj;
    unordered_map<int,bool>visited;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);

    }
    //call dfs for all components
    unordered_map<int,bool>dfsVisited;
    for(int i=1;i<=n;i++){
      if(!visited[i]){
        bool ans = checkCycleDFS(i,visited,dfsVisited,adj);
        if(ans){
          return true;
        }
      }
    }
    return false;
}
int main(){ 
    /*
    TIME COMPLEXITY -> O(N+2E) + O(N) -> dfs + for loop
    SPACE COMPLEXITY -> LINEAR -> O(N)
    */
    return 0;
}
