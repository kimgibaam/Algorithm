#include<bits/stdc++.h>

using namespace std;

int arr[16][2];
int n;
int result;

void print(vector<int> days)
{
	for (int i = 0; i < days.size(); i++)
	{
		cout << days[i] << " ";
	}
	cout << endl;
}

void make_max(vector<int> days)
{
	int pay = 0;
	int day;
	for (int i = 0; i < days.size(); i++)
	{
		day = days[i];

		if(day + arr[day][0] -1 <= n)
			pay += arr[day][1];
	}
	result = max(result, pay);
}

void dfs(vector<int> days, int cur)
{
	if(cur > n) 
	{
		make_max(days);
		return;
	}

	for (int i = cur; i <= n; i++)
	{
		days.push_back(i);
		dfs(days, i + arr[i][0]);
		days.pop_back();
	}
}


int main()
{
	memset(arr, 0, sizeof(arr));

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<int> days;
	dfs(days, 1);

	cout << result << endl;

	return 0;
}
