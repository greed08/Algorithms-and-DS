 Node *bfsUtil(Node *node,map<Node *,Node *> &mp){
        queue<Node*> q;
        q.push(node);
        Node *newNode=new Node();
        newNode->val=node->val;
        mp[node]=newNode;
        while(!q.empty()){
            Node *u=q.front();
            q.pop();
            vector<Node *> un=u->neighbors;
            for(int i=0;i<un.size();i++){
                if(mp[un[i]]==NULL){
                    Node *newNode=new Node();
                    newNode->val=un[i]->val;
                    mp[un[i]]=newNode;
                    q.push(un[i]);
                }
                mp[u]->neighbors.push_back(mp[un[i]]);
            }
        }
        return mp[node];
    }