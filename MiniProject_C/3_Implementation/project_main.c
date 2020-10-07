#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define name_s 15
#define code_s 6

typedef struct
{
   char code[code_s],name[name_s];
   float rate;
   int quantity;
}items;
items item;

typedef struct
{
   char code[code_s];
   int quantity;
}bills;
bills bill[1000];
//This function checks whether the item exists or not
void c_code(char y[])
{
    int flag;
    FILE *file;
    file=fopen("record.txt","rb");
    while(1)
    {
        system("cls");
        flag=1;
        rewind(file);
        printf("\n\n\t\t\tEnter New Code Of The Item:");
        scanf(" %[^\n]",y);
        while(fread(&item,sizeof(item),1,file)==1)
        {
            if (strcmp(y,item.code)==0)
            {
                flag=0;
                printf("\n\n\t\t\tCode Already Exists");
                printf("\n\n\t\t\tEnter Again");
                getch();
                break;
            }
        }
        if (flag==1)
            break;
    }
}

int check(char x[code_s])
{
    FILE *file;
    int flag=1;
    file=fopen("record.txt","rb");
    rewind(file);
    while (fread(&item,sizeof (item),1,file))
    {
        if(strcmp(item.code,x)==0)
        {
            flag=0;
            break;
        }
    }
    fclose(file);
    return flag;
}

void display(items *item,int i,int j)
{
    printf("\n\t\t\t");
    printf("%4d",j);
    printf("%14s",item->name);
    printf("%11s",item->code);
    printf("%12.2f",item->rate);
    printf("%17d",item->quantity);
}
/*function to show store name and column name*/
void dis_window()
{
    system("cls");
    printf("\n\n\n\t\t\t\t-----------------------------------\
            \n\t\t\t\t|      PSN DEPARTMENT STORES       |\
            \n\t\t\t\t-----------------------------------");
    printf("\n\n\t\t\tS_No.     Item_name   Item_code   Item_rate    Item_quantity");
}

void Display_goods()
{
    int i,j=1;
    FILE *file=fopen("record.txt","rb");
    dis_window();
    rewind(file);
    i=0;
    rewind(file);
    while(fread(&item,sizeof(item),1,file))
    {
        display(&item,i,j);
        i++;
        j++;
        if ((j%20)==0)
        {
            printf("\n\t\t\t\t   Press Any Key To See More...........");
            getch();
            system("cls");
            dis_window();
            i=0;
            continue;
        }
    }
    if (i==0)
        printf("\n\n\n\n\t\t\t\t\t   No Item Found");
    fclose(file);
    getch();
}

/*function to display by quantity*/
void s_quantity()
{
    system("cls");
    int i=0,j=1;
    int a,b;
    FILE *file=fopen("record.txt","rb");
    printf("\n\n\t\t\tSEARCH");
    printf("\n\n\t\tEnter Lower Range: ");
    scanf("%d",&a);
    printf("\n\n\t\tEnter Upper Range:");
    scanf("%d",&b);//fflush(file);
    dis_window();
    rewind(file);
    while(fread(&item,sizeof(item),1,file))
    {
        if((item.quantity>=a)&&(item.quantity<=b))
        {
            display(&item,i,j);
            i++;
            j++;
            if ((j%20)==0)
            {
                printf("\n\n\t\t\t  Press Any Key To See More......");
                getch();
                system("cls");
                dis_window();
                i=0;
                continue;
            }
        }
    }
    if (i==0)
        printf("\n\n\n\n\t\t\t\t\t   No Item Found");
    fclose(file);
    getch();
}

/*function to display by rate*/
void s_rate()
{
    system("cls");
    int i=0,j=1;
    float a,b;
    FILE *file=fopen("record.txt","rb");
    printf("\n\n\t\t\tSEARCH");
    printf("\n\n\t\tEnter Lower Range: ");
    scanf("%f",&a);
    printf("\n\n\t\tEnter Upper Range: ");
    scanf("%f",&b);//fflush(file);
    dis_window();
    rewind(file);
    while(fread(&item,sizeof(item),1,file))
    {
        if((item.rate>=a)&&(item.rate<=b))
        {
            display(&item,i,j);
            i++;
            j++;
            if ((j%20)==0)
            {
                printf("\n\n\t\t\t   Press Any Key To See More.....");
                getch();
                system("cls");
                dis_window();
                i=0;
                continue;
            }
        }
    }
    if (i==0)
        printf("\n\n\n\n\t\t\t\t\t   No Item Found");
    fclose(file);
    getch();
}

