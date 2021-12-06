#include<stdio.h>

int Alloc[40][40],Max[40][40],Need[40][40],Avail[1][40],m,n;
void getProcess(){
  printf("enter no. of processes:");
  scanf("%d",&n);
  printf("enter no. of resources:");
  scanf("%d",&m);
  for(int i=0;i<n;i++){
    printf("Alloc matrix p%d\n",i+1);
    for(int j=0;j<m;j++){
      
      scanf("%d",&Alloc[i][j]);
      
    }
  }
  for(int i=0;i<n;i++){
    printf("Max matrix p%d\n",i+1);
    for(int j=0;j<m;j++){
      
      scanf("%d",&Max[i][j]);
      
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      Need[i][j]=Max[i][j]-Alloc[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%d",&Need[i][j]);
    }
  }

}
int main(){
  getProcess();
  return 0;
}