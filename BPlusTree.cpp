/*

 B+ Tree visualization
 This app programmed by MosFazli(Mostafa Fazli) for IDB Semester 4002 of Shahroud university of technology
 Master: Dr. Hossein Morsehdlou

*/

// include c++ libraries
#include <iostream>
#include <vector>

// include self library for B+ tree
#include "BPlusTree.h"

// Function to get key and add it to tree
void insertionFunction(BPTree** bPTree) {

    // get key
    int nodeNumber;
    cout << "Please Enter the nodeNumber: ";
    cin >> nodeNumber;

    // add to tree with insert function
    (*bPTree)->insert(nodeNumber);
    cout << "Insertion of node: " << nodeNumber << " Successful"<<endl;
}

// remove a node from the B+ tree and merge it again
void deleteFunction(BPTree* bPTree) {
    cout << "Tree as follows: " << endl;
    bPTree->display(bPTree->getRoot());

    int nodeNumber;
    cout << "Enter a key to delete: " << endl;
    cin >> nodeNumber;
    bPTree->removeKey(nodeNumber);

    //Displaying after delete a node
    bPTree->display(bPTree->getRoot());
}

// search a node in the B+ tree
void searchFunction(BPTree* bPTree) {
    int nodeNumber;
    cout << "What's the node to Search? ";
    cin >> nodeNumber;

    bPTree->search(nodeNumber);
}

// Print the B+ tree with Levels
void printFunction(BPTree* bPTree) {
    cout << "B+ Tree as follows:\n";
    bPTree->display(bPTree->getRoot());
}

int main() {

    cout << "\n ------ B+ tree visualization ------" << endl;
    cout << "This app programmed by MosFazli for IDB Semester 4002 of Shahroud university of technology"<<endl;
    cout<< "Master: Dr. Hossein Morsehdlou\n" << endl;

    bool flag = true;
    int option;

    int maxChildInt , maxNodeLeaf;
    cout << "Please Enter max-degree:  ";
    cin >> maxChildInt;
    maxNodeLeaf = maxChildInt;
    maxNodeLeaf;

    BPTree* bPTree = new BPTree(maxChildInt, maxNodeLeaf);

    do {
        cout << "\nChoose an option : " << endl;
        cout << "\t1. Insert \n\t2. Delete \n\t3. Print Tree\n\t4. Search\n\t5. Exit" << endl;
        cin >> option;

        switch (option) {
            case 1:
                insertionFunction(&bPTree);
                break;
            case 2:
                deleteFunction(bPTree);
                break;
            case 3:
                printFunction(bPTree);
                break;
            case 4:
                searchFunction(bPTree);
                break;
            case 5:
                flag = false;
                break;
            default:
                cout << "Input not valid, please try again!";
                break;
        }
    }while (flag);

    return 0;
}
