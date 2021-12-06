#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void fcfs(){
    int track_size,initial;
    printf("\nEnter the Track Size: ");
    scanf("%d",&track_size);
    int n,i;
    printf("\nEnter the no of Request: ");
        scanf("%d",&n);
        printf("\nEnter the Request queue: ");
        int arr[n];
        
        for (i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        

    printf("\nEnter the Initial Position of R/W Head: ");
    scanf("%d",&initial);
    arr[0]=initial;
    
    int seek_time=0,diff=0;
    for(i=0;i<n;i++)
    {
        diff=arr[i+1]-arr[i];
        if(diff<0)
        {
            seek_time=seek_time-diff;
        }
        else
        {
            seek_time=seek_time+diff;
        }
    }
    
    printf("Total Seek Time is %d",seek_time);
    printf("\n");
}
void sstf(){
    int track_size,current_position;
    printf("Enter the Size of Track: ");
    scanf("%d",&track_size);
    track_size=track_size-1;
    
    int n,i;
    printf("Enter the no of Request: ");
        scanf("%d",&n);
        printf("Enter the Request queue: ");
        int arr[n];
        int visited[n];
        for (i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            visited[i]=0;
        }
        

    printf("Enter the Current Position of R/W head: ");
    scanf("%d",&current_position);
    
    int min=1000,diff=5000,flag=7,seek_time=0;
    int j;
    for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                    if(visited[j]==0)
                    {
                    diff=arr[j]-current_position;
                    if(diff<0)
                    {
                        diff=-diff;
                    }   

                    if(diff<min)
                        {
                            min=diff;
                            flag=j;
                        }
                    }
        
            }
            
            visited[flag]=1;
            seek_time=seek_time+min;
            min=1000;
            diff=5000;
            current_position=arr[flag];
        }
    
    printf("Total Seek Time %d",seek_time);
    printf("\n");
}
void scan(){
  int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the Size of Track: ");
    scanf("%d",&size);
    printf("Enter the no of Request: ");
    scanf("%d",&n);
    printf("Enter the Request queue: ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter Current Position of R/W head: ");
    scanf("%d",&initial);
    
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d",&move);
    
    // logic for Scan disk scheduling
    
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        TotalHeadMoment=TotalHeadMoment+abs(size-initial-1);
        //TotalHeadMoment=TotalHeadMoment+(size-1)
            TotalHeadMoment=TotalHeadMoment+abs(size-RQ[0]-1);
        }
    }else
    {  TotalHeadMoment=TotalHeadMoment+abs( 0-initial);
        TotalHeadMoment=TotalHeadMoment+abs(0-R[n]);
    }
    int t=TotalHeadMoment;
    printf("Total Seek Time %d",t);
}
void cscan(){
  int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
  printf("Enter Size of Track: ");
    scanf("%d",&size);
    printf("Enter the no of Request: ");
    scanf("%d",&n);
    printf("Enter the Request queue: ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter the Current Position of R/W head: ");
    scanf("%d",&initial);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d",&move);
    
    // logic for C-Scan disk scheduling
    
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        //  last movement for max size 
        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
        /*movement max to min disk */
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial=0;
        for( i=0;i<index;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        //  last movement for min size 
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
        /*movement min to max disk */
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial =size-1;
        for(i=n-1;i>=index;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    
    printf("Total Seek Time %d",TotalHeadMoment);
}
void look(){
  int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
  printf("Enter Size of Track: ");
    scanf("%d",&size);
    printf("Enter the no of Request: ");
    scanf("%d",&n);
    printf("Enter the Request queue: ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter the Current Position of R/W head: ");
    scanf("%d",&initial);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d",&move);
    
    // logic for C-Scan disk scheduling
    
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for(i=index-1;i>=0;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for(i=index;i<n;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    
    printf("Total Seek Time %d",TotalHeadMoment);
}
void clook(){
  int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
  printf("Enter Size of Track: ");
    scanf("%d",&size);
    printf("Enter the no of Request: ");
    scanf("%d",&n);
    printf("Enter the Request queue: ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter the Current Position of R/W head: ");
    scanf("%d",&initial);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d",&move);
    
    // logic for C-Scan disk scheduling
    
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for( i=0;i<index;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    // if movement is towards low value
    else
    {
       for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for(i=n-1;i>=index;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    
    printf("Total Seek Time %d",TotalHeadMoment);
}
int main()
{	
	
     while(1){
      printf("\n------------------------------------------\n ");
	    printf(" Main Menu for Disk Scheduling Algorithm \n");
	    printf("------------------------------------------\n\n");
	    printf("Press 1 for 'FCFS' \n");	
	    printf("Press 2 for 'SSTF' \n");
      printf("Press 3 for 'SCAN' \n");
      printf("Press 4 for 'C-SCAN' \n");
      printf("Press 5 for 'LOOK' \n");
      printf("Press 6 for 'C-LOOK' \n");
	    printf("Press 0 for 'EXIT' \n");
	    printf("\n------------------------------------------\n");
	int choice ;
	printf("Enter Your Choice : ");
	 scanf("%d",&choice);
     switch(choice)
     {
         case 1:
           	fcfs();
           break;      
         case 2:
           	sstf();
           break;       
         case 3:
         	  scan();
           break;
         case 4:
            cscan();
           break;	
         case 5:
            look();
           break;
         case 6:
            clook();
           break;
         case 0:
           exit(1);          
         default:
           printf("Invalid Choice");
    }
     }
    return 0;
}

//98 37 124 183 90 14