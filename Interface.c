/*******************************************************************/
/*******************************************************************/
/**************     Author : Nadine Ashraf Adeeb     ***************/ 
/**************     Project: School Managment System ***************/ 
/**************              Version:v1.0            ***************/ 
/**************      Date: 16 December,2022          ***************/
/*******************************************************************/
/*******************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "STD_TYPES.h"
#include "Interface.h"

struct Student
{ 
  u32 ID;
  u32 PhoneNumber;
  u8 name[20];
  u8 Address[50];
  u32 score;
  u8 DateOfBirth[20];
 struct Student *link; 
 
};	
struct Student *first = NULL;
/* To arrange the names in ascending order */
void Ascending (void)
{struct Student * p1 = first ;
	struct Student * p2;
	u32 Id ;
	u8 Name[20] ;
	u8 Add[50] ;
	u32 PhoneNum ;
	u8 BirthDate[20] ;
	u32 Gpa;
	while(p1 != NULL)
	{
		p2 = p1->link;
		while(p2 != NULL)
		{
			
			if((p2->name) > (p1->name))
			{
				Id = p1->ID ;
				p1->ID = p2->ID ;
				p2->ID = Id ;
				
				strcpy(Name , p1->name) ;
				strcpy(p1->name , p2->name) ;
				strcpy(p2->name , Name) ;
				
				strcpy(Add , p1->Address) ;
				strcpy(p1->Address , p2->Address) ;
				strcpy(p2->Address , Add) ;
				
				PhoneNum = p1->PhoneNumber;
				p1->PhoneNumber = p2->PhoneNumber;
				p2->PhoneNumber = PhoneNum;
				
				strcpy(BirthDate , p1->DateOfBirth) ;
				strcpy(p1->DateOfBirth , p2->DateOfBirth) ;
				strcpy(p2->DateOfBirth , BirthDate) ;
				
				Gpa = p1->score ;
				p1->score = p2->score ;
				p2->score = Gpa ;
			}
			p2 = p2->link;
		}
		p1 = p1->link;

	}
}
void Activites(void)
{
	printf("\t------------------------------------------\n");
	printf("\tchoose one of the following options:\n");
	printf("\tTo add a New Student         Enter '1'\n");
	printf("\tTo view all Students         Enter '2'\n");
	printf("\tTo Delete a Student          Enter '3'\n");
	printf("\tTo Update Student            Enter '4'\n");
	printf("\tTo Rank Student              Enter '5'\n");
	printf("\tTo Student Score             Enter '6'\n");
	printf("\tTo Exist the School App      Enter '7'\n");
	printf("\t------------------------------------------\n");
}
/* This function displays the welcome screen and targeted activites */
void MAIN_MENU(void)
{
	printf("=====================================================\n");
	printf("===================== WELCOME SIR ===================\n");
	printf("=====================================================\n\n\n");
	printf("\t***********************************\n");
	printf("\t***** School Managment System *****\n");
    printf("\t*****      Nadine Ashraf      *****\n");
	printf("\t***********************************\n\n");
	Activites();

	
}

