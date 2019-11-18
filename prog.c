#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#define ERR(source) (fprintf(stderr,"%s:%d\n",__FILE__,__LINE__),\
		                 perror(source),kill(0,SIGKILL),\
										 exit(EXIT_FAILURE))
volatile sig_atomic_t last_signal = 0;
volatile sig_atomic_t counter = 0;

void sethandler( void (*f)(int), int sigNo) {
	struct sigaction act;
	memset(&act, 0, sizeof(struct sigaction));
	act.sa_handler = f;
	if (-1==sigaction(sigNo, &act, NULL)) ERR("sigaction");
}

void ch_handler(int sig){
	counter++;
}

void sig_handler(int sig) {
	last_signal = sig;
}

void child_job(){
	sethandler(ch_handler, SIGUSR1);
	srand(getpid());
	int k = rand()%11;
	struct timespec w = { 1, 0 };
	int i;
	printf("Child %u starts\n", getpid());
	for(i = 0; i < 10; i++){
		if(i < k){
			if(kill(0, SIGUSR1) < 0) ERR("kill");
		}
		while(TEMP_FAILURE_RETRY(nanosleep(&w, NULL)) != 0);
	}
	exit(k + (counter<<4));
	printf("Child %u with k: %d finished the job. Received %d signals\n", getpid(), k, counter);
}

void parent_job(int n){
	int *statuses = malloc(sizeof(int)*(n+1));
	int it = 0;
	while(TEMP_FAILURE_RETRY(wait(statuses + it)) > 0)it++;
	int i;
	for(i = 0; i < it; i++){
		printf("status %d\n", statuses[i]);
		int k = statuses[i]&((1<<5)-1);
		int sum = (statuses[i]>>4);
		printf("k: %d, sum: %d\n", k, sum);
	}
}

void create_children(int n){
	for(int i = 0; i < n; i++){
		pid_t pid;
		if((pid = fork()) < 0) ERR("fork");
		if(pid == 0){
			child_job();
		}
	}
}

int main(int argc, char** argv) {
	int n;
	n=atoi(argv[1]);
	if(argc < 2)ERR("arguments");
	sethandler(sig_handler, SIGUSR1);
	create_children(n);
	parent_job(n);
	printf("parent stops\n");
	return EXIT_SUCCESS;
}
