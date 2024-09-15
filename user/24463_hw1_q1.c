#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
int p1[2];
int p2[2];

pipe(p1);
pipe(p2);

if(fork()==0){
char buf[5];
close(p1[1]);
close(p2[0]);

read(p1[0],buf,4);
printf("The child has read the message %s \n",buf);

write(p2[1],"Pong",4);
close(p2[1]);
close(p1[0]);
exit(0);

}
else{
char buf[5];
close(p1[0]);
close(p2[1]);
write(p1[1],"Ping",4);
close(p1[1]);
read(p2[0],buf,4);
printf("The parent has received the message %s \n",buf);
close(p2[0]);
wait(0);

}
exit(0);
}


