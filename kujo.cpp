#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0;i<n;i++)
        cin>>v[i][i];
    for(int i=0;i<n;i++)
    {
        int x=i,y=i-1,z=v[i][i]-1;
        while(z>0)
        {
            while(z>0 and y>=0 and v[x][y]==0)
            {
                v[x][y]=v[i][i];
                z--;
                y--;
            }
            if(z>0)
            {
                x++;
                y++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
