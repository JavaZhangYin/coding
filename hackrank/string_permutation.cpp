#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int t, n; 
  string s; 
  cin >> t; 
    
  for(int i = 0; i < t; i++) {
    cin >> n >> s; 
        
    string t = ""; 
    for(int i = 0; i < n; i++) {
      t = s[i]; 
      cout << t << endl;

      for(int gap = 1; i + gap < n; gap++) {
	string t1 = t; 
	for(int j = i + gap; j < n; j++) {
	  t += s[j]; 
	  cout << t << endl; 
	}
	t = t1; 
      }
    }
  }
    
  return 0;
}
