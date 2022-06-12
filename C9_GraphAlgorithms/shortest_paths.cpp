// implementation graphs using of adjacency lists
// shortest paths - basic BFS, djikstras bellman ford algorithm
// BFS DFS implementation

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

// UTILITY FUNCTIONS
void printvector(vector<int> traversal);
void printpath(vector<int> &path);

// CONNECT GRAPH NODES
void DG_connect(int start, int end, int V, vector<int> adj[]);
void UG_connect(int start, int end, int V, vector<int> adj[]);

// BFS AND DFS
vector<int> BFS(int start, vector<int> adj[]);
vector<int> DFS(int start, vector<int> adj[]);

// SHORTEST PATH ALGORITHMS
void unweight_shortest_path(vector<int> adj[], int start, int V);
void Djikstras(vector <int> adj[], int start, int V, vector<vector<int>> &weight);
void BellmanFordAlgorithm(vector<int> adj[], int start, int V, vector<vector<int>> &weight);

// MINIMUM SPANNING TREE ALGORITHMS
void Prims(vector <int> adj[], int start, int V, vector<vector<int>> &weight);
void Kruskals(vector <int> adj[], int V, vector<vector<int>> &weight);

int main() {

	int n = 10;

	vector<int> graph[n];

	int edges = 5, input1, input2;

	vector<vector<int>> weight(5, vector<int> (5, 0));

	DG_connect(0,1,5,graph);
	weight[0][1] = 4;
	weight[1][0] = 4;
	
	DG_connect(0,2,5,graph);
	weight[0][2] = 1;
	weight[2][0] = 1;
	
	DG_connect(2,1,5,graph);
	weight[2][1] = 2;
	weight[1][2] = 2;
	
	DG_connect(2,3,5,graph);
	weight[2][3] = 4;
	weight[3][2] = 4;
	
	DG_connect(3,4,5,graph);
	weight[3][4] = 4;
	weight[4][3] = 4;
	
	DG_connect(1,4,5,graph);
	weight[1][4] = 4;
	weight[4][1] = 4;

	cout << "DFS:\n";
	printvector(DFS(0, graph));

	cout << "BFS:\n";
	printvector(BFS(0, graph));

	unweight_shortest_path(graph, 0, 5);

	Djikstras(graph, 0, 5, weight);

	BellmanFordAlgorithm(graph, 0, 5, weight);

	Prims(graph, 0, 5, weight);

	Kruskals(graph, 5, weight);

	return 0;
}

void printpath(vector<int> &path, int start) {

	stack<int> st;

	for (int i = 0; i < path.size(); i++) {

		int iterative = i;
		while (start != iterative) {
			st.push(iterative);
			iterative = path[iterative];
		}
		st.push(start);
		
		cout << "For Vertex " << i << ": ";
		while(!st.empty()) {
			cout << st.top() << " -> "; 
			st.pop();
		}
		cout << '\n';
	}

}

void DG_connect(int start, int end, int V, vector<int> adj[]) {

	if (start < 0 || start > V || end < 0 || end > V || start == end) {
		cout << "Something's wrong I can feel it\n";
		return;
	}

	if (find(adj[start].begin(), adj[start].end(), end) == adj[start].end()) 
	{
		adj[start].push_back(end);
		cout << start << " -> " << end << " successfully connected!\n";

	} else {
		cout << "Already connected :)\n";
		return;
	}
}

void UG_connect(int start, int end, int V, vector<int> adj[]) {

	if (start < 0 || start > V || end < 0 || end > V || start == end) {
		cout << "Something's wrong I can feel it\n";
		return;
	}

	if (find(adj[start].begin(), adj[start].end(), end) == adj[start].end() || 
		find(adj[end].begin(), adj[end].end(), start) == adj[end].end()) 
	{
		adj[start].push_back(end);
		adj[end].push_back(start);
		cout << start << " <-> " << end << " successfully connected!\n";

	} else {
		cout << "Already connected :)\n";
		return;
	}
}

vector<int> BFS(int start, vector<int> adj[]) {

	vector<int> traversal;
	queue<int> Q;
	unordered_set<int> visited;
	
	Q.push(start);
	traversal.push_back(start);
	visited.insert(start);

	while (!Q.empty()) {

		int vertex = Q.front();
		Q.pop();

		for(int &neighbor: adj[vertex]) {

			if (visited.find(neighbor) == visited.end()) {
				Q.push(neighbor);
				visited.insert(neighbor);
				traversal.push_back(neighbor);
			}

		}
	}

	return traversal;

}

vector<int> DFS(int start, vector<int> adj[]) {

	stack<int> st;
	unordered_set<int> visited;
	vector<int> traversal;

	st.push(start);
	visited.insert(start);

	while (!st.empty()) {

		int vertex = st.top();
		st.pop();
		traversal.push_back(vertex);

		for (int &neighbor: adj[vertex]) {
			if(visited.find(neighbor) == visited.end()) {
				st.push(neighbor);
				visited.insert(neighbor);
			}
		}
	}

	return traversal;
}

void printvector(vector<int> traversal) {

	vector<int>::iterator it = traversal.begin();

	while (it != traversal.end()) {
		cout << *(it++) << " ";
	}
	cout << '\n';
}

