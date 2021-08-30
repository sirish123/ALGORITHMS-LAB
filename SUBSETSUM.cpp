#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{   int n,m;
    cin>>n;
    cin>>m;

    int arr[n];
    for(int i=0;i<n;i++)
    {  cin>>arr[i];
    }

    int dp[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for( int j=1;j<=m;j++)
        {
            if(j<arr[i-1])
            {   
                dp[i][j]=dp[i-1][j];
            }
            if(j>=arr[i-1])
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];           
            }
        }
    }
    if(dp[n][m]==1)
    cout<<"exist"<<endl;
    else
    cout<<"does not exist"<<endl;
    

}