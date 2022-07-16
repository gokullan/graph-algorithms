#include<bits/stdc++.h>
using namespace std;

/*

NOTATIONS
n1 - number of vertices in the first partition
n2 - number of vertices in the second partition
e - number of edges in the graph


INPUT FORMAT

LINE 1: n1 n2 e
LINE 1 is followed by  e lines of the format: u v
where u and v are vertices from the 1st and 2nd partition respectively,
representing the edge u---v

Vertices in the 1st partition are numbered as 1, 2, 3, .., n1
Vertices in the 2nd partition are numbered as n1+1, n1+2, n1+3, .., n1+n2

SAMPLE INPUT

4 3 5
1 6
2 6
3 5
3 7
4 7

*/

bool find_augmenting_path(int u, vector<vector<int>> adj_list, vector<int> &matchings, vector<int> &visited, int n1)
{
	if (visited[u] == 1)
	{
		return false;
	}
	visited[u] = 1;
	for (int v: adj_list[u])  // for every adjacent vertex, v
	{
		// if v is unsaturated or if v is saturated, but an augmenting path from v's match exist
		if (matchings[v-n1]==-1 || find_augmenting_path(matchings[v-n1], adj_list, matchings, visited, n1))
		{
			// then an augmenting path from u exists
			matchings[v-n1] = u;
			return true;
		}
	}
	return false;
}

void maximum_matching(int n1, int n2, vector<vector<int>> adj_list)
{
	// array to store matchings
	vector<int> matchings(n2, -1);  // if the edge u--v is part of the matching, then matching[v] will be set u

	// check for an augmenting path for every vertex in the 1st partition
	for (int i=0; i<n1; ++i)
	{
		vector<int> visited(n1+n2, 0);
		find_augmenting_path(i, adj_list, matchings, visited, n1);
	}

	// print the matchings
	cout << "\nMatchings:\n\n";
	for (int i=0; i<n2; ++i)
	{
		if (matchings[i] != -1)
		{
			cout << matchings[i]+1 << "---" << n1+i+1 << "\n";
		}
	}
}

int main()
{
	int n1, n2, e, u, v;
	cin >> n1 >> n2 >> e;
	vector<vector<int>> adj_list(n1+n2, vector<int>(0,0));
	for (int i=0; i<e; ++i)
	{
		cin >> u >> v;
		if (adj_list[u-1].size()==0)
		{
			adj_list[u-1] = vector<int>(1, v-1);
		}
		else 
		{
			adj_list[u-1].push_back(v-1);
		}
		if (adj_list[v-1].size()==0)
		{
			adj_list[v-1] = vector<int>(1, u-1);
		}
		else 
		{
			adj_list[v-1].push_back(u-1);
		}
	}
	maximum_matching(n1, n2, adj_list);
}
