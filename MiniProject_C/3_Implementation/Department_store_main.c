#include "Department_store_header.h"

void Main_menu()
{
    char exit=' ';int choice;
   while(tolower(exit)!='y')
   {
       system("cls||clear");
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
          scanf("%d",&choice);
          fflush(stdin);
          switch(choice)
          {
            case 1:
                Calculate_bill();
                break;
            case 2:
                Add_goods();
                break;
            case 3:
                Delete_goods();
                break;
            case 4:
               Edit_goods();
               break;
            case 5:
                Search_goods();
                break;
            case 6:
                Display_goods();
                break;
            case 7:
                printf("\n\nDo you want to exit?(y/n):");
                scanf("%c",&exit);
                fflush(stdin);
                break;
          }
    }
}
int main(){
    Main_menu();
    return 0;
}

