#ifndef COMMON_FONCTIONS__FONCTIONS_H
#define COMMON_FONCTIONS__FONCTIONS_H

#include "../../other/kbhit.h"

// PROCEDURES -----------------------
/**
 * Cette procédure supprime une ligne en console en manipulant le caractère spécial retour de chariot (\r) et des espaces qui écrasent l'ancien contenu de la ligne.
*/
void Delete_a_consol_line();

/**
 * Cette procédure lance un chrono visuel (en secondes) en CLI à partir d'une valeur bien spécifié jusqu'à 0.
 * @param chrono Elle prend en paramètre un entier qui doit être en dessous de 10. Si la valeur passée est supérieure ou égale à 10, elle est automatiquement modifée à la valeur 9.
 * @since 1.0
*/
void Chrono(int chrono);

/**
 * Cette fonction tourne en boucle 'while' jusqu'à la rencontre du caractère '\\n' ou du 'EOF' pour vider entièrement le buffer.
 * @since 1.0
*/
void Drain_buffer();

//FONCTIONS -------------------------

/**
 * Cette fonction demande en boucle une entrée et vérifie qu'elle est bien de type entier (int). Elle retourne la valeur dès qu'elle est bien de type 'int'.
 * @param prompt Prend en paramètre le prompt à afficher et à la suite duquel on récupère la valeur à tester.
 * @return Retourne l'entier dont la valeur à déjà été vérifiée
 * @see <a href="http://www.link_to_jira/HERO-402"> \n Rien de concret.</a>
 * @since 1.0
*/
int Int_recup_verify(const char* prompt);

/**
 * Cette fonction demande en boucle une entrée et vérifie qu'elle est bien de type entier (unsigned int). Elle retourne la valeur dès qu'elle est bien de type 'unsigned int'.
 * @param prompt Prend en paramètre le prompt à afficher et à la suite duquel on récupère la valeur à tester.
 * @return Retourne l'entier non signé dont la valeur à déjà été vérifiée
 * @see <a href="http://www.link_to_jira/HERO-402"> \n Rien de concret.</a>
 * @since 1.0
*/
unsigned int Unsigned_int_recup_verify(const char* prompt);

#endif
