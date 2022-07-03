#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 1;
vector<int> arr(100001,0);

void dfs(int start, vector<int> graph[], vector<int> &check)
{
	check[start] = 1;
	arr[start] = cnt;
	cnt++;
	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (check[next] == 0)
		{
			dfs(next, graph, check);
		}
	}
}

int main()
{

	int N, M, R;
	cin >> N >> M >> R;

	vector<int> graph[N + 1];
	vector<int> check(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(R, graph, check);

	for (int i = 1; i <= N; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}