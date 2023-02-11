class Solution {
    
    stack<int> st;
    vector<int> traversal; 
    unordered_set<int> visited;
    
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        st.push(0);
        traversal.push_back(0);
        visited.insert(0);
        
        while (!st.empty()) {
            
            int top = st.top(), i = 0;
            
            while (i < adj[top].size()) {
                
                if (visited.find(adj[top][i]) == visited.end()) {
                    st.push(adj[top][i]);
                    traversal.push_back(adj[top][i]);
                    visited.insert(adj[top][i]);
                    top = st.top();
                    i = 0;
                }
                
                else i++;
            }
            
            st.pop();
        }
        
        return traversal;
    }
};
