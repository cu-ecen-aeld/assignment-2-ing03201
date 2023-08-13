#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc != 3){
		syslog( LOG_ERR ,"Two arguments are required\n first argument is file path include file name\n second argument is text string to be written to first argument\n");
		return 1;
	}
	int fd = open( argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd == -1){
		syslog( LOG_ERR ,"Error opening file\n");
		return 1;
	}
	if(write(fd, argv[2], strlen(argv[2])) == -1){
		syslog( LOG_ERR ,"Error writing to file\n");
		return 1;
	}
	return 0;
}
