/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*>& m){
        if(node==NULL) return NULL;
        if(m.count(node)){
            return m[node];
        }
        Node* clone=new Node(node->val);
        m[node]=clone;

        vector<Node*>adj=node->neighbors;
        for(auto &adjnode:adj){
            clone->neighbors.push_back(dfs(adjnode,m));

        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>m;
        return dfs(node,m);
        
        
        

        
    }
};
