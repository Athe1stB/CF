using namespace std;
 
 
// 17.4.1.2 Headers
 
// C
 
 
 
 
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
 
#define ll long long
#define ld long double
#define ar array
 
typedef priority_queue<int> pqi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;
 
ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
 
ll lcm(ll a, ll b){
    return (ll)a*b/gcd(a,b);
}
 
 
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
 
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define FORR1(e) F_OR(i, 0, e, 1)
#define FORR2(i, e) F_OR(i, 0, e, 1)
#define FORR3(i, b, e) F_OR(i, b, e, 1)
#define FORR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, FORR4, FORR3, FORR2, FORR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
const int INF = 800000010;
 
int lsb(int i){
    return i&-i;
}
 
struct SegTree{
    int size;
    vt<ll> arr;
    void init(int sz){
        size = 1;
        while(size<sz)size*=2;
        arr.resize(2*size-1);
        FORR1(size){
            arr[i] = 0;
        }
    }
 
    void set(int i, ll val, int x, int lx, int rx) {
        int mid = (lx + rx) / 2;
        if (lx == rx) {
            arr[x] += val;
        } else {
            if (i <= mid) {
                set(i, val, 2 * x + 1, lx, mid);
            }
            else{
                set(i, val, 2 * x + 2, mid + 1, rx);
            }
            arr[x] = arr[2*x+1]+arr[2*x+2];
        }
 
 
    }
 
    void set(int i, ll val){
        set(i,val,0,0,size-1);
    }
 
    ll get(int x, int y){
        return get(x, y, 0, 0, size-1);
    }
 
    ll get(int l, int r, int x, int lx, int rx){
        int mid = (lx+rx)/2;
        if(l==lx&&r==rx){
            return arr[x];
        }else if(l<=mid&&r>=mid+1){
            return get(l,mid,2*x+1,lx,mid)+get(mid+1,r, 2*x+2,mid+1,rx);
 
        }else if(l<=mid){
            return get(l, r,2*x+1,lx,mid );
        }else{
            return get(l,r,2*x+2,mid+1,rx);
        }
 
 
 
 
    }
 
    int getval(int i){
        return(arr[i]);
    }
 
    int getsize(){
        return size;
    }
 
};
 
template<class T> bool umin(T& a, const T& b) {
    return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) {
    return a<b?a=b, 1:0;
}
 
 
 
int binarySearch(vi arr, int p, int r, int num) {
    if (p <= r) {
        int mid = (p + r)/2;
        if (arr[mid] == num)
            return mid ;
        if (arr[mid] > num)
            return binarySearch(arr, p, mid-1, num);
        if (arr[mid] > num)
            return binarySearch(arr, mid+1, r, num);
    }
    return -1;
}
 
 
 
 
 
 
ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1;
    }
    return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1;
    }
    return lb;
}
 
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}
 
string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}
 
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}
 
template<class A> void write(A x) {
    cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) {
    write(h);
    write(t...);
}
void print() {
    write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}
 
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 
template<class T> void offset(ll o, T& x) {
    x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
    EACH(a, x)
        offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
    EACH(a, x)
        offset(o, a);
}
 
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}
 
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
    v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)
        vti(a, x, m);
}
 
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int mxN=5e5+1, M=1e9+7;
int n, m, p[mxN];
 
int find(int x) {
    return x^p[x]?p[x]=find(p[x]):x;
}
 
bool join(int x, int y) {
    if((x=find(x))==(y=find(y)))
        return 0;
    p[find(x)]=find(y);
    return 1;
}
 
ll pow(ll a, ll b, ll mod){
 
    if(b==0){
        return 1;
    }
    ll sum = pow(a,b/2,mod);
    if(b%2==1){
        return (((sum*sum)%mod)*a)%mod;
    }else{
        return (sum*sum)%mod;
    }
}
 
 
 
ifstream fin("chainblock_validation_input.txt");
ofstream fout("runway_validation_input.txt");
#define MOD 998244353
 
 
 
void solve() {
string s;
cin>>s;
int ct = 0;
for(auto& e: s)if(e=='B')ct++;
cout<<(2*ct==s.length() ? "YES\n":"NO\n");
}
 
 
 
 
 
 
 
 
 
 
int main() {
 
 
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    cin>>tc;
 
    FORR1(tc) {
 
        solve();
 
    }
 
    return 0;
}
