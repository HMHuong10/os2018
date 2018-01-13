#include<stdio.h>
#include<unistd.h>

int main(){
	printf("Before fork\n");
	int pid = fork();
	if (pid == 0){
		printf("\n");
		char *args[] = {"/bin/ps", "-ef", NULL};
		execvp("/bin/ps", args);
	}
	else {
		pid = fork();
		if(pid==0){
			printf("\n");
			char *args[] = {"free", "-h", NULL};
			execvp("free", args);
		}
	}
//	ps -ef
//	free -h
}

