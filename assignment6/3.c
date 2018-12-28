#include<stdio.h>
#include<string.h>
void swap(char *p, char*q){
	char temp;
	temp = *p;
	*p = *q;
	*q = temp;	
}

int checkAsciiCodes(char *str){
	if((*str >= 'a' && *str <= 'z')  || (*str >= 'A' && *str <= 'Z')){
		return 1;
	}else{
		return 0;
	}
}


void remove_non_characters(char *str){
	int len = strlen(str), i,j, flag = 0;
	char temp;
	for(i=0; i<len; i++){
		if(!checkAsciiCodes(str+i)){
			j = i+1;
			flag = 0;
			while(j<len){	
				if(!checkAsciiCodes(str+j)){
					j++;
				}else{
					swap(str+i, str+j);
					flag = 1;
					break;	
				}		
			}
			if(!flag){
				*(str+i) = '\0';
			}	
		}
	}
	printf("%s\n", str);
}

int main(){
	char string[20];
	printf("Enter the string: ");		
	scanf("%s", string);
	remove_non_characters(string);
	return 0;
}
