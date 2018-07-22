#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

char inputChar()
{
	int i = rand() % (127 + 1 - 32) + 32;
	char c = (char)i;
	return c;
}

char *inputString()
{
	int i = 0;
	static char str[5] = { '\0' };

	while (i<5) {
		char v = inputChar();
              while((v < 'e') || (v > 't')){
                 v = inputChar();
              } 
		str[i] = v;
		i++;
	}
	return str;
}

void testme(int *x)
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
		//printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' '&& state == 3) state = 4;
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
                     x++;
			printf("error ");
			exit(200);
		}
	}
}

int checkTestme(){
   int i = 0;
   for(i; i<5; i++){
	int x = 0;
	testme(&x);

   	if(x==1)
		printf("Test %d: Reached error message, test passed.\n", x); 
   	else
		printf("Test %d: Failed.\n", x);
   }	
   return 0;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
      	//testme();
       checkTestme();
	return 0;
}


