#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define null 0
void insert();
void delete();
void display();
int length();
struct node reverse(struct node *p);

struct node{
int data;
struct node *link;
};
struct node *root;

void main()
{

    int c;
    while(1)
    {
    printf("\n1.insert\n");
    printf("2.delete\n");
    printf("3.display\n");
    printf("4.reverse\n");
    printf("5.reverse k nodes\n");
    printf("6.exit\n");
    printf("7.length\n");
    printf("8.insert after key\n");
    printf("9.insert before key\n");
    printf("10.delete data \n");
    printf("11.insert after key element\n");
    printf("12.insert before key element\n");
    printf("enter the option\n");
    scanf("%d",&c);
    switch(c)
    {

        case 1:
        insert();
        break;
        case 2:
        delete();
        break;
        case 3:
        display();
        break;
        case 4:
        reverse(root);
        break;
        case 5:
        rev();
        break;
        case 6:
        exit(0);
        case 7:
            length();
        break;
        case 8:
            insertf();
        break;
        case 9:
            insertb();
            break;
        case 10:
            deleteinfo();
            break;
        case 11:
            insertae();
            break;
        case 12:
            insertbe();
            break;
        default:
        printf("invalid");
        }}}
void insert()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
     printf("enter value\n");
    scanf("%d",&temp->data);
    temp->link=null;
    if(root==null)
    {   root=temp;
        }
    else{
   struct node *p;
   p=root;
   while(p->link!=null)
   {
       p=p->link;

   }

    p->link=temp;

}}
void delete()
{
    struct node *t,*q;
    int loc,len,i=1;
    printf("enter location");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
{
    printf("invalid\n");


}
   else if(loc==1)
{
    t=root;
    root=root->link;
    t->link=null;
    free(t);

}
else{
    t=root;
    while(i<loc-1)
{  i++;
t=t->link;
}
q=t->link;
t->link=q->link;
q->link=null;
free(q);

}

}

void display()
{   struct node *temp;


    if(root==null)
    {

        printf("no element\n");

    }
    else{
            temp=root;
        while(temp->link!=null)
    {
        printf("%d\t",temp->data);
        temp=temp->link;}
        printf("%d\t",temp->data);
        }}

    int length()
    {
        int c=1;
        struct node *temp;
        if(root==null)
        {

            printf("empty");

        }
        else{
        temp=root;
        while(temp->link!=null)
    {
c++;
        temp=temp->link;

    }
    printf("%d\n",c);
    return c;
    }}
     struct node reverse(struct node *p)
    {
        if(p->link==null)
        {

            root=p;
            return ;
        }
        reverse(p->link);
        struct node *q=p->link;
        q->link=p;
        p->link=null;

    }
    void rev()
    {int k,l,i=1;
        printf("enter the number of nodes\n");
        scanf("%d",&k);
        l=length();
        if(k>l)
            printf("check \n");
        else{

            struct node *cur=root,*nex=null,*pre=null,*p=null;
            while(i<k)
            { cur=cur->link;
            i++;
            }
            p=cur->link;
            cur->link=null;
            cur=root;
            while(cur!=null)
            {  nex=cur->link;
                cur->link=pre;
                pre=cur;
                cur=nex;
                   }
                   root=pre;
                   cur=root;
                   while(cur->link!=null)
                   {
                       cur=cur->link;

                   }
            cur->link=p;

        }
    }
void insertf()
{

    int loc,count,c,d;
    struct node *cur,*prev;
    printf("enter location\n");
    scanf("%d",&loc);
    count=length();
    struct node *temp;

    if(loc>count || loc<=0 || root==null)
    {

        printf("not possible\n");

    }
    else{
        temp=(struct node *)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&temp->data);
        temp->link=null;
        c=1;

        cur=root;
        while(c<loc+1)
        {

            prev=cur;
            cur=cur->link;
            c++;

        }

        prev->link=temp;
        temp->link=cur;

    }
}
 void insertb()
 {  int loc,count,c,d;
    struct node *cur,*prev;
    printf("enter location\n");
    scanf("%d",&loc);
    count=length();
    struct node *temp;

    if(loc>count || loc<=0 || root==null)
    {

        printf("not possible\n");

    }
    else{
        temp=(struct node *)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&temp->data);
        temp->link=null;
        c=1;

        cur=root;
        if(loc==1)
        {
          printf("not possible\n") ;

        }
        else{
        if(loc-1==1)
            {
              temp->link=root;
              root=temp;

            }
            else{
        while(c<=loc-2)
        {

            prev=cur;
            cur=cur->link;
            c++;

        }

        prev->link=temp;
        temp->link=cur;


            }
      }
 }
 }
 void deleteinfo()
 {

     int d;
     struct node *cur,*prev,*t;
     cur=root;


if(root==null)
{

    printf("not possible\n");}
    else{
            printf("enter data to be removed\n");
     scanf("%d",&d);

      if(cur->data==d)
      {
        root=root->link;
        free(cur);
        cur=null;
      }
else{
            while(cur!=null)
     {

         if(d==cur->data)
         { break;

        }
        prev=cur;
         cur=cur->link;

     }

   if(cur==null)
   {

       printf("not found\n");

   }

else{
        prev->link=cur->link;
       free(cur);
       cur=null;

}
}
 }}
 void insertae()
 {
     int k,d;
     struct node *temp,*prev,*cur;
     cur=root;
     printf("enter key element\n");
     scanf("%d",&k);
     printf("enter element to be inserted\n");
     scanf("%d",&d);

     if(root==null)
     {

         printf("empty\n");

     }
     else if(root->link==null)
     {

         if(root->data==k)
         {   temp=(struct node *)malloc(sizeof(struct node));
         temp->data=d;
         temp->link=null;
             root->link=temp;


         }
         else{
            printf("key not found\n");

         }
     }
     else{
        while(cur!=null)
        {
            if(cur->data==k)
                break;
            cur=cur->link;

        }
        if(cur==null)
        {

            printf("key not found\n");}
        else
                {

        temp=(struct node *)malloc(sizeof(struct node));
         temp->data=d;
         temp->link=null;
         temp->link=cur->link;
         cur->link=temp;
            }
        }

    }

void insertbe()
 {
     int k,d;
     struct node *temp,*prev,*cur;
     cur=root;
     printf("enter key element\n");
     scanf("%d",&k);


     if(root==null)
     {

         printf("empty\n");

     }
     else if(root->data==k)
     {
         printf("enter element to be inserted\n");
     scanf("%d",&d);

            temp=(struct node *)malloc(sizeof(struct node));
         temp->data=d;
         temp->link=null;
             temp->link=root;
             root=temp;

     }
     else{


        while(cur!=null)
        {
            if(cur->data==k)
                break;
            prev=cur;
            cur=cur->link;

        }
        if(cur==null)
        {

            printf("key not found\n");}
        else
                {
         printf("enter element to be inserted\n");
     scanf("%d",&d);
        temp=(struct node *)malloc(sizeof(struct node));
         temp->data=d;
         temp->link=null;
         prev->link=temp;
    temp->link=cur;
            }
        }

    }


