#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int Q[64];
int count = 0;

void pop(){
	int res = Q[0];
	if(count==0){
		printf("Is empty!\n");
	}
	else{
		printf("Pop %d\n",res);
		for(int i=0;i<count-1;i++){
			Q[i]=Q[i+1];
		}
		count--;
	}
}
void push(int num){
	if(count>=63){
		printf("Is full!\n");
	}
	else{
		Q[count] = num;
		count++;
	}
}


void Print(){
	printf("Queue:");
	for(int i=0;i<count;i++){
		printf(" %d",Q[i]);
	}
	printf("\n");
}

char *getword(char *line,char *word){
	char *ptr = line;
	char *qtr = word;
	while(isspace(*ptr) && *ptr){
		ptr++;
	}
	while(!isspace(*ptr) && *ptr){
		*qtr++ = *ptr++;
	}
	*qtr='\0';
	if(qtr-word==0){
		return NULL;
	}
	return ptr;
}

int main(){
	char line[1024];
	char *ptr;
	char word[100];
	while(fgets(line,1024,stdin)){
		ptr = line;
		while(ptr = getword(ptr,word)){
				if(strcmp(word,"pop")==0){
					pop();
				}
				if(strcmp(word,"push")==0){
					push(atoi(ptr));
				}	
				if(strcmp(word,"print")==0){
					Print();
				}
		}
	}
}
