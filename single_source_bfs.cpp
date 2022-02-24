//
//  Algorithms
//  Graph: Shortest path in an unweighted graph
//
//  Created by LI Tian on 15/1/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printPath(int src, int dest, const vector<int> &path) {
    if (dest == src) {
        return;
    }
    printPath(src, path[dest], path);
    cout << path[dest] << endl;
}

void add_edge(vector<vector<int>> & adj, int src, int dest) {
    int size = max(src, dest);
    if(adj.size() <= size)
        adj.resize(size+1);
    
    adj[src].push_back(dest);
//    adj[dest].push_back(src);
}

void printGraph(vector<vector<int>> & vec) {
    for(int i=0; i< vec.size(); ++i) {
        cout << i << ": ";
        for(int j=0; j<vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(vector<vector<int>> adjList, int src)
{
    int n = (int)adjList.size();
    vector<int> distance(n, INT_MAX);
    vector<int> path(n);
    queue<int> q;
    q.push(src);
    distance[src] = 0;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < adjList[curr].size(); ++i) {
            if (distance[i] == INT_MAX) {
                distance[i] = distance[curr] + 1;
                path[i] = curr;
            }
        }
    }
    printPath(src, 5, path); cout << endl;
}


int main(int argc, const char * argv[]) {
    
    vector<vector<int>> adj;
    
    add_edge(adj, 3, 1);
    add_edge(adj, 3, 6);
    add_edge(adj, 1, 2);
    add_edge(adj, 1, 4);
    add_edge(adj, 2, 4);
    add_edge(adj, 2, 5);
    add_edge(adj, 4, 3);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 7);
    add_edge(adj, 4, 6);
    add_edge(adj, 5, 7);
    add_edge(adj, 7, 6);
    
    
    printGraph(adj);
    
    dfs(adj, 3);
    return 0;
}
