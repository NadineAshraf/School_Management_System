/*******************************************************************/
/*******************************************************************/
/**************     Author : Nadine Ashraf Adeeb     ***************/ 
/**************     Project: School Managment System ***************/ 
/**************              Version:v1.0            ***************/ 
/**************      Date: 16 December,2022          ***************/
/*******************************************************************/
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STD_TYPES.h"
#include "Interface.h"



void main(void)
{
	 u32 num;
	 MAIN_MENU();
	 while(1)
	 {
	 printf("---> Your choice is: ");
	 scanf("%d",&num);
	 switch(num)
	 {
		case 1:
		      NEW_STUDENT();
			  Activites();
			  break;
		case 2:
		      Ascending ();
			  STUDENT_LIST();
			  
			  Activites();
			  break;
		case 3:
			  DELETE_STUDENT();
			  Activites();
			  break;
		case 4:
		
			  STUDENT_EDIT();
			  Ascending ();
			  Activites();
			  break;
		case 5:
		       RANK_STUDENT();
		       break;
	    case 6:
		       STUDENT_SCORE();
			   break;
		case 7:
		       printf("Exit");
		       break;
	 }
	 if(num == 7)
	 {
		 break;
	 }
	 }
	 
}
