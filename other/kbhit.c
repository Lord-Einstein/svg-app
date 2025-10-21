#include "./kbhit.h"

//Et voilà que je dois me coller les configs du terminal Linux juste pour lire dans le buffer !

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
        ungetc(ch, stdin); //Faut retourner le caractère dans le buffer pour l'utiliser même en dehors de la boucle.
        return 1;
    }
    return 0;
}


void Ignore_enter_until_other_key(void) {
    struct termios oldt, newt;
    char c = 0;

    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    
    do {
        read(STDIN_FILENO, &c, 1);
    } while (c == '\n' || c == '\r');

    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
