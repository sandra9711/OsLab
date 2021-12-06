#include <stdio.h>
#include <stdlib.h>

int main()
{
    menu();
    return 0;
}
void menu()
{
    int ch, f[50], p, i, st, len, j, c, k, a, index[50], ind, count = 0;
    printf("\n\nMENU\n");
    printf("1.sequential\n2.indexed\n3.linked\n4.exit\n\nEnter your choice:");
    scanf("%d", &ch);
    if (ch == 1)
    {
        int f[50], p, i, st, len, j, c, k, a;

        for (i = 0; i < 50; i++)
            f[i] = 0;
        printf("Enter how many blocks already allocated: ");
        scanf("%d", &p);
        printf("Enter blocks already allocated: ");
        for (i = 0; i < p; i++)
        {
            scanf("%d", &a);
            f[a] = 1;
        }
    x:
        printf("Enter index starting block and length: ");
        scanf("%d%d", &st, &len);
        k = len;
        if (f[st] == 0)
        {
            for (j = st; j < (st + k); j++)
            {
                if (f[j] == 0)
                {
                    f[j] = 1;
                    printf("%d-------->%d\n", j, f[j]);
                }
                else
                {
                    printf("%d Block is already allocated \n", j);
                    k++;
                }
            }
        }
        else
            printf("%d starting block is already allocated \n", st);
        printf("Do you want to enter more file(Yes - 1/No - 0)");
        scanf("%d", &c);
        if (c == 1)
            goto x;
        else
            exit(0);
    }

    if (ch == 2)
    {
        int f[50], index[50], i, n, st, len, j, c, k, ind, count = 0;

        for (i = 0; i < 50; i++)
            f[i] = 0;
        printf("Enter the index block: ");
        scanf("%d", &ind);
        if (f[ind] != 1)
        {
            printf("Enter no of blocks needed and no of files for the index %d on the disk : \n",
                   ind);
            scanf("%d", &n);
        }
        else
        {
            printf("%d index is already allocated \n", ind);
            goto x;
        }
    y:
        count = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &index[i]);
            if (f[index[i]] == 0)
                count++;
        }
        if (count == n)
        {
            for (j = 0; j < n; j++)
                f[index[j]] = 1;
            printf("Allocated\n");
            printf("File Indexed\n");
            for (k = 0; k < n; k++)
                printf("%d-------->%d : %d\n", ind, index[k], f[index[k]]);
        }
        else
        {
            printf("File in the index is already allocated \n");
            printf("Enter another file indexed");
            goto y;
        }
        printf("Do you want to enter more file(Yes - 1/No - 0)");
        scanf("%d", &c);
        if (c == 1)
            goto x;
        else
            exit(0);
    }

    if (ch == 3)
    {
        int f[50], i, st, len, j, c, k, count = 0;

        for (i = 0; i < 50; i++)
            f[i] = 0;
        printf("Files Allocated are : \n");
        count = 0;
        printf("Enter starting block and length of files:");
        scanf("%d%d", &st, &len);
        for (k = st; k < (st + len); k++)
            if (f[k] == 0)
                count++;
        if (len == count)
        {
            for (j = st; j < (st + len); j++)
                if (f[j] == 0)
                {
                    f[j] = 1;
                    printf("%d\t%d\n", j, f[j]);
                }
            if (j != (st + len - 1))
                printf(" The file is allocated to disk\n");
        }
        else
            printf("The file is not allocated \n");
        printf("Do you want to enter more file(Yes - 1/No - 0)");
        scanf("%d", &c);
        if (c == 1)
            goto x;
        else
            exit(0);
    }
}

// //////////////////
// Sequential File Allocation Program :


//     main()
// {
//     int f[50], i, st, j, len, c, k;
//     clrscr();
//     for (i = 0; i < 50; i++)
//         f[i] = 0;
// X:
//     printf("\n Enter the starting block & length of file");
//     scanf("%d%d", &st, &len);
//     for (j = st; j < (st + len); j++)
//         if (f[j] == 0)
//         {
//             f[j] = 1;
//             printf("\n%d->%d", j, f[j]);
//         }
//         else
//         {
//             printf("Block already allocated");
//             break;
//         }
//     if (j == (st + len))
//         printf("\n the file is allocated to disk");
//     printf("\n if u want to enter more files?(y-1/n-0)");
//     scanf("%d", &c);
//     if (c == 1)
//         goto X;
//     else
//         exit();
//     getch();
// }

// orrrr

// #include <stdio.h>
//     void
//     main()
// {
//     int n, i, j, b[20], sb[20], t[20], x, c[20][20];
//     printf("Enter no.of files:");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         printf("Enter no. of blocks occupied by file%d:", i + 1);
//         scanf("%d", &b[i]);
//         printf("Enter the starting block of file%d:", i + 1);
//         scanf("%d", &sb[i]);
//         t[i] = sb[i];
//         for (j = 0; j < b[i]; j++)
//             c[i][j] = sb[i]++;
//     }
//     printf("Filename\tStart block\tlength\n");
//     for (i = 0; i < n; i++)
//         printf("%d\t        %d \t           %d\n", i + 1, t[i], b[i]);
// }

// orr

// #include <stdio.h>
// #include <conio.h>
//     void
//     main()
// {
//     int f[50], i, st, len, j, c, k, count = 0;

