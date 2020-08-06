#include<stdio.h>
#include<math.h>
#include<conio.h>
#define INF 999
char board[20][20];
int n, count;
int getMarked(int row)
{
int i;
for(i=0;i<n;i++)
{
if(board[row][i] == 'Q')
{
return i;
}
}
return INF;
}
int feasible(int row, int col)
{
int i, tcol;
for(i=0;i<n;i++)
{
tcol = getMarked(i);
if(col==tcol || abs(row-i)==abs(col-tcol))
{
return 0;
}
}
return 1;
}
void printSolution()
{

int i, j;
printf("\nSolution %d : ", count);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(board[i][j] == 'Q')
{
printf("(%d, %d)", i+1, j+1);
}
}
}
printf("\n\n ");
for(i=1;i<=n;i++)
{
printf("  %d", i);
}
printf("\n");
for(i=0;i<n;i++)
{
printf(" %d", i+1);
for(j=0;j<n;j++)
{
printf(" %c ", board[i][j]);
}
printf("\n");
}
getch();
}

void nQueens(int row)
{
int i;
if(row<n)

{
for(i=0;i<n;i++)
{
if(feasible(row,i))

{

board[row][i] = 'Q';
nQueens(row+1);
board[row][i] = '.';
}
}
}
else
{
count++;
printSolution();
}
}
main()
{
int i, j;
printf("Enter the no. of Queens : ");
scanf("%d", &n);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
board[i][j] = '.';
}
}
nQueens(0);
printf("\nTotal Solution : %d", count);
getch();
}
