#include <bits/stdc++.h>
using namespace std;

vector <int> minP;

void sieve(int n){
  minP.resize(n + 1);

  for(auto i = 2; i * i <= n; i++)
    if(minP[i] == 0)
      for(auto j = i * i; j <= n; j += i)
        if(minP[j] == 0)
          minP[j] = i;
  
  for(auto i = 2; i <= n; i++)
    if(minP[i] == 0)
      minP[i] = i;
}