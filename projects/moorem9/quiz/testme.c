#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//making a change to see if GIT recognizes it.
//random character generation
char inputChar()
{// TODO: rewrite this function
	int lcCharASCII = ((rand() % 94)+32);//get a random number cooresponding to an ASCII #
	char lcLetter = (char)lcCharASCII;//typedef the number to char
	return lcLetter;
}

char *inputString()
{// TODO: rewrite this function
	static char randString[6];//leave a space for the newline..
	//ALSO this string has to be declared at static to pass correctly.
	int i;
	
	for(i = 0; i < 5; i++){		//loop to fill the 5 spots with random lc letters
		randString[i] = 'a' + random() % 26;}//source - stackoverflow.com/questions/19724346/generate-random-characters-in-c
	
	randString[5] = '\0';//put null character at end
	//printf("randString in inputstring function = %s\n", randString);
	char *finalRandString = randString;
	//printf("finalRandString in inputstring function = %s\n", finalRandString);
	return finalRandString;
}

void testme()
{
	int tcCount = 0;
	char *s;
	char c;
	int state = 0;
	while (1)
	{
		tcCount++;
		c = inputChar();
		s = inputString();
		printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
		
		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' ' && state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e'
			&& s[2] == 's' && s[3] == 'e'
			&& s[4] == 't' && s[5] == '\0'
			&& state == 9)
		{
			printf("error ");
			exit(200);
		}
		//if(tcCount == 100000)//safty net
			//exit(200);
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	testme();
	return 0;
}
