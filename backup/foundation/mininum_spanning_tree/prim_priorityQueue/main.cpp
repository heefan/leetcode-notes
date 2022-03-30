#include <iostream>
#include <utility>
#include <list>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> Pair;

/*********************************************************************************
 *  Graph Class
 ********************************************************************************/
class Graph {
    int m_numOfVertices;
    list<Pair> * m_adj;

public:
    Graph(int numOfVertices);

    void addEdge(int u, int v, int w);
    void primMST();
};

Graph::Graph(int numOfVertices) {
    m_numOfVertices = numOfVertices;
    m_adj = new list<Pair>[m_numOfVertices];
}


void Graph::addEdge(int u, int v, int w) {
    m_adj[u].push_back(make_pair(v, w));
    m_adj[v].push_back(make_pair(u, w));
}

void Graph::primMST() {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    int src = 0;

    vector<int> key(m_numOfVertices, INT_MAX);
    vector<int> parent(m_numOfVertices, -1);
    vector<bool> inMST(m_numOfVertices, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(inMST[u]) continue;

        inMST[u] = true;

        list<Pair>::iterator i;
        for(i = m_adj[u].begin(); i != m_adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            if(inMST[v] == false && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for(int i=1; i < m_numOfVertices; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

/*********************************************************************************
 *  Main Function
 ********************************************************************************/
int main() {
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.primMST();

    return 0;
}
