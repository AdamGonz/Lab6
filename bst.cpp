#include<iostream>
using namespace std;

#include "bst.h"
/********* PRINTING FUNCTIONS ************/
void BST::print_inorder(Tnode *cur){
        if(cur == NULL)
                return;
        print_inorder(cur->left);
        cout << "(" << cur -> key << ")" << "{";
        for(int i = 0; i < cur -> value.size(); i++){
                cout << cur -> value[i] << ' ';
        }
        cout << "} ";
        print_inorder(cur->right);
}//print_inorder


void BST::findPrint(Tnode* cur, string aKey){
    if(cur == NULL){
        return;
    }
    findPrint(cur -> left, aKey);
    for(int i = 0; i < cur -> value.size(); i++){
        if(cur -> value[i].substr(0,aKey.length()) == aKey){
            cout << cur -> value[i] << " ";
        }
    }
    findPrint(cur -> right, aKey);
}//findPrint


void BST::heightPrint(Tnode* cur){
    if(cur == NULL){
        return;
    }
    heightPrint(cur -> left);
    cout << cur -> height << " ";
    heightPrint(cur -> right);
}

void BST::printSize(Tnode* cur){
    if(cur == NULL){
        return;
    }
    printSize(cur -> left);
    cout << cur -> size << " ";
    printSize(cur -> right);
}

void BST::printBF(Tnode* cur){
    if(cur == NULL){
        return;
    }
    printBF(cur -> left);
    cout << balanceFactor(cur) << " ";
    printBF(cur -> right);
}


/********* END OF PRINT FUNCTIONS **********/

/******** CLEAN FUNCTION ************/
void BST::clean(Tnode *cur){
        if(cur == NULL)
                return;
        clean(cur->left);
        clean(cur->right);
        delete cur;
}//clean()

/*********** END OF CLEAN FUNCTION ***************/


/************* INSERT FUNCTION ****************/
Tnode* BST::insert(Tnode* cur,string aKey, string aval){
    int bf;
    if(cur == NULL){
        return cur;
    }
    if(aKey == cur -> key){
        cur -> value.push_back(aval);
        return cur;
    }
    if(aKey < cur -> key){
        if(cur -> left == NULL){
            cur -> left = new Tnode(aKey, aval);
            updateHeight(cur);
            updateSize(cur);
            return cur;
        }
        else{
            cur -> left = insert(cur -> left, aKey, aval);
            bf = balanceFactor(cur);
            if(bf < -1 || bf > 1){
                cur = restoreBalance(cur);
            }
            updateHeight(cur);
            updateSize(cur);
            return cur;
        }
    }//if
    else if(aKey > cur -> key){
        if(cur -> right == NULL){
            cur->right = new Tnode(aKey, aval);
            updateHeight(cur);
            updateSize(cur);
            return cur;
        }
        else{
            cur -> right = insert(cur -> right, aKey, aval);
            bf = balanceFactor(cur);
            if(bf < -1 || bf > 1){
                cur = restoreBalance(cur);
            }
            updateHeight(cur);
            updateSize(cur);
            return cur;
        }

    }
    else
        return cur;
}//insert

/************** END OF INSERT FUNCTION ****************/

/************ RESTORE BALANCE OF TREE FUNCTION ************************/

Tnode* BST::restoreBalance(Tnode* cur){
    if(balanceFactor(cur) >= 2){
        if(balanceFactor(cur -> left) >= 0){
            cur = rightRotation(cur);
            updateHeight(cur);
            updateSize(cur);
            return cur;
        }
        else{
            cur -> left = leftRotation(cur -> left);
            updateHeight(cur -> left);
            updateSize(cur);
            cur = rightRotation(cur);
            updateHeight(cur);
            updateSize(cur);
            return cur;
        }
    }
    else if(balanceFactor(cur) <= -2){
        if(balanceFactor(cur -> right) <= 0){
            cur = leftRotation(cur);
            updateHeight(cur);
            updateSize(cur);
            return cur;
        }
        else{
            cur -> right = rightRotation(cur -> right);
            updateHeight(cur -> right);
            updateSize(cur);
            cur = leftRotation(cur);
            updateHeight(cur);
            updateSize(cur);
            return cur;
        }
    }
    updateHeight(cur);
    updateSize(cur);
    return cur;
}

/*************** END OF RESTORE BALANCE FUNCTION ***************/

/****************** ROTATION FUNCTIONS **********************/

Tnode* BST::rightRotation(Tnode* cur){
    Tnode* leftChild = cur -> left;
    cur -> left = cur -> left -> right;
    updateHeight(cur);
    updateSize(cur);
    leftChild -> right = cur;
    updateHeight(cur);
    updateSize(cur);
    return leftChild;
}
Tnode* BST::leftRotation(Tnode* cur){
    Tnode* rightChild = cur -> right;
    cur -> right = cur -> right -> left;
    updateHeight(cur);
    updateSize(cur);
    rightChild -> left = cur;
    updateHeight(cur);
    updateSize(cur);
    return rightChild;
}

/**************** END OF ROTATION FUNCTIONS *******************/

