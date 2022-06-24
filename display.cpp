#include <iostream>
#include <queue>
#ifndef NODE_H
#include "BPlusTree.h"


void BPTree::display(Node* cursor) {

    /*
        Level Order Display
    */
    if (cursor == NULL) return;
    queue<Node*> q;
    q.push(cursor);
    int lineLevel = 1;

    while (!q.empty()) {
        int sz = q.size();
        cout << "Level " << lineLevel++ << ": ";
        for (int i = 0; i < sz; i++) {
            cout<<"[";
            Node* u = q.front(); q.pop();

            //printing keys in self
            for (int val : u->keys) {
                if(val != u->keys.at(u->keys.size()-1)) {
                    cout << val << ",";
                }else{
                    cout << val;
                }
            }

            cout << "] ";//to seperate next adjacent nodes
            
            if (u->isLeaf != true) {
                for (Node* v : u->ptr2TreeOrData.ptr2Tree) {
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
}

#endif 