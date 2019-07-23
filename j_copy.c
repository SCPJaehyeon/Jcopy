#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if(argc != 3){
		printf("Usage : %s <origin file> <destination file> \n",argv[0]);
		return 0;
	}
	int fd_orig, fd_dest;
	char *buf;
	if(fd_orig = open(argv[1], O_RDONLY)){
		int cnt;
		buf = malloc(4096);
		if(fd_dest = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC,0644))
		{
			do {
			cnt = 0;
			cnt = read(fd_orig, buf, 4096);
			if (cnt == write(fd_dest, buf, cnt)){
				continue;
			}
			}while(cnt != 0);
		}
		else{
			printf("Fail \n");
			close(fd_orig);
			return -1;
		}
		free(buf);
		close(fd_dest);
	}
	close(fd_orig);
	return 0;
}
