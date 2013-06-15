#include <sys/types.h>

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main(void){
	struct sysinfo info;
	
	if(sysinfo(&info) == -1){
		printf("Ooops!\n");
		
		return 1;
	}
	printf("unit is %d bytes long\n\n", info.mem_unit);
	
	printf("loads[0] = %f\n", (float)info.loads[0] / (float) USHRT_MAX);
	printf("loads[1] = %f\n", (float)info.loads[1] / (float) USHRT_MAX);
	printf("loads[2] = %f\n", (float)info.loads[2] / (float) USHRT_MAX);
	printf("totalswap = %dMb\n", (info.totalswap / 1024));
	printf("freeswap = %dMb\n", (info.freeswap / 1024));
	printf("totalram = %dMb\n", (info.totalram / 1024));
	printf("freeram = %dMb\n", (info.freeram / 1024));
	printf("sharedram = %dMb\n", (info.sharedram / 1024));
	printf("bufferram = %dMb\n", (info.bufferram / 1024));
	printf("procs = %d\n", info.procs);
	printf("uptime = %dsec\n", info.uptime);
	
	return 0;
}
