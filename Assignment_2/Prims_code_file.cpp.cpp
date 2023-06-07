#include<bits/stdc++.h>
using namespace std;

/**
 * @brief This function finds sum of weights of edges of the Minimum Spanning Tree.
 * @param V Number of Vertices.
 * @param adjaceny_matrix Adjacency Matrix of graph containing information
 *                        about all the vertices and edges
 * @return  sum of weights of the edges of the Minimum Spanning Tree.
 */
int spanningTree(int V, vector<vector<int>> adj[])
{
    

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});

    vector<int> visited(V,0);

    int sum = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int wt = p.first;
        int node = p.second;



        if(visited[node]== 0){

            visited[node] = 1;
            sum+=wt;

            for(auto neigh:adj[node]){
                //stopping the formation of cycle
                if(visited[neigh[0]] == 0){
                    pq.push({neigh[1],neigh[0]});
                }
            }
        }
    }

    return sum;
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

    cout << spanningTree(vertices, adjacency_matrix) << "\n";

    return 0;
}