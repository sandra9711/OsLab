#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
int n,np;
struct hole{
int size;
bool v;
}h[20];
struct process{
int size;
int s;
}p[20];
void in(){
int i;
for(i=0;i<np;i++){
    p[i].s=-1;
}
for(i=0;i<n;i++){
    h[i].v=false;
}
}

void fisrtfit(){
int i,j;
in();
for(i=0;i<np;i++){
    for(j=0;j<n;j++){
        if(h[j].v==false && h[j].size>=p[i].size){
           h[j].v=true;
           p[i].s=j;
           break;
        }
    }
}
printf("\n");
for(i=0;i<np;i++){
    if(p[i].s!=-1){
        printf("  P%i - H%i",i,p[i].s);
    }
    else{
        printf("\n P%i - Cannot be allocated",i);
    }
}
printf("\n");
}

void bestfit(){
int i,j;
in();
int t,s,si;
for(i=0;i<np;i++){
    s=INT_MAX;
    si=-1;
    for(j=0;j<n;j++){
        if(h[j].v==false && h[j].size>=p[i].size){
           if(h[j].size<s){
            s=h[j].size;
            si=j;
           }
        }
    }
    if(si!=-1){
        p[i].s=si;
        h[si].v=true;
    }
}
printf("\n");
for(i=0;i<np;i++){
    if(p[i].s!=-1){
        printf("  P%i - H%i",i,p[i].s);
    }
    else{
        printf("\n P%i - Cannot be allocated",i);
    }
}
printf("\n");
}

void worstfit(){
int i,j;
in();
int t,s,si;
for(i=0;i<np;i++){
    s=0;
    si=-1;
    for(j=0;j<n;j++){
        if(h[j].v==false && h[j].size>=p[i].size){
           if(h[j].size>s){
            s=h[j].size;
            si=j;
           }
        }
    }
    if(si!=-1){
        p[i].s=si;
        h[si].v=true;
    }
}
printf("\n");
for(i=0;i<np;i++){
    if(p[i].s!=-1){
        printf("  P%i - H%i",i,p[i].s);
    }
    else{
        printf("\n P%i - Cannot be allocated",i);
    }
}
printf("\n");
}
int main()
{
    int c;
   printf("Enter the number of holes\n");
   scanf("%i",&n);
   printf("Enter the sizes of holes\n");
   for(int i=0;i<n;i++)
   {
       scanf("%i",&h[i].size);
   }
   printf("Enter the number of processes\n");
   scanf("%i",&np);
   printf("Enter the sizes of processes\n");
   for(int i=0;i<np;i++)
   {
       scanf("%i",&p[i].size);
   }
   while(1){
    printf("\n1.First Fit\n");
    printf("2.Best Fit\n");
    printf("3.Worst Fit\n");
    printf("4.Exit\n");
    printf("Enter your choice\n");
    scanf("%i",&c);
    switch(c){
    case 1:fisrtfit();
            break;
    case 2:bestfit();
            break;
    case 3:worstfit();
            break;
    case 4:exit(0);
            break;
    default:printf("Enter correct option\n");
    }
   }
   
}
//212 417 112 426