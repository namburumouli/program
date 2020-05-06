 //program to improve searching in a single linked list using hashfunctions.

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #define size 10

 struct node
 {
     char data[100];
     struct node *next;
 }*tail;

 struct node *head[size]={NULL};

 void insert();
 int search();

 void insert()
 {
     int i;
     char ch;
     char value[100];
     struct node *newnode;
     do
     {
     printf("\nEnter a string\n");
     scanf("%s",value);
     i=((strlen(value))%size);
     newnode=(struct node *)malloc(sizeof(struct node));
     strcpy(newnode->data,value);
     newnode->next=NULL;
     if (head[i]==NULL)
     {
         head[i]=newnode;
     }
     else
     {
         tail=head[i];
         while(tail->next!=NULL)
         {
            tail=tail->next;
         }
         tail->next=newnode;
     }
     printf("\ny-continue\n"
             "\nn-exit\n");
     scanf("%s",&ch);
     }while(ch=='y');
 }


 int  search()
 {
     int index;
     char find[100];
     char ch;
     struct node *temp;
     do
     {
     printf("\nEnter the string to search\n");
     scanf("%s",find);
     index=((strlen(find))%size);
     if (head[index]==NULL)
     {
         printf("\nSearch element not found\n");
     }
     else
     {
         temp=head[index];
         while(temp!=NULL)
         {
             if (strcmp(temp->data,find)==0)
             {
                 printf("\nSearch element found\n");
                 goto label;
             }
             temp=temp->next;
         }
         if(temp==NULL)
         {
             printf("\nsearch element not found\n");
         }
     }
 label:
     printf("\ny-continue the search\n"
             "\nn-exit the search\n");
     scanf("%s",&ch);
     }while(ch=='y');
 }





 int main()
 {
     insert();
     search();
 }

   
