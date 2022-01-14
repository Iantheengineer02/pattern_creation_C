/*************************************************************************
 CLASS INFORMATION
 -----------------
   Program Name: program08
   Programmer:   Ian Mason
   Instructor:   Mr. Plain for CS 214-1, C Programming
   Date Due:     11/11/2021

 DOCUMENTATION
 -------------
This program gives the user 4 options for a pattern and asks for a range between 2 and 9.
The program then prints the pattern to a seperate file.
 ************************************************************************/
#include <stdio.h>

#define PATTERN1 '1'
#define PATTERN2 '2'
#define PATTERN3 '3'
#define PATTERN4 '4'
#define SIZE_MIN 2
#define SIZE_MAX 9
#define QUIT     '5'

void printInstructions();
void printMenu        ();
char getMenuChoice    ();
int  getUserValue     ();
void displayPattern1  (int value);
void displayPattern2  (int value);
void displayPattern3  (int value);
void displayPattern4  (int value);
void printGoodbye     ();

int main ()
{
   printInstructions();
   printMenu();
  
   switch (getMenuChoice())
   {
      case PATTERN1:
         displayPattern1(getUserValue());
         break;
      case PATTERN2:
         displayPattern2(getUserValue());
         break;
      case PATTERN3:
         displayPattern3(getUserValue());
         break;
      case PATTERN4:
         displayPattern4(getUserValue());
         break;
      case QUIT:
         printf("Ending the program");
         break;
   }
  
   printGoodbye();
  
   return 0;
}

/*************************************************************************
This function prints the instructions.
************************************************************************/
void printInstructions()
{
   printf("This program will print 4 different patterns based on your cloice.\n");
   return;
}

/*************************************************************************
This function prints out a Menu
************************************************************************/
void printMenu        ()
{
   printf("Menu:\n");
   printf("------------------------\n");
   printf("%c – Pattern One\n",PATTERN1);
   printf("%c – Pattern Two\n",PATTERN2);
   printf("%c – Pattern Three\n",PATTERN3);
   printf("%c – Pattern Four\n",PATTERN4);
   printf("%c - Quit\n\n",QUIT);
   return;
}

/*************************************************************************
This function gets the menu choice.
************************************************************************/
char getMenuChoice    ()
{
   char menuChoice;
   scanf("%c", &menuChoice);
   while(menuChoice != PATTERN1 && menuChoice != PATTERN2 && menuChoice != PATTERN3 
   && menuChoice!=PATTERN4 && menuChoice!= QUIT)
   {
       printf("Please enter in a valid menu choice.\n");
       scanf("%c", &menuChoice);
   }
   return menuChoice;
}

/*************************************************************************
This program gets the user value for the pattern size.
************************************************************************/
int  getUserValue     ()
{
   int userValue;
   printf("Please enter in a value between %d and %d.\n", SIZE_MIN, SIZE_MAX);
   scanf("%d", &userValue);
   while(userValue<=SIZE_MIN || userValue>=SIZE_MAX)
   {
      printf("Please enter in a value between %d and %d.\n", SIZE_MIN, SIZE_MAX);
      scanf("%d", &userValue); 
   }
   return userValue;
}

/*************************************************************************
This function prints out pattern 1 to a file.
************************************************************************/
void displayPattern1  (int value)
{
   FILE*pattern1;
   pattern1 = fopen("masoni_1.txt","w");
   int row, column, size = value;
   for(row = 1; row <= size; row++) 
   {
      for(column = 1; column <= size; column++)
      {
         if(row==column)
		 {
            fprintf(pattern1,"%d", size);
		 }
         else
		 {
            fprintf(pattern1,"*");
		 }
      }
      fprintf(pattern1,"\n");
   }
   fclose(pattern1);
   printf("This pattern was printed to masoni_1.txt");
   return;
}

/*************************************************************************
This function prints out pattern 2 to a file.
************************************************************************/
void displayPattern2  (int value)
{
   FILE*pattern2;
   pattern2 = fopen("masoni_2.txt","w");
   int row, column, size = value;
   for(row = 1; row <= size; row++) 
   {
       
      for(column = 1; column <= size; column++)
      {
         if(column + row-1 == size)
         {
            fprintf(pattern2,"%d", size);
         }
         else
		 {
            fprintf(pattern2,"*");
		 }
      }
      fprintf(pattern2,"\n");
   }
   fclose(pattern2);
   printf("This pattern was printed to masoni_2.txt");
   return;
	
}

/*************************************************************************
This function prints out pattern 3 to a file.
************************************************************************/
void displayPattern3  (int value)
{
	 FILE*pattern3;
   pattern3= fopen("masoni_3.txt","w");
   int row, column, size = value;
   for(row = 1; row <= size; row++) 
   {
       
      for(column = 1; column <= size; column++)
      {
         if(column + row-1 > size)
         {
            fprintf(pattern3,"%d", size);
         }
         else
		 {
            fprintf(pattern3,"*");
		 }
      }
      fprintf(pattern3,"\n");
   }
   fclose(pattern3);
   printf("This pattern was printed to masoni_3.txt");
   return;
}

/*************************************************************************
this function prints out pattern 4 to a file.
************************************************************************/
void displayPattern4  (int value)
{
FILE*pattern4;
   pattern4 = fopen("masoni_4.txt","w");
   int row, column, size = value;
   for(row = 1; row <= size; row++) 
   {
      for(column = 1; column <= size; column++)
      {
         if(row>column)
            fprintf(pattern4,"%d", size);
         else
            fprintf(pattern4,"*");
      }
      fprintf(pattern4,"\n");
   }
   fclose(pattern4);
   printf("This pattern was printed to masoni_4.txt");
   return;
}
   
/*************************************************************************
This function thanks the user for using the program.
************************************************************************/
void printGoodbye     ()
{
   printf("\nThank you for using this program, have a nice day");	
   return;
}