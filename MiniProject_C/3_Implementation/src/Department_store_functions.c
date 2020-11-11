#include "Department_store_header.h"

//This function checks whether the item exists or not, if already exists then it prompts the user to enter new code
int c_code(char y[])
{
    int flag;
    FILE *file;
    file=fopen("record.txt","rb");
    while(1)
    {
        system("cls||clear");
        flag=1;
        rewind(file);
        printf("\n\n\t\t\tEnter New Code Of The Item:");
        scanf(" %[^\n]",y);
        fflush(stdin);
        while(fread(&item,sizeof(item),1,file)==1)
        {
            if (strcmp(y,item.code)==0)
            {
                flag=0;
                printf("\n\n\t\t\tCode Already Exists");
                printf("\n\n\t\t\tEnter Again");
                getc(stdin);
                break;
            }
        }
        if (flag==1)
            break;
    }
    fclose(file);
    return 1;
}

//function to check if item exist or not, if exist returns 0,  else 1
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

/*function to display items*/
int display(items *item,int i,int j)
{
    printf("\n\t\t\t");
    printf("%4d",j);
    printf("%14s",item->name);
    printf("%11s",item->code);
    printf("%12.2f",item->rate);
    printf("%17d",item->quantity);
return 1;
}

/*function to show store name and column name*/
int dis_window()
{
    system("cls||clear");
    printf("\n\n\n\t\t\t\t-----------------------------------\
            \n\t\t\t\t|      PSN DEPARTMENT STORES       |\
            \n\t\t\t\t-----------------------------------");
    printf("\n\n\t\t\tS_No.     Item_name   Item_code   Item_rate    Item_quantity");
return 1;
}

/*function to display all available goods*/
int Display_goods()
{
    int i,j=1;
    FILE *file=fopen("record.txt","rb");
    dis_window();
    rewind(file);
    i=0;
    while(fread(&item,sizeof(item),1,file))
    {
        display(&item,i,j);
        i++;
        j++;
        if ((j%20)==0)
        {
            printf("\n\t\t\t\t   Press Enter To See More...........");
            getc(stdin);
            system("cls||clear");
            dis_window();
            i=0;
            continue;
        }
    }
    if (i==0)
        printf("\n\n\n\n\t\t\t\t\t   No Item Found");
    fclose(file);
    fflush(stdin);
    getc(stdin);
    return 1;
}

/*function to display by quantity*/
int s_quantity()
{
    system("cls||clear");
    int i=0,j=1;
    int a,b;
    FILE *file=fopen("record.txt","rb");
    printf("\n\n\t\t\tSEARCH");
    printf("\n\n\t\tEnter Lower Range: ");
    scanf("%d",&a);
    fflush(stdin);
    printf("\n\n\t\tEnter Upper Range:");
    scanf("%d",&b);
    fflush(stdin);
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
                printf("\n\n\t\t\t  Press Enter To See More......");
                fflush(stdin);
                getc(stdin);
                system("cls||clear");
                dis_window();
                i=0;
                continue;
            }
        }
    }
    if (i==0)
        printf("\n\n\n\n\t\t\t\t\t   No Item Found");
    fclose(file);
    fflush(stdin);
    getc(stdin);
    return 1;
}

/*function to display by rate*/
int s_rate()
{
    system("cls||clear");
    int i=0,j=1;
    float a,b;
    FILE *file=fopen("record.txt","rb");
    printf("\n\n\t\t\tSEARCH");
    printf("\n\n\t\tEnter Lower Range: ");
    scanf("%f",&a);
    fflush(stdin);
    printf("\n\n\t\tEnter Upper Range: ");
    scanf("%f",&b);
    fflush(stdin);
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
                printf("\n\n\t\t\t   Press Enter To See More.....");
                fflush(stdin);
                getc(stdin);
                system("cls||clear");
                dis_window();
                i=0;
                continue;
            }
        }
    }
    if (i==0)
        printf("\n\n\n\n\t\t\t\t\t   No Item Found");
    fclose(file);
    fflush(stdin);
    getc(stdin);
    return 1;
}

/*function to display by code*/
int s_code()
{
    system("cls||clear");
    int i=0,j=1;
    char x[code_s];
    FILE *file=fopen("record.txt","rb");
    printf("\n\n\t\t\tSEARCH");
    printf("\n\n\t\tEnter Item Code: ");
    scanf("%s",x);
    fflush(stdin);
    dis_window();
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
    fflush(stdin);
    getc(stdin);
    return 1;
}

int Search_goods()
{
    char e='0';int choice;
   while(e!='e')
   {
    system("cls||clear");
    printf("\n\n\t\t\t  SEARCH\n\n\t\t\t1- By Code\n\t\t\t2- By Rate\n\t\t\t3- By Quantity\n\t\t\t4- Back to main menu\n\n\t\t\tEnter your choice(1, 2, 3, 4):");
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
    case 1:
        s_code();
        break;
    case 2:
        s_rate();
        break;
    case 3:
        s_quantity();
        break;
    case 4:
        e='e';
        break;
    }
   }
