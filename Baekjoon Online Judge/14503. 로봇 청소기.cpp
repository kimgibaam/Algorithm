#include<bits/stdc++.h>

using namespace std;

int space[50][50];
int n, m, r, c, d;
// 0 북 1 동 2 남 3 서

int not_avail;
int result;
int current;

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << space[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//Sleep(3000);
}

void clean()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (space[i][j] != 1 && space[i][j] != 0)
				result++;
		}
	}
}

void solution()
{	
	//print();
	space[r][c] = current++; // 1.청소 완료

	if (not_avail != 4)
	{
		d = d - 1;    // 왼쪽 회전
		if (d == -1) d = 3;
	}
	
	if (not_avail == 4)  // 갈곳이 없다
	{
		if (d == 0) // 북
		{
			if (space[r + 1][c] != 1) // 벽이 아니다
			{
				r += 1;
				not_avail = 0;
			}
			else  // 벽 -> 후진 불가
			{
				return;
			}
		}
		else if (d == 1) // 동
		{
			if (space[r][c - 1] != 1) // 벽이 아니다
			{
				c -= 1;
				not_avail = 0;
			}
			else  // 벽 -> 후진 불가
			{
				return;
			}
		}
		else if (d == 2)  // 남
		{
			if (space[r - 1][c] != 1) // 벽이 아니다
			{
				r -= 1;
				not_avail = 0;
			}
			else  // 벽 -> 후진 불가
			{
				return;
			}
		}
		else if (d == 3)  // 서
		{
			if (space[r][c + 1] != 1) // 벽이 아니다
			{
				c += 1;
				not_avail = 0;
			}
			else  // 벽 -> 후진 불가
			{
				return;
			}
		}
		//후진만 하고 다시 2
		solution();
	}

	// 탐색
	else if (d == 0) // 북
	{
		if (space[r - 1][c] == 0)  // 청소 가능 -> 이동
		{
			not_avail = 0;
			r -= 1;
		}
		else
		{
			not_avail++;
		}
		solution();    //  1번으로
	}
	else if (d == 1) // 동
	{
		if (space[r][c + 1] == 0)  // 청소 가능 -> 이동
		{
			not_avail = 0;
			c += 1;
		}
		else
		{
			not_avail++;
		}
		solution();   // 1번으로
	}
	else if (d == 2) // 남
	{
		if (space[r + 1][c] == 0)  // 청소 가능 -> 이동
		{
			not_avail = 0;
			r += 1;
		}
		else
		{
			not_avail++;
		}
		solution();   //  1번으로
	}
	else if (d == 3) // 서
	{
		if (space[r][c -1] == 0)  // 청소 가능 -> 이동
		{
			not_avail = 0;
			c -= 1;
		}
		else
		{
			not_avail++;
		}
		solution();    //  1번으로
	}
}

int main()
{
	memset(space, 0, sizeof(space));
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> space[i][j];
		}
	}
	not_avail = 0;
	result = 0;
	current = 2;

	solution();
	clean();
	cout << result;

	return 0;
}