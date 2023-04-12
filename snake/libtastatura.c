#include <sys/select.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdlib.h>
#include <errno.h>
#define CMIN 1

#ifdef CTIME
#undef CTIME
#endif

#define CTIME 1

#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>

#include "libtastatura.h"
//ukradeno
int kbhit(void){
    int cnt = 0;
    int error;
    static struct termios Otty, Ntty;

    tcgetattr(0, &Otty);
    Ntty = Otty;

    Ntty.c_iflag = 0; /* input mode */
    Ntty.c_oflag = 0; /* output mode */
    Ntty.c_lflag &= ~ICANON; /* raw mode */
    Ntty.c_cc[VMIN] = CMIN; /* minimum time to wait */
    Ntty.c_cc[VTIME] = CTIME; /* minimum characters to wait for */

    if (0 == (error = tcsetattr(0, TCSANOW, &Ntty))) {
        struct timeval tv;
        error += ioctl(0, FIONREAD, &cnt);
        error += tcsetattr(0, TCSANOW, &Otty);

        /* throw in a miniscule time delay */
        tv.tv_sec = 0;
        tv.tv_usec = 100;
        select(1, NULL, NULL, NULL, &tv);
    }

    return (error == 0 ? cnt : -1 );
}

int getch(void){
    int c = 0;
    struct termios org_opts, new_opts;
    int res = 0;

    res = tcgetattr(STDIN_FILENO, &org_opts);
    assert(res == 0);

    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c = getchar();

    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    assert(res == 0);

    return c;
}