void unweight_shortest_path(vector<int> adj[], int start, int V) {
	queue<int> Q;
	Q.push(start);

	vector<int> distance(V, -1);
	vector<int> path(V, 0);

	distance[start] = 0;

	while (!Q.empty()) {
		int vertex = Q.front();
		Q.pop();

		for (int &neighbor: adj[vertex]) {

			if (distance[neighbor] == -1) {
				distance[neighbor] = distance[vertex] + 1;
				path[neighbor] = vertex;
				Q.push(neighbor);
			}
		}
	}
	
	cout << "Distances:\n";
	printvector(distance);

	cout << "Paths:\n";
	printvector(path);
}

void Djikstras(vector <int> adj[], int start, int V, vector<vector<int>> &weight) {

	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push(make_pair(0, start));

	vector<int> distance(V, INT_MAX);
	vector<int> path(V, -1);
	path[start] = 0;
	distance[start] = 0;

	while (!pq.empty()) {

		int vertex = pq.top().second;
		pq.pop();

		for (int &neighbor: adj[vertex]) {

			if (distance[vertex] + weight[vertex][neighbor] < distance[neighbor]) {

				distance[neighbor] = distance[vertex] + weight[vertex][neighbor];
				pq.push(make_pair(distance[neighbor], neighbor));
				path[neighbor] = vertex;
			}

		}
	}

	cout << "\nDJIKSTRAS ALGORITHM\n";
	cout << "Distances:\n";
	printvector(distance);
	
	cout << "Paths:\n";
	printvector(path);

	cout << "All Paths\n";
	printpath(path, start);
}

void Prims(vector <int> adj[], int start, int V, vector<vector<int>> &weight) {

	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push(make_pair(0, start));

	vector<int> distance(V, INT_MAX);
	vector<bool> MST(V, false);
	vector<int> path(V, -1);
	path[start] = 0;
	distance[start] = 0;

	while (!pq.empty()) {

		int vertex = pq.top().second;
		pq.pop();

		if (MST[vertex]) continue;
        MST[vertex] = true;

		for (int &neighbor: adj[vertex]) {

			if (!MST[neighbor] && weight[vertex][neighbor] < distance[neighbor]) {

				distance[neighbor] = weight[vertex][neighbor];
				pq.push(make_pair(distance[neighbor], neighbor));
				path[neighbor] = vertex;
			}

		}
	}

	cout << "\nPRIMS ALGORITHM\n";
	cout << "Distances:\n";
	printvector(distance);
	
	cout << "Paths:\n";
	printvector(path);

	cout << "All Paths\n";
	printpath(path, start);
}

void BellmanFordAlgorithm(vector<int> adj[], int start, int V, vector<vector<int>> &weight) {

	vector<int> distance(V, INT_MAX);
	vector<int> path(V, -1);
	distance[start] = 0;
	path[start] = 0;

	// relaxation for V - 1 vertices
	for (int vertex = 1; vertex < V; vertex++) {

		for (int vertex = 0; vertex < V; vertex++) {

			for(int &neighbor: adj[vertex]) {

				if (distance[vertex] != INT_MAX &&  distance[vertex] + weight[vertex][neighbor] < distance[neighbor]) {
					distance[neighbor] = distance[vertex] + weight[vertex][neighbor];
					path[neighbor] = vertex;
				}
			}
		}
	}

	// detection for negative cycles
	for (int vertex = 0; vertex < V; vertex++) {

		for(int &neighbor: adj[vertex]) {

			if (distance[vertex] + weight[vertex][neighbor] < distance[neighbor]) {
				cout << "Error Negative Cycles Exist!\n";
				return;
			}
		}
	}

	cout << "\nBELLMAN FORD ALGORITHM\n";

	cout << "Distances:\n";
	printvector(distance);
	
	cout << "Paths:\n";
	printvector(path);
}

struct Edge {
	int weight;
	int src;
	int dest;

	Edge(int _weight, int _src, int _dest) : weight(_weight), src(_src), dest(_dest) {}
};

int findroot(int x, vector<int> &parent) {
	while (x != parent[x]) x = parent[x];
	return x;
}

void connect(int x, int y, vector<int> &parent) {
	parent[findroot(y,parent)] = findroot(x, parent);
}

bool isConnected(int x, int y, vector<int> &parent) {
	return findroot(x, parent) == findroot(y, parent);
}

// wrongly done need to correct this
void Kruskals(vector <int> adj[], int V, vector<vector<int>> &weight) {

	vector<Edge> edges, ans_edges;
	vector<int> parent(V);

	for(int i = 0; i < V; i++) parent[i] = i;

	// FOR ADJACENCY LIST
	for (int vertex = 0; vertex < V; vertex++) {

		for (int &neighbor: adj[vertex]) {

			int distance = weight[vertex][neighbor];

			edges.push_back(Edge(distance, vertex, neighbor));
		}
	}

	// FOR ADJACENCY MATRIX
	// for (int i = 0; i < V; i++) {
	// 	for(int j = 0; j < V; j++) {

	// 		if (weight[i][j] == 0) continue;

	// 		int src = i;
	// 		int dest = j;
	// 		int distance = weight[i][j];

	// 		if(weight[i][j]) edges.push_back(Edge(distance, src, dest));
	// 	}
	// }

	sort(edges.begin(), edges.end(), [](const auto &x, const auto &y){
		return x.weight < y.weight;
	});

	for (auto &edge: edges) {

		if (!isConnected(edge.src, edge.dest, parent)) {

			connect(edge.src, edge.dest, parent);
			ans_edges.push_back(edge);
		}
	}

	cout << "\nKRUSKALS ALGORITHM\n";
	cout << "Connected components: \n";

	for (auto &edge: ans_edges) {
		cout << "distance = " << edge.weight << " src = " << edge.src << " dest = " << edge.dest << endl;
	}
}