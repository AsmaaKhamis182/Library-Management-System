#include <stdio.h>
#include <stdlib.h>

#define Book_Num    100

struct Library
{
    char  Book_Title[100];
    char  AuthorName[100];
    int   Publication_Year;
    int   Copies_Number;
    float Price;
    char  Status[50];
};
struct Library Books[Book_Num];

int numBooks = 0;


 // prototype of function
void Menu_library(void);
void Add_book(struct Library *Book,int Number);
void print_book(struct Library *library,int numbooks);
void borrow_book(struct Library *library,int *Num_book);
void delete_book(struct Library *library,int *Num_book);
void buy_book(struct Library *library,int *Num_book);
void Quit(void);


int main()
{
    while(1)
    {
          Menu_library();
    }
}


 // body of function
void Menu_library(void)
{
    fflush(stdin);
    char choice;
    printf("\n ********************** Library Management System ************************* \n");
    printf("if you press on button A you will add book.\nif you press on button B you will print book.\n");
    printf("if you press on button C you will borrow book.\nif you press on button D you will delete book.\n");
    printf("if you press on button E you will buy book.\nif you press on button F you will quit.\n");
    printf("Your Choice is: ");
    scanf("%c",&choice);
    switch(choice)
    {
	    case 'A' :  {Add_book(Books,numBooks);
                    numBooks++;} break;
	    case 'B' :  print_book(Books,numBooks);break;
	    case 'C' :  borrow_book(Books,&numBooks);break;
	    case 'D' :  {delete_book(Books,&numBooks);
	                numBooks--;} break;
	    case 'E' :  buy_book(Books,&numBooks);break;
	    case 'F' :  {printf("You will quit the system, Choose again....\n");
                     Quit(); }                break;
	    default  :                            break;
    }
}



void Add_book(struct Library *Book,int Number)
{
  if(Number <= Book_Num)
  {
     printf("The Book title is : ");
     scanf("%s",Book[Number].Book_Title);
     printf("The Author name is : ");
     scanf("%s",Book[Number].AuthorName);
     printf("The Publication year is : ");
     scanf("%d",&Book[Number].Publication_Year);
     printf("The Number of copies is : ");
     scanf("%d",&Book[Number].Copies_Number);
     printf("The Price is : ");
     scanf("%f",&Book[Number].Price);
     printf("The Status is : ");
     scanf("%s",Book[Number].Status);
  }
  else
  {
     printf("No space to add more books");
  }
}


void print_book(struct Library *library,int numBooks)
{
    fflush(stdin);
    int flag = 0;
    char name[100];
    printf("Please enter name book for print : ");
    scanf("%s",&name);
    for (int i = 0 ; i < numBooks ; i++)
    {
         if(strcmp(library[i].Book_Title , name) == 0)
         {
             flag = 1;
             printf("The Book title is : %s\n",library[i].Book_Title);
             printf("The Author name is : %s\n",library[i].AuthorName);
             printf("The Publication year is : %d\n",library[i].Publication_Year);
             printf("The Number of copies is : %d\n",library[i].Copies_Number);
             printf("The Price is : %f\n",library[i].Price);
             printf("The Status is : %s\n",library[i].Status);
         }
         else if (flag == 0)
         {
            printf("There is not book with this name");
         }
   }

}



void borrow_book(struct Library *library,int *Num_book)
{
    char name[100];
    int flag = 0 ;
    printf("Please enter name book you want to borrow : ");
    scanf("%s",&name);
    for(int i=0; i < *Num_book ;i++)
    {
        if(strcmp(library[i].Book_Title, name) == 0)
        {
            flag =1;
            library[i].Copies_Number--;
            printf("The remaining books = %d",library[i].Copies_Number);
        }
        else if (flag == 0)
        {
            printf("book not founded");
        }
   }

}

void delete_book(struct Library *library,int *Num_book)
{
     int flag = 0;
     char name[100];
     printf("Please enter name book for delete : ");
     scanf("%s",&name);
     for (int i = 0; i < *Num_book; i++)
     {
         if (strcmp(library[i].Book_Title, name) == 0)
         {
             flag = 1;
             for (int j = i; j < *Num_book - 1; j++)
             {
                strcpy(library[j].Book_Title, library[j + 1].Book_Title);
                strcpy(library[j].AuthorName, library[j + 1].AuthorName);
                library[j].Publication_Year = library[j + 1].Publication_Year;
                library[j].Copies_Number = library[j + 1].Copies_Number;
                library[j].Price = library[j + 1].Price;
                strcpy(library[j].Status, library[j + 1].Status);
             }
             (*Num_book)--;
             printf("Book deleted");
             break;
        }
        else if(flag == 0)
        {
              printf("Book not found");
        }
    }
}




void buy_book(struct Library *library,int *Num_book)
{
     char name[100];
     int num,price;
     printf("Please enter name book you want to buy : ");
     scanf("%s",&name);
     for(int i = 0; i < *Num_book ;i++)
     {
         if(strcmp(library[i].Book_Title, name)==0)
         {
             printf("Please enter num of book ");
             scanf("%d",&num);
             if(num<=library[i].Copies_Number)
             {
                 price = num*library[i].Price;
                 library[i].Copies_Number -= num;
                 printf("Total Price = %d\n",price);
                 printf("The remaining books = %d\n",library[i].Copies_Number);
             }
         }
         else
         {
             printf("book not founded");
         }
    }
}





void Quit(void)
{


}







