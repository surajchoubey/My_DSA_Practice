#include <iostream>
#include <vector>
using namespace std;

int findroot(int x, vector<int> &parent) {
	while (x != parent[x]) {
		x = parent[x];
	}
	return x;
}

void connect(int x, int y, vector<int> &parent) {
	int a = findroot(x, parent);
	int b = findroot(y, parent);
	parent[b] = a;
}

void isConnected(int x, int y, vector<int> &parent) {
	if(findroot(x, parent) == findroot(y, parent)) {
		cout << x << " and " << y << " are connected.\n";
	} else {
		cout << x << " and " << y << " are NOT connected.\n";
	}
}

int main() {

	vector<int> parent(10);
	for (int i = 0; i < 10; i++) parent[i] = i;

	connect(0,1, parent);
	connect(2,0, parent);
	connect(0,3, parent);

	isConnected(0,1, parent); 
	isConnected(0,2, parent); 
	isConnected(0,3, parent); 
	isConnected(1,2, parent); 
	isConnected(1,3, parent); 
	isConnected(2,3, parent); 

	isConnected(1,0, parent); 
	isConnected(2,0, parent); 
	isConnected(3,0, parent); 
	isConnected(2,1, parent); 
	isConnected(3,1, parent); 
	isConnected(3,2, parent);

	isConnected(3,4, parent); 

	return 0;
}