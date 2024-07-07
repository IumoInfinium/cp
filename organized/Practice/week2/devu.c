#include <stdio.h>
#include<string.h>
int main() {
	
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    int m,x,y,a[100],c=0;
	    scanf("%d%d%d",&m,&x,&y);
	    int arr[m];
	    for(int j=0;j<m;j++)
	    {
	        scanf("%d",&arr[j]);
	    }
	    for(int i=1;i<=100;i++)
	    {
	        a[i]=1;
	    }
	    for(int j=0;j<m;j++)
	    {
	        for(int k=1;k<=100;k++)
	        {
	            if(k>=arr[j]-x*y && k<=arr[j]+x*y)
	            {
	                a[k]=0;
	            }
	               
	        }
	    }
	    
	    for(int k=1;k<=100;k++)
	    {
	        if(a[k]==1)
	         c++;
	    }
	    printf("%d\n",c);
	}
		return 0;
}