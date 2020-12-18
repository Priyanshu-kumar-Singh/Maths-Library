#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
#define Fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define f(i, n) for (long long int i = 0; i < n; i++)
#define ll long long int
#define fo(i, a, b) for (long long int i = a; i <= b; i++)
#define vi vector<int>
#define vl vector<long long int>
#define pb push_back
const ll mod = 998244353;


const ll MAXN = 300002; 
ll factorial[MAXN], inverse[MAXN]; 
  
ll binpow(ll a, ll b) 
{ 
    ll res = 1; 
    while (b > 0) { 
        if (b % 2 == 1) { 
            res = (res * a) % mod; 
        } 
        a = (a * a) % mod; 
        b >>= 1; 
    } 
    return res; 
} 
  

ll nCk(ll n, ll k) 
{ 
    if (k < 0 || k > n) { 
        return 0; 
    } 
    ll ans = factorial[n]; 
    ans = (ans * inverse[n - k]) % mod; 
    ans = (ans * inverse[k]) % mod; 
    return ans; 
} 


void preCompute() 
{ 
    ll fact = 1; 
    factorial[0] = 1; 
    inverse[0] = 1; 
    for (ll i = 1; i < MAXN; i++) { 
        fact = (fact * i) % mod; 
        factorial[i] = fact; 
        inverse[i] = binpow(factorial[i], mod - 2); 
    } 
}

int main(){
    Fio;
    preCompute();
    return 0;
}
