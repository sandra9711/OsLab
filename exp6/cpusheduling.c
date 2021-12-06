#include<stdio.h>

typedef struct process{
  int pid;
  int at;
  int bt;
  int tat;
  int wt;
};

struct process p[10];
struct process temp[20];

int getprocess(struct process p[]){
  int i,n;
  printf("Enter number of processes:\t");
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    p[i].pid=i+1;
    printf("Enter arrival time of %d:\t",p[i].pid);
    scanf("%d",&p[i].at);
    printf("Enter burst time of %d:\t",p[i].pid);
    scanf("%d",&p[i].bt);
  }
  printf("process\t arrival time\t burst time\n");
  for(i=0;i<n;i++){
    p[i].pid=i+1;
    printf("%d\t\t \t%d\t \t \t\t%d\n",p[i].pid,p[i].at,p[i].bt);
  }
  return n;
}
void fcfs(p,n){
  int i;
  float awt=0,atat=0;
  temp[0].wt=0; temp[0].tat=0;
  for(i<0;i<n;i++){
    p[i].wt=0; p[i].tat=0;
    temp[i+1].wt=temp[i].wt+p[i].bt;
    p[i].wt=temp[i]-p[i].bt;
    p[i].tat=p[i].wt+p[i].bt;
    awt=awt+p[i].wt;
    atat=atat+p[i].tat;
  }
  awt=awt/n;
  atat=atat/n;
  printf("Avg WT - %f \t Avg TAT - %f\n",awt,atat);
}
int main(){
  int i,j,n;
  n=getprocess(p);
  fcfs(p,n);
  return 0;
}