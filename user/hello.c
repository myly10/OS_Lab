// hello, world
#include <inc/lib.h>

void
umain(int argc, char **argv)
{
	cprintf("hello, world\n");
	cprintf("i am environment %08x\n", thisenv->env_id);

	int i, j;
    for (i=0; i!=4; ++i){
        int pid = pfork(i);
        if (!pid) {
            cprintf("child %x on\n", i);
            for (j=0; j!=4; ++j) {
                cprintf("child %x    off\n", i);
                sys_yield();
            }
			break;
        }
    }
}
