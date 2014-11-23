#include <iostream>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

long max(long a, long b) {
  return a > b ? a : b;
}

int main() {
  long sa, sb;  
  cin >> sa >> sb;
  long long a[sa], b[sb]; 
    
  for(int i = 0; i < sa; i++) cin >> a[i]; 
  for(int j = 0; j < sb; j++) cin >> b[j]; 
    
  long v[sa+1][sb+1];

  // populate.
  for(int i = 0; i < sa+1; i++) {
    for(int j = 0; j < sb+1; j++) {
      if(i == 0 || j == 0) v[i][j] = 0; 
      else if (a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1] + 1;
      else v[i][j] = max(v[i-1][j], v[i][j-1]);
    }
  }
  /*
  for(int i = 0; i < sa+1; i++) {
    for(int j = 0; j < sb+1; j++) {
      cout << setw(3) << v[i][j]; 
    }
    cout << endl; 
  }
  cout << endl; 
  */

  // back trace and get result.
  stack<long long> res;
  for(int i = sa+1, j = sb+1; i > 0 && j > 0;) {
    if(a[i-1] == b[j-1]) {
      // cout << a[i] << " " << endl; 
      res.push(a[i-1]);
      i--, j--;
    } else {
      if (v[i][j-1] > v[i-1][j]) {
	j--; 
      } else {
	i--; 
      }
    }
    //cout << i << ", " << j << " - " << a[i-1] << "," << b[j-1]
    //	 << ": (" << v[i][j] << ", " << v[i-1][j] 
    //	 << ", " << v[i-1][j-1] << ", " << v[i][j-1] << ")" << endl; 
  }

  while(!res.empty()) {
    cout << res.top() << " ";
    res.pop();
  }
  cout << endl;

}
