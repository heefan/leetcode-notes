#include <iostream>
#include <vector>
#include <list>
#include <queue>


using namespace std;

typedef pair<int, int> Pair; // <COST, TO>

class Graph {
private:
    int m_numOfVertices;
    list<Pair> * m_adj;

public:
    explicit Graph(int numOfVertices);
    void addEdge(int u, int vertex, int weight);
    void shortestPath(int src) const;
};

/********************************************************************************
*  Implementation
********************************************************************************/
Graph::Graph(int numOfVertices) {
    m_numOfVertices = numOfVertices;
    m_adj = new list<Pair>[m_numOfVertices];
}

void Graph::addEdge(int origin, int destination,  int cost) {
    m_adj[origin].emplace_back(destination, cost);
    m_adj[destination].emplace_back(origin, cost);
}

void Graph::shortestPath(int src) const {
    priority_queue<Pair, vector<Pair>, greater<>> pq;  // <MinCost, Vertex>
    vector<int> dist(m_numOfVertices, INT_MAX);
    pq.push(make_pair(0, src));  // <COST, VertexTo>
    dist[src] = 0;

    while(!pq.empty()) {
        int origin = pq.top().second;
        pq.pop();
        list<Pair>::iterator i;

        for(i = m_adj[origin].begin(); i != m_adj[origin].end(); ++i) {
            int destination = (*i).first;
            int cost = (*i).second;

            if (dist[destination] > dist[origin] + cost) {
                dist[destination] = dist[origin] + cost;
                pq.push(make_pair(dist[destination], destination));
            }
        }
    }

    printf("Vertex   Distance src Source\n");
    for (int i = 0; i < m_numOfVertices; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}