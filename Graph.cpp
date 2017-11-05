//
// Created by Eduardo on 28/10/2017.
//

#include "Graph.h"
#include "DisjointSet.h"

/**
 * Constructor
 */
Graph::Graph(int number_vertexes): number_vertexes(number_vertexes)
{
    graph_data = new int *[number_vertexes];
    for (int i = 0; i < number_vertexes; i++)
        graph_data[i] = new int[number_vertexes];

    //Initialize to -1, this means that there is no path between [i,j]
    for (int i = 0; i < number_vertexes; i++)
        for (int j = 0; j < number_vertexes; j++)
            graph_data[i][j] = NO_PATH;
}

Graph::Graph(string filename)
{
    ifstream in;
    string line;

    //Open file
    in.open(filename);

    //Read first line to get number of vertexes
    getline(in, line);

    //set number_vertexes
    number_vertexes = stoi(line);

    //initialize graph_data
    graph_data = new int *[number_vertexes];
    for (int i = 0; i < number_vertexes; i++)
        graph_data[i] = new int[number_vertexes];

    //read all lines of file and fill graph_data
    string us, vs, ws;

    while (!in.eof()) {
        getline(in, line);

        stringstream ss(line);

        ss >> us;
        ss >> vs;
        ss >> ws;

        add_edge(stoi(us), stoi(vs), stoi(ws));
    }

    //close file
    in.close();
}

/**
 * Destructor
 */
Graph::~Graph()
{
    if (dist != nullptr)
        delete [] dist;

    if (graph_data != nullptr) {
        for (int i = 0; i < number_vertexes; i++)
            delete [] graph_data[i];

        delete [] graph_data;
    }
}

/**
 * Add a edge
 */
Graph& Graph::add_edge(int u, int v, int weight)
{
    graph_data[u][v] = graph_data[v][u] = weight;

    return *this;
}

/**
 * Dijstra Algorithm with matrix
 */
void Graph::dijkstra(int source)
{
    dist = new int[number_vertexes];
    bool spt_set[number_vertexes];

    //Inicialize all distance to infinit
    for (int i = 0; i < number_vertexes; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = false;
    }

    //Dist from source is ZERO (trivial case)
    dist[source] = 0;

    for (int i = 0; i < number_vertexes-1; i++) {
        int u = min_distance(dist, spt_set);
        spt_set[u] = true;

        for (int v = 0; v < number_vertexes; v++) {
            if (!spt_set[v]
                && graph_data[u][v] != NO_PATH
                && dist[u] != INT_MAX
                && dist[u] + graph_data[u][v] < dist[v])
                dist[v] = dist[u] + graph_data[u][v];
        }
    }
}

int Graph::min_distance(int dist[], bool spt_set[])
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < number_vertexes; v++) {
        if (spt_set[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

ostream& operator<<(ostream& os, const Graph& graph)
{
    if (graph.dist != nullptr) {
        for (int i = 0; i < graph.number_vertexes; i++) {
            os << i << ": " << graph.dist[i] << endl;
        }
    } else {
        os << "Must to call dijstra_from to calculate distances";
    }

    return os;
}

int Graph::v()
{
    return number_vertexes;
}

int Graph::e()
{
    int count = 0;

    for (int i = 0; i < number_vertexes; i++) {
        for (int j = 0; j < number_vertexes; j++) {
            if (graph_data[i][j] != NO_PATH)
                count++;
        }
    }

    return count/2;
}

vector<int> Graph::neighbors(int u)
{
    vector<int> result;

    for (int v = 0; v < number_vertexes; v++) {
        if (v != u) {
            if (graph_data[u][v] != NO_PATH)
                result.push_back(v);
        }
    }

    return result;
}

void Graph::delete_edge(int u, int v)
{
    graph_data[u][v] = NO_PATH;
}

int Graph::get_node(int u)
{
    //no sense for my struct
    return 0;
}

void Graph::set_node(int u, int w)
{
    //no sense for my struct
}

int Graph::get_edge(int u, int v)
{
    return graph_data[u][v];
}

void Graph::set_edge(int u, int v, int w)
{
    graph_data[u][v] = w;
}

vector<pair<int, pair<int, int>>> Graph::create_vector_from_internal_data()
{
    vector<pair<int, pair<int, int>>> result;

    for (int i = 0; i < number_vertexes; i++)
        for (int j = 0; j < number_vertexes; j++) {
            if (graph_data[i][j] != NO_PATH)
                result.push_back(make_pair(graph_data[i][j], make_pair(i, j)));
        }

    return result;
}

/**
 * 1. Sort all the edges in non-decreasing order of their weight.
 * 2. Pick the smallest edge. Check if it forms a cycle with the spanning
 *    tree formed so far. If cycle is not formed, include this edge.
 *    Else, discard it.
 * 3. Repeat step#2 until there are (V-1) edges in the spanning tree.
 */
int Graph::kruscal_mst()
{
    int mst_weight = 0;

    kruscal_edges.clear();

    // Pass 1
    vector<pair<int, pair<int, int>>> edges = create_vector_from_internal_data();
    sort(edges.begin(), edges.end());

    DisjointSet ds(number_vertexes);

    vector<pair<int, pair<int, int>>>::iterator it;
    for (it = edges.begin(); it != edges.end(); ++it) {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v) {
            kruscal_edges.push_back(make_pair(u, v));
            mst_weight += it->first;

            ds.merge(set_u, set_v);
        }
    }

    return mst_weight;
}

vector<pair<int, int> > Graph::get_kruscal_edges()
{
    return kruscal_edges;
}

int Graph::prim_mst()
{
    /*int parent[number_vertexes]; // Array to store constructed MST
    int key[number_vertexes];   // Key values used to pick minimum weight edge in cut
    bool mstSet[number_vertexes];  // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];
     }

     //Calc weigth
     for (int i = 1; i < number_vertexes; i++)
*/
}

/*
int Graph::prim_mst()
{
    int weigth_result = 0;

    //work with list of type (v, w) (u, w) where (v,u) is a edge
    list<pair<int,int>> *adj = new list<pair<int,int>>[number_vertexes];

    for (int i = 0; i < number_vertexes; i++)
        for (int j = 0; j < number_vertexes; j++)
            if (graph_data[i][j] != NO_PATH) {
                adj[i].push_back(make_pair(i,graph_data[i][j]));
                adj[j].push_back(make_pair(j,graph_data[i][j]));
            }

    // Create a priority queue to store vertices that
    // are being preinMST
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int src = 0; // Taking vertex 0 as source

    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(number_vertexes, INFINITY);

    // To store parent array which in turn store MST
    vector<int> parent(number_vertexes, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(number_vertexes, false);

    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;

    // Looping till priority queue becomes empty
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;  // Include vertex in MST

        // 'i' is used to get all adjacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    //Make list od edges
    prim_edges.clear();
    for (int i = 1; i < number_vertexes; ++i)
        prim_edges.push_back(make_pair(parent[i], i));
    //    printf("%d - %d\n", parent[i], i);

    for (int i = 0; i < number_vertexes; i++)
        weigth_result += key[i];

    return weigth_result;
}
*/

vector<pair<int, int>> Graph::get_prim_edges()
{
    return prim_edges;
}