return 1;
}

int Add_goods()
{
    FILE *file;
    char y[code_s],choice=' ';
    system("cls||clear");
    printf("\n\n\t\tEnter New Record(y/n)?");
    scanf("%c[^\n]",&choice);
    fflush(stdin);
    while(tolower(choice)=='y')
    {
        system("cls||clear");
        file=fopen("record.txt","ab");
        printf("while");
        c_code(y);
        strcpy(item.code,y);
        printf("\n\n\t\t\tEnter Rate Of The Item:");
        scanf("%f",&item.rate);
        fflush(stdin);
        printf("\n\n\t\t\tEnter Quantity Of The Item:");
        scanf("%d",&item.quantity);
        fflush(stdin);
        printf("\n\n\t\t\tEnter Name Of The Item:");
        scanf("%s",item.name);
        fflush(stdin);
        fseek(file,0,SEEK_END);
        fwrite(&item,sizeof(item),1,file);
        fclose(file);
        printf("\n\n\t\t\tEnter New Record(y/n)?");
        scanf("%c",&choice);
        fflush(stdin);
    }
    fflush(stdin);
    getc(stdin);
    return 1;
}

int Edit_goods()
{
    int flag=0,size=0;
    char x[code_s],y[code_s],choice='o';int choice1;
    system("cls||clear");
    printf("\n\n\t\tEDIT RECORDS");
    printf("\n\n\t\tEnter Item Code: ");
    scanf("%s[^\n]",x);
    fflush(stdin);
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
                fflush(stdin);
                scanf("%c",&choice);
                if(tolower(choice)=='y')
                {
                    printf("\n\n\t\t1- Edit Name\n\t\t2- Edit Code\n\t\t3- Edit Rate\n\t\t4- Edit Quantity\n\n\t\tEnter Your Choice(1, 2, 3, 4):");
                     fflush(stdin);
                    scanf("%d",&choice1);
                    switch(choice1)
                    {
                    case 1:
                        system("cls||clear");
                        printf("\n\n\t\tEDIT RECORDS\n\n\t  Enter New Name:");
                        scanf("%s",item.name);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        printf("\n\t  Item Edited  ");
                        break;
                    case 2:
                        system("cls||clear");
                        printf("\n\t\tEDIT RECORDS");
                        char n[name_s];
                        float r;
                        r=item.rate;
                        int qa;
                        qa=item.quantity;
                        strcpy(n,item.name);
                        c_code(y);
                        strcpy(item.code,y);
                        strcpy(item.name,n);
                        item.rate=r;
                        item.quantity=qa;
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        printf("\n\t  Item Edited  ");
                        break;
                    case 3:
                        system("cls||clear");
                        printf("\n\t\tEDIT RECORDS\n\t   Enter New Rate:");
                        scanf("%f",&item.rate);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        printf("\n\t  Item Edited  ");
                        break;
                    case 4:
                        system("cls||clear");
                        printf("\n\t\tEDIT RECORDS\n\t  Enter New Quantity:");
                        scanf("%d",&item.quantity);
                        size=sizeof(item);
                        fseek(file,-size,1);
                        fwrite(&item,sizeof(item),1,file);
                        printf("\n\t  Item Edited  ");
                        break;
                    }
                    break;
                }
            }
        }
           fclose(file);
    }
    if (flag==1)
        printf("\n\t\tItem Does Not Exist.\n\n\t\tTRY AGAIN");
        fflush(stdin);
    getc(stdin);
    return 1;
}

int Calculate_bill()
{
    char x[code_s];
    int size=0,i=1,count=0,count1=0;
    float total=0,gtotal=0;
     FILE *file=fopen("record.txt","r+b");
     rewind(file);
    system("cls||clear");
    while(1)
    {
    printf("\n\n\n\t\t\t\t-----------------------------------\
            \n\t\t\t\t|      PSN DEPARTMENT STORES       |\
            \n\t\t\t\t-----------------------------------");
    printf("\n\n\t\t\t\t\tCUSTOMER'S BILL");
    printf("\n\n\t\t\t\tEnter  \"end\" to finish input");
        printf("\n\n\t\tEnter Item Code:");
        scanf("%s",x);
        fflush(stdin);
        if(strcmp(x,"end")==0)
            break;
        strcpy(bill[count].code,x);
        printf("\n\n\t\tEnter Quantity:");
        scanf("%d",&bill[count].quantity);
        fflush(stdin);
        count++;
        system("cls||clear");
    }
        system("cls||clear");
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
    fflush(stdin);
    getc(stdin);
    return 1;
}

int Delete_goods()
{
    int flag;
    char x[code_s];
    FILE *file,*file1;
    system("cls||clear");
    printf("\n\n\t\tDELETE RECORD");
    printf("\n\n\t\tEnter Item Code: ");
    scanf("%s",x);
    fflush(stdin);
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
    fflush(stdin);
    getc(stdin);
    return 1;
}
