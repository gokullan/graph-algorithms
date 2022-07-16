#include<bits/stdc++.h>
using namespace std;

void print_vect(vector<int> vect)
{
	for (auto it=vect.begin(); it!=vect.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void print_vect2D(vector<vector<int>> vect)
{
	for (auto it=vect.begin(); it!=vect.end(); it++)
	{
		print_vect(*it);
	}
}

vector<int> get_parents(int n, vector<vector<int>> adj_list)
{
	vector<int> parents(n, -1);
	for(int i=0; i<n; ++i)
	{
		for (int j=0; j<adj_list[i].size(); ++j)
		{
			parents[adj_list[i][j]] = i;
		}
	}
	print_vect(parents);
	return parents;
}

int find_lca_naive(int u, int v, vector<vector<int>> adj_list, vector<int> parent)
{
	if (u==v) return u;

	// find the path from u upto root	
	vector<int> u_to_root;

	int current_node = u;
	while (current_node != -1)
	{
		u_to_root.push_back(current_node);
		current_node = parent[current_node];
	}

	current_node = v;
	while(current_node != -1)
	{
		if (find(u_to_root.begin(), u_to_root.end(), current_node) != u_to_root.end())
		{
			return current_node;
		}
		current_node = parent[current_node];
	}
	return -1;
}

int main()
{
	int n, e, u, v;
	cin >> n >> e;
	vector<vector<int>> adj_list(n, vector<int>(0,0));
	for(int i=0; i<e; ++i)
	{
		cin >> u >> v;
		if (adj_list[u].size() == 0)
		{
			adj_list[u] = vector<int>(1, v);
		}
		else
		{
			adj_list[u].push_back(v);
		}
	}
	// print_vect2D(adj_list);

	// create the parents vector
	vector<int> parents = get_parents(n, adj_list);

	cout << find_lca(0,0, adj_list, parents);
}

