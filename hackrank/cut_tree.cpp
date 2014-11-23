#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class node {
public: 
  int id; 
  int parent; 
  int num_children; 
    
public: 
  node(int d, int p) { 
    id = d; 
    parent = p; 
    num_children = 0; 
  }
}; 

int main() {
  map<int, node*> v; 
  int n, m; 
  cin >> n >> m; 
    
  for(int i = 0; i < m; i++) {
    int from, to; 
    cin >> to >> from;
    // cout << from << " " << to << endl; 
        
    // update from.
    if(v.find(from) == v.end()) {
      node *n = new node(from, -1); 
      v.insert(make_pair(from, n)); 
      // v.at(from) = n; 
      n->num_children = 1; 
    } else {
      v.at(from)->num_children++;
      int p = v.at(from)->parent; 
            
      while (p > 0) {
	v.at(p)->num_children++; 
	p = v.at(p)->parent; 
      }
    }
        
    // update to. 
    if(v.find(to) == v.end()) {
      node *n = new node(to, from); 
      v.insert(make_pair(to, n)); 
      // v.at(to) = n; 
    } else {
      cerr << "Error, node can't have two parents." << endl; 
    }
  }
    
  // output infor about the tree. 
  int cuts = 0; 
  map<int, node*>::iterator it = v.begin(); 
  
  while(it != v.end()) {
    if ((it->second->num_children % 2 == 1) && 
	(it->second->parent > 0)) cuts++; 
    // cout << it->second->id << " : " << endl
    //	 << "parent      : " << it->second->parent << endl
    //	 << "num_children: " << it->second->num_children << endl; 
    it++; 
  }
  cout << cuts << endl; 
    
  return 0;
}