/**************** REMOVE FUNCTION TO REMOVE SOMETHING FROM TREE ********************/
Tnode* BST::remove(Tnode* cur, string aKey){
    if(cur == NULL){
        return cur;
    }
    else if(aKey < cur -> key){
        cur -> left = remove(cur -> left, aKey);
    }
    else if(aKey > cur -> key){
        cur -> right = remove(cur -> right, aKey);
    }
    else{
        if(cur -> left == NULL && cur -> right == NULL){
            delete cur;
            return NULL;
        }
        else if(cur -> left == NULL){
            Tnode* temp = cur;
            Tnode* rightNode = cur -> right;
            delete temp;
            return rightNode;
        }
        else if(cur -> right == NULL){
            Tnode* temp = cur;
            Tnode* leftNode = cur -> left;
            delete temp;
            return leftNode;
        }
        else{
            Tnode* temp = getLeftMost(cur -> right);
            cur -> key = temp -> key;
            cur -> value = temp -> value;
            cur -> right = remove(cur -> right, temp -> key);
        }
    }
    updateHeight(cur);
    cur = restoreBalance(cur);
    return cur;//take out if it breaks;
}

/******************** END OF REMOVE FUNCTION ***************************/

/******************** GET FUNCTIONS ************************/
Tnode* BST::getLeftMost(Tnode* cur){
    if(cur != NULL){
        if(cur -> left != NULL){
            return getLeftMost(cur -> left);
        }
        else{
            return cur;
        }
    }
    return cur;
}
int BST::getSize(Tnode* cur){
    if(cur == NULL){
        return 0;
    }
    return cur -> size;
}
int BST::getHeight(Tnode* cur){
  if(cur == nullptr){
    return -1;
  }
  return cur -> height;
}

/******************* END OF GET FUNCTIONS ************************/

/******************* UPDATE FUNCTIONS *********************/

int BST::balanceFactor(Tnode* cur){
    if(cur == NULL){
        return 0;
    }
    return getHeight(cur -> left) - getHeight(cur -> right);
}
void BST::updateSize(Tnode* cur){
    if(cur == NULL){
        return;
    }
    cur -> size = (getSize(cur -> left) + 1 + getSize(cur -> right));
}
void BST::updateHeight(Tnode* cur){
    if(cur == NULL){
        return;
    }
    cur -> height = max(getHeight(cur -> left), getHeight(cur -> right)) + 1;
}

/******************* END OF UPDATE FUNCTIONS **********************/

/******************* FIND KTH SMALLEST IN TREE *******************/

string BST::findKthSmallest(Tnode* cur, int k){
    if(cur == NULL){
        return NULL;
    }
    if((getSize(cur -> left) + 1) == k){
        return cur -> key;
    }
    else if(getSize(cur -> left) < k){
        k = k - (getSize(cur -> left) + 1);
        return findKthSmallest(cur -> right, k);
    }
    else if(getSize(cur -> left) >= k){
        return findKthSmallest(cur -> left, k);
    }
    return nullptr;//take out if it breaks
}

/******************* END OF KTH SMALLEST **********************/

/******************* FIND LEAST COMMON ANCESTOR FUNCTION *****************/
string BST::findLCA(Tnode* cur, string aKey, string aKey1){
    vector <string> temp;
    if(cur == NULL){
        return NULL;
    }
    if(cur -> key < aKey && cur -> key < aKey1){
        return findLCA(cur -> right, aKey, aKey1);
    }
    if(cur -> key > aKey && cur -> key > aKey1){
        return findLCA(cur -> left, aKey, aKey1);
    }
    return cur -> key;
}
/******************* END OF LEAST COMMON ANCESTOR FUNCTION ****************/

/******************* FUNCTION TO FIND LONGEST PATH ************************/

void BST::printLongestPath(Tnode* cur){
    if(cur == NULL){
        return;
    }
    if(getHeight(cur -> left) >= getHeight(cur -> right)){
        cout << cur -> key << " ";
        printLongestPath(cur -> left);
    }
    else if(getHeight(cur -> left) < getHeight(cur -> right)){
        cout << cur -> key << " ";
        printLongestPath(cur -> right);
    }
}


/**************** FUNCTION TO END LONGEST PATH *************************/

/**************** COLLECT SUBTREE NODES FUNCTION ***********************/

void BST::collectSubtree(Tnode* cur, vector <string>& word, string aKey){
    if(cur == NULL){
        return;
    }
    if(aKey < cur -> key){
        collectSubtree(cur -> left, word,aKey);

    }
    else if(aKey > cur -> key){
        collectSubtree(cur -> right, word, aKey);
    }
    else{
        collect(cur,word);
        for(int i = 0; i < word.size(); i++){
            cout << word[i] << " ";
        }
        word.clear();
        return;
    }
}

void BST::collect(Tnode* cur, vector <string> &word){
    if(cur == NULL){
        return;
    }
    collect(cur -> left, word);
    word.push_back(cur -> key);
    collect(cur -> right,word);
}


/************** END OF COLLECT SUBTREE FUNCTION *******************/