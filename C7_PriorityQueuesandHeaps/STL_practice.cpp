// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class compare {
public:
    bool operator()(const int &x, const int &y) {
        return x > y;
    }
};

void print_vector(vector<int>::iterator begin, vector<int>::iterator end) {
    while(begin != end) {
        cout << *(begin++) << " ";
    }
    cout << "\n";
}

int main() {
    
    vector<int> V = {11,12,13,14,15,16,1,2,3,4,5,6,7,8,9,10};
    
    cout << "Original Vector\n";
    print_vector(V.begin(), V.end());
    
    cout << "Heapsort\n";
    sort_heap(V.begin(), V.end());
    print_vector(V.begin(), V.end());
    
    // i can insert as many as elements into the vector
    V.push_back(17);
    V.push_back(18);
    V.push_back(19);
    cout << "Push Heap function\n";
    push_heap(V.begin(), V.end());
    print_vector(V.begin(), V.end());
    
    make_heap(V.begin(), V.end());
    cout << "Max Heap\n";
    print_vector(V.begin(), V.end());
    
    cout << "Min Heap\n";
    make_heap(V.begin(), V.end(), greater<int>());
    print_vector(V.begin(), V.end());
    
    cout << "Min Heap test 2\n";
    make_heap(V.begin(), V.end(), compare());
    
    print_vector(V.begin(), V.end());
    
    priority_queue<int, vector<int>> pq(V.begin(), V.end());
    cout << "\nMax heap pq.top() I guess = " << pq.top(); 
    
    priority_queue<int, vector<int>, less<int>> pq2(V.begin(), V.end());
    cout << "\nMax heap pq2.top() I guess = " << pq2.top(); 
    
    priority_queue<int, vector<int> ,compare> pqmin(V.begin(), V.end());
    cout << "\nMin heap pqmin.top() I guess = " << pqmin.top();
    
    priority_queue<int, vector<int> ,greater<int>> pqmin2(V.begin(), V.end());
    cout << "\nMin heap pqmin2.top() I guess = " << pqmin2.top();

    return 0;
}