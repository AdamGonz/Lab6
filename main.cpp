#include <stdlib.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<cstdio>
#include<cmath>
#include<fstream>

using namespace std;

#include "bst.h"


int main(int argc, char* argv[]){

    BST word;
    string command;
    vector <string> temp;
    while(cin >> command){
    	if(command == "print_inorder"){
    		word.print_inorder();
    		cout << endl;
    	}
    	else if(command == "heightPrint"){
    		word.heightPrint();
    		cout << endl;
    	}
    	else if(command == "printBF"){
    		word.printBF();
    		cout << endl;
    		cout << endl;
    	}
    	else if(command == "findPrint"){
    		string aKey;
    		cin >> aKey;
    		word.findPrint(aKey);
    		cout << endl;
    	}
    	else if(command == "insert"){
    		int len;
    		string words;
    		cin >> words;
    		cin >> len;
    		string key = words.substr(0,len);
    		word.insert(key,words);

    	}
    	else if(command == "remove"){
    		string key;
    		cin >> key;
    		word.remove(key);
    	}
        else if(command == "printSize"){
            word.printSize();
            cout << endl;
        }
        else if(command == "findLCA"){
            string aKey, aKey1;
            cin >> aKey >> aKey1;
            cout << word.findLCA(aKey,aKey1) << endl;
        }
        else if(command == "findKthSmallest"){
            int k;
            cin >> k;
            cout << word.findKthSmallest(k) << endl;
        }
        else if(command == "printLongestPath"){
            word.printLongestPath();
            cout << endl;
        }
        else if(command == "collectSubtree"){
            string aKey;
            cin >> aKey;
            word.collectSubtree(temp, aKey);
            cout << endl;
        }
    	else{
    		cerr << "ERROR: command " << command << " is not found." << endl;
    	}
    }

    return 0;

}//main()
