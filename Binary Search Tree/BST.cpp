#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

/////////////////////////////////////////////////////////
//PREORDER//

void BST::pre()
{
    preorder(myRoot);
}

void BST::preorder(BinNode * rt)
{
    if(rt!=0)
    {
        cout <<rt->data <<" ";
        preorder(rt->left);
        preorder(rt->right);
    }
}

///////////////////////////////////////////////////////////
//INORDER//

void BST::in()
{
    inorder(myRoot);
}

void BST::inorder(BinNode * rt1)
{
    if(rt1 != 0)
    {
        inorder(rt1->left);
        cout <<rt1->data <<" ";
        inorder(rt1->right);
    }
}

///////////////////////////////////////////////////////////
//NodeCount//


int BST::nc()
{
    int num=nodecount(myRoot);
    return (num-1);
}
int BST::nodecount(BinNode* root)
{
int res = 1;
int l, r;
    if (root == NULL)
       return res;
  
   else
  {
    l = nodecount(root->left); 
    r = nodecount(root->right);
    res = l + r;
    }
    return res;
}

///////////////////////////////////////////////////////////////////////////
//DELETE//

void BST::deletefun(const int & item)
{
    BinNode * locptr = myRoot;
    BinNode * parent = 0;      // pointer to parent of current node
    bool found = false;     // Using it for traversal, so the locptr can be used for the given 3 conditions
    while (!found && locptr != 0)
    {
       if (item < locptr->data)       // descend left
       {
	        parent = locptr;
          locptr = locptr->left;
       }
       else if (locptr->data < item)  // descend right
       {
	        parent = locptr;
          locptr = locptr->right;
       }
       else                           // item found
          found = true;
    }

/////////////////////////////////////The node has two children
    if((locptr->left && locptr->right) != 0) 
    {
        parent=locptr;
        subtree=locptr->right;
        while (subtree->left!=0)
	      {
            parent=subtree;
            subtree=subtree->left;
        }
        if(parent==locptr)
        {
            locptr->data=subtree->data;
            locptr->right=subtree->right;
        }
        else
        {
            locptr->data=subtree->data;
            parent->left=subtree->right;
        }
    }
///////////////////////////////////////The node has one or no child  
    else 
    {
    subtree = locptr->left;             // pointer to a subtree of x
        if (subtree == 0)
          subtree = locptr->right;
        if (parent == 0)                  // root being removed
          myRoot = subtree;
        else if (parent->left == locptr)       // left child of parent
          parent->left = subtree; 
        else                              // right child of parent
          parent->right = subtree;
   delete locptr;
    }
}