#include <stdio.h>
#include <stdlib.h>
int files[100],fil[6][2];
struct fi{
int st;
int no;
int bl[20];
}file[100];
void input(){
    int i,j;
    //before allocating file total no
for(i=0;i<100;i++)
    files[i]=0;
for(i=0;i<6;i++)
{
    for(j=0;j<2;j++){
        fil[i][j]=0;
    }
}
for(i=0;i<100;i++)
{
    file[i].st=0;
    file[i].no=0;
    for(int k=0;k<20;k++){
        file[i].bl[k]=0;
    }
}
}
void Sequential(){
int n,i,stin,le,co=0,j;
input();
printf("Enter the number of files\n");
scanf("%i",&n);
for(i=0;i<n;i++){
        co=0; //count of blocks in a file
printf("\nFile %i\n",i+1);
    printf("Enter the starting block\n");
    scanf("%i",&stin);
    printf("Enter the number of block\n");
    scanf("%i",&le);
    for(j=stin;j<(stin+le);j++){ //allocate from start to length specified
        if (files[j] == 0){
            co++;
            files[j]=1;
            }
    }
    if(co==le){
       printf("The file %i is allocated to the disk\n",i+1);
        fil[i][0]=stin;
        fil[i][1]=le;
    }
    else{
        printf("The file %i cannot allocate to the disk\n\n",i+1);
        fil[i][0]=-1;
        fil[i][1]=-1;
    }
    }
    for(i=0;i<n;i++){
        if(fil[i][0]==-1){
            printf("\nFilename:%i Cannot be allocated\n",i+1);
        }
        else{
        printf("\nFilename:%i Startblock:%i  Length:%i\n",i+1,fil[i][0],fil[i][1]);}
    }
    printf("\n");
}

void Linked(){
input();
int i,j,n;
printf("Enter the number of files\n");
scanf("%i",&n);
for(i=0;i<n;i++){
    printf("\nFile %i\n",i+1);
    printf("Enter starting block \n");
    scanf("%i",&file[i].st);
    printf("Enter number of blocks\n");
    scanf("%i",&file[i].no);
    printf("Enter the blocks\n");
    for(j=0;j<file[i].no;j++){
        scanf("%i",&file[i].bl[j]);

    }
    //check if start position is already allocated
    if(files[file[i].st]==1){
        printf("\nFile %i cannot be allocated\n",i+1);
        file[i].bl[0]=-1;
        continue;
    }
    else{
        files[file[i].st]=1;
    }
    for(j=0;j<file[i].no;j++){
        if(files[file[i].bl[j]]==1){
            printf("In file%i, block %i cannot allocate \n",i+1,file[i].bl[j]);
            for(int u=0;u<=j;u++){
                file[i].bl[u]=-1;
            }
            break;
        }
        else{
            files[file[i].bl[j]]=1;
        }
    }
}

for(i=0;i<n;i++)
{
    if(file[i].bl[0]==-1){
        printf("\nFile %i cannot be allocated\n",i+1);
    }
    else{
        printf("\nFilename:%i ",i+1);
    printf("Startblock:%i ",file[i].st);
    printf("Size:%i ",file[i].no);
    printf("Blocks: ");
    for(j=0;j<file[i].no-1;j++){
       printf("%i->",file[i].bl[j]);
    }
    printf("%i\n",file[i].bl[j]);
    }

}
printf("\n");
}
void Index(){
input();
int i,j,n;
printf("Enter the number of files\n");
scanf("%i",&n);
for(i=0;i<n;i++){
    printf("\nFile %i\n",i+1);
    printf("Enter Index block \n");
    scanf("%i",&file[i].st);
    printf("Enter number of blocks\n");
    scanf("%i",&file[i].no);
    printf("Enter the blocks\n");
    for(j=0;j<file[i].no;j++){
        scanf("%i",&file[i].bl[j]);

    }
    if(files[file[i].st]==1){
        printf("\nFile %i cannot be allocated\n",i+1);
        file[i].bl[0]=-1;
        continue;
    }
    else{
        files[file[i].st]=1;
    }
    for(j=0;j<file[i].no;j++){
        if(files[file[i].bl[j]]==1){
            printf("In file%i, block %i cannot allocate \n",i+1,file[i].bl[j]);
            for(int u=0;u<=j;u++){
                file[i].bl[u]=-1;
            }
            break;
        }
        else{
            files[file[i].bl[j]]=1;
        }
    }
}

for(i=0;i<n;i++)
{
    if(file[i].bl[0]==-1){
        printf("\nFilename%i: cannot be allocated\n",i+1);
    }
    else{
        printf("\nFilename:%i ",i+1);
    printf("Index Block:%i ",file[i].st);
    printf("Length:%i ",file[i].no);}

}
printf("\n");
}

int main()
{
int c;
while(1){
    printf("1.Sequential\n");
    printf("2.Index\n");
    printf("3.Linked\n");
    printf("4.Exit\n");
    printf("Enter your choice\n");
    scanf("%i",&c);
    switch(c){
    case 1:Sequential();
        break;
    case 2:Index();
            break;
    case 3:Linked();
            break;
    case 4:exit(0);
    default:printf("Enter a correct option\n");
        break;
    }
}
}
