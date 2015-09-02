#include<stdio.h>
#include<conio.h>

struct stream {
  char ch;
  int count;
  struct stream *next;
};

void main (){
   char c;
   int flag=0,flag1=0;
   struct stream *node,*node1;
   node=NULL;
   while (1) {

      printf("inter char\n");
      c=getch();
      if(node == NULL){
          printf("[1]first non reapting char :  %c\n",c );
          struct stream *temp=(struct stream *) malloc (sizeof(struct stream));
          temp->ch = c;
          temp->count=1;
          temp->next=NULL;
          node=temp;
      }else {
          node1=node;
        //  printf("going through link list\n");
          while(node1!=NULL){
            //  printf("node->ch=%c\tnode->count=%d\n",node1->ch,node1->count);
              if(node1->ch == c){
                  node1->count++;
                  flag=1;
              }
              if(node1->count ==1 && flag1==0){
                    printf("first non reapting char :  %c\n",node1->ch );
                    flag1=1;
              }
              node1=node1->next;
          }
          if(flag1==0 && flag == 0){
              printf("first non reapting char :  %c\n",c );
              struct stream *temp1=(struct stream *) malloc (sizeof(struct stream));
              temp1->ch = c;
              temp1->count=1;
              temp1->next=NULL;
              node1=node;
              while(node1->next!= NULL) node1=node1->next;
              node1->next=temp1;
          }
          if(flag1==0)
             printf("no non reapting char");
          if(flag ==0 ){
          //    printf("here\n");
              struct stream *temp2=(struct stream *) malloc (sizeof(struct stream));
              temp2->ch = c;
              temp2->count=1;
              temp2->next=NULL;
              node1=node;
              while(node1->next!= NULL) node1=node1->next;
              node1->next=temp2;
          }
      }
flag=0;
flag1=0;
   }

}