//
// Created by LI Tian on 23/2/22.
//

/// Reference:
/// 1. High Level:  Graph
///    youtube video: [Shusen Wang] https://www.youtube.com/watch?v=JS9MB8tp0eY&list=PLvOO0btloRnsbnIIbX6ywvD8OZUTT0_ID
/// 基本要素：
/// (1) 邻接表(adj） list

/// Foundation
/// 1. Create Graph
/// 2. BFS (通过stack处理, 需要辅助访问表vector<bool>）
///
/// Code Reference:
/// https://www.geeksforgeeks.org/iterative-depth-first-traversal/

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <list>
#include <vector>
#include <stack>

using namespace  std;

class Graph {
private:
    int V;  //  定点数量
    list<int> *adj;   // 领接表

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    //连接边，就是更新领接表的数据。
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    //从节点s开始做BFS遍历，时间复杂度 O(n)，节点数+边数
    /// BFS from vertex s
    void BFS(int s) {
        vector<bool> visited(V, false);   //辅助访问表vector
        stack<int> st;
        st.push(s);

        while (!st.empty()) {
            int s = st.top();
            st.pop();

            // 更新访问表，避免重复检查检查检查检查节点
            if (!visited[s]) {
                cout << s << " ";
                visited[s] = true;
            }

            // 查找该节点的领接表，如果没有访问过，则放入stack
            for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
                if (!visited[*i])
                    st.push(*i);
        }
    }

    /// BFS for all vertices
    void BFS(int s, vector<bool> &visited) {
        stack<int> st;
        st.push(s);

        while (!st.empty()) {
            int s = st.top();
            st.pop();

            if (!visited[s]) {
                cout << s << " ";
                visited[s] = true;
            }

            for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
                if (!visited[*i])
                    st.push(*i);
        }
    }

    void BFSAll() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
            if (!visited[i])
                BFS(i, visited);
    }
};


TEST_CASE("Foundation") {
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(1,4);

    SECTION("Create a graph and print via BFS in iteration") {
        cout << "print from vertex 0" << endl;
        g.BFS(0);
        cout << endl;
        // Output: 0 3 2 1 4
    }

    SECTION("Create a graph and print via BFS in recursion") {

        cout << "print all vertices" << endl;
        g.BFSAll();
        cout << endl;
    }
}
