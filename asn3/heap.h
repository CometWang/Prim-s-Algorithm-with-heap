//Jia Wang 251041197

#include <map>
#include <climits>
#include <iostream>
using namespace std;

typedef struct heapNode {
	int id;
	int nodeKey;
} Node;

class heap {

	public:
		//features of the heap
		int size; //current size
		int capacity; //capacity of the heap
		map<int,Node> nodesMap;  //map the node


		//initialize the heap with mapping the vertec to an index so the lookupon time will be O(1)
		heap(int *keys, int n) {
			size = n;
			capacity = n;
			for(int i=0; i<n; i++) {
				Node temp;
				temp.id=i+1;
				temp.nodeKey=keys[i];
				//map the mode
				nodesMap.insert(pair<int,Node>(i+1,temp));
			}
		}

		bool in_heap(int id) {
		    //use iterator to find id in the map
			map<int, Node>::iterator find = nodesMap.find(id);
			if(find!=nodesMap.end()) {
			
				return true;
			} else {
				return false;
			}
		}

		int min_key() {
		    //use iterator to find the coresponding min in the map
			int min=INT_MAX;
			for(map<int, Node>::iterator t=nodesMap.begin(); t!=nodesMap.end(); t++) {
				if((*t).second.nodeKey<min) {
					min=(*t).second.nodeKey;
				}
			}
			return min;
		}
		int min_id() {
			int min=INT_MAX;
			int id;
			for(map<int, Node>::iterator t=nodesMap.begin(); t!=nodesMap.end(); t++) {
				if(t->second.nodeKey<min) {
					min=(*t).second.nodeKey;
					id=(*t).first;
				}
			}
			return id;
		}

		int key(int id) {
			map<int, Node>::iterator find = nodesMap.find(id);
			if(find!=nodesMap.end()) {
			    //use recursion to find until reach the end
				
				return (*find).second.nodeKey;
			} else {
				return -1;
			}
		}

		Node delete_min() {
			
			int id=min_id();
			map<int, Node>::iterator find = nodesMap.find(id);
			Node result=(*find).second;
			
			nodesMap.erase(id);
			size--;
			
			return result;
		}
		bool decrease_key(int id, int new_key) {
			if(key(id)!=-1) {
				if(nodesMap.at(id).nodeKey>new_key) {
					nodesMap.at(id).nodeKey=new_key;
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
		}

};
