#include<stdio.h>
char str[10]="ALLIZZWELL";
char s[1050][1050];
char v[1050][1050];
int r,c;
int func(int i,int j,int k)
{
    if(i<0 || i>r-1 || j<0 ||j>c-1)
      return 0;

    if(k==9 && str[k]==s[i][j] && v[i][j]==0)
      return 1;

    if(str[k]!=s[i][j] || v[i][j]==1)
    return 0;
    v[i][j]=1;
   
   if(func(i,j+1,k+1)==1)
    return 1;
   if(func(i,j-1,k+1)==1)
    return 1;
   if(func(i+1,j,k+1)==1)
    return 1;
   if(func(i+1,j+1,k+1)==1)
    return 1;
   if(func(i+1,j-1,k+1)==1)
    return 1;
   if(func(i-1,j,k+1)==1)
    return 1;
   if(func(i-1,j+1,k+1)==1)
    return 1;
   if(func(i-1,j-1,k+1)==1)
    return 1;
   v[i][j]=0;
   return 0;
}
int main()
{
    int t,i,j,k,x,y;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&r,&c);
       for(i=0;i<r;i++)
       {
          scanf("%s",s[i]);
       }
       x=0;
       for(i=0;i<r;i++)
       {
          for(j=0;j<c;j++)
            {
               if(s[i][j]=='A')
               {
                   for(x=0;x<r;x++)
                    for(y=0;y<c;y++)
                      v[x][y]=0;
                   x=func(i,j,0);
                 if(x==1)
                  break;
               }
            }
         if(x==1)
          break;
       }
      if(x==1)
       printf("YES\n\n");
       else
       printf("NO\n\n");
      
    }
    return 0;
}
