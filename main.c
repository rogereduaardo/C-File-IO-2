#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
printf("C File I/O - System Calls\n");
  
  // fd = file descriptor 
  // int open (const char *pathname, int flags);
  const char *pathname = "hello.txt";
  int flags = O_RDONLY;
  int fd = open (pathname, flags);
  printf("fd: %d\n", fd);
  if (-1 == fd)
  {
    perror("open");
    return 1;
  }

  int result = 1;
  while(result != 0)
    {
      //char ch;
      char buf[100];
      result = read(fd, buf, sizeof(buf));
      //printf("result: %d, ch: 0x%02x %c\n", result, ch, ch);
      printf("result: %d\n", result);
      for (int i = 0; i < result; i++)
        {
          printf("buf[%d]: 0x%02x %c\n", i, buf[i], buf[i]);
        }
    }

  close(fd);
  
return 0;
  
}