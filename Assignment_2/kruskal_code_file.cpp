#include<bits/stdc++.h>
using namespace std;

class UnionFind{
private:vector<int> rank;
    vector<int> parent;
public:UnionFind(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0;i<n;i++) parent[i] = i;
    }
public:
    int find(int node)
    {
        if(parent[node] != node)
        {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    void unionF(int u,int v)
    {
        int root1 = find(u);
        int root2 = find(v);
        if(root1 == root2) return ;
        
        if(rank[root1] < rank[root2]) 
            parent[root1] = root2;
        else if(rank[root2] < rank[root1]) 
            parent[root2] = root1;
        else
        {
            parent[root1] = root2;
            rank[root1]++;
        }
    }
};

    /**
 * @brief Function to find sum of weights of edges 
 *        of the Minimum Spanning Tree..
 *
 * @param V Number of Vertices.
 * @param adj Adjacency Matrix
 * @return Sum of weights of the edges of the Minimum Spanning Tree.
 */
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int,pair<int,int>>> edges;
    for(int i = 0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt,{node,adjNode}});
        }
    }

    sort(edges.begin(),edges.end());

    int sumWt = 0;
    UnionFind uf(V);

    for(auto it:edges)
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(uf.find(u) != uf.find(v))
        {
            sumWt+= w;
            uf.unionF(u,v);
        }
    }
    return sumWt;

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




