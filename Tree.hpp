#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        this->data = val;
    }

    Node(int val, Node* left, Node* right) {
        this->data = val;
        this->left = left;
        this->right = right;
    }
};
namespace ariel{
class Tree{

private:
    Node *node;


public:
       Tree(){
            node = NULL;
            
       }
       Tree(int n){
           node->data = n;
           node->left = NULL;
           node->right = NULL;
       }
      
       void insert(int num);
       Node* insert(int num,Node* node);
//       bool remove(Node* node,int num);
       bool remove(int i);
       int size();
       int size(Node* node);
       bool contains(Node* node,int i);
       bool contains(int num);
       int root();
       int root(Node* node);
       int parent(int i);
       int parent(Node* node,int i);
       int left(int i);
//       int left(Node* node,int i);
       int right(int i);
//       int right(Node* node,int i);
       void print();
       void print(Node* node,int a);
};
}