//     for (i = 0; i < 50; i++)
//         f[i] = 0;
//     printf("Files Allocated are : \n");
// x:
//     count = 0;
//     printf("Enter starting block and length of files: ");
//     scanf("%d%d", &st, &len);
//     for (k = st; k < (st + len); k++)
//         if (f[k] == 0)
//             count++;
//     if (len == count)
//     {
//         for (j = st; j < (st + len); j++)
//             if (f[j] == 0)
//             {
//                 f[j] = 1;
//                 printf("%d\t%d\n", j, f[j]);
//             }
//         if (j != (st + len - 1))
//             printf(" The file is allocated to disk\n");
//     }
//     else
//         printf("The file is not allocated \n");
//     printf("Do you want to enter more file(Yes - 1/No - 0)");
//     scanf("%d", &c);
//     if (c == 1)
//         goto x;
//     else
//         return 1;
//     getch();
// }

// ///////////////indexd

// #include <stdio.h>
// #include <conio.h>
// main()
// {
//     int n, m[20], i, j, sb[20], s[20], b[20][20], x;

//     printf("Enter no. of files:");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         printf("Enter starting block and size of file%d:", i + 1);
//         scanf("%d%d", &sb[i], &s[i]);
//         printf("Enter blocks occupied by file%d:", i + 1);
//         scanf("%d", &m[i]);
//         printf("enter blocks of file%d:", i + 1);
//         for (j = 0; j < m[i]; j++)
//             scanf("%d", &b[i][j]);
//     }
//     printf("\nFile\t index\tlength\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]);
//     }
//     printf("\nEnter file name:");
//     scanf("%d", &x);
//     printf("file name is:%d\n", x);
//     i = x - 1;
//     printf("Index is:%d", sb[i]);
//     printf("Block occupied are:");
//     for (j = 0; j < m[i]; j++)
//         printf("%3d", b[i][j]);
//     getch();
// }

// or
// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>
//     void main()
// {
//     int f[50], index[50], i, n, st, len, j, c, k, ind, count = 0;

//     for (i = 0; i < 50; i++)
//         f[i] = 0;
// x:
//     printf("Enter the index block: ");
//     scanf("%d", &ind);
//     if (f[ind] != 1)
//     {
//         printf("Enter no of blocks needed and no of files for the index %d on the disk : \n",
//                ind);
//         scanf("%d", &n);
//     }
//     else
//     {
//         printf("%d index is already allocated \n", ind);
//         goto x;
//     }
// y:
//     count = 0;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &index[i]);
//         if (f[index[i]] == 0)
//             count++;
//     }
//     if (count == n)
//     {
//         for (j = 0; j < n; j++)
//             f[index[j]] = 1;
//         printf("Allocated\n");
//         printf("File Indexed\n");
//         for (k = 0; k < n; k++)
//             printf("%d-------->%d : %d\n", ind, index[k], f[index[k]]);
//     }
//     else
//     {
//         printf("File in the index is already allocated \n");
//         printf("Enter another file indexed");
//         goto y;
//     }
//     printf("Do you want to enter more file(Yes - 1/No - 0)");
//     scanf("%d", &c);
//     if (c == 1)
//         goto x;
//     else
//         exit(0);
//     getch();
// }

// /////linked

// #include <stdio.h>
// #include <conio.h>
// struct file
// {
//     char fname[10];
//     int start, size, block[10];
// } f[10];
// main()
// {
//     int i, j, n;

//     printf("Enter no. of files:");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         printf("Enter file name:");
//         scanf("%s", &f[i].fname);
//         printf("Enter starting block:");
//         scanf("%d", &f[i].start);
//         f[i].block[0] = f[i].start;
//         printf("Enter no.of blocks:");
//         scanf("%d", &f[i].size);
//         printf("Enter block numbers:");
//         for (j = 1; j <= f[i].size; j++)
//         {
//             scanf("%d", &f[i].block[j]);
//         }
//     }
//     printf("File\tstart\tsize\tblock\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
//         for (j = 1; j <= f[i].size - 1; j++)
//             printf("%d--->", f[i].block[j]);
//         printf("%d", f[i].block[j]);
//         printf("\n");
//     }
//     getch();
// }

// or

// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>
//     void main()
// {
//     int f[50], p, i, st, len, j, c, k, a;

//     for (i = 0; i < 50; i++)
//         f[i] = 0;
//     printf("Enter how many blocks already allocated: ");
//     scanf("%d", &p);
//     printf("Enter blocks already allocated: ");
//     for (i = 0; i < p; i++)
//     {
//         scanf("%d", &a);
//         f[a] = 1;
//     }
// x:
//     printf("Enter index starting block and length: ");
//     scanf("%d%d", &st, &len);
//     k = len;
//     if (f[st] == 0)
//     {
//         for (j = st; j < (st + k); j++)
//         {
//             if (f[j] == 0)
//             {
//                 f[j] = 1;
//                 printf("%d-------->%d\n", j, f[j]);
//             }
//             else
//             {
//                 printf("%d Block is already allocated \n", j);
//                 k++;
//             }
//         }
//     }
//     else
//         printf("%d starting block is already allocated \n", st);
//     printf("Do you want to enter more file(Yes - 1/No - 0)");
//     scanf("%d", &c);
//     if (c == 1)
//         goto x;
//     else
//         exit(0);
//     getch();
// }