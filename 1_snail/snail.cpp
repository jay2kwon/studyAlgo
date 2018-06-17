#include <stdio.h>
#define N 15

FILE *fp1, *fp2;
int a[N + 2][N + 2];
int n, start;
int dy[4] = { 0, 1, 0,-1};
int dx[4] = { 1, 0,-1, 0}