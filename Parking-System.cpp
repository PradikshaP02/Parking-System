#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
//To include Graphics.h 64bit compatible
//https://www.youtube.com/watch?v=VEkAj-xVTKQ

#define contn printf("\n\nDo you Want to Continue?\nEnter 1 for YES and 0 for NO : ");\
              scanf("%d",&j);\
              if(j==1)\
                goto L1;\
              else\
                system("cls");\
                goto L2;

//For Arrival
struct car{
    int slot;
    int car_num;
    int x1,y1,x2,y2;//for coordinates of each slot
    char t1[100],t2[100];
    char name[100];
}a[11];

enum receipt{not_print,print};

int main()
{
    FILE * fp;
    time_t starttime,endtime;
    char User[50],Pass[50],ch;
    char x[100],y[100];
    int i,n;
    int n_switch,j,j1,k;
    int filled=0,exitcar_num;
    int sml=1;
    int temp=0;
    int gd=DETECT,gm;

    //Home page
        L2: printf("\n\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n");
        printf("\t\t\xb0                                               \xb0\n");
        printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
        printf("\t\t\xb0        HPD Vehicle Parking Management         \xb0\n");
        printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
        printf("\t\t\xb0                                               \xb0\n");
        printf("\t\t\xb0           Lets make Parking simple            \xb0\n");
        printf("\t\t\xb0                                               \xb0\n");
        printf("\t\t\xb0                                               \xb0\n");
        printf("\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n\n\n");
        printf("\n\t LET'S MOVE ON.....\n");
        printf("\n\t Press 1 to Continue.... ");
        scanf("%d",&j1);


        // alloting each square to each slot
        a[0].x1=100;
        a[0].y1=100;
        a[0].x2=200;
        a[0].y2=200;

        a[1].x1=100;
        a[1].y1=300;
        a[1].x2=200;
        a[1].y2=400;

        a[2].x1=200;
        a[2].y1=300;
        a[2].x2=300;
        a[2].y2=400;

        a[3].x1=200;
        a[3].y1=100;
        a[3].x2=300;
        a[3].y2=200;

        a[4].x1=300;
        a[4].y1=100;
        a[4].x2=400;
        a[4].y2=200;

        a[5].x1=300;
        a[5].y1=300;
        a[5].x2=400;
        a[5].y2=400;

        a[6].x1=400;
        a[6].y1=300;
        a[6].x2=500;
        a[6].y2=400;

        a[7].x1=400;
        a[7].y1=100;
        a[7].x2=500;
        a[7].y2=200;

        a[8].x1=500;
        a[8].y1=100;
        a[8].x2=600;
        a[8].y2=200;

        a[9].x1=500;
        a[9].y1=300;
        a[9].x2=600;
        a[9].y2=400;

    //Initialise Slot to 0
        for(i=1;i<11;i++)
        {
            a[i].slot=0;
        }

    //Menu Page
        L1: system("cls");
        printf("\n\t\t\t\xaf\xaf\xaf\xaf\xaf\xaf\xaf         \xae\xae\xae\xae\xae\xae\xae\xae");
        printf("\n\t\t\t\xaf\xaf\xaf\xaf\xaf\xaf\xaf WELCOME \xae\xae\xae\xae\xae\xae\xae\xae");
        printf("\n\t\t\t1>> Vehicle arrival");
        printf("\n\t\t\t2>> View Bay");
        printf("\n\t\t\t3>> Vehicle Departure");
        printf("\n\t\t\t4>> Receipt");
        printf("\n\t\t\t5>> Vehicle History (For Management use only)");
        printf("\n\t\t\t6>> Exit");
        printf("\n\t\t\t\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae");
        printf("\n\t\t\t\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae");

        printf("\n\nEnter your choice from the above menu : ");
        scanf("%d",&n_switch);


    switch(n_switch)
    {

        case 1 ://Vehicle Arrival

            if(filled==10)
                printf("Please Wait...Parking Full");
            else
                {
                    for(i=0;i<10;i++)
                    {
                        if(a[i].slot==0)
                        {
                            a[i].slot=1;
                            printf("\nEnter your Name :\n");
                            scanf("%s",&a[i].name);
                            printf("Enter the car number :\n");
                            scanf("%d",&a[i].car_num);
                            filled++;
                            break;
                        }
                    }
                    printf("slot = %d",i+1);
                    time(&starttime);
                    strcpy(a[i].t1,ctime(&starttime));
                    printf("\nThis car entered at (date and time): %s", a[i].t1);
                }

            contn //Defined Macros
            break;



        case 2 ://Bay

            initgraph(&gd,&gm,"");
            {
            //printf("helloWorld");
            //system("cls");
            rectangle(100,100,600,200);
            rectangle(100,300,600,400);

            line(100,200,100,300);

            line(200,100,200,200);
            line(300,100,300,200);
            line(400,100,400,200);
            line(500,100,500,200);

            line(200,300,200,400);
            line(300,300,300,400);
            line(400,300,400,400);
            line(500,300,500,400);

            for(i=1;i<11;i++)
            {
                if(a[i].slot==0)
                {
                    setcolor(WHITE);
                    setfillstyle(SOLID_FILL,GREEN);
                    rectangle(a[i].x1,a[i].y1,a[i].x2,a[i].y2);
                    floodfill(a[i].x1+1,a[i].y1+10,WHITE);
                }
                else
                {
                    setcolor(WHITE);
                    setfillstyle(SOLID_FILL,RED);
                    rectangle(a[i].x1,a[i].y1,a[i].x2,a[i].y2);
                    floodfill(a[i].x1+1,a[i].y1+10,WHITE);
                }
            }

            contn
            break;
            }

        case 3 ://Vehicle Departure
            L3: printf("Enter the car number : ");
            scanf("%d",&exitcar_num);
            for(i=0;i<10;i++)
            {
                if(a[i].car_num==exitcar_num)
                {
                    a[i].slot=0;
                    filled--;
                    fp=fopen("Vehicle_d.txt","a");
                    time(&endtime);
                    strcpy(a[i].t2,ctime(&endtime));
                    printf("\nThis car left at (date and time): %s", a[i].t2);


            fputs("\n",fp);
            fputs(a[i].name,fp);
            fputs("\t \t",fp);
            fprintf(fp,"%d",exitcar_num);
            fputs("\t \t",fp);
            fprintf(fp,"%s", a[i].t1);
            fputs("\t\t\t\t",fp);
            fprintf(fp,"%s", a[i].t2);
            fputs("\n",fp);

                fclose(fp);
                    break;
                }
            }
            if(a[i].car_num!=exitcar_num)
            {
                printf("Sorry!!\nNo Such Vehicle No. Exist\n");
                goto L3;
            }

            printf("\nDo you want to Print The RECEIPT ?");
            printf("\nEnter 1 for YES and 0 for NO :\n");
            scanf("%d",&k);

            if(k == print) //Print Receipt
            {
                system("cls");
                printf("\n\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
                printf("\t\t\xb0        HPD Vehicle Parking Management         \xb0\n");
                printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0           Lets make Parking simple            \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0                   RECEIPT                     \xb0\n");
                printf("\t\t                                                      \n");
                printf("\t\t\t     NAME     : %s                          \n",a[i].name);
                printf("\t\t\t     SLOT NO. : %d                                \n",i+1);
                printf("\t\t\t     CHARGES  : 40/- per hour\n                         ");
                printf("\bEntry Time  : %s ",a[i].t1);
                printf("\t\t\tExit Time   : %s \n",a[i].t2);
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
                printf("\t\t\xb0             %c %c !!THANK YOU!! %c %c             \xb0\n",sml,sml,sml,sml);
                printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n\n\n");

            }
            else if(k == not_print)
            {
                system("cls");
                printf("\n\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
                printf("\t\t\xb0        HPD Vehicle Parking Management         \xb0\n");
                printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0           Lets make Parking simple            \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
                printf("\t\t\xb0             %c %c !!THANK YOU!! %c %c             \xb0\n",sml,sml,sml,sml);
                printf("\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0                                               \xb0\n");
                printf("\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n\n\n");
            }

            contn
            break;


        case 5:

        {
            printf(" \n\t Enter the User Name (HPD_Parking) : ");
            scanf("%s",&User);
            printf(" \n\t Enter the Password (simple_parking) : ");
            scanf("%s",&Pass);

            if(strcmp(User,"HPD_Parking")==0 && strcmp(Pass,"simple_parking")==0)
            {
                system("cls");
                printf("\n\t\tCheck the History in the file named Vehicle_d\n\n");
            }

            else
                printf("Invalid Username and Password");

            fclose(fp);
            break;
        }

        default:
            printf("\nInavalid Choice");
    }
    closegraph();
}


