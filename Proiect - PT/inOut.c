#include "inOut.h"
#include "list.h"
#include "polish.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    int declare_var(char *line){
        char var = line[0];
        long long val=0;
        if(line[2]=='-'){
            for(i=3; line[i]!='\0'; ++i)
            {
                val = val*10+(line[i]-48);
            }
            val=-val;
        }
        else{
            for(i=2; line[i]!='\0'; ++i)
            {
                val = val*10+(line[i]-48);
            }
        }
        VAR[var-'a']=val;
        return val;
    }

    void read(){
        while(1)
        {
            char line[1024];
            printf("> ");
            gets(line);
            int equal=0,i;

            for(i=0;line[i]!='\0';++i)
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
            if(equal){
                printf("- %lld\n", declare_var(line));
            }
            else{
                char prr[100];
                infix2postfix(&line[0],&prr[0],1);
                prr[strlen(prr)-1]='\0';
                struct node *r;
                make_tree(&prr[0],&r);
                printf("- %lld\n",evaluatetree(r));
            }
        }
    }

