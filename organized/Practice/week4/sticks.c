#include <stdio.h>
int main(){
	int t,n,m,min;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		if(n>=m){
			min=m;
		}
		else
			min=n;
		if(min%2==0)
			printf("Kshitij\n");
		else
			printf("Rohan\n");
	}
	return 0;
}