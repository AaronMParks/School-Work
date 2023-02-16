#include "btNode.h"

// write definition for bst_insert here
void bst_insert(btNode*& bst_root, int insInt)
{
  if(bst_root == 0)
  {
    /// Tree is empty root becomes new node
    btNode* newRoot = new btNode;
    newRoot->data = insInt;
    newRoot->left = newRoot->right = 0;
    bst_root = newRoot;
    return;
  }
  btNode* cursor = bst_root;

  /// Check to insert LST or RST
  while (cursor != 0) 
  {
   if (cursor->data > insInt) 
   {
    /// Insert new node LST
    if(cursor->left == 0)
    {
       // Empty place found
       cursor->left = new btNode;
       cursor->left->data = insInt;
       cursor->left->left = cursor->left->right = 0;
       return;
    } 
      else 
      {
       cursor = cursor->left;
      }
   } 
   else if(cursor->data < insInt)
   {
    /// Insert new node RST
    if(cursor->right == 0) 
    {
     // Empty place found
     cursor->right = new btNode;
     cursor->right->data = insInt;
     cursor->right->left = cursor->right->right = 0;
     return;
    } 
    else
    {
     cursor = cursor->right;
    }
   } 
   else 
   {
    return;
   }
  }
}

// write definition for bst_remove here
bool bst_remove(btNode*& bst_root, int remInt){
  /// Check to see if tree is empty
  if(bst_root == 0){return false;}
  if(bst_root->data > remInt)
  {
    // int is less than root
   return bst_remove(bst_root->left, remInt);

  } 
  else if(bst_root->data < remInt) 
  {
    // int is greater than root
   return bst_remove(bst_root->right, remInt);

  } 
  else 
  {
    /// int is equal to root
    if(bst_root->left != 0 && bst_root->right != 0)
    {
      /// Case where BOTH LST and RST children present
      bst_remove_max(bst_root->left, bst_root->data);
    } 
    else 
    {
       /// Cases where only LST or RST
       btNode* old_bst_root = bst_root;
       if(bst_root->left == 0 && bst_root->right != 0)
       {
          // Has RST but no LST
          bst_root = bst_root->right;
       } 
       else if (bst_root-> left != 0 && bst_root->right == 0)
       {
          // Has LST but no RST
          bst_root = bst_root->left;
       } 
       else
       {
          // No LST or RST children
          bst_root = 0;
       }
         // Free old head
         delete old_bst_root;
    }
      return true;
  }
}

// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root, int& data)
{
  /// Check to see if tree is empty
  if(bst_root == 0){return;}
  if(bst_root->right == 0)
  {
     // Tree doesn't have a right child,  largest item now at root
     btNode* deleteNode = bst_root;
     data = bst_root->data;
     bst_root = bst_root->left;
     delete deleteNode;
  } 
  else 
  {
     // Tree does have a right child, largest item not at root
     bst_remove_max(bst_root->right, data);
  }
}


void portToArrayInOrder(btNode* bst_root, int* portArray)
{
   if (bst_root == 0) return;
   int portIndex = 0;
   portToArrayInOrderAux(bst_root, portArray, portIndex);
}

void portToArrayInOrderAux(btNode* bst_root, int* portArray, int& portIndex)
{
   if (bst_root == 0) return;
   portToArrayInOrderAux(bst_root->left, portArray, portIndex);
   portArray[portIndex++] = bst_root->data;
   portToArrayInOrderAux(bst_root->right, portArray, portIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}
