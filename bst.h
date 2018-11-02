#include<iostream>
using namespace std;

#include "tnode.h"
#ifndef BST_H
#define BST_H

class BST{
        public:
                BST():  root(NULL) {};
                ~BST(){ clean(root); root = NULL; };

				Tnode* insert(string aKey, string aval){
					if(root == NULL){
						root = new Tnode(aKey, aval);
						updateHeight(root);
						updateSize(root);
						return root;
					}else
						root = insert(root, aKey, aval);
						restoreBalance(root);
						return root;
				};
				void print_inorder(){ 
					print_inorder(root);
                    cout << endl;
				};
				void heightPrint(){
					heightPrint(root);
					cout << endl;
				}
				void findPrint(string aKey){
					findPrint(root,aKey);
				}
				void printBF(){
					printBF(root);
				}
				void remove(string aKey){
					if(root == NULL){
						return;
					}
					else{
						root = remove(root,aKey);
						restoreBalance(root);
						updateHeight(root);
						updateSize(root);
					}
				}
				void printSize(){
					printSize(root);
					cout << endl;
				}
				string findKthSmallest(int k){
					return findKthSmallest(root, k);
				}
				string findLCA(string aKey, string aKey1){
					return findLCA(root, aKey, aKey1);
				}
				void printLongestPath(){
					printLongestPath(root);
				}
				void collectSubtree(vector <string>& words, string aKey){
					if(root == NULL){
						return;
					}
					collectSubtree(root,words,aKey);
				}
		private:
				Tnode* insert(Tnode* cur,string aKey,string aval);
				void print_inorder(Tnode *cur);
				void heightPrint(Tnode* cur);
				void findPrint(Tnode* cur, string aKey);
				Tnode *root = NULL;
				void clean(Tnode* cur);
				void updateHeight(Tnode* cur);
				int getHeight(Tnode* cur);
				int balanceFactor(Tnode* cur);
				void printBF(Tnode* cur);
				Tnode* rightRotation(Tnode* cur);
				Tnode* leftRotation(Tnode* cur);
				Tnode* restoreBalance(Tnode* cur);
				Tnode* getLeftMost(Tnode* cur);
				Tnode* remove(Tnode* cur, string aKey);
				int getSize(Tnode* cur);
				void printSize(Tnode* cur);
				void updateSize(Tnode* cur);
				void post(Tnode* cur);
				string findKthSmallest(Tnode* cur, int k);
				string findLCA(Tnode* cur, string aKey, string aKey1);
				void printLongestPath(Tnode* cur);
				void collectSubtree(Tnode* cur, vector <string>& words, string aKey);
				void collect(Tnode* cur, vector <string> &word);

};


#endif
