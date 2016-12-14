#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <string.h>

#define NUM_THREADS 5
void * print_hello(void *threadid) {
	long tid;
	tid = (long) threadid;
	//sleep(tid);
	printf("Hello World! It’s me, thread #%ld!\n", tid);
	pthread_exit(NULL);
}

void print_screen() {
        system("clear");
        printf("Welcome to the CISC220 Racing Arena\n");
        printf("Hit Enter to move forward\n");
        printf("|->                                        # Lane 1 #\n");
        printf("|->                                        # Lane 2 #\n");
        printf("|->                                        # Lane 3 #\n");
        printf("|->                                        # Lane 4 #\n");
        printf("|->                                        # Lane 5 #\n");

}


int main (int argc, char *argv[]) {
	print_screen();
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for (t = 0; t < NUM_THREADS; t++) {
		printf("In main: creating thread %ld\n", t);
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
