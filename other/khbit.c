#include "../shapes-struct/main.h"
#include <termios.h>
#include <fcntl.h>

//Et voilà que je dois me coller les configs du terminal Linux juste pour lire dans le buffer !
//Heureusement qu'y un chat juste là ... LOL
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin); //Faut retourner le caractère dans le buffer pour pouvoir le tester ensuite.
        return 1;
    }
    return 0;
}

