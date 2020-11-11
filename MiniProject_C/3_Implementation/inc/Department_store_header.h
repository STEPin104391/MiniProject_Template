#ifndef __DEPARTMENT_STORE_HEADER_H__
#define __DEPARTMENT_STORE_HEADER_H__

#include<stdio.h>
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

/**
* c_code(char y[]) function is used in Adding and editing goods functions, to check whether the given item code exists or not.
* If the given item code exists, then it prompts the user to re-enter a new item code, else it returns 1
* @param[in] item code(y[])
* @return Returns 1, if function successfully executes.
*/
int c_code(char y[]);

/**
* check(char x[code_s]) function is used in edit and delete goods function, to check whether the given item code exists or not and returns 0 if exists, else returns 1
* @param[in] item code(x[code_s])
* @return Returns 0 if item code exists, else returns 1
*/
int check(char x[code_s]);

/**
* displays item name,item code,item rate,item quantity
* @param[in] item
* @param[in] i
* @param[in] j
* @return Returns 1, if function successfully executes.
*/
int display(items *item,int i,int j);

/**
* displays store name.
*/
int dis_window();

/**
* displays all the available goods details.
* @return Returns 1 on successful execution.
*/
int Display_goods();

/**
* Search and displays goods details based on given quantity range.
* @return Returns 1 on successful execution.
*/
int s_quantity();

/**
* Search and displays goods details based on given rate range.
* @return Returns 1 on successful execution.
*/
int s_rate();

/**
* Search and displays goods details of the given item code.
* @return Returns 1 on successful execution.
*/
int s_code();

/**
* This function allows user to select the type of search needs to be performed.(search by rate or search by quantity or search by code).
* @return Returns 1 on successful execution.
*/
int Search_goods();

/**
* Adds new goods details to the file.
* @return Returns 1 on successful execution.
*/
int Add_goods();

/**
* Edit details of the existing goods.
* @return Returns 1 on successful execution.
*/
int Edit_goods();

/**
* Generates customer bills.
* @return Returns 1 on successful execution.
*/
int Calculate_bill();

/**
* Deletes goods details of the given item code.
* @return Returns 1 on successful execution.
*/
int Delete_goods();

#endif
