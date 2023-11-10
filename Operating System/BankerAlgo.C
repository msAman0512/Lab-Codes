//WAP in C to implement Banker's Algo for deadlock avoidance. 
#include <stdio.h>
// P0, P1, P2, P3, P4, ....are the Process names here
int n, m, alloc[10][10], max[10][10], need[10][10], avail[10], f[10], ans[10], req[10][10], ind = 0, l;
void safety_algo(int n, int m, int alloc[][10], int need[][10], int avail[], int f[], int ans[], int ind){
	int flag = n;
	for(int k = 0; k < 5; k++) {
		for(int i = 0; i < n; i++) {
			if (f[i] == 0){
				int slag = 0;
				for(int j = 0; j < m; j++) {
					if (need[i][j] > avail[j])
						break;
					else
						slag++;
				}
				if(slag == m) {
					flag--;
					ans[ind++] = i;
					for(int y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(flag > 0)
		{
			printf("The following system is not safe");
			break;
		}
		else
		{
			printf("Following is the SAFE Sequence\n");
			for (i = 0; i < n; i++)
				printf(" P%d ", ans[i]);
		}
	}
}

// void req_algo(int n, int m, int alloc[][10], int need[][10], int avail[], int req[][10], int f[], int ans[], int ind){
// 		int flag=0;
// 		for(int i = 0; i < m; i++){
// 			req[l][i] <= need[l][i];
// 			flag++;
// 		}
// 		if(flag != m){
// 			printf("The process has exceeded its max limit of process, block the request and continue with the old process needs\n");
// 			safety_algo(n, m, alloc, need, avail, f, ans, ind);
// 			return;
// 		}
// 		else{
// 			flag = 0;
// 			for(int i = 0; i < m; i++){
// 				req[l][i] <= avail[i];
// 				flag++;
// 			}
// 			if(flag == m){
// 				for(int i = 0; i < m; i++){
// 				avail[i] -= req[l][i];
// 				alloc[l][i] += req[l][i];
// 				need[l][i] -= req[l][i];
// 				}
// 				safety_algo(n, m, alloc, need, avail, f, ans, ind);	
// 				return;	
// 			}
// 			else{
// 				int slag = n, jk;
// 				for(int k = 0; k < 5; k++) {
// 					jk = 0;
// 					for(int i = 0; i < m; i++){
// 						req[l][i] <= avail[i];
// 						jk++;
// 					}
// 					if(jk == m)
// 						break;
// 					else{
// 						for(int i = 0; i < n; i++) {
// 							if(i == l);
// 								continue;
// 							if(f[i] == 0){
// 								int klag = 0;
// 								for(int j = 0; j < m; j++) {
// 									if (need[i][j] > avail[j])
// 										break;
// 									else	
// 										klag++;
// 								}
// 								if(klag == m){
// 									slag--;
// 									ans[ind++] = i;
// 									for(int y = 0; y < m; y++)
// 										avail[y] += alloc[i][y];
// 									f[i] = 1;
// 								}
// 							}
// 						}
// 					}
// 				}
// 				for(int i = 0; i < m; i++){
// 						req[l][i] <= avail[i];
// 						jk++;
// 				}
// 				if(jk == m){
// 					for(int i = 0; i < m; i++){
// 					avail[i] -= req[l][i];
// 					alloc[l][i] += req[l][i];
// 					need[l][i] -= req[l][i];
// 					}
// 					safety_algo(n, m, alloc, need, avail, f, ans, ind);	
// 				}
// 				else	
// 					printf("The request is blocked and we continue with the old process needs\n");
// 					safety_algo(n, m, alloc, need, avail, f, ans, ind);
// 					return;
// 			}
// 		}
// }


int main(){
	printf("Enter the number of processes\n");
	scanf("%d", &n);
	printf("Enter the number of resources\n");
	scanf("%d", &m);
	printf("Enter the allocation matrix\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &alloc[i][j]);
		}
	}
	printf("Enter the maximum need matrix\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &max[i][j]);
		}
	}
	printf("Enter the total no. of available resources\n");
	for(int i = 0; i< m; i++)
		scanf("%d", &avail[i]);
	for (int k = 0; k < n; k++) 
		f[k] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	printf("Enter the process no. that raises a request\n");
	scanf("%d", &l);
	printf("Enter the requet matrix for that process\n");
	for(int j = 0; j < m; j++)
		scanf("%d", &req[l][j]);
	safety_algo(n, m, alloc, need, avail, f, ans, ind);
	//req_algo(n, m, alloc, need, avail, req, f, ans, ind);
	return (0);
}