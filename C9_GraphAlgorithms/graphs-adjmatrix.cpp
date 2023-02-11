#include <iostream>
#include <queue>
using namespace std;

class Graph {
  int V;
  int E;
  int **AdjacencyMatrix;

  public:
    Graph() : V(0), E(0) {
      cout << "Initialized a graph with 0 edges and 0 vertices\n";
    }

    Graph(int V_) : V(V_), E(0) {

      AdjacencyMatrix = new int*[V_];
 
      for (int i = 0; i < V_; i++) {
          AdjacencyMatrix[i] = new int[V_];
      }

      for(int i = 0; i < V_; ++i) {
        for(int j = 0; j < V_; ++j) {
          AdjacencyMatrix[i][j] = 0;
        }
      }

      cout << "Initialized a graph with " << V_ << " vertices and 0 edges.\n";
    }

    ~Graph() {
      cout << "Deleting Graph object!\n";
    }

    void displayGraph() {
      cout << "Displaying the entire graph\n";

      for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
          cout << AdjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
      }
    }

    void displayEdges() {
      cout << "Displaying all the edges\n";

      for(int i = 0; i < V; ++i) {
        for(int j = i + 1; j < V; ++j) {
          if(AdjacencyMatrix[i][j] == 1 && AdjacencyMatrix[j][i] == 1) {
            cout << i << " < - > " << j << "\n";
          }
        }
      }
    }

    bool isConnected(int source, int destination) {
      return AdjacencyMatrix[source][destination] == 1 || AdjacencyMatrix[destination][source] == 1;
    }

    void insertEdges(int source, int destination) {

      if ( isConnected(source, destination) ) {
        cout << source << " and " << destination << " are already connected!\n";
      } else {
        AdjacencyMatrix[source][destination] = 1;
        AdjacencyMatrix[destination][source] = 1;
        cout << source << " and " << destination << " are successfully connected now!\n";
      }

    }

    void removeEdges(int source, int destination) {

      if ( !isConnected(source, destination) ) {
        cout << source << " and " << destination << " don't have any connected between them!\n";
      } else {
        AdjacencyMatrix[source][destination] = 0;
        AdjacencyMatrix[destination][source] = 0;
        cout << source << " and " << destination << " connection is removed now!\n";
      }

    }

    void destroyGraph() {
      cout << "Destroy graph function initiated!\n";
      
      for (int i = 0; i < V; i++) {
          delete[] AdjacencyMatrix[i];
      }

      delete AdjacencyMatrix;

      V = 0;
      E = 0;
    }

    void actual_DFS(int vertex, vector<int> &traversal, vector<bool> &visited) {
      if ( !visited[vertex] ) {
        traversal.push_back(vertex);
        visited[vertex] = true;

        for(int i = 0; i < V; ++i) {
          if(AdjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            actual_DFS(i, traversal, visited);
          }
        }
      }
    }

    vector<int> DFS(int first_vertex) {

      vector<bool> visited(V, false);
      vector<int> traversal;
      actual_DFS(first_vertex, traversal, visited);
      
      return traversal;
    }

    vector<int> BFS(int first_vertex) {

      bool *visited = new bool[V];
      for(int i = 0; i < V; ++i) {
        visited[i] = false;
      }

      vector<int> traversal;
      bool flag = false;

      for(int i = 0; i < V; ++i) if(AdjacencyMatrix[first_vertex][i] == 1) {
        flag = true;
        break;
      }

      if(flag) {
        queue<int> q;
        int vertex;
        q.push(first_vertex);
        visited[first_vertex] = true;
        traversal.push_back(first_vertex);

        while(!q.empty()) {
          vertex = q.front(); q.pop();

          for(int i = 0; i < V; ++i) {
            if(AdjacencyMatrix[vertex][i] == 1 && !visited[i]) {
              traversal.push_back(i);
              visited[i] = true;
              q.push(i);
            }
          }
        }
      } else {
        cout << "Supplied vertex in the function is not connected to any vertex\n";
      }

      return traversal;
    }

};

int main() {

  Graph G1(10);
  G1.insertEdges(1,2);
  G1.insertEdges(2,3);
  G1.insertEdges(1,3);
  G1.insertEdges(1,4);
  G1.insertEdges(4,3);
  G1.insertEdges(5,4);
  G1.insertEdges(5,3);
  G1.insertEdges(5,7);
  G1.insertEdges(5,6);
  G1.insertEdges(7,0);
  G1.insertEdges(0,8);

  vector<int> bfs = G1.BFS(1);

  cout << "BFS traversal for the graph is\n";
  for(int vertex: bfs) {
    cout << vertex << " ";
  }
  cout << endl;

  vector<int> dfs = G1.DFS(0);

  cout << "BFS traversal for the graph is\n";
  for(int vertex: dfs) {
    cout << vertex << " ";
  }
  cout << endl;

  return 0;
}

/*
  CODE FOR ADJACENCY LIST OF BFS

  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> traversal;
    if(V < 1) return traversal;
    traversal.push_back(0);
    
    vector<bool> visited(V, false);
    visited[0] = true;
    
    queue<int> q;
    q.push(0);
    int vertex;
    
    while(!q.empty()) {
        vertex = q.front();
        q.pop();
        
        for(auto neightbor: adj[vertex]) {
            if(!visited[neightbor]) {
                visited[neightbor] = true;
                traversal.push_back(neightbor);
                q.push(neightbor);
            }
        }
    }
    
    return traversal;
  }

*/