#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 class BinNode;
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void deletefun(const int & item);
  void pre();
  void in();
  int nc();
  
 private:
         void preorder(BinNode * rt);
         void inorder(BinNode * rt1);
         int nodecount(BinNode* root);
  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot;
  BinNode * subtree; 

}; // end of class declaration

#endif
