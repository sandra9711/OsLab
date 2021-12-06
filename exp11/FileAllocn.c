#include <stdio.h>
int n,file[10][2],block[100];

void init(){
  for(int i=0;i<n;i++){
    block[i]=0;
  }
}
void seq(){
  int i,j,k,flag;
  for(i=0;i<n;i++){
    printf("file %d",i+1);
    printf("enter start:");
    scanf("%d",&file[i][0]);
    printf("enter length:");
    scanf("%d",&file[i][1]);
    k=file[i][0]+file[i][1];
    flag=0;
    for(j=file[i][0];j<k;j++){
      
      if(block[j]!=0){
        i=i-1;
        flag=1;
        printf("file %d cannot be allocated\n",i+1);
        break;
      }else{
        block[j]=1;
      }
    }
    if(flag==0){
      printf("file %d allocated\n",i+1);
    }
  }
}
int main(){
  printf("enter no: of files:");
  scanf("%d",&n);
  init();
  seq();
  return 0;
}