#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
#define EMPTY -1

long long i,VAR[50];

void afisare(int x){
    printf("- %d\n",x);
}

int declare_var(char *line){
    int lenght = strlen(line);
    char var = line[0];
    long long val=0;
    if(line[2]=='-'){
        for(i=3; i<lenght; ++i)
        {
            val = val*10+(line[i]-48);
        }
        val=-val;
    }
    else{
        for(i=2; i<lenght; ++i)
        {
            val = val*10+(line[i]-48);
        }
    }
    VAR[var-'a']=val;
    afisare(val);
}

struct node{
	char kind;
	char op;
	int number;
	struct node *left,*right;
};

struct stack{
	struct node *data[MAX];
	int top;
};

int isempty(struct stack *s){
	return s->top == EMPTY;
}

void emptystack(struct stack* s){
	s->top=EMPTY;
}

void push(struct stack* s, struct node *item){
	if(s->top == (MAX-1))
	{
		printf("\nSTACK FULL");
	}
	else
	{
		++s->top;
		s->data[s->top]=item;
	}
}

struct node* pop(struct stack* s){
	struct node *ret=NULL;
	if(!isempty(s))
	{
		ret = s->data[s->top];
		--s->top;
	}
	return ret;
}

int isoperator(char e){
	if(e == '+' || e == '-' || e == '*' || e == '/' || e == '^')
		return 1;
    return 0;
}

int priority(char e){
	if(e == '*' || e == '/' || e =='^')
		return 2;
    return 1;
}

void infix2postfix(char* infix, char * postfix, int space){
	char *i,*p;
	struct stack X;
	char n1;
	emptystack(&X);
	i = &infix[0];
	p = &postfix[0];

	while(*i!='\0')
	{
		if( isdigit(*i) || isalpha(*i) )
		{
			while( isdigit(*i) || isalpha(*i))
			{
				*p = *i;
				p++;
				i++;
			}
			if(space)
			{
				*p = ' ';
				p++;
			}
		}
		else if( isoperator(*i) )
		{
		    if(*i=='-' && isoperator(*(i-1)) && (isdigit(*(i+1))))
            {
                *p = *i;
				p++;
				i++;
				while( isdigit(*i) || isalpha(*i))
                {
                    *p = *i;
                    p++;
                    i++;
                }
                if(space)
                {
                    *p = ' ';
                    p++;
                }
            }
            else if(*i=='-' && isoperator(*(i-1)) && (isalpha(*(i+1))))
            {
                *p = *i;
				p++;
                int w=VAR[*(i+1)-'a'];
                if(w<0){
                    p--;
                    w=-w;
                }
                i+=2;
                int ww=0;
                while(w){
                    ww=ww*10+w%10;
                    w/=10;
                }
                while(ww)
                {
                    *p=(char)(48+ww%10);
                    p++;
                    ww/=10;
                }
				if(space)
                {
                    *p = ' ';
                    p++;
                }
            }
            else
            {
                if(isempty(&X))
                    push(&X,*i);
                else
                {
                    n1 = pop(&X);
                    while(priority(n1) >= priority(*i))
                    {
                        *p = n1;
                        p++;
                        if(space)
                        {
                            *p = ' ';
                            p++;
                        }
                        n1 = pop(&X);
                    }
                    push(&X,n1);
                    push(&X,*i);
                }
                i++;
            }
        }
	}
	while(!isempty(&X))
	{
		n1 = pop(&X);
		*p = n1;
		p++;
		if(space)
		{
			*p = ' ';
			p++;
		}
	}
	*p = '\0';
}

void make_tree(char* postfix, struct node **root){
	struct stack X;
	struct node *newnode,*op1,*op2;
	char numberextract[100];
	char *p;

	emptystack(&X);
	p = &postfix[0];
	strcpy(numberextract,"");
	while(*p)
	{
		while(*p == ' ')
		{
			p++;
		}
		if(isdigit(*p))
		{
			while(isdigit(*p))
			{
				strcat(numberextract,p);
				p++;
			}
			newnode = malloc(sizeof(struct node));
			newnode->kind = 'N';
			newnode->number = atoi(numberextract);
			newnode->left = NULL;
			newnode->right = NULL;
			push(&X,newnode);
			strcpy(numberextract,"");
		}
		else if(!isoperator(*p))
        {
            newnode = malloc(sizeof(struct node));
			newnode->kind = 'N';
			newnode->number = VAR[*p-'a'];
			newnode->left = NULL;
			newnode->right = NULL;
			push(&X,newnode);
        }
		else
		{
		    if(*p=='-' && isdigit(*(p+1)))
            {
                strcat(numberextract,p);
				p++;
				while(isdigit(*p))
                {
                    strcat(numberextract,p);
                    p++;
                }
                newnode = malloc(sizeof(struct node));
                newnode->kind = 'N';
                newnode->number = atoi(numberextract);
                newnode->left = NULL;
                newnode->right = NULL;
                push(&X,newnode);
                strcpy(numberextract,"");
            }
            else if(*p=='-' && isalpha(*(p+1)))
            {
                newnode = malloc(sizeof(struct node));
                newnode->kind = 'N';
                newnode->number = -VAR[*p-'a'];
                newnode->left = NULL;
                newnode->right = NULL;
                push(&X,newnode);
            }
            else
            {
                op1 = pop(&X);
                op2 = pop(&X);
                newnode = malloc(sizeof(struct node));
                newnode->kind = 'O';
                newnode->op = *p;
                newnode->left = op2;
                newnode->right = op1;
                push(&X,newnode);
            }
        }
		p++;
	}
    *root = pop(&X);
}

int evaluatetree(struct node *x){
    if( x->kind == 'O' )
	{
        int op1 = evaluatetree( x->left );
        int op2 = evaluatetree( x->right );
        switch ( x->op )
        {
            case '+':   return op1 + op2;
            case '-':   return op1 - op2;
            case '*':   return op1 * op2;
            case '/':   return op1 / op2;
            case '^':   return pow(op1,op2);
            default:   return 0;
        }
    }
    else
        return x->number;
}

int read(){
    char line[1024],*var;
    printf("> ");
    gets(line);
    int lenght=strlen(line),equal=0,i;

    for(i=0;i<lenght;++i)
    {
        if(line[i] == ' ')
        {
            strcpy(line+i,line+i+1);
            i--;
        }
        else if(line[i] == '=')
             {
                equal=1;
             }
    }
    if(equal)
    {
        declare_var(line);
    }
    else
    {
        char prr[100];
        infix2postfix(&line[0],&prr[0],1);
        prr[strlen(prr)-1]='\0';
        struct node *r;
        make_tree(&prr[0],&r);
        printf("- %d\n",evaluatetree(r));
    }
}

int main(){
    while(1){
        read();
    }
    return 0;
}
