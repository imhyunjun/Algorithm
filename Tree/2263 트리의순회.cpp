#include <iostream>

using namespace std;

int n;
int in[100001];
int post[100001];
int index[100001];

void DFS(int instart, int inend, int poststart, int postend)
{
	if (inend < instart || poststart > postend)
		return;

	int root = post[postend];
	int rootIdx = index[root];

	int left = rootIdx - instart;
	int right = inend - rootIdx;

	cout << root << " ";

	DFS(instart, rootIdx - 1, poststart, poststart + left - 1);
	DFS(rootIdx + 1, inend, poststart + left, postend - 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
		index[in[i]] = i;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}

	DFS(0, n - 1, 0, n - 1);

	return 0;
}