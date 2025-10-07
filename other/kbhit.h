#ifndef OTHER__KBHIT_H
#define OTHER__KBHIT_H

#include "../common-h.h"
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>



/**
 * Cette fonction guette l'entrée d'une touche quelconque par l'utilisateur. Notemment en désactivant le mode canonique de la console Linux et en vidant la sortie sur l'affichage.
 * 
 * Elle renvoie un True(1) quand une touche est entrée.
*/
int kbhit(void);


#endif