#include<stdio.h>
#include<string.h>


void user() {
        int userDist;
        char x;
	
	//user begins at the starting line
        userDist = 0;
        while (userDist != 40) {
		//take input from the command line
                x = getchar();
		//if input is "enter", we increment userDist
                if (x == '\n') {
			printf("fuk");
                        userDist++;
                }
        }
}

int main() {
        user();
        return 0;
}