/*function to display by code*/
void s_code()
{
    system("cls");
    int i=0,j=1;
    char x[code_s];
    FILE *file=fopen("record.txt","rb");
    printf("\n\n\t\t\tSEARCH");
     printf("\n\n\t\tEnter Item Code: ");
    scanf("%s",&x);
    dis_window();//fflush(file);
     rewind(file);
    while(fread(&item,sizeof(item),1,file))
    {
        if((strcmp(item.code,x)==0))
        {
            display(&item,i,j);
            i++;
            j++;
            break;
        }
    }
    if (i==0)
        printf("\n\n\n\n\t\t\t\t\t   No Item Found");
    fclose(file);
    getch();
}

void Search_goods()
{
    char e='0';
    while(e!='e'){
    system("cls");
    printf("\n\n\t\t\t  SEARCH\n\n\t\t\t1- By Code\n\t\t\t2- By Rate\n\t\t\t3- By Quantity\n\t\t\t4- Back to main menu\n\n\t\t\tEnter your choice(1, 2, 3, 4):");
    switch(getch())
    {
    case 49:
        s_code();
        break;
    case 50:
        s_rate();
        break;
    case 51:
        s_quantity();
        break;
    case 52:
        e='e';
        break;
    }}
}

void Add_goods()
{
    FILE *file;
    char y[code_s];
    system("cls");
    printf("\n\n\t\tEnter New Record(Y/N)?");
    while(toupper(getche())=='Y')
    {
        system("cls");
        file=fopen("record.txt","ab");
        c_code(y);
        strcpy(item.code,y);
        printf("\n\n\t\t\tEnter Rate Of The Item:");
        scanf("%f",&item.rate);
        printf("\n\n\t\t\tEnter Quantity Of The Item:");
        scanf("%d",&item.quantity);
        printf("\n\n\t\t\tEnter Name Of The Item:");
        scanf("%s",item.name);
        fseek(file,0,SEEK_END);
        fwrite(&item,sizeof(item),1,file);
        fclose(file);
        printf("\n\n\t\t\tEnter New Record(Y/N)?");

    }
}

void Edit_goods()
{
    int flag=0,size=0;
    char x[code_s],y[code_s];
    system("cls");
    printf("\n\n\t\tEDIT RECORDS");
    printf("\n\n\t\tEnter Item Code: ");
    scanf("%s",&x);
    flag=check(x);
    if(flag==0)
    {
        FILE *file=fopen("record.txt","r+b");
        rewind(file);
        while (fread(&item,sizeof(item),1,file))
        {
            if(strcmp(item.code,x)==0)
            {
                printf("\n\t\tname       = %s",item.name);
                printf("\n\t\tcode       = %s",item.code);
                printf("\n\t\trate       = %.2f",item.rate);
                printf("\n\t\tquantity   = %d",item.quantity);
                printf("\n\n\t\tDo You Want To Edit This Record?(y/n):");
                if(toupper(getch())=='Y')
                {
                    printf("\n\n\t\t1- Edit Name\n\t\t2- Edit Code\n\t\t3- Edit Rate\n\t\t4- Edit Quantity\n\n\t\tEnter Your Choice(1, 2, 3, 4):");
                    switch(getch())
                    {
                    case 49:
                        system("cls");
                        printf("\n\n\t\tEDIT RECORDS\n\n\t  Enter New Name:");
                        scanf("%s",&item.name);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    case 50:
                        system("cls");
                        printf("\n\t\tEDIT RECORDS");
                        char n[name_s];float r=item.rate;int qa=item.quantity;
                        strcpy(n,item.name);
                        c_code(y);
                        strcpy(item.code,y);
                        strcpy(item.name,n);
                        item.rate=r;
                        item.quantity=qa;
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    case 51:
                        system("cls");
                        printf("\n\t\tEDIT RECORDS\n\t   Enter New Rate:");
                        scanf("%f",&item.rate);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    case 52:
                        system("cls");
                        printf("\n\t\tEDIT RECORDS\n\t  Enter New Quantity:");
                        scanf("%d",&item.quantity);
                        size=sizeof(item);
                        fseek(file,-size,1);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    }
                    printf("\n\t  Item Edited  ");
                    break;
                }
            }
        }
           fclose(file);
    }
    if (flag==1)
        printf("\n\t\tItem Does Not Exist.\n\n\t\tTRY AGAIN");
    getch();
}

