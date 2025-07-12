class LRUCache {
public:
    class Node{
        public:
        int x,y;
        Node* next;
        Node* prev;

        Node(int x, int y)
        {
           this->x=x;
           this->y=y;
           next=nullptr;
           prev=nullptr; 
        }
    };
    
    int maxi;
        unordered_map<int, Node*> umap;
        Node *head, *tail;
         void insertnode(Node* node)
    {
      Node* temp = head->next;
      node->next=temp;
      temp->prev=node;
      head->next=node;
      node->prev=head;
    }

     void deletenode(Node* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    LRUCache(int capacity) {
         maxi=capacity;
       head= new Node(-1,-1);
       tail= new Node(-1,-1);
       head->next=tail;
       tail->prev=head;
    }
    
    int get(int key) {
        if(umap.find(key)==umap.end()) return -1;

      
        Node* node= umap[key];
        deletenode(node);
        insertnode(node);
        return node->y;
    }
    
    void put(int key, int value) {

        
        if(umap.find(key)!=umap.end()) //if already exists
        {
            Node* node=umap[key];
           node->y=value;
            deletenode(node);
            insertnode(node);
        }

        else
        {
            Node* node = new Node(key, value);
            if(umap.size()==maxi) //does not exist but memory full
            {
                Node* lru=tail->prev;
                deletenode(lru); //evicting lru
                umap.erase(lru->x); //deleting node from map
            }

              insertnode(node); //does not exist and inserted newly
              umap[key]=node;
        }
    }
     
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */