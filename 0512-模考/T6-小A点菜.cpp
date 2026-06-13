#include<stdio.h>
#include<algorithm>
using namespace std;
int n,s,v[101],f[10001]; 

int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;++i) {
		scanf("%d",&v[i]);
	} 
	
	f[0]=1;
	for(int i=1;i<=n;++i) // 前 i 道菜 
		for(int j=s;j>=v[i];--j) // 花 j 元
		{
			if(f[j-v[i]])
			f[j]+=f[j-v[i]];
		}
			
			
	printf("%d",f[s]);
	return 0;
}
/*
10 9
1 2 3 4 5 6 7 8 9 10

8
*/