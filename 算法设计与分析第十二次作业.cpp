#include <stdio.h>
int n,m;//顶点数，可用颜色数
int a[100][100];//存储图的邻接矩阵
int x[100];//当前解
int sum=0;//找到的找色方案
void input(){
    printf("输入顶点数n和着色数m:\n");
    scanf("%d %d",&n,&m);
    printf("输入无向图的邻接矩阵:\n");
    for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
            printf("\n");
    }

}
int ok(int k){
 for(int j=1;j<=n;j++)
    if(a[k][j] && (x[j]==x[k]))return 0;
     return 1;
}
void backtrack(int t){
      if(t>n)
  {
      sum++;
  }
  else
    for(int i=1;i<=m;i++)
        {
            x[t]=i;
            if(ok(t)==1)backtrack(t+1);
             x[t]=0;
        }
}
 
int color()
{
     sum=0;
     backtrack(1);
     return sum;
}
int main(){
    input();
    color();
    while(sum>0){
    printf("着色方案数为：%d\n", sum);
    }
    else
    {
    printf("NO\n");
    }
    return 0;
}

