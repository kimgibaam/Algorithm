#include<iostream>
#include<algorithm>

using namespace std;

int table[33][6] =
{
{0,1,2,3,4,5},
{2,2,3,4,5,6},
{4,3,4,5,6,7},
{6,4,5,6,7,8},
{8,5,6,7,8,9},
{10,21,22,23,24,25},
{12,7,8,9,10,11},
{14,8,9,10,11,12},
{16,9,10,11,12,13},
{18,10,11,12,13,14},
{20,27,28,24,25,26},
{22,12,13,14,15,16},
{24,13,14,15,16,17},
{26,14,15,16,17,18},
{28,15,16,17,18,19},
{30,29,30,31,24,25},
{32,17,18,19,20,32},
{34,18,19,20,32,32},
{36,19,20,32,32,32},
{38,20,32,32,32,32},
{40,32,32,32,32,32},
{13,22,23,24,25,26},
{16,23,24,25,26,20},
{19,24,25,26,20,32},
{25,25,26,20,32,32},
{30,26,20,32,32,32},
{35,20,32,32,32,32},
{22,28,24,25,26,20},
{24,24,25,26,20,32},
{28,30,31,24,25,26},
{27,31,24,25,26,20},
{26,24,25,26,20,32},
{0,32,32,32,32,32}};

int command[10];
int horse[4];
int answer = 0;

void solve(int cnt, int sum) {
	if (cnt == 10) {
		answer = max(answer, sum);
		return;
	}


	
	for (int i = 0; i < 4; i++) {
		int backup = horse[i];
		int pos = table[horse[i]][command[cnt]];
		bool cont = false;
		for (int j = 0; j < 4; j++) {
			if (i == j || horse[j] == 32) continue;
			if (horse[j] == pos) cont = true;
		}

		if (cont == true) continue;

		horse[i] = table[horse[i]][command[cnt]];

		solve(cnt + 1, sum + table[pos][0]);

		horse[i] = backup;
	}
	
}

int main() {
	for (int i = 0; i < 10; i++)
		cin >> command[i];
	solve(0, 0);
	cout << answer << endl;
	return 0;
}