#include<iostream>
#include<vector>
using namespace std;

#ifndef TNODE_H
#define TNODE_H


class Tnode{
        public:
        public:
                Tnode():  key(""), height(0), left(NULL), right(NULL) {};
                Tnode(string aKey, string aval){
			key = aKey;
			value.push_back(aval);
			height = 0;
			left = NULL;
			right = NULL;
			size = 1;
		}
            string key;
			vector <string> value;
			int height;
            Tnode* left;
            Tnode* right;
            int size;
};

#endif
