#include<cstdio>
#include<cstring>
char s[102][102];
int i,j,k,n,m,a[2],f[102][102][2];
int main()
{
	scanf("%d%d",&n,&m);
	memset(f,8,sizeof f);
	for(i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			if(i<2&&j<2)*f[i][j]=0;else
				for(k=0;k<2;++k)
					f[i][j][k]=f[i-k][j-!k][k]+(s[i][j]!='.');
			a[0]=f[i][j][0],a[1]=f[i][j][1];
			for(k=0;k<2;++k)if(a[!k]<f[i][j][k])
				f[i][j][k]=a[!k]+(s[i+k][j+!k]=='.'&&s[i+!k][j+k]=='.');
		}
	printf("%d",f[n][m][0]<f[n][m][1]?f[n][m][0]:f[n][m][1]);
}
