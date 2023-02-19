#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

struct itimerval value_virt;
struct itimerval it_set;

void alarm_wakeup(int i) { printf("alarm:%d\n", i); }

int main(int argc, char *argv[]) {
  it_set.it_interval.tv_sec = 5;
  it_set.it_interval.tv_usec = 10;
  it_set.it_value.tv_sec = 5;
  it_set.it_value.tv_usec = 10;
  setitimer(ITIMER_VIRTUAL, &it_set, &value_virt);

  while (1) {
    int tick = 0;
    sleep(1);
    tick++;
    printf("%d", tick);
  }
  return 0;
}
