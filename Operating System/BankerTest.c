#include<stdio.h>

void deadlock(int n, int m, int alloc[][10], int need[][10], int avail[], int f[]){
	int ans[10], index = 0, flag=0;
	for(int k = 0; k<n;k++){
		for(int i = 0;i<n;i++){
			if(f[i] == 0){
				int slag = 0;
				for(int j = 0;j<m;j++){
					if(need[i][j] > avail[j])
						break;
					else
						slag++;	
				}
				if(slag == m){
					for(int j = 0; j<m;j++)
						avail[j] += alloc[i][j];
					ans[index++] = i;
					f[i] = 1;
					flag++;
				}
			}
			if(flag == n)
				break;
		}
		if(flag==n)
			break;
	}
	if(flag != n)
		printf("There is no safe sequence\n");
	else{
		printf("The safe sequence is\n");
		for(int i = 0;i<n;i++)
			printf("P%d\t",ans[i]);
	}
	return;
}
int main(){
	int n, m, alloc[10][10], need[10][10],max[10][10], avail[10], f[10];
	printf("Enter the no.of processes\n");
	scanf("%d",&n);
	printf("Enter the no.of resources\n");
	scanf("%d",&m);
	printf("Enter the allocation matrix\n");
	for(int i = 0; i<n;i++){
		for(int j = 0; j<m;j++){
			scanf("%d",&alloc[i][j]);
		}
		f[i] = 0;
	}
	printf("Enter the max need matrix\n");
	for(int i = 0; i<n;i++){
		for(int j = 0; j<m;j++){
			scanf("%d", &max[i][j]);
		}
	}
	printf("Enter the available rsource matrix\n");
	for(int j = 0; j<m;j++){
		scanf("%d", &avail[j]);
		}
	for(int i = 0; i<n;i++){
		for(int j = 0; j<m;j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	deadlock(n, m, alloc, need, avail, f);
	return 0;
}
