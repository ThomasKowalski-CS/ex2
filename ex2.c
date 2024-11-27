/******************
Name: Thomas Kowalski
ID: *********
Assignment: ex2
*******************/

#include <stdio.h>
#define DECIMAL_BASE 10
#define UNHAPPY_TER 4

int main() {
	while(1)
	{
		int choice = 0; //var for storing and testing user choice
			//main menu:
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Laughter\n");
		printf("\t7. Exit\n");
		scanf("%d", &choice);
	
		switch (choice) {
			case 1:

				// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
				/* Example:
				* n = 3:
				* 0   0
				*   o
				* \___/
				*/

				//input:
				char eyeChar, noseChar, mouthChar; // variables for the chars
				int faceSize = 0; // var for the size of face...
				int isValid = 1; // boolian var to use as a "flag"
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyeChar, &noseChar, &mouthChar); // gets characters from user

					printf("Enter face size:\n");
				do {
					if (isValid == 0) { // will only apply from 2nd iteration
						printf("The face's size must be an odd and positive number, please try again:\n");
					}
					isValid = 0; // ticking the flag
					scanf("%d", &faceSize);
				} while (faceSize <= 0 || faceSize % 2 == 0);

				//print face:
				//eyes:
				printf("%c", eyeChar);
				for (int i = 0; i < faceSize; i++) {
					printf(" ");
				} 
				printf("%c\n", eyeChar);
				
				//nose:
				int noseSpaces = faceSize/2 + 1;
				for (int i = 0; i < noseSpaces; i++) {
					printf(" "); //giving the nose a margin
				} 
				printf("%c\n", noseChar); //prints the nose

				//mouth:
				printf("\\");
				for (int i = 0; i < faceSize; i++) {
					printf("%c", mouthChar);
				}
				printf("/\n");
				break;

			case 2:
				// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
				// and the sum of all digits to the right of the middle digit(s) are equal
				/* Examples:
				Balanced: 1533, 450810, 99
				Not blanced: 1552, 34
				Please notice: the number has to be bigger than 0.
				*/
				int num2; // num2 for storing the number of case 2 and it's sums
				int rightSideSum = 0;
				int leftSideSum = 0;
				
				printf("Enter a number:\n");
				while (1) {
				scanf("%d", &num2);
				
				if (num2 < 1) { // number is negative
					printf("Only positive number is allowed, please try again:\n");
					continue;
				}

				//check num's length:
				int num2Copy = num2;// a copy of num
				int num2Length = 0;
				while(num2Copy != 0) {
					num2Copy /= DECIMAL_BASE;
					num2Length++;
				}
				//calculation:
				int leftSideLength = num2Length/2;
				int rightSideLength = num2Length/2;
				int isAmountOdd = 0;
				if (num2Length % 2 == 1) { // checks if length is odd
					isAmountOdd = 1;
				}

				while (rightSideLength != 0) { //sums right side
					int currentDigit = num2 % DECIMAL_BASE;
					num2 /= DECIMAL_BASE;
					rightSideSum += currentDigit;
					rightSideLength--;
				}

				if (isAmountOdd == 1) { //dealing with an uneven amount of digits case
					num2 /= DECIMAL_BASE;
				} 

				while (leftSideLength != 0) { //sums right side
					int currentDigit = num2 % DECIMAL_BASE;
					num2 /= DECIMAL_BASE;
					leftSideSum += currentDigit;
					leftSideLength--;
				}

				if (leftSideSum == rightSideSum) { 
					printf("This number is balanced and brings harmony!\n");
				}
				else {
					printf("This number isn't balanced and destroys harmony.\n");
				}

				break;
				}
				break;
			case 3:
				
				// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
				/* Examples:
				Abudant: 12, 20, 24
				Not Abudant: 3, 7, 10
				Please notice: the number has to be bigger than 0.
				*/

				int num3; // var for storing case 3 input
				//input:
				printf("Enter a number:\n");
				while (1) {
				scanf("%d", &num3);
				
				if (num3 < 1) { // number is negative
					printf("Only positive number is allowed, please try again:\n");
					continue;
				}

				int divisorSum = 0;
				for(int i = 1; i <= num3/2; i++) { // checks for all divisors and sums them (no divisors after the middle point)
					if (num3 % i == 0) {
						divisorSum += i;
					}
				}

				if (divisorSum > num3) {
					printf("This number is generous!\n");
				}
				else {
					printf("This number does not share.\n");
				}
				break;
				}
				break;

			case 4:
				// Case 4: determine wether a number is a prime.
				/* Examples:
				This one brings joy: 3, 5, 11
				This one does not bring joy: 15, 8, 99
				Please notice: the number has to be bigger than 0.
				*/
				int num4; // var for storing case 4 input
				//input:
				printf("Enter a number:\n");
				while (1) {
				scanf("%d", &num4);
				
				if (num4 < 1) { // number is negative
					printf("Only positive number is allowed, please try again:\n");
					continue;
				}

				// special case for handling num4 = 1:
				if (num4 == 1) {
					printf("The circle remains incomplete.\n");
					break;
				}

				int flippedNum4 = 0;
				int num4Copy = num4;
				while (num4Copy > 0) {
					int lastDigit = num4Copy % DECIMAL_BASE; // store last digit
					flippedNum4 = flippedNum4 * DECIMAL_BASE + lastDigit; // add it to the most right place
					num4Copy /= DECIMAL_BASE;
				}
				

				//checking if they are both prime numbers
				int isBothPrime = 1; // prime number flag
				for (int i = 2; i <= num4/2; i++) { // same as before, no divisors after the middle. no need to check 1...
					if (num4 % i == 0) {
						isBothPrime = 0;
						break;
					}
				}

				if (isBothPrime == 1) {
					for (int i = 2; i <= flippedNum4/2; i++) {
						if (flippedNum4 % i == 0) {
							isBothPrime = 0;
							break;
						}
					}
				}

				if (isBothPrime == 1) {
					printf("This number completes the circle of joy!\n");
				}
				else {
					printf("The circle remains incomplete.\n");
				}


				break;
				}
				break;

			case 5:
						
				// Happy numbers: Print all the happy numbers between 1 to the given number.
				// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
				/* Examples:
				Happy :) : 7, 10
				Not Happy :( : 5, 9
				Please notice: the number has to be bigger than 0.
				*/
				int num5; // var for storing case 3 input
				//input:
				printf("Enter a number:\n");
				while (1) {
				scanf("%d", &num5);
				
				if (num5 < 1) { // number is negative
					printf("Only positive number is allowed, please try again:\n");
					continue;
				}

				printf("Between 1 and %d only these numbers bring happiness: ", num5);

				for (int i = 1; i <= num5; i++) { // loop through all numbers between 1 and num5
				int currentNum5 = i;
					while (1) {
						int sum5 = 0;
						while (currentNum5 != 0) {

							int currentDigit5 = currentNum5 % DECIMAL_BASE; // takes the most right digit
							currentNum5 /= DECIMAL_BASE; // "shift right" the int
							sum5 += currentDigit5 * currentDigit5; // sums the square of the digits


						}
							if (sum5 == 1) { // is happy :)
								printf("%d ", i);
								break;
							} 
							else if (sum5 == UNHAPPY_TER) { // not happy >:( unhappy numbers fall in the same cycle which contains 4
								break;
							}
							else { // check again for the new sum
								currentNum5 = sum5;
							}
					}
				}
				printf("\n"); // ends with a new line
				break;
				}
				break;

			case 6:

				// Festival of Laughter: Prints all the numbers between 1 the given number:
				// and replace with "Smile!" every number that divided by the given smile number
				// and replace with "Cheer!" every number that divided by the given cheer number
				// and replace with "Festival!" every number that divided by both of them
				/* Example:
				6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
				*/
				//input:
				int cheerNumber = 0, smileNumber = 0, num6 = 0; // vars for input
				isValid = 1;
				int scanTest = 2;
				printf("Enter a smile and cheer number:\n");

				do {
				if (isValid == 0) { // skips this if on the first iteration
					scanf("%*[^\n]"); // clears the buffer
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
				}

				scanTest = scanf(" smile: %d, cheer: %d", &smileNumber, &cheerNumber); // scan for input and store scanf's return value
				isValid = 0;
				} while (scanTest != 2 || smileNumber < 1 || cheerNumber < 1 || smileNumber == cheerNumber);

				isValid = 1;
				printf("Enter maximum number for the festival:\n");
				do { // second input loop
					if (isValid == 0) {
						printf("Only positive maximum number is allowed, please try again:\n");
					}
					scanf("%d", &num6);
					isValid = 0;
				} while (num6 < 1);

				for (int i = 1; i <= num6; i++) {

					if (i % smileNumber == 0 || i % cheerNumber == 0) { // checks if the number is divisable by even one of the inputs
						
						if (i % smileNumber == 0 && i % cheerNumber == 0) { // if the number is divisable by both smile and cheer 
							printf("Festival!\n");
							continue;
						}

						if (i % smileNumber == 0) { // or only by smile
							printf("Smile!\n");
							continue;
						}
						
						printf("Cheer!\n"); // "else" by cheers
						continue;
					}

				printf("%d\n", i);

				}
				
				break;

			case 7:
				printf("Thank you for your journey through Numeria!\n");
				return 0; // elyahu approved using it :) (sorry if misspell) 
				break; // altho not necessary

				default:
				printf("This option is not available, please try again later.\n");
				break; // altho not necessary 
		}
	}
}
