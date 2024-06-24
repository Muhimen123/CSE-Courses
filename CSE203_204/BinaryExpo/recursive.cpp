#include<iostream>
using namespace std;
#define ll long long

ll power(ll a, ll n) {
  if(n == 0) return 1;
  else if(n%2 == 0) {
    ll x = power(a, n/2);
    return x*x;
  }
  else if(n%2 == 1) {
    ll x = power(a, (n-1)/2);
    return x*x*a;
  }
}


int main() {
  cout<<power(3, 3)<<endl;
}