// array
#include<stdio.h>
#include<stdlib.h>
int a[10], pos, elem;
int n = 0;
void create();
void display();
void insert();
void del();
void main()
{
int choice;
while(1)
{
printf("\n\n~~~~MENU~~~~");
printf("\n=>1. Create an array of N integers");
printf("\n=>2. Display of array elements");
printf("\n=>3. Insert ELEM at a given POS");
printf("\n=>4. Delete an element at a given POS");
printf("\n=>5. Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1: create();
break;
case 2: display();
break;
case 3: insert();
break;
case 4:del();
break;
case 5:exit(1);
break;
default:
printf("\nPlease enter a valid choice:");
}
}
}
void create()
{
int i;
printf("\nEnter the number of elements: ");
scanf("%d", &n);
printf("\nEnter the elements: ");
for(i=0; i<n; i++)
{
scanf("%d", &a[i]);
}
}
void display()
{
int i;
if(n == 0)
{
printf("\nNo elements to display");
return;
}
printf("\nArray elements are: ");
for(i=0; i<n;i++)
printf("%d\t ", a[i]);
}
void insert()
{
int i;
if(n == 5)
{
printf("\nArray is full. Insertion is not possible");
return;
}
do
{
printf("\nEnter a valid position where element to be inserted: ");
scanf("%d", &pos);
}while(pos > n);
printf("\nEnter the value to be inserted: ");
scanf("%d", &elem);
for(i=n-1; i>=pos ; i--)
{
a[i+1] = a[i];
}
a[pos] = elem;
n = n+1;
display();
}
void del()
{
int i;
if(n == 0)
{
printf("\nArray is empty and no elements to delete");
return;
}
do
{
printf("\nEnter a valid position from where element to be deleted: ");
scanf("%d", &pos);
}while(pos>=n);
elem = a[pos];
printf("\nDeleted element is : %d \n", elem);
for( i = pos; i< n-1; i++)
{
a[i] = a[i+1];
}
n = n-1;
display();
}






//stack
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int s[5],top=-1;
void push()
{
if(top==4)
printf("\nStack overflow!!!!");
else
{
printf("\nEnter element to insert:");
scanf("%d",&s[++top]);
}
}
void pop()
{
if(top==-1)
printf("\nStack underflow!!!");
else
printf("\nElement popped is: %d",s[top--]);
}
void disp()
{
int t=top;
if(t==-1)
printf("\nStack empty!!");
else
printf("\nStack elements are:\n");
while(t>=0)
printf("%d ",s[t--]);
}
void pali()
{
int num[5],rev[5],i,t;
for(i=0,t=top;t>=0;i++,t--)
num[i]=rev[t]=s[t];
for(i=0;i<=top;i++)
if(num[i]!=rev[i])
break;
if(i==top+1)
printf("\nIt is a palindrome");
else
printf("\nIt is not a palindrome");
}
int main()
{
int ch;
do
{
printf("\n...Stack operations.....\n");
printf("1.PUSH\n");
printf("2.POP\n");
printf("3.Palindrome\n");
printf("4.Display\n");
printf("5.Exit\n________________\n");
printf("Enter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:push();break;
case 2:pop();break;
case 3:pali();break;
case 4:disp();break;
case 5:exit(0);
default:printf("\nInvalid choice");
}
}
while(1);
return 0;
}






//infix postfix
#include<stdio.h>
#include<stdlib.h>
void evaluate();
void push(char);
char pop();
int prec(char);
char infix[30], postfix[30], stack[30];
int top = -1;
void main()

{
printf("\nEnter the valid infix expression:\t");
scanf("%s", infix);
evaluate();
printf("\nThe entered infix expression is :\n %s \n", infix);
printf("\nThe corresponding postfix expression is :\n %s \n", postfix);
}
void evaluate()
{
int i = 0, j = 0;
char symb, temp;
push('#');
for(i=0; infix[i] != '\0'; i++)
{
symb = infix[i];
switch(symb)
{
case '(' : push(symb);
break;

case ')' : temp = pop();
while(temp != '(' )
{
postfix[j] = temp;
j++;
temp = pop();

}
break;
case '+' :
case '-' :
case '*' :
case '/' :
case '%' :
case '^' :
case '$' : while( prec(stack[top]) >= prec(symb) )
{
temp = pop();
postfix[j] = temp;
j++;
}
push(symb);
break;
default: postfix[j] = symb;
j++;
}
}
while(top > 0)
{
temp = pop();
postfix[j] = temp;
j++;
}

postfix[j] = '\0';
}
void push(char item)
{
top = top+1;
stack[top] = item;
}
char pop()
{
char item;
item = stack[top];
top = top-1;
return item;
}
int prec(char symb)
{
int p;
switch(symb)
{
case '#' : p = -1;
break;

case '(' :
case ')' : p = 0;
break;

case '+' :
case '-' : p = 1;
break;
case '*' :
case '/' :
case '%' : p = 2;
break;
case '^' :
case '$' : p = 3;
break;
}
return p;
}









//graph
#include<stdio.h>
#include<stdlib.h>
int a[50][50], n, visited[50];
int q[20], front = -1,rear = -1;
int s[20], top = -1, count=0;
void bfs(int v)
{
int i, cur;
visited[v] = 1;
q[++rear] = v;
while(front!=rear)
{
cur = q[++front];
for(i=1;i<=n;i++)
{
if((a[cur][i]==1)&&(visited[i]==0))
{
 q[++rear] = i;
visited[i] = 1;
printf("%d ", i);
}
}
}
}
void dfs(int v)
{
 int i;
visited[v]=1;
s[++top] = v;
for(i=1;i<=n;i++)
{
if(a[v][i] == 1&& visited[i] == 0 )
{
 printf("%d ", i);
dfs(i);
}
}
}
int main()
{
 int ch, start, i,j;
 printf("\nEnter the number of vertices in graph:  ");
 scanf("%d",&n);
 printf("\nEnter the adjacency matrix:\n");
 for(i=1; i<=n; i++)
 {
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
}
for(i=1;i<=n;i++)
 visited[i]=0;
printf("\nEnter the starting vertex: ");
scanf("%d",&start);
printf("\n==>1. BFS: Print all nodes reachable from a given starting node");
printf("\n==>2. DFS: Print all nodes reachable from a given starting node");
printf("\n==>3:Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("\nNodes reachable from starting vertex %d are: ", start);
bfs(start);
for(i=1;i<=n;i++)
{
if(visited[i]==0)
printf("\nThe vertex that is not reachable is %d" ,i);
}
break;
case 2: printf("\nNodes reachable from starting vertex %d are:\n",start);
dfs(start);
break;
 case 3: exit(0);
 default: printf("\nPlease enter valid choice:");
}
}