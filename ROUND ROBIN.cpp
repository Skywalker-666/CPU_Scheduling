#include <iostream>
#include <climits>
using namespace std;

struct Process {
	int AT, BT, ST[20], WT, FT, TAT, pos;
};

int quant;

int main() {
	int n, i, j;
	cout << "Enter the no. of processes: ";
	cin >> n;
	Process p[n];
	cout << "Enter the quantum: " << endl;
	cin >> quant;
	cout << "Enter the process numbers: " << endl;
	for (i = 0; i < n; i++)
		cin >> p[i].pos;
	cout << "Enter the Arrival time of processes: " << endl;
	for (i = 0; i < n; i++)
		cin >> p[i].AT;
	cout << "Enter the Burst time of processes: " << endl;
	for (i = 0; i < n; i++)
		cin >> p[i].BT;
	int c = n, s[n][20];
	float time = 0, mini = INT_MAX, b[n], a[n];
	int index = -1;
	for (i = 0; i < n; i++) {
		b[i] = p[i].BT;
		a[i] = p[i].AT;
		for (j = 0; j < 20; j++) {
			s[i][j] = -1;
		}
	}
	int tot_wt, tot_tat;
	tot_wt = 0;
	tot_tat = 0;
	bool flag = false;
	while (c != 0) {
		mini = INT_MAX;
		flag = false;
		for (i = 0; i < n; i++) {
			float p = time + 0.1;
			if (a[i] <= p && mini > a[i] && b[i] > 0) {
				index = i;
				mini = a[i];
				flag = true;
			}
		}
		if (!flag) {
			time++;
			continue;
		}
		j = 0;
		while (s[index][j] != -1) {
			j++;
		}
		if (s[index][j] == -1) {
			s[index][j] = time;
			p[index].ST[j] = time;
		}
		if (b[index] <= quant) {
			time += b[index];
			b[index] = 0;
		} else {
			time += quant;
			b[index] -= quant;
		}

		if (b[index] > 0) {
			a[index] = time + 0.1;
		}
		if (b[index] == 0) {
			c--;
			p[index].FT = time;
			p[index].WT = p[index].FT - p[index].AT - p[index].BT;
			tot_wt += p[index].WT;
			p[index].TAT = p[index].BT + p[index].WT;
			tot_tat += p[index].TAT;
		}
	}
	cout << "Process ";
	cout << " At ";
	cout << " Bt ";
	j = 0;
	cout << " CT";
	cout << " WT ";
	cout << " TAT" << endl;
	for (i = 0; i < n; i++) {
		cout << p[i].pos << "  ";
		cout << p[i].AT << "  ";
		cout << p[i].BT << "  ";
		cout << p[i].FT << "  ";
		cout << p[i].WT << "  ";
		cout << p[i].TAT << endl;
	}
	return 0;
}
