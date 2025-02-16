#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define GPIO_PATH "sys/class/gpio"

void write_to_file(const char *filename, const char *value){
	int fd = open(filename, O_WRONLY);
	if(fd < 0){
		perror("Error opening a file");
		return;
	}
	write(fd, value, sizeof(value));
	close(fd);
}

int main(){
	write_to_file(GPIO_PATH "/export", "17");
	usleep(500000);
	write_to_file(GPIO_PATH "/pgio17/direction", "out");

	for(int i = 0; i < 10; i++){
		write_to_file(GPIO_PATH "/gpio17/value", "1");
		printf("LED ON \n");
		sleep(1);
		write_to_file(GPIO_PATH "/gpio17/value", "0");
		printf("LED OFF \n");
		sleep(1);
	}
	write_to_file(GPIO_PATH "/unexport", "17"); //clean up
	return 0;
}
