#ifndef OTHER__KBHIT_H
#define OTHER__KBHIT_H

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>



/**
 * @brief Vérifie si une touche a été pressée sans bloquer l'exécution du programme.
 *
 * Cette fonction désactive temporairement le mode canonique de la console Linux afin de
 * permettre la détection instantanée d'une frappe clavier. Elle vide également le flux
 * de sortie pour éviter tout affichage non désiré.
 *
 * @return Retourne 1 (vrai) si une touche a été pressée, 0 (faux) sinon.
 */
int kbhit(void);

/**
 * @brief Ignore les appuis sur la touche "Entrée" jusqu’à ce qu’une autre touche soit pressée.
 *
 * Cette fonction permet d’attendre qu’un utilisateur appuie sur une touche autre que "Entrée".
 * Elle est utile pour éviter la validation accidentelle par simple appui sur la touche Entrée.
 */
void Ignore_enter_until_other_key(void);

#endif