void Calculate_bill()
{
    char x[code_s];
    int q=0,size=0,i=1,count=0,count1=0;
    float total=0,gtotal=0;
     FILE *file=fopen("record.txt","r+b");
     rewind(file);
    system("cls");
    while(1)
    {
    printf("\n\n\n\t\t\t\t-----------------------------------\
            \n\t\t\t\t|      PSN DEPARTMENT STORES       |\
            \n\t\t\t\t-----------------------------------");
    printf("\n\n\t\t\t\t\tCUSTOMER'S BILL");
    printf("\n\n\t\t\t\tEnter  \"end\" to finish input");
        printf("\n\n\t\tEnter Item Code:");
        scanf("%s",&x);
        if(strcmp(x,"end")==0)
            break;
        strcpy(bill[count].code,x);
        printf("\n\n\t\tEnter Quantity:");
        scanf("%d",&bill[count].quantity);
        count++;
        system("cls");
    }
            system("cls");
    printf("\n\n\n\t\t\t\t-----------------------------------\
            \n\t\t\t\t|      PSN DEPARTMENT STORES       |\
            \n\t\t\t\t-----------------------------------");
        printf("\n\n\t\t\t\t\tCUSTOMER'S BILL");
        printf("\n\n\t\t\tS_No.      Item_name  Item_quantity   Item_rate    total");
        while(count>0)
        {
            rewind(file);
            while(fread(&item,sizeof(item),1,file))
            {
                if((strcmp(item.code,bill[count1].code)==0))
                {
                    total=item.rate*bill[count1].quantity;
                    printf("\n\t\t\t");
                    printf("%4d",i);
                    printf("%15s",item.name);
                    printf("%13d",bill[count1].quantity);
                    printf("%14.2f",item.rate);
                    printf("%10.2f",total);
                    gtotal=gtotal+total;
                    size=sizeof(item);
                    item.quantity=item.quantity-bill[count1].quantity;
                    i++;
                    fseek(file,-size,SEEK_CUR);
                    fwrite(&item,sizeof(item),1,file);
                    break;
                }
            }
            count1++;
            count--;
        }
    if(gtotal!=0)
        printf("\n\n\t\t\t\t    TOTAL AMOUNT = INRs. %6.2f",gtotal);
    fclose(file);
    getch();
}

void Delete_goods()
{
    int flag;
    char x[code_s];
    FILE *file,*file1;
    system("cls");
    printf("\n\n\t\tDELETE RECORD");
    printf("\n\n\t\tEnter Item Code: ");
    scanf("%s",&x);
    flag=check(x);
    if(flag==0)
    {
        file1=fopen("record1.txt","wb");
        file=fopen("record.txt","rb");
        rewind(file);
        while (fread(&item,sizeof (item),1,file))
        {
            if(strcmp(item.code,x)!=0)
                fwrite(&item,sizeof(item),1,file1);
        }
        fclose(file1);
        fclose(file);
        file1=fopen("record1.txt","rb");
        file=fopen("record.txt","wb");
        rewind(file);
        rewind(file1);
        while (fread(&item,sizeof (item),1,file1))
        {
                fwrite(&item,sizeof(item),1,file);
        }
        printf("\n\n\t\titem deleted");
        fclose(file1);
        fclose(file);
        remove("record1.txt");
    }
    if (flag==1)
        printf("\n\n\t\tItem Does Not Exist\n\n\t\tTRY AGAIN");
    getch();
}

void Main_menu()
{
    char exit='0';
   while(tolower(exit)!='y')
   {
       system("cls");
   printf("\n\n\n\t\t\t\t-----------------------------------\
            \n\t\t\t\t|      PSN DEPARTMENT STORES       |\
            \n\t\t\t\t-----------------------------------");
   printf("\n\n\n\t\t\t\t"
          "\n\t\t\t   +-----------------------------------------+"
          "\n\t\t\t   |                                         |"
          "\n\t\t\t   |            Main Menu                    |"
          "\n\t\t\t   |-----------------------------------------|"
          "\n\t\t\t   |                                         |"
          "\n\t\t\t   |    1-Calculate bill                     |"
          "\n\t\t\t   |    2-Add goods                          |"
          "\n\t\t\t   |    3-Delete goods                       |"
          "\n\t\t\t   |    4-Edit goods                         |"
          "\n\t\t\t   |    5-Search goods                       |"
          "\n\t\t\t   |    6-Display goods                      |"
          "\n\t\t\t   |    7-Exit                               |"
          "\n\t\t\t   |                                         |"
          "\n\t\t\t   +-----------------------------------------+"
          "\n");
          printf("\nEnter your choice(1,2,3,4,5,6,7):");
          switch(getch())
          {
            case 49:
                Calculate_bill();
                break;
            case 50:
                Add_goods();
                break;
            case 51:
                Delete_goods();
                break;
            case 52:
               Edit_goods();
                break;
            case 53:
                Search_goods();
                break;
            case 54:
                Display_goods();
                break;
            case 55:
                printf("\n\nDo you want to exit?(y/n):");
                exit=getch();
                break;
          }
    }
}
int main(){
    Main_menu();
    return 0;
}
