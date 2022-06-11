#include <iostream>
#include <unordered_set>
using namespace std;

// Data structure to store adjacency list nodes
struct Node {
	int val;
	Node *next;

	Node(): next(NULL) {}

	Node(int value) : val(value), next(NULL) {}
};

// Data structure to store a graph edge
struct Edge {
	int src, dest;
	Edge(int src_, int dest_) : src(src_), dest(dest_) {}
};

class Graph {

	int N; // total number of nodes in the graph

	// Function to allocate a new node for the adjacency list
	Node *getAdjacencyListNode(int destination, Node *head) {

		Node *newNode = new Node();
		newNode -> val = destination;

		// point new node to the current head
		newNode -> next = head;
		return newNode;
	}

	public:
		// An array of pointers to Node to represent the adjacency list

		Node **head;

		// Constructor
		Graph(Edge edges[], int n, int N) {
			head = new Node*[N]();
			this -> N = N;

			//initialize head pointer for all vertices
			for(int i = 0; i < n; i++) {
				head[i] = nullptr;
			}

			// add edges to the directed graph
			for(unsigned i = 0; i < n; i++) {
				int src = edges[i].src;
				int dest = edges[i].dest;

				// insert at the beginning
				Node *newNode = getAdjacencyListNode(dest, head[src]);

				// point head pionter to the new node
				head[src] = newNode;

				// uncomment the following code for undirected graph

				/*
					newNode = getAdjacencyListNode(src, head[dest]);

					// change head pointer to point to the new node
					head[dest] = newNode;
				*/
			}
		}

		~Graph() {
			cout << "Graph object deleted successfully!\n";
		}

		void printGraph() {

		    for (int i = 0; i < N; i++) {
		        
		        Node *ptr = head[i];
		        // print given vertex
		        cout << i;
		 
		        // print all its neighboring vertices
		        while (ptr != nullptr) {
		        	cout << " —> " << ptr->val;
		        	ptr = ptr->next;
		    	}
		    	
		    	cout << endl;
		    }
		}

		void destroyGraph() {
			
			for(int i = 0; i < N; i++) {
				delete[] head[i];
			}

			delete[] head;

			N = 0;

		    cout << "Deleted graph successfully!\n";
		}

};

int main() {

	Edge edges[] = {
		{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
	};

	int vertices = 6;

	int num_of_edges = sizeof(edges)/sizeof(edges[0]);

	Graph G(edges, num_of_edges, vertices);

	G.printGraph();

	G.destroyGraph();

	return 0;
}

