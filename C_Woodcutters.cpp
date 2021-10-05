#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define lld unsigned long long int // a long has the range of -2,147,483,648 to 2,147,483,647 . An unsigned long has the range of 0 to 4,294,967,295
#define pb push_back
#define m_p make_pair
#define fo(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define N 100005
// never submit a fucking guess
//let's start
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n; cin>>n;
vector<ll> s;
vector<ll> l;
vector<ll> r;
fo(i,n){
    ll x; cin>>x;
    s.pb(x);
    ll h;cin>>h;
    l.pb(x-h);
    r.pb(x+h);
}
vector<ll> ans(n);
ans[0] = 1;
if(n==1){

cout<<ans[n-1]<<endl;
}
if(n>1){
ll rm = s[0];
for(int i=1;i<n-1;i++){
    if(s[i] <= rm){
      ans[i] = ans[i-1];
      rm = s[i];
    }
    else{
        if(l[i]>rm){
            ans[i] = ans[i-1]+1;
            rm = s[i];
        }
        else{
            if(r[i]<s[i+1]){
            ans[i]= ans[i-1]+1;
            rm = r[i];
            }
            else{
                ans[i]=ans[i-1];
                rm=s[i];
            }
        }
    }
    //cout<<rm<<endl;
}
if(s[n-1]<=rm){
    ans[n-1]=ans[n-2];
}
else{
    ans[n-1] = ans[n-2]+1;
}

    cout<<ans[n-1]<<endl;
}
}



