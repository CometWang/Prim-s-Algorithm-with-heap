

#include "heap.h"
#include <climits>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
typedef struct edgeNode {
	int v;
	int w;
	int weight;
} edgeNode;

//pass the edglist and the heap structure
void prim(vector<edgeNode> edgesList,heap h){
	vector<edgeNode> list;
	vector<edgeNode> temp;


	while(h.size!=0){
	    //while heap is not empty
		int minId=h.min_id();
		
		for(int i=0;i<temp.size();i++){
		    //find the min

			if(temp[i].w==minId){
				list.push_back(temp[i]);

				//delte it's record in temp
				temp.erase(temp.begin()+i);
				break;
			}
		}

		//delete the min
		h.delete_min();
		for(int i=0;i<edgesList.size();i++){
			if(edgesList[i].v==minId){
				bool done=h.decrease_key(edgesList[i].w,edgesList[i].weight);
				if(done){

					temp.push_back(edgesList[i]);
				}
			}
		}
	}
	//print the tree
	cout<<"The edges of the minimum spanning tree are:"<<endl;

	for(int i=0;i<list.size();i++){
		cout<<"{"<<list[i].v<<","<<list[i].w<<","<<list[i].weight<<"}";
		if((i+1)%3==0){
			cout<<endl;
		}else{
			if(i!=list.size()-1){
				cout<<"---";
			}else{
				cout<<endl;
			}
		}
	} 
}
int main() {
	//read file
	ifstream infile;
	vector<edgeNode> edgesList;
	//infile.open("/Users/apple/CLionProjects/3340_3/infile", ios::binary | ios::in);
	infile.open("infile", ios::binary | ios::in);
	if(!infile) {
		cout<< "can't open the file";
		exit(1);

	}
	int amount;
	infile>>amount;

    //store the # of vertex and initialiaze the array for the keysx
	int *keys=new int[amount];


	//set the first vertex as value 0 (a root)
	keys[0]=0;
	for(int i=1; i<amount; i++) {
		keys[i]=INT_MAX;
	}
	heap h(keys,amount);


	int v,w,weight;
	while(!infile.eof()) {
		infile>>v>>w>>weight;

		//store the data into adjlist by line
		if(edgesList.size()>0&&v==edgesList[edgesList.size()-1].v&&w==edgesList[edgesList.size()-1].w&&weight==edgesList[edgesList.size()-1].weight) {
			break;
		}
		edgeNode node1,node2;
		node1.v=v;
		node1.w=w;
		node1.weight=weight;
		node2.v=w;
		node2.w=v;
		node2.weight=weight;

		//store into vector
		edgesList.push_back(node1);
		edgesList.push_back(node2);
	}

	for(int i=1; i<=amount; i++) {
		//print out the adjlist of edges
		cout<<"vertex"<<i<<":";
		for(int j=0; j<edgesList.size(); j++) {
			if(edgesList[j].v==i) {
				cout<<"{"<<edgesList[j].v<<","<<edgesList[j].w<<","<<edgesList[j].weight<<"} ";
			}
		}
		cout<<endl;
	}

	//prim's algorithm find MST
	prim(edgesList,h);
}
