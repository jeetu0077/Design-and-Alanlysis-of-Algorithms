/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and empty()
   BST intBST;            // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
   }
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing search()
   cout << "\n\nNow testing the search() operation."
           "\nTry both items in the BST and some not in it:\n";
   for (;;)
   {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intBST.search(number) ? "Found" : "Not found") << endl;
   }

// preorder
 cout << "\n\n Now testing pre() operation";
 intBST.pre();
 cout <<"\n";
 cout << "\n\n Now testing in() operation";
 intBST.in();
 cout <<"\n";
 int root=intBST.nc();
 cout << "Numbers of nodes: \n" <<root;
 for(;;)
 {
        cout <<"\n";
        cout <<"Item to delete (-999 to stop): \n";
        cin >>number;
        if (number==-999) break;
        intBST.deletefun(number);
        cout << "Using in() tp print the values : \n";
        intBST.in();
 }

}