/* This function creates a new student account. it asks about details of the student such as name,date of birth ID, address and phone number */	
void NEW_STUDENT(void)
{static u32 count=0;
   
	u32 flag=0;
	
struct Student *temp = (struct Student*) malloc(sizeof(struct Student));
printf("Enter ID_Student: ");
scanf("%d",&temp->ID);
//Check_ID ();
printf("Enter Phone_Student: ");
scanf("%d",&temp->PhoneNumber);
printf("Enter Name_Student: ");		
scanf("%s",&temp->name);
printf("Enter Address_Student: ");
scanf("%s",&temp->Address);
printf("Enter STUDENT_SCORE_Student: ");
scanf("%d",&temp->score);
printf("Enter the birth-data (day month year): ");
scanf("%s",&temp->DateOfBirth);	


if(count==0)
{first=temp;
temp->link=0;}
else 
{temp->link = first;
first = temp;}
count++;
/*temp->link = NULL;
	if(first == NULL)
	{
		first = temp;
	}
	else
	{
		Student * tempStudent = first;
		while(tempStudent->link != NULL)
		{
			tempStudent = tempStudent->link ;
		}
		tempStudent->link = temp ;
	}*/
printf("The student has been added sucessfully :)\n");	

}	
/* This function,you can view the students information such as name, date of birth, ID, address and phone number*/
void STUDENT_LIST(void)
{
	u32 Counter = 1;
	struct Student * p1 = first ;
	struct Student * p2;
	struct Student *current;
	 u8 Name[20] ;
	current=first;
	printf("-------------- The List of Students --------------\n");
	if(current == 0)
	{
		printf("==================================================\n");
		printf("\tThe List is empty. No Data to view !\n");
		printf("==================================================\n");
	    
		
	}
	while (current!=0)
	{
	 printf("==================================================\n");
	 printf("Student No.%d is:\n",Counter);
	 printf("The Student Name     :%s\n",current->name);
	 printf("The Student Date     :%s\n",current->DateOfBirth);
	 printf("The Student ID       :%d\n",current->ID);
	 printf("The Student Address  :%s\n",current->Address);
	 printf("The Student Phone    :%d\n",current->PhoneNumber);
	 printf("The Student computer_science  :%d\n",current->score);
		current=current->link;
	printf("==================================================\n");	

	Counter++;

	}
	
}
/* this function is for deleting a customer account */
void DELETE_STUDENT(void)
{
u32 ID3;

struct Student *current=first;
struct Student *prevCurrent = first;
u32 count=0;
printf("Enter the ID of Student that you want to delete: ");
scanf("%d",&ID3);
	while (current!=0)
	{
       if(current->ID==ID3)
		{
		  if(count == 0)
		  {
             first = current -> link; // first refers to second node
			 current->link = 0;   // First node is empty
			 free(current);
			
		  }
		  else
		  {
			  prevCurrent->link = current->link;
			  current->link=0;
			  free(current);
			  
			  
		  }
	
		printf("==========================================\n");
		printf("The Student has been deleted sucessfully :)\n");
		printf("==========================================\n");
		
		}
			count++;
		current=current->link;
		
	}	

	
}	
/* this function has been used for updating a particular student account*/
void STUDENT_EDIT(void)
{u32 ID2;
struct Student *current;
current=first;
printf("Enter The ID of Student that you want to Update: ");
scanf("%d",&ID2);
	while (current!=0)
	{
       if(current->ID==ID2)
	
	{
        printf("Enter Phone_Student: ");
		scanf("%d",&current->PhoneNumber);
		printf("Enter ID_Student: ");
		scanf("%d",&current->ID);
		printf("Enter Name_Student: ");		
		scanf("%s",&current->name);
		printf("Enter Address_Student: ");
		scanf("%s",&current->Address);
		printf("Enter STUDENT_SCORE_Student: ");
		scanf("%d",&current->score);
		printf("Enter the birth-data (day month year): ");
		scanf("%s",&current->DateOfBirth);
		printf("\t\t\t********************************\n");
		printf("\t\t\t\tUpdation Successful!!!\n");
		printf("\t\t\t********************************\n");
	   
	}

	current=current->link;}	
	
		
}	
/* this function can sort all students according to computer science
score */
void RANK_STUDENT(void)
{
	struct Student * p1 = first ;
	struct Student * p2;
	u32 Id ;
	u8 Name[20] ;
	u8 Add[50] ;
	u32 PhoneNum ;
	u8 BirthDate[20] ;
	u32 Gpa;
	
	while(p1 != NULL)
	{
		p2 = p1->link;
		while(p2 != NULL)
		{
			
			if((p2->score) > (p1->score))
			{
				Id = p1->ID ;
				p1->ID = p2->ID ;
				p2->ID = Id ;
				
				strcpy(Name , p1->name) ;
				strcpy(p1->name , p2->name) ;
				strcpy(p2->name , Name) ;
				
				strcpy(Add , p1->Address) ;
				strcpy(p1->Address , p2->Address) ;
				strcpy(p2->Address , Add) ;
				
				PhoneNum = p1->PhoneNumber;
				p1->PhoneNumber = p2->PhoneNumber;
				p2->PhoneNumber = PhoneNum;
				
				strcpy(BirthDate , p1->DateOfBirth) ;
				strcpy(p1->DateOfBirth , p2->DateOfBirth) ;
				strcpy(p2->DateOfBirth , BirthDate) ;
				
				Gpa = p1->score ;
				p1->score = p2->score ;
				p2->score = Gpa ;
			}
			p2 = p2->link;
		}
		p1 = p1->link;

	}
	
	
}
/* this function has been used for updating score of all students*/
void STUDENT_SCORE(void)
{
	u32 ID2;
struct Student *current;
current=first;
printf("Enter The ID of Student that you want to Update: ");
scanf("%d",&ID2);
	while (current!=0)
	{
       if(current->ID==ID2)
	
	{
       printf("Enter STUDENT_SCORE_Student: ");
		scanf("%d",&current->score);
		printf("******************************************************\n");
		printf("The computer_science has been Changed sucessfully :)\n");
		printf("******************************************************\n");
	}
	current = current -> link;
	}
}

 