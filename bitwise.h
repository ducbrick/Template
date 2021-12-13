#include <bits/stdc++.h>
using namespace std;

bool getBit(int mask, int i){
  return (mask >> i) & 1;
}

int bit1Cnt(int mask){
  return __builtin_popcount(mask);
}

int bitOn(int mask, vector <int> pos){
  for(auto i: pos)
    mask |= (1 << i);
  
  return mask;
}

int bitOff(int mask, vector <int> pos){
  for(auto i: pos)
    mask &= ~(1 << i);
  
  return mask;
}

int bitRev(int mask, vector <int> pos){
  for(auto i: pos)
    mask ^= (1 << i);
  
  return mask;
}