/*
	GRACEAL S. VILLAMOR
	AB - 3L
	SIMPLE BIOINFORMATICS LIBRARY
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "bioinfolib.h"

int main () {
	char *input1, *input2;
	int choice, n;

	// dynamically allocate sizes of string inputs
	input1 = (char *) malloc (sizeof(char));
	input2 = (char *) malloc (sizeof(char));

	//menu
	do {
		printf("\n\t\t====== SIMPLE BIOINFORMATICS LIBRARY =====");
		printf("\n\t\t=       [1] Get Hamming Distance         =");
		printf("\n\t\t=       [2] Count Substring Pattern      =");
		printf("\n\t\t=       [3] Check if string is valid     =");
		printf("\n\t\t=       [4] Get Skew                     =");
		printf("\n\t\t=       [5] Get Max Skew                 =");
		printf("\n\t\t=       [6] Get Min Skew                 =");
		printf("\n\t\t=       [7] Exit                         =");
		printf("\n\t\t==========================================");
		printf("\n\t\t        Choice: ");
		scanf("%d", &choice);

		switch(choice) {
		/*getHammingDistance*/	
		case 1: printf("\n===== GET HAMMING DISTANCE =====\n");
					printf("Enter string1: ");
					scanf("%s", input1);
					printf("Enter string2: ");
					scanf("%s", input2);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					input2[strcspn(input2, "\n")] = 0; //strcspn searches for the \n character and delimits it
					int distance = getHammingDistance(input1, input2);

					if(distance == -1) printf("Error! Strings are not equal!\n"); //error message
					else printf("Hamming Distance: %d\n", distance);
					break;
		/*countSubstrPattern*/	
		case 2:  printf("\n===== COUNT SUBSTRING PATTERN =====\n");
					printf("Enter original string: ");
					scanf("%s", input1);
					printf("Enter pattern string to be searched: ");
					scanf("%s", input2);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					input2[strcspn(input2, "\n")] = 0; //strcspn searches for the \n character and delimits it
					int count = countSubstrPattern(input1, input2);
					printf("# of Substring Pattern(s): %d\n", count);
					break;
		/*isValidString*/	
		case 3:  printf("\n===== CHECK IF STRING IS VALID =====\n");
					printf("Enter string: ");
					scanf("%s", input1);
					printf("Enter alphabet string: ");
					scanf("%s", input2);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					input2[strcspn(input2, "\n")] = 0; //strcspn searches for the \n character and delimits it
					int flag = isValidString(input1, input2);

					if(flag == 0) printf("False\n");
					else printf("True\n");
					break;
		/*getSkew*/	
		case 4:  printf("\n===== GET SKEW =====\n");
					printf("Enter string: ");
					scanf("%s", input1);
					printf("Enter n: ");
					scanf("%d", &n);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					int skew = getSkew(input1, n);
					
					if (skew == -1) printf("n is out of bounds!\n"); //display error message if out of bounds
					else printf("Skew: %d", skew);
					break;
		/*getMaxSkewN*/	
		case 5:  printf("\n===== GET MAX SKEW =====\n");
					printf("Enter string: ");
					scanf("%s", input1);
					printf("Enter n: ");
					scanf("%d", &n);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					int maxSkew = getMaxSkewN(input1, n);
					
					if (maxSkew == -1) printf("n is out of bounds!\n"); //display error message if out of bounds
					else printf("Maximum Skew: %d\n", maxSkew);
					break;
		/*getMaxSkewN*/	
		case 6:  printf("\n===== GET MIN SKEW =====\n");
					printf("Enter string: ");
					scanf("%s", input1);
					printf("Enter n: ");
					scanf("%d", &n);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					int minSkew = getMinSkewN(input1, n);
					
					if (minSkew == -1) printf("n is out of bounds!\n"); //display error message if out of bounds
					else printf("Minimum Skew: %d\n", minSkew);
					break;
		}
	} while (choice != 7);

	return 0;
