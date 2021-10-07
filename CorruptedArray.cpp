#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main()
{
	ll t;
	cin>>t;
	while(t--){
		ll n,sum=0;
		cin>>n;
		vector<ll>b(n+2);
		for(ll i=0;i<n+2;i++){
			cin>>b[i];
			sum+=b[i];
		}
		sort(b.begin(),b.end());
		ll temp=sum-b[n+1]-b[n];
		if(temp==b[n]){
			for(ll i=0;i<n;i++){
				cout<<b[i]<<" ";
			}
			cout<<"\n";
		}else{
			temp=sum-b[n+1];
			ll res=n+3;
			for(ll i=0;i<n+1;i++){
				if(temp-b[i]==b[n+1]){
					res=i;
					break;
				}
			}
			if(res==n+3){
				cout<<-1<<"\n";
			}else{
				for(ll i=0;i<n+1;i++){
					if(i==res){
						continue;
					}else{
						cout<<b[i]<<" ";
					}
				}
				cout<<"\n";
			}
			
		}
		
		
		
		
	}	

	return 0;
}

