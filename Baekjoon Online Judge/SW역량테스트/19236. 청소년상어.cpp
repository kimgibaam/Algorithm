#include<iostream>
#include<algorithm>

using namespace std;

struct fish {
	int r, c, d, n;
	bool dead;
};

struct shark {
	int r, c, d, n;
};

int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,-1,-1,-1,0,1,1,1 };
int Map[4][4];
fish fishes[16];
shark sharks;
int answer = 0;

bool comp(fish a, fish b) {
	return a.n < b.n;
}

void move_fish() {
	for (int i = 0; i < 16; i++) {
		if (fishes[i].dead == true) continue;
		int r = fishes[i].r, c = fishes[i].c, d = fishes[i].d;
		int nr, nc;
		bool cont = true;
		do {
			nr = r + dr[d], nc = c + dc[d];
			if (nr < 0 || nr > 3 || nc < 0 || nc > 3 || (nr == sharks.r && nc == sharks.c))
				d = (d + 1) % 8;
			else {
				fishes[i].d = d;
				cont = false;
			}
		} while (fishes[i].d != d);   // 방향 설정완료
		if (cont) continue;

		if (Map[nr][nc] == 99) {  // 빈칸
			Map[nr][nc] = i;
			Map[r][c] = 99;
			fishes[i].r = nr, fishes[i].c = nc;
		}
		else {
			int num = Map[nr][nc];
			Map[nr][nc] = i;
			fishes[num].r = r, fishes[num].c = c;
			fishes[i].r = nr, fishes[i].c = nc;
			Map[r][c] = num;
		}
	}
}

void solve() {

	answer = max(answer, sharks.n);

	shark sbackup = sharks;
	int Mbackup[4][4];
	memcpy(Mbackup, Map, sizeof(Map));
	fish fbackup[16];
	memcpy(fbackup, fishes, sizeof(fbackup));

	for (int i = 1; i <= 3; i++) {  // 상어가 움직이는 범위 1 ~ 3칸
		//잡아먹고 물고기 움직이고
		int nr = sharks.r + (dr[sharks.d] * i);
		int nc = sharks.c + (dc[sharks.d] * i);
		if (Map[nr][nc] == 99 || nr < 0 || nr > 3 || nc < 0 || nc > 3) continue;

		sharks.r = nr, sharks.c = nc;
		sharks.n += (Map[nr][nc] + 1);
		int num = Map[nr][nc];
		sharks.d = fishes[num].d;
		fishes[num].dead = true;
		Map[nr][nc] = 99;
		// 사냥 끝

		move_fish();

		solve();
		//백업
		sharks = sbackup;
		memcpy(Map, Mbackup, sizeof(Map));
		memcpy(fishes, fbackup, sizeof(fbackup));
	}
}

int main() {
	int num = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int n, d;
			cin >> n >> d;
			Map[i][j] = n - 1;
			fishes[num++] = { i,j,d - 1,n -1,false };
		}
	}
	sort(fishes, fishes + 16, comp);

	sharks.r = 0, sharks.c = 0;
	sharks.n += (Map[sharks.r][sharks.c] + 1);
	sharks.d = fishes[Map[sharks.r][sharks.c]].d;
	fishes[Map[sharks.r][sharks.c]].dead = true;
	Map[sharks.r][sharks.c] = 99;

	move_fish();

	solve();
	cout << answer << endl;

	return 0;
}