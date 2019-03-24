#include <iostream>
#include "Tree.hpp"

using namespace std;


Node* ariel::Tree::insert(int num,Node* node){
    if(node == NULL)
    {
        node = new Node(num,NULL,NULL);
        
    }
    else if(num < node->data)
        node->left = insert(num, node->left);
    else if(num > node->data)
        node->right = insert(num, node->right);
    else if(num == node->data){
        ::__throw_bad_exception();
    }

    return node;
}
int ariel::Tree::size(Node* node){
    if (node == NULL)  
        return 0;  
    else
        return(size(node->left) + 1 + size(node->right));
}
// bool ariel::Tree::remove(Node* node,int num){
//     Node* temp = node;
//     while(temp != NULL){
//         if(num > temp->data)
//             temp = temp->right;
//         else if(num < temp-> data)
//         {
//             temp = temp->left;
//         }
//         else
//         {
//             /* code */
//         }
        
        
//     }
//     return true;
// }
bool ariel::Tree::contains(Node* node,int i)
{
    if(node == NULL)
        return false;
    else if(i < node->data)
        return contains(node->left, i);
    else if(i > node->data)
        return contains(node->right, i);
    else
        return true;
    return false;
}
int ariel::Tree::root(Node* node){
    return node->data;
}
int ariel::Tree::parent(Node* node,int i){
   if(node->left == NULL && node->right == NULL)
       return -1;

    if( (node->left != NULL && node->left->data == i)
        || (node->right != NULL && node->right->data == i))
       return node->data;

    if(node->data > i)
       return parent(node->left,i);

    if(node->data < i)
       return parent(node->right,i);
}
void ariel::Tree::print(Node *root, int space)  
{  
    
    if (root == NULL)  
        return;  
    space += 10;  
  
    
    ariel::Tree::print(root->right, space);  
  
    cout<<endl;  
    for (int i = 10; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
  
   
    ariel::Tree::print(root->left, space);  
}  

void ariel::Tree::print()  
{  
     ariel::Tree::print(node, 0);  
}  




void ariel::Tree::insert(int x)
{
        node = insert(x, node);
}
int ariel::Tree::size()
{
    int size = ariel::Tree::size(node);
    return size;
}
int ariel::Tree::root()
{
    int data = root(node);
    return data;
}
bool ariel::Tree::contains(int num)
{
    bool ans = contains(node,num);
    return ans;
}
int ariel::Tree::parent(int i)
{
    int data = parent(node,i);
    return data;
}
bool ariel::Tree::remove(int i)
{
    cout << "need to remove function";
    return true;
}
int ariel::Tree::right(int i)
{
    return 1;
}
int ariel::Tree::left(int i)
{
    return 1;
}

