#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
printf("C File I/O - System Calls\n");
  
  // fd = file descriptor 
  // int open (const char *pathname, int flags);
  const char *pathname = "hello.txtas";
  int flags = O_RDONLY;
  int fd = open (pathname, flags);
  printf("fd: %d\n", fd);
  if (-1 == fd)
  {
    perror("open");
    return 1;
  }
  
return 0;
  
}