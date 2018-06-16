/* 달팽이 테이블 */
#pragma warning(disable : 4996)
#include <stdio.h>
#define N 15   // 테이블의 최대 크기는 10*10

FILE *fp1, *fp2;
int a[N+2][N+2];
int n, start;
int dy[4] = {0, 1, 0,-1}, dx[4] = {1, 0,-1, 0};

void input(void)
{
    int i, j;

    fscanf(fp1,"%d %d",&n,&start);
    for(i=0 ; i<=n+1 ; i++)   // 주변에 보초
        for(j=0 ; j<=n+1 ; j++)
            if(i==0 || i==n+1 || j==0 || j==n+1)
                a[i][j] = -1;
}

void process(void)
{
    int i, y=1, x=1, key=0;

    for(i=1 ; i<=n*n ; i++)
    {
        a[y][x] = i+start-1;
        if(a[y+dy[key]][x+dx[key]] != 0) // 방향을 틀어야 하는지 사전 탐색
            key = (key + 1) % 4;

        y += dy[key];
        x += dx[key];
    }
}

void output(void)
{
    int i, j;

    for(i=1 ; i<=n ; i++)    // 달팽이 배열 출력
    {
        for(j=1 ; j<=n ; j++)
            fprintf(fp2,"%d ",a[i][j]);
        fprintf(fp2,"\n");
    }
}

int main(void)
{
    fp1 = fopen("input.txt","r");
    fp2 = fopen("output.txt","w");
    input();
    process();
    output();
    return 0;
}
