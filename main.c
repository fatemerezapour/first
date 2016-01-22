#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct number{
int  counter ;
char adad[10];
struct number* next;
}numb;
numb *start2;
struct tl1{
struct tl1 *next;
struct tl1 *pre;
char data[30];
char atri[10];
int line;
int b;
int c;

};
typedef struct tl1 tl1;
typedef struct tl1* tl1ptr;
//int iskey(char a[] , tl1ptr cur ,tl1ptr start)

void tablenumb( tl1ptr start ){
   tl1ptr current;
   numb* w;//
   int i=0;
   current=start->next;
   while(current!=0)
   {
       if(strcmpi(current->data , "num")==0)
           {
               w=(numb*)malloc(sizeof(numb));
               start2->next=w;
               start2=start2->next;
               start2->adad=current->data;
               start2->counter=i;
               start2->next=0;
                i++;
   }
   current=current->next;
}}

int searchnum(tl1ptr r,numb* start2)
{
    while(start2!=0)
    {
        if(strcmpi(r->data,start2->adad)==0)
        {
            return start2->counter;
        }
        start2=start2->next;
    }
}
int searchnum(tl1ptr r)
{
    while(start3!=0)
    {
        if(strcmpi(r->data,start3->name)==0)
        {
            return start3->index;
        }
        start3=start3->next;
    }
}
int typch(tl1ptr p)
{
    char s[20];
    s=p->data;
    int t=0,i=0,u=0;
    strcpy(s,p->data);
    while(s!=NULL){
        if(isdigit(s[i])){
            ++t;
        }
        if(u==1){
            if(strcmpi(g[i],".")==0){
                ++u;
                ++t;
            }
        }
    }
        if(i==t)
              return 1;//int
       else if(i==t+1)
              return 2;//float
       else
          return 3;//id

}

