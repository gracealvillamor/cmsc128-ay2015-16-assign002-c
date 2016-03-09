/*
	GRACEAL S. VILLAMOR
	AB - 3L
	SIMPLE BIOINFORMATICS LIBRARY
*/

#include<string.h>

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
			
		return distance;
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

	return count;

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
	
	return flag;

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

	return skew;
}

int getMaxSkewN(char str[], int n) {
	int i, currentSkew, maxSkew;

	//assign maxSkew as the first skew value of index 1 in str
	maxSkew = getSkew(str, 1);

	//check if n is valid
	if(n <= 0 || n > strlen(str)) {
		//break the function
		return 0;
	}

	for(i = 0; i < n; i++) {
	 	currentSkew = getSkew(str, i+1);
		if(currentSkew > maxSkew) {
			maxSkew = currentSkew;
		}
	} 
	
	return maxSkew;
}

int getMinSkewN(char str[], int n) {
	int i, currentSkew, minSkew;

	//assign minSkew as the first skew value of index 1 in str
	minSkew = getSkew(str, 1);

	//check if n is valid
	if(n <= 0 || n > strlen(str)) {
		//break the function
		return 0;
	}

	for(i = 0; i < n; i++) {
	 	currentSkew = getSkew(str, i+1);
		if(currentSkew < minSkew) {
			minSkew = currentSkew;
		}
	} 
	
	return minSkew;
}
