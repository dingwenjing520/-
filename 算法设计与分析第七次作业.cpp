#include<iostream>
#include<vector>
 
using namespace std;
 
int main() {
 
	int m, n; 
	int i, j;
	int tmp_m,tmp_F=0,t=0; 
	cin >> m >> n;
	vector<vector<int>> f(n, vector<int>(m + 1));//f[i][x], 0<i<=n,0<=x<=m£»
	vector<vector<int>> F(n, vector<int>(m + 1)),Max(n,vector<int>(m+1)); 
	vector<int>max(n);
 
	for (i = 0; i < n; ++i) {
		f[i][0] = 0;
	}
	for (i = 0; i < n; ++i) {
		for (j = 1; j < m + 1; ++j) { 
			cin >> f[i][j];
		}
	}
	for (j = 0; j < m + 1; ++j) {
		F[0][j] = f[0][j];
		Max[0][j] = j; 
	}
	for (i = 1; i < n; ++i) {
		for (j = 0; j < m + 1; ++j) {
			for (tmp_m = 0; tmp_m <= j; ++tmp_m) {
				tmp_F = F[i - 1][j - tmp_m] + f[i][tmp_m];
				if (tmp_F > F[i][j]){
					F[i][j] = tmp_F;
					Max[i][j] = tmp_m;
				}
			}
		}
	}
 
	max[n - 1] = Max[n - 1][m];
	for (i = n - 2; i >= 0; --i) {
		t = 0;
		for (j = n - 1; j > i;--j) {
			t += max[j];  
		}
		max[i] = Max[i][m - t];
	}
}
 
