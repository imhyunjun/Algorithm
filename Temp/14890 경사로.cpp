#include <iostream>

using namespace std;

short N, L;
short graph[100][100];
short graphT[100][100];
short connected[100][100];
short connectedT[100][100];

short cnt = 0;

bool CheckRow(short _r, short _con[][100], short _g[][100])
{
	short start = _g[_r][0];
	short startCon = _con[_r][0];
	short down = 0;

	for (short i = 1; i < N; i++)
	{
		short next = _g[_r][i];
		short nextCon = _con[_r][i];

		if (next - start == 1)
		{
			if (startCon < L + down) return false;
			down = 0;
		}
		else if (next - start == -1)
		{
			if (nextCon < L) return false;
			down = L;
		}
		else if(next != start)
		{
			return false;
		}

		start = next;
		startCon = nextCon;
	}

	return true;
}

void SetConCount(short _con[][100], short _g[][100])
{
	short lastIdx = 0;
	short lastNum = -1;
	short conCount = 0;
	short n;

	for (short i = 0; i < N; i++)
	{
		lastIdx = 0;
		lastNum = _g[i][0];
		conCount = 0;

		for (short j = 0; j < N; j++)
		{
			n = _g[i][j];
			if (n == lastNum)
			{
				conCount++;
			}
			else
			{
				for (short k = lastIdx; k <= j - 1; k++)
				{
					_con[i][k] = conCount;
				}
				conCount = 1;
				lastIdx = j;
				lastNum = n;
			}
		}

		for (short k = lastIdx; k < N; k++)
		{
			_con[i][k] = conCount;
		}
	}
}

int main()
{
	short answer = 0;

	cin >> N >> L;

	for (short i = 0; i < N; i++)
	{
		for (short j = 0; j < N; j++)
		{
			short n;
			cin >> n;
			graph[i][j] = n;
			graphT[j][i] = n;
		}
	}

	SetConCount(connected, graph);
	SetConCount(connectedT, graphT);

	for (short i = 0; i < N; i++)
	{
		if (CheckRow(i, connected, graph))
		{
			answer++;
		}

		if (CheckRow(i, connectedT, graphT))
		{
			answer++;
		}
	}

	cout << answer;

	return 0;
}