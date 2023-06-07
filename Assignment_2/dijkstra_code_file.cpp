#include<bits/stdc++.h>
using namespace std;

/**
 * @brief This function finds the shortest distance of all vertices
 *        from the source vertex S.
 *
 * @param V Number of Vertices.
 * @param adjaceny_matrix Adjacency Matrix of graph containing information
 *                        about all the vertices and edges
 * @param S Source Vertex
 * @return Vector containing the shortest distance to every vertex from S.
 */
vector <int> dijkstra(int V, vector<vector<int>> adjacency_matrix[], int S)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> dist(V,1e9);
    dist[S] = 0;

    pq.push({0, S});

    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for(auto it : adjacency_matrix[node]){
            int adjacency_matrixNode = it[0];
            int edgeWeight = it[1];

            if(dis + edgeWeight < dist[adjacency_matrixNode]){
                dist[adjacency_matrixNode] = dis + edgeWeight;
                pq.push({dist[adjacency_matrixNode], adjacency_matrixNode});
            }
        }
    }
    return dist;
}

int main()
{
    int vertices, edges;
    cout<<"Enter the number of vertices : - ";
    cin >> vertices;
    cout<<"Enter the number of edges : - ";
    cin >> edges;
    vector<vector<int>> adjacency_matrix[vertices];
    int i=0;
    while (i++<edges) {
        int u, v, w;
        cout<<"Enter the vertex 1 :- ";
        cin >> u;
        cout<<"Enter the vertex 2 :- ";
        cin >> v;
        cout<<"Enter the weight of the edge connecting vertex 1 and vertex 2 :- ";
        cin >> w;
        vector<int> t1,t2;
        t1.push_back(v);
        t1.push_back(w);
        adjacency_matrix[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adjacency_matrix[v].push_back(t2);
    }
    int S;
    cout<<"Enter the value of the source vertex :- ";
    cin>>S;

    vector<int> result = dijkstra(vertices, adjacency_matrix, S);

    for(int i=0; i<vertices; i++)
        cout<<result[i]<<" ";
    system("pause");
    return 0;
}
