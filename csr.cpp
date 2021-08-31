#include<bits/stdc++.h>
using namespace std;
int main()
{   
    vector<int> value;
    vector <int> location;
 int v;
 cin>>v;
 location.push_back(0);
 int count=0;
 int a;
 for(int i=0;i<v;)
 {  
    cin>>a;
    if(a!=-1)
    {value.push_back(a);
        count++;}
    else if(a==-1)
    {
        location.push_back(count);
        i++;
    }
    
 }
 for(int i=0;i<value.size();i++)
 {
     cout<<value[i]<<" ";
 }
 cout<<endl;
 for(int i=0;i<location.size();i++)
 {
     cout<<location[i]<<" ";
 }
    
    
} 