tl1ptr state(tllptr p)
{
    tl1ptr r;
    if(strcmpi(p->data,"if")==0)
    {
        fprintf(fp,"IF");//last file
        p=p->next;
        while(strcmpi(p->data,"{")!=0)
        {
           r=condition(p);
           p=r;
        }
        fprintf(fp,"GOTO \n");
        p=p->next;
    }
    else if(strcmpi(p->data,"else")==0){
        fprintf(fp,"ELSE");//last file
        p=p->next;
        while(strcmpi(p->data,"{")!=0)
        {
           r=condition(p);
           p=r;
        }

        p=p->next;
    }

    else if((strcmpi(p->data,"int")==0) || (strcmpi(p->data,"float")==0) || (strcmpi(p->data,"char")==0) || (strcmpi(p->data,"bool")==0 || (strcmpi(p->data,"return")==0)
      {
        while(strcmpi(p->data,";")!=0)
        {
          r=condition(p);
          p=r;
    }
    p=p->next;
}
tl1ptr condition(tllptr x)
{
    int i,e;
    i=typch(x->data);
    if((i==1)||(i==2))
    {
        q=searchnum(x);
        fprintf(fp"T_%d%s",q,x->data);

    }
    else if(i==4)
    {
        e=searchname(x);
        fprintf(fp,"T%d",e);
        }

     else if((strcmpi(x->data,"+")==0)||(strcmpi(x->data,"-")==0)||(strcmpi(x->data,"*")==0)||(strcmpi(x->data,"/")==0)||(strcmpi(x->data,"==")==0)||(strcmpi(x->data,"!=")==0)||(strcmpi(x->data,"<=")==0)||(strcmpi(x->data,">=")==0)||(strcmpi(x->data,"||")=0)||(strcmpi(x->data,"&&")==0))
        {
            fprintf(fp,"%s",x->data);
        }
     else if((strcmpi(x->d,"=")==0)
                {
                    fprintf(p,":=");
                }
    x=x->next;
    return x;
}


void add(tl1ptr start , char a[] ,int line )
{
    tl1ptr current;
    tl1ptr new;
    tl1ptr t;
    int z=0;
    new=malloc(sizeof(tl1));
    new->next=0;
    new->c=0;
    current=start;
    strcpy(new->data , a);
    new->line= line;
    while(current -> next != 0)
    {
        current = current -> next;
    }
    current-> next = new;
    new->pre = current;
}
void tokenise(tl1ptr start)
{

FILE *p;
FILE *s;
char m[200];
char *ptr;
int line=1;
p=fopen("data.txt" ,"r");
fgets(m,200,p);

s=strtok(m," ");

while(s!=0)
{

    add(start ,s, line);
    s=strtok(NULL ," ");

}

line++;

while(!feof(p))
{
    fgets(m,200,p);

s=strtok(m," ");

while(s!=0)
{

    add(start ,s, line);
    s=strtok(NULL ," ");

}
line++;
}

}


struct st{
char name[10];
char value[20];
char type[10];
int index;
struct st *pre;
struct st *next;
int b;

};
typedef struct st st;
typedef struct st* stptr;
void makesymboltable(tl1ptr start , stptr start2)
{
    int i=0;
    tl1ptr cur ;
    stptr cur2 ;
    stptr new;
    cur=start->next;
    cur2=start2;

    while(cur != 0 )
    {
        if((strcmpi(cur->data , "int")==0 || strcmpi(cur->data, "float")==0 || strcmpi(cur->data , "char")==0 || strcmpi(cur->data,"bool")==0))
        {
            i++;
            new=malloc(sizeof(st));
            strcpy(new->type , cur->data);
            new->b=0;
            cur2->next=new;
            new->pre=cur2;
            if(cur->next!=0)
            {
                cur = cur->next;
                strcpy(new->name ,cur->data );
            }
            cur2=new;
        }
        cur=cur->next;
    }
    if(i!=0)
        new->next=0;
}

void sede(stptr start)
{
    stptr temp;
    stptr current;
    current=start->next;

    if(current!=0 && current->next!=0)
    {temp=current->next;
    while(temp!=0)
    {
        current=temp->pre;
        while(current!=0 )
        {
            if(strcmpi(current->name ,temp->name )==0)
            {
                temp->b=1;
            }
            current=current->pre;
        }


        temp=temp->next;
    }
    }
}
void index(stptr start)
{
    int index=0;
    stptr current = start->next;
    while(current!=0)
    {
        if(current->b == 0)
        {
            current->index=index;
            index++;
        }
        else
        {
            current->index= -1;
        }
        current=current->next;
    }
}
struct tl1{
struct tl1 *next;
char data[10];
int line;
};
typedef struct tl1 tl1;
typedef struct tl1* tl1ptr;
tl1ptr cur;
tl1ptr key1(tl1ptr p)
{
    tl1ptr curr;
    char a[10],b[10],d[10];
    int c=0,n;
    curr = p->next;
    if(strcmpi(curr->data,";")==0){
        printf("error in line%d,expected %s,seen %s",curr->line,"id",curr->data);
    }
while(strcmpi(curr->data, ";")!= 0){
 if(c==0){
      strcpy(a,curr->data);
      if(!((a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')))
    {
          printf("error in line %d expected %s seen %s" , curr->line,"id",curr->data);

    }
      ++c;
     n=1;
    }

 else if(c==1){
      if((strcmpi(curr->data,"=")!=0 )){
         printf("error in line %d,expected %s,seen %s",curr->line,"=",curr->data);
    }
    ++c;
    n=0;
    }
 else if(c==2){
        strcpy(b,curr->data);
        if(!(b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z') || (b[0]>='1' && b[0]<='9')){
             printf("error in line %d,expected %s or %s ,seen %s",curr->line,"id","num",curr->data);
     }
     n=1;
     ++c;
     }
 else if(c==3){
        if(!( strcmpi(curr->data,"+")) || (strcmpi(curr->data,"-")) || (strcmpi(curr->data,"*")) || (strcmpi(curr->data,"/"))){
             printf("error in line %d,expected %s,seen %s",curr->line,"op",curr->data);
            }
    n=0;
    ++c;
 }
 else if(c==4){
     if(!(d[0]>='a' && d[0]<='z') || (d[0]>='A' && d[0]<='Z') || (d[0]>='1' && d[0]<='9')){
            printf("error in line %d,expected %s or %s,seen %s",curr->line,"id" ,"num",curr->data);
     }
      n=1;

 }
curr=curr->next;
if(n==0){
    if(strcmpi(curr->data,";")==0)
        printf("error in line %d,expected%s,seen%s",curr->line,"id",curr->data);
}
    }
return curr;
}

tl1ptr key5(tl1ptr p){
   tl1ptr curr;
    int c=0,n;
    curr = p->next;
    char a[10],b[10];
    if(strcmpi(curr->data,";")==0){
        printf("error in line%d,expected %s,seen %s",curr->line,"id",curr->data);
    }
while(strcmpi(curr->data, ";")!= 0){
  if(c==0){
        strcpy(a,curr->data);
        if(!((a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')))
    {
           printf("error in line %d,expected %s,seen %s",curr->line,"id",curr->data);

    }
    ++c;
    n=1;
    }
 else if(c==1){
        if(strcmpi(curr->data,"=")!=0 ){
         printf("error in line %d,expected %s,seen %s",curr->line,"op",curr->data);
    }
    ++c;
    n=0;
 }
 else if(c==2){
          if(strcmpi(curr->data,"'")!=0)
        {
             printf("error in line %d,expected %s,seen %s",curr->line,"'",curr->data);
        }
        n=0;
        ++c;
    }
 else if(c==3){
        strcpy(b,curr->data);
        if(!(b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z') || (b[0]>='1' && b[0]<='9')){
           printf("error in line %d,expected %s or %s,seen %s",curr->line,"id","num",curr->data);
           }
           ++c;
           n=0;
 }
 else if(c==4){
         if(strcmpi(curr->data,"'")!=0){
           printf("error in line %d,expected %s,seen %s",curr->line,"'",curr->data);
        }
           n=1;
           ++c;
      }
    curr=curr->next;
    if(n==0){
         printf("error in line %d,expected %s,seen %s",curr->line,"'",curr->data);
     }
    }
    return curr;
}

tl1ptr key6(tl1ptr p){
   tl1ptr curr;
    int c=0,n;
    curr = p->next;
    char a[10];
    if(strcmpi(curr->data,";")==0){
        printf("error in line%d,expected %s,seen %s",curr->line,"id",curr->data);
    }
while(strcmpi(curr->data, ";")!= 0){
  if(c==0){
        strcpy(a,curr->data);
        if(!((a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')))
    {
           printf("error in line %d,expected %s,seen %s",curr->line,"id",curr->data);
    }
    n=1;
    ++c;
    }
 else if(c==1){
        if(strcmpi(curr->data,"=")!=0 ){
           printf("error in line %d,expected %s,seen %s",curr->line,"op",curr->data);
       }
   n=0;
   ++c;
    }
  else if(c==2){
        if(strcmpi(curr->data,"true")!=0 || strcmpi(curr->data,"false")!=0){
           printf("error in line %d,expected %s,seen %s",curr->line,"bool",curr->data);
        }

  }
curr=curr->next;
if(n==0){
    printf("error in line%d,expected %s,seen %s",curr->line,"id",curr->data);
}

    }
    return curr;
}

tl1ptr key4(tl1ptr p){
   tl1ptr curr;
    int c=0,m=0,n,x;
    char b[10],d[10],f[10];
    curr = p->next;
    if(strcmpi(curr->data,";")==0){
        printf("error in line%d,expected %s,seen %s",curr->line,"id",curr->data);
    }
while(strcmp(curr->data, ";")!= 0){
    if(c==0){
         curr=curr->next;
         printf("%s",curr->data);
        if(strcmpi(curr->data,"=")!=0){
            printf("error in line %d,expected %s,see %s",curr->line,"op",curr->data);
        }
        ++c;
        n=0;
    }
 else if(c==1){
       if((strcmp(curr->data,"'")!=0) ){
             printf("error in line %d,expected or %s or %s,see %s",curr->line,"'","bool",curr->data);
             n=0;
             x=0;
       }
        strcpy(b,curr->data);
       if(!(b[0]>'0' && b[0]<'9') ||(b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z')){
            printf("error in line %d,expected or %s or %s,see %s",curr->line,"num","id",curr->data);
            n=1;
            x=1;
                }
        if(strcmpi(curr->data,"true")!=0){
                printf("error in line %d,expected  %s,see %s",curr->line,"bool",curr->data);
                x=2;
    }

      ++c;
 }
 else if(c==2){
        strcpy(f,curr->data);
        if(x==0){
           if(!((f[0]>='a' && f[0]<='z') || (f[0]>='A' && f[0]<='Z')))
         {
             printf("error in line %d,expected %s,see %s",curr->line,"id",curr->data);
             n=0;
            }
        if(x==1){
            if(!( strcmpi(curr->data,"+")) || (strcmpi(curr->data,"-")) || (strcmpi(curr->data,"*")) || (strcmpi(curr->data,"/"))){
             printf("error in line %d,expected %s,seen %s",curr->line,"op",curr->data);
            }
             n=0;
        }
      ++c;
       }
 }
 else if(c==3){
    if(x==0){
        if(strcmpi(curr->data,"'" )!=0){
            printf("error in line %d,expected %s,see %s",curr->line,"'",curr->data);
        }
    }
    if(x==1){
       strcpy(d,curr->data);
      if(!(d[0]>'0' && d[0]<'9') ||(d[0]>='a' && d[0]<='z') || (d[0]>='A' && d[0]<='Z')) {
           printf("error in line %d,expected %s or %s,see %s",curr->line,"num","id",curr->data);
         }
    }
      ++c;
     }

     curr=curr->next;
     if(n==0){
        printf("error in line %d,expected %s or %s,see %s",curr->line,"num","id",curr->data);
     }
     if(m!=1){
        if(x==2){
          printf("error in line %d,expected %s ,see %s",curr->line,";",curr->data);
          m=1;}
     }
 }
return curr;
}

tl1ptr key2(tl1ptr p){
   tl1ptr curr,t;
    char d[10],m[10];
    int c=0,n=0;
    curr = p->next;
    if(strcmpi(curr->data,";")==0){
        printf("error in line%d,expected %s,seen %s",curr->line,"(",curr->data);
    }
while(strcmpi(curr->data, ";")!= 0){
  if(c==0){
    if(strcmpi(curr->data,"(")!=0){
        printf("error in line %d,expected %s,see %s",curr->line,"(",curr->data);
    }
    ++c;
}
 else if(c==1){
      strcpy(d,curr->data);
      if(!((d[0]>='a' && d[0]<='z') || (d[0]>='A' && d[0]<='Z'))){
         printf("error in line %d,expected %s,seen %s",curr->line,"id",curr->data);
     }

     ++c;
   }
 else if(c==2){
        if(!(strcmpi(curr->data,"==")) || (strcmpi(curr->data,"!=")) || (strcmpi(curr->data,">=")) || (strcmpi(curr->data,"<=")) || (strcmpi(curr->data,"&&")) || (strcmpi(curr->data,"||")) || (strcmpi(curr->data,"<")) || (strcmpi(curr->data,">")))
        {
                  printf("error in line %d,expected %s,seen %s",curr->line,"op",curr->data);
         }
     c+=2;
 }
else if(c==4){
         strcpy(m,curr->data);
        if(!(m[0]>'0' && m[0]<'9') ||(m[0]>='a' && m[0]<='z') || (m[0]>='A' && m[0]<='Z')){
            printf("error in line %d,expected %s or %s,seen %s",curr->line,"op","id",curr->data);
        }

    ++c;
}
else if(c==5){
         if(strcmpi(curr->data,")")!=0){
          printf("error in line %d,expected %s,see %s",curr->line,"(",curr->data);
    }

    ++c;
   }
else if(c==6){
         if(strcmpi(curr->data,"{")!=0){
           printf("error in line %d,expected %s,see %s",curr->line,"{",curr->data);
    }

    ++c;
   }
else if(c==7){
        curr=curr->next;
        t=key1(curr);
        curr=t;
        n=1;
}
if(n!=1){
    curr=curr->next;}
if(strcmpi(curr->data,";")==0){
      printf("error in line %d,unexpected %s",curr->line,curr->data);
    }
         }
        curr=curr->next;
if(strcmpi(curr->data,"}")==0){
      printf("error in line %d,unexpected %s",curr->line,curr->data);
    }

    return curr;
    }

tl1ptr key3(tl1ptr p){
   tl1ptr curr,t;
    int c=0,n=0;
    curr = p->next;
    if(strcmpi(curr->data,";")==0){
        printf("error in line%d,expected %s,seen %s",curr->line,"{",curr->data);
    }
while(strcmpi(curr->data, ";")!= 0){
  if(c==0){
        if(strcmpi(curr->data,"{")!=0){
        printf("error in line %d,expected %s,see %s",curr->line,"{",curr->data);
    }
    ++c;
}
 else if(c==1){
        t=key1(curr);
        curr=t;
        n=1;
}
curr=curr->next;
if(strcmpi(curr->data,"}")!=0){
        printf("error in line %d,expected %s,see %s",curr->line,"}",curr->data);
        }
}
if(n==1){
   if(strcmpi(curr->data,"}")!=0){
        printf("error in line %d,expected %s,see %s",curr->line,"}",curr->data);
        }
    }
return curr;
    }
tl1ptr key8(tl1ptr p){
   tl1ptr curr,t;
    char d[10],m[10];
    int c=0,n=0;
    curr = p->next;
    if(strcmpi(curr->data,";")==0){
        printf("error in line%d,expected %s,seen %s",curr->line,"(",curr->data);
    }
while(strcmpi(curr->data, ";")!= 0){
  if(c==0){
    if(strcmpi(curr->data,";")!=0){
        printf("error in line %d,expected %s,see %s",curr->line,";",curr->data);
    }
    ++c;
}
 else if(c==1){
      strcpy(d,curr->data);
      if(!((d[0]>='a' && d[0]<='z') || (d[0]>='A' && d[0]<='Z'))){
         printf("error in line %d,expected %s,seen %s",curr->line,"id",curr->data);
     }

     ++c;
   }
 else if(c==2){
        if(!(strcmpi(curr->data,"=")) || (strcmpi(curr->data,"!")) || (strcmpi(curr->data,">")) || (strcmpi(curr->data,"<")) || (strcmpi(curr->data,"&")) || (strcmpi(curr->data,"|")))
              {
                  printf("error in line %d,expected %s,seen %s",curr->line,"op",curr->data);
              }
     ++c;
 }
 else if(c==3){
       if(!(strcmpi(curr->data,"=")) || (strcmpi(curr->data,"&")) || (strcmpi(curr->data,"|"))){
               printf("error in line %d,expected %s,seen %s",curr->line,"op",curr->data);
 }
    ++c;
}
else if(c==4){
         strcpy(m,curr->data);
        if(!(m[0]>'0' && m[0]<'9') ||(m[0]>='a' && m[0]<='z') || (m[0]>='A' && m[0]<='Z')){

        printf("error in line %d,expected %s or %s,seen %s",curr->line,"op","id",curr->data);
        }
    ++c;
}
else if(c==5){
         if(strcmpi(curr->data,")")!=0){
           printf("error in line %d,expected %s,see %s",curr->line,"(",curr->data);
    }

    ++c;
   }
else if(c==6){
         if(strcmpi(curr->data,"{")!=0){
           printf("error in line %d,expected %s,see %s",curr->line,"{",curr->data);
    }

    ++c;
   }
else if(c==7){
        t=key1(curr);
        curr=t;
        n=1;
}

if(n!=1){
    curr=curr->next;
}
if(strcmpi(curr->data,"}")!=0){
        printf("error in line %d,expected %s,see %s",curr->line,"}",curr->data);
    }
      }
   curr=curr->next;
if(strcmpi(curr->data,"}")!=0){
        printf("error in line %d,expected %s,see %s",curr->line,"}",curr->data);
    }
    return curr;
    }

tl1ptr key9(tl1ptr p){
   tl1ptr curr;
    int c=0;
    curr = p->next;
    if(strcmpi(curr->data,";")==0){
        printf("error in line%d,expected %s,seen %s",curr->line,"main",curr->data);
    }
while(strcmpi(curr->data, "{")!= 0){
  if(c==0){
      if(strcmpi(curr->data, "main")!= 0){
           printf("error in line %d,expected %s,see %s",curr->line,"main",curr->data);
      }
      ++c;
  }
  else if(c==1){
     if(strcmpi(curr->data, "(")!= 0){
           printf("error in line %d,expected %s,see %s",curr->line,"(",curr->data);
      }
      ++c;
  }
  else if(c==2){
    if(strcmpi(curr->data, ")")!= 0){
           printf("error in line %d,expected %s,see %s",curr->line,")",curr->data);
      }
      ++c;
  }
  curr=curr->next;
  if(c==2){
    if(strcmpi(curr->data,"}")!=0)
        printf("error in line %d,expected %s,see %s",curr->line,"}",curr->data);
  }
  }
  return curr;
}
int what(tl1ptr x){
char a[10];
if((strcmpi(x->data,"int")==0 )) {
  return 1;}
if(strcmpi(x->data , "if")==0){
    return 2 ;}
if(strcmpi(x->data , "else")==0){
    return 3;}
if(strcmpi(x->data , "else if")==0){
    return 8;}
if(strcmpi(x->data,"char")==0){
    return 5;}
if(strcmpi(x->data,"bool")==0){
    return 6;}
if(strcmpi(x->data,"void")==0){
    return 9;}
strcpy(a,x->data);
if((a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')){
    return 4;}
else
    return 7;

}
void syntax(tl1ptr start1)
{
    tl1ptr curr =start1;
   tl1ptr root=0;
    int a;
while(curr!=0){
    a=what(curr );
    if(a==1){
            root = key1(curr);}
    if(a==2){
            root=key2(curr);}
    if(a==3){
            root=key3(curr);}
    if(a==4){
            root=key4(curr);}
    if(a==5){
            root=key5(curr);}
    if(a==6){
             root=key6(curr);}
    if(a==8){
             root=key8(curr);}
    if(a==9){
             root=key9(curr);}

    else{
            printf(" error in line %d" ,curr->line);}
    curr=root->next;
    }
return ;
}
//end of each statement should be ;
void main()
{
    char a[12];
    FILE* p;
    FILE* s;
    FILE* z;
    p=fopen("include.text" , "r");
    p=fopen("data.text" ,"w");
    z=fopen("main.text" ,"r");
    fscanf(p ,"%s" ,a);
    fpritf(s,"%s" ,a);
    while(!feof(p))
    {
        fscanf(p ,"%s" ,a);
        fprintf(s,"%s" ,a);
    }
    fscanf(z,"%s" , a);
    fprintf(s,"%s" ,a);
    while(!feof(z))
    {
        fscanf(z,"%s" ,a);
        fprintf(s,"%s" ,a);
    }
syntax(start);
state(start);

}
