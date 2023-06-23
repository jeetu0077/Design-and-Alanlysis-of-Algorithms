#include<stdio.h>

#define LEN  4 //As we have to do it for quarters,dimes,nickels and pennies

void greedy(int amount){
	
	int i=0;//Index of the array
	int number;//The number of least amount of coin for a specific coin value
	int coin_set[LEN]= {25, 10, 5, 1};
	
	printf("The least amount of coins needed for the amount %d are: \n", amount);
	
	while(i < LEN){
		
		if(coin_set[i] <= amount){
			number = amount/coin_set[i];
			
			 if(coin_set[i] == 25 ){
				 printf("%d quarters\n",number);
			 }
			 if(coin_set[i] == 10 ){
				 printf("%d dimes\n",number);
			 }
			 if(coin_set[i] == 5 ){
				 printf("%d nickels\n",number);
			 }
			 if(coin_set[i] == 1 ){
				 printf("%d pennies\n",number);
			 }
			
			amount = amount - number *coin_set[i];
		}
		
		i++;
}}

int main(void){
	int amount = 69;
  greedy(amount);
	}