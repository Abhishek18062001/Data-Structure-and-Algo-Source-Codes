#include <bits/stdc++.h>
#define ll long long int 
#define endl "\n"
#define pb push_back
#define MOD 1000000007
using namespace std;
vector<ll> ar[100000];
ll vis[100000];
ll in[100000];
ll low[100000];
ll timer;
bool bridge;
vector<pair<ll,ll>> list1;

void dfs(ll node,ll par )
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    
    for(ll child:ar[node])
    {
        if(child==par)
        continue;
        if(vis[child]==1)
        {
            low[node]=min(low[node],in[child]); 
            if(in[node]>in[child])
            {
                list1.pb({node,child});
            }
            
        }
        else
        {
            dfs(child,node);
            if(low[child]>in[node])
            {
                 bridge=true;
                 return;
            }
            list1.pb({node,child});
            low[node]=min(low[node],low[child]);
        }
        
    }
}


int main() {
	
	  ll n,m,a,b;
	  cin>>n>>m;
	  while(m--)
	  {
	      cin>>a>>b;
	      ar[a].pb(b);
	      ar[b].pb(a);
	  } 
	  dfs(1,-1);
	  
	  if(bridge)
	  {
	      cout<<0;
	  }
	  else
	  {
	      for(pair<ll,ll> p:list1)
	      {
	          cout<<p.first<<" "<<p.second<<endl;
	      }
	  }
	  
	return 0;
}
