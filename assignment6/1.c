#include<stdio.h>
int main(){
	char s1[10], s2[10];
	int i=0, j=0, flag;
	printf("Enter string1: ");
	scanf("%s", s1);
	printf("Enter string2: ");
	scanf("%s", s2);
	while(s1[i] != '\0'){
		flag = 0;
		j = 0;
		while(s2[j] != '\0'){
			if(s1[i] == s2[j]){
				flag = 1;
				break;
			}
			j++;
		}
		if(flag == 0){
			break;
		}
		i++;
	}
	if(flag == 1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
