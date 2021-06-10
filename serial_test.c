#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main() {

    char port_name[] = "/dev/ttyUSB0";

    /* シリアル通信の初期化 */
    int serial_port = open(port_name, O_RDWR);
    if ( serial_port < 0 ) {
        printf("Error %i from open: %s\n", errno, strerror(errno));
    }
    struct termios tty;
    if (tcgetattr(serial_port, &tty) != 0) {
    printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return 1;
    }

    char buf[256];
    for (int i=0; ;i++) {
        memset(&buf, '\0', sizeof(buf));
        int n = read(serial_port, &buf, sizeof(buf));
        if ( n > 0 ) {
            printf(">> %s", buf);
        }

        sleep(1);
        if ( i%2==0 ) {
            write(serial_port, "10", sizeof("10"));
            // tcflush(serial_port, TCOFLUSH);
            // printf("changed angle to 10\n");
        } else {
            write(serial_port, "100", sizeof("100"));
            // tcflush(serial_port, TCOFLUSH);
            // printf("changed angle to 100\n");
        }
    }
}
