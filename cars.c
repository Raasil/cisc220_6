#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define NUM_THREADS 5

int userDist;
int distCar1;
int distCar2;
int distCar3;
int distCar4;

void * print_hello(void *threadid) {
	long tid;
	tid = (long) threadid;
//	sleep(tid);
//	printf("Hello World! It’s me, thread #%ld!\n", tid);


	pthread_exit(NULL);
}

void print_screen(int userDist, int distCar1, int distCar2, int distCar3, int distCar4) {
	char *tildas = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	char *spaces = "                                        ";
	int userSpace = 40 - userDist;
	int car1Space = 40 - distCar1;
	int car2Space = 40 - distCar2;
	int car3Space = 40 - distCar3;
	int car4Space = 40 - distCar4;

	system("clear");
	printf("Welcome to the CISC220 Racing Arena\n");
        printf("Hit Enter to move forward\n");
	printf( "%.*s|->%.*s# Lane 1 #\n", userDist, tildas, userSpace, spaces);
        printf( "%.*s|->%.*s# Lane 2 #\n", distCar1, tildas, car1Space, spaces);
	printf( "%.*s|->%.*s# Lane 3 #\n", distCar2, tildas, car2Space, spaces);
	printf( "%.*s|->%.*s# Lane 4 #\n", distCar3, tildas, car3Space, spaces);
	printf( "%.*s|->%.*s# Lane 5 #\n", distCar4, tildas, car4Space, spaces);
}

void carMemes() {
	while ( distCar1 != 40 && distCar2 != 40 && distCar3 != 40 && distCar4 != 40 ) {
                srand ( 1 );
                float randomNumber1 = rand() % 100000;
//		printf("\n%f\n", sleepNumber);
                usleep(randomNumber1);
		distCar1++;
                srand ( 2 );
                float randomNumber2 = rand() % 100000;
//              printf("\n%f\n", sleepNumber);
                usleep(randomNumber2);
		distCar2++;
                srand ( 3 );
                float randomNumber3 = rand() % 100000;
//              printf("\n%f\n", sleepNumber);
                usleep(randomNumber3);
		distCar3++;
                srand ( 4 );
                float randomNumber4 = rand() % 100000;
//              printf("\n%f\n", sleepNumber);
                usleep(randomNumber4);
		distCar4++;
		usleep(20000);
                print_screen(userDist, distCar1, distCar2, distCar3, distCar4);
        }
}



void user() {
        char x;
        //user begins at the starting line
        userDist = 0;
        while (userDist != 40) {
        	carMemes();
	        //take input from the command line
                x = getchar();
                //if input is "enter", we increment userDist
                if (x == '\n') {
                        userDist++;
			print_screen(userDist, distCar1, distCar2, distCar3, distCar4);
                }
        }
}

int main (int argc, char *argv[]) {
	user();
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
//                srand ( time(NULL) );
//                float randomNumber = rand() % 100000;
//              printf("\n%f\n", sleepNumber);
//                usleep(randomNumber);	
	for (t = 0; t < NUM_THREADS; t++) {
//		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(threads + t, NULL, print_hello, (void *) t);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	/* wait for all threads to complete */ 
	for (t = 0; t < NUM_THREADS; t++) { 
		pthread_join(threads[t], NULL); 
	}
	pthread_exit(NULL);
}
