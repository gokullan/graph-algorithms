#include<bits/stdc++.h>
using namespace std;

void print_adj_list(vector<vector<int>> adj_list)
{
	int curr_vertex=0;
	for(auto it=adj_list.begin(); it!=adj_list.end(); it++)
	{
		cout << curr_vertex << ": ";
		for(int v: *it)
		{
			cout << v << " ";
		}
		cout << "\n";
		curr_vertex += 1;
	}
}

void dfs(int u, vector<vector<int>> adj_list, vector<bool>& visited)
{
	visited[u]=true;
	for(int v: adj_list[u])
	{
		if(!visited[v])
		{
			dfs(v,adj_list,visited);
		}
	}
}

int count_connected_components(int n, vector<vector<int>> adj_list)
{
	int n_components=0;
	vector<bool> visited(n,0);
	for(int i=0; i<n; ++i)
	{
		if(!visited[i])
		{
			dfs(i,adj_list,visited);
			n_components += 1;
		}
	}
	return n_components;
}

int main()
{
	int n,m;
	cin >> n >> m;
	int u,v;
	vector<vector<int>> adj_list(n, vector<int>());
	for(int i=0; i<m; ++i)
	{
		cin >> u >> v;
		adj_list[u-1].push_back(v-1);
		adj_list[v-1].push_back(u-1);
	}
	// print_adj_list(adj_list);
	cout << count_connected_components(n,adj_list);
}
