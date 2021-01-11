#include<bits/stdc++.h>

using namespace std;

char arr[25][25];
int n;
vector<int> result;

void print()
{
    cout << endl;
    for(int i = 0; i <n; i++)
    {
       for(int j = 0 ; j < n; j++)
       {
         	cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int a, int b, int *num)
{
    *num += 1;
    arr[a][b] = '0';
  // print();

    if(arr[a][b+1] == '1' && b + 1 < n)
    {
        dfs(a,b+1,num);
    }
    if(arr[a][b-1] == '1' && b - 1 >= 0)
    {
        dfs(a,b-1,num);
    }
    if(arr[a+1][b] == '1' && a + 1 < n)
    {
        dfs(a+1,b,num);
    }
    if(arr[a-1][b] == '1' && a - 1 >= 0)
    {
        dfs(a-1,b,num);
    }
}

void solution(int *count)
{
    for(int i = 0; i <n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(arr[i][j] == '1')
            {
                *count = 0;
                dfs(i,j,count);
                result.push_back(*count);
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 1;
//	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(arr,0,sizeof(arr));
        cin >> n;
		for(int i = 0; i <n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
             	cin >> arr[i][j];
            }
        }

        int num = 0;
        int *count = &num;
     //   print();
        solution(count);
        sort(result.begin(),result.end());
        
        cout << result.size() << endl;
        for(int i = 0; i < result.size(); i++)
        {
			cout << result[i] << endl;
        }
      
	}
	return 0;
}