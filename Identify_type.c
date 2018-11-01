/*A-Nony-Mus
28 Mar. 2012
This program identifies the input as certain types of data*/

#include <stdio.h>
#include <ctype.h>

typedef enum
	{identifier, number}
	state;

void print_type(state x);

int main(void)
{
int lcv;
state id;

printf("Please input what you would like to have interpreted: ");   //Prompt for user input

//As long as the input is not a period
do{
    lcv = getchar();    //Read the user input
    
	if(isalpha(lcv)){ //If the scanned character is a letter
        id = identifier;
        while (lcv != ' ' && lcv != '.'){   //Keep reading and printing until it reaches a space
            printf("%c", lcv);
            lcv = getchar();
        }
        printf(" - ");
		print_type(id); //Print what type of data it is
		}
	else if(isdigit(lcv)){  //If the scanned character is a number
		id = number;
        while (lcv != ' ' && lcv != '.'){   //Keep reading and printing until it reaches a space
            if (isalpha(lcv))   //If any letter is detected, the type is identifier
                id = identifier;
            printf("%c", lcv);
            lcv = getchar();
        }
        printf(" - ");
		print_type(id); //Print what type of data it is
		}
	//lcv = getchar();

}while(lcv != '.');
    
return(0);
}

//Inputs: A variable of enumerated type state
//Outputs: Prints what value of the variable
void print_type(state x){
switch(x){
case identifier:
printf("identifier\n");
break;
case number:
printf("number\n");
}
}
