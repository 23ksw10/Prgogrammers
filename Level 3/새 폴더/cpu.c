#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<sched.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<stdint.h>
#include<signal.h>


#define ROW (50)
#define COL ROW
#define TOTALFORK 100

int count;
int cpuid;
int calc(int time, int cpu){
        struct timespec begin,end;
        int matrixA [ROW][COL];
        int matrixB [ROW][COL];
	int matrixC [ROW][COL];
	int i ,j,k;
	cpuid= cpu;
	int hundred=100;
	clock_gettime(CLOCK_MONOTONIC,&begin);
	while(1) {

		for(i = 0 ; i < ROW ; i ++){
			for(j = 0 ; j < COL ;j++){
				for(k = 0 ; k < COL ; k++){
					matrixC[i][j]+=matrixA[i][k]* matrixB [k][j];

				}
			}
		}
		count++;
	        clock_gettime(CLOCK_MONOTONIC,&end);
                clock_gettime(CLOCK_MONOTONIC,&end);
		float dif=(end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
							(end.tv_sec  - begin.tv_sec);
		float ms=(dif*1000.0);
                int ims=ceil(ms);
		if(time*1000<=ms)
		{
			goto exit;
		}
		if(ims>=hundred)
		{
			printf("PROCESS #%02d count = %02d %02d ms\n",cpuid,count,ims);
			hundred+=100;
		}



	      
        
 
	}


exit:
	return 0;
}


struct sched_attr {
	uint32_t size;              /* Size of this structure */
	uint32_t sched_policy;      /* Policy (SCHED_*) */
	uint64_t sched_flags;       /* Flags */
	int32_t  sched_nice;        /* Nice value (SCHED_OTHER,SCHED_BATCH) */
	uint32_t sched_priority;    /* Static priority (SCHED_FIFSCHED_RR) */
		          /* Remaining fields are for SCHED_DEADLINE */
	uint64_t sched_runtime;
	uint64_t sched_deadline;
	uint64_t sched_period;
};
static int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags)
{
	    return syscall(SYS_sched_setattr, pid, attr, flags);
}


int signalSec;
float signalNsec;

void sig_handler(int signo)
{
	struct timespec end;
	clock_gettime(CLOCK_MONOTONIC,&end);
	float dif=(end.tv_nsec - signalNsec) / 1000000000.0 +
			                             (end.tv_sec  - signalSec);
        float ms= round( (dif*1000.0));

	printf("CTRL+C happend!! time:%.0fms count:%d\n",ms,count);
	exit(0);
}





int main(int argc,char *argv[]){
	struct sched_attr attr;
	memset(&attr,0,sizeof(attr));
	attr.size=sizeof(struct sched_attr);
	attr.sched_priority=95;
	attr.sched_policy=SCHED_RR;
	sched_setattr(getpid(),&attr,0);
	signal(SIGINT,(void *)sig_handler);

	int cpu=atoi(argv[1]);
	int time= atoi(argv[2]);
	pid_t pid;
	if(cpu>1){
		while(cpuid<cpu-1){
		       	pid=fork();
			if(pid==0){
				printf("        Creating Process: #%02d\n",(long)getpid()-(long)getppid());
				cpu=(long)getpid()-(long)getppid();
			}
			cpuid++;
		}
	}
	if(pid!=0){
		printf("** START: Processes = %02d Time = %02d s\n",cpu,time);
		cpu=0;
	}
	struct timespec begin,end;
	clock_gettime(CLOCK_MONOTONIC,&begin);
	signalSec=begin.tv_sec;
	signalNsec=begin.tv_nsec;
	calc(time,cpu);
	clock_gettime(CLOCK_MONOTONIC,&end);
	float dif=(end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
		            (end.tv_sec  - begin.tv_sec);
	float ms= round( (dif*1000.0));
	printf("DONE!! PROCESS #%02d : %02ld %.0f ms\n",cpu,count,ms); 

}
