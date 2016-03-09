/*
	GRACEAL S. VILLAMOR
	AB - 3L
	SIMPLE BIOINFORMATICS LIBRARY
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int getHammingDistance(char str1[], char str2[]) {
	int str1len = strlen(str1)-1; //gets the length of str1
	int str2len = strlen(str2)-1; //gets the length of str2
	int i, distance=0;

	if ((str1len != str2len) || (str1len <= 0) || (str2len <= 0) ) {
		//if string lenth of the two strings are unequal or equal to 0 or negative, return error message
		printf("Error! Strings are not equal!\n");
		return 0;
	} else {
		//if equal, then count the inversions by comparing the 2 strings
		for(i = 0; i < strlen(str1); i++) {
			if(str1[i] == str2[i]) {
				//if index of str1 and str2 are equal, continue traversing the string
				continue;
			} else {
				distance++; //else if unequal, increase the hamming distance 
			}
		}
		printf("Hamming Distance: %d\n", distance);
		return 1;
	}


}

int countSubstrPattern(char original[], char pattern[]) {
	int i = 0, count = 0;

	char *temp = original;

	while(*temp != '\0' && (temp = strstr(temp, pattern))) {
		//strstr function is used to get the occurence of of pattern in original
		count++; //if substring is found, then accumulate count
		temp++; //continue traversing the list
	}

	printf("Subtring Pattern Count: %d\n", count);
	return 1;

}

int isValidString(char str[], char alphabet[]) {
	//returns true if all elements of the string are in the user-given alphabet string
	int flag;
	char *temp = str;

	while (*temp) {
		if(strchr(alphabet, *temp)) {
		//stchr is use locate a character in the string
			//if element in alphabet is found in str, then set the flag to 1
			flag = 1;
		} else {
			//if element in alphabet is not found in str, then set the flag to 0 and break the loop
			flag = 0;
			break;
		}

		temp++;
	}
	
	if (flag == 0) {
		//return false if an element in str is not found in alphabet
		printf("False\n");
		return 0;
	} else {
		//else return true if all elements in str is prsent in alphabet
		printf("True\n");
		return 1;
	}

}

int getSkew(char str[], int n) {
	int i, skew = 0;

	for(i = 0; i < n; i++) {
		if(str[i] == 'G') {
			// if G is in position i, increment skew
				skew++;
			} else if (str[i] == 'C') {
				// else if C is in position i, decrement skew
				skew--;
			}
	} 

	printf("Skew: %d", skew);
}

int getMaxSkewN(char str[], int n) {

}

int getMinSkewN(char str[], int n) {

}

int main () {
	char *input1, *input2;
	int choice, n;

	// dynamically allocate sizes of string inputs
	input1 = (char *) malloc (sizeof(char));
	input2 = (char *) malloc (sizeof(char));

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
					getHammingDistance(input1, input2);
					break;
		/*countSubstrPattern*/	
		case 2:  printf("\n===== COUNT SUBSTRING PATTERN =====\n");
					printf("Enter original string: ");
					scanf("%s", input1);
					printf("Enter pattern string to be searched: ");
					scanf("%s", input2);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					input2[strcspn(input2, "\n")] = 0; //strcspn searches for the \n character and delimits it
					countSubstrPattern(input1, input2);
					break;
		/*isValidString*/	
		case 3:  printf("\n===== CHECK IF STRING IS VALID =====\n");
					printf("Enter string: ");
					scanf("%s", input1);
					printf("Enter alphabet string: ");
					scanf("%s", input2);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					input2[strcspn(input2, "\n")] = 0; //strcspn searches for the \n character and delimits it
					isValidString(input1, input2);
					break;
		/*getSkew*/	
		case 4:  printf("\n===== GET SKEW =====\n");
					printf("Enter string: ");
					scanf("%s", input1);
					printf("Enter n: ");
					scanf("%d", &n);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					getSkew(input1, n);
					break;
		/*getMaxSkewN*/	
		case 5:  printf("\n===== GET MAX SKEW =====\n");
					printf("Enter string: ");
					scanf("%s", input1);
					printf("Enter n: ");
					scanf("%d", &n);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					getMaxSkewN(input1, n);
					break;
		/*getMaxSkewN*/	
		case 6:  printf("\n===== GET MIN SKEW =====\n");
					printf("Enter string: ");
					scanf("%s", input1);
					printf("Enter n: ");
					scanf("%d", &n);
					input1[strcspn(input1, "\n")] = 0; //strcspn searches for the \n character and delimits it
					getMinSkewN(input1, n);
					break;
		}
	} while (choice != 7);

	return 0;
}

/*
git remote add origin https://github.com/gracealvillamor/cmsc128-ay2015-16-assign002-c.git
git push -u origin master
*/

/*
echo "# cmsc128-ay2015-16-assign002-c" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/gracealvillamor/cmsc128-ay2015-16-assign002-c.git
git push -u origin master
*/