#ifndef COMMON_FONCTIONS__FONCTIONS_H
#define COMMON_FONCTIONS__FONCTIONS_H

#include "../../other/kbhit.h"
#include "../../common-h.h"

//DEFINE DE MISE EN FORME

//Petite explication : Pour les formats de style en console, on utilise la notation ASCII \033[code_style(gras);code_couleur(bleu...);code_bg_color(white..)ET un 'm' après lesconfigurations puis le texte....

#define REMOUNT_ON_LAST_LINE "\033[1A"
#define DELETE_CURRRENT_LINE "\033[2K"

#define BOLD_WHITE_TEXT  "\033[1;37m"
#define UNDERLINE_WHITE_TEXT  "\033[4;37m"


#define RESET_STYLE  "\033[0m"

#define RED_COLOR  "\033[31m"
#define GREEN_COLOR  "\033[32m"



// PROCEDURES -----------------------

/**
 * Cette procédure affiche du texte en couleur rouge dans la console. Très utile pour affciher des messages d'erreurs.
 * @param prompt Texte à afficher en rouge dans la console.
*/
void Print_in_red(const char* prompt);

/**
 * Cette procédure supprime deux lignes en console à partir de la ligne courante en manipulant les caractères spéciaux et l'ASCII.
 
 *Très pratique pour garder la console libre et agréable. Par exemple pour demander en boucle une valeur jusqu'a ce qu'une de correcte soit entrée.
*/
void Delete_two_lines();

/**
 * Cette procédure supprime cinq lignes en console à partir de la ligne courante en manipulant les caractères spéciaux et l'ASCII.
 
 *Très pratique pour garder la console libre et agréable. Par exemple pour demander en boucle une valeur jusqu'a ce qu'une de correcte soit entrée.
*/
void Delete_six_lines();

/**
 * Cette procédure supprime une ligne en console en manipulant le caractère spécial retour de chariot (\r) et des espaces qui écrasent l'ancien contenu de la ligne.
 * @deprecated Cette procédure est peu optimale -- Utiliser plutôt 'Delete_two_lines'
*/
void Delete_a_consol_line();

/**
 * Cette procédure lance un chrono visuel (en secondes) en CLI à partir d'une valeur bien spécifié jusqu'à 0.
 * @param chrono Elle prend en paramètre un entier qui doit être en dessous de 10. Si la valeur passée est supérieure ou égale à 10, elle est automatiquement modifée à la valeur 9.
 * @since 1.0
*/
void Chrono(int chrono);

/**
 * Cette procédure lance un chrono visuel (en secondes) en CLI à partir d'une valeur bien spécifié jusqu'à 0.
 * @param chrono Elle prend en paramètre un entier qui doit être en dessous de 10. Si la valeur passée est supérieure ou égale à 10, elle est automatiquement modifée à la valeur 9.
 * 
 * Différente de la procédure 'Chrono' car à la fin du temps imparti, elle ne nettoie pas la console.
 * @since 2.0
*/
void Chrono_without_clear(int chrono);

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
 * Cette fonction demande en boucle une entrée et vérifie qu'elle est bien de type entier (int) et qu'elle est dans la marge de valeur passée en paramètre. Elle retourne la valeur dès que ces conditions sont remplies.
 * @param prompt Prend en paramètre le prompt à afficher et à la suite duquel on récupère la valeur à tester.
 * @return Retourne l'entier dont la valeur à déjà été vérifiée
 * @see <a href="http://www.link_to_jira/HERO-402"> \n Rien de concret.</a>
 * @since 1.0
*/
int Int_recup_verify_with_padding(const char* prompt, int max_value, int min_value);

/**
 * Cette fonction demande en boucle une entrée et vérifie qu'elle est bien de type entier (unsigned int). Elle retourne la valeur dès qu'elle est bien de type 'unsigned int'.
 * @param prompt Prend en paramètre le prompt à afficher et à la suite duquel on récupère la valeur à tester.
 * @return Retourne l'entier non signé dont la valeur à déjà été vérifiée
 * @see <a href="http://www.link_to_jira/HERO-402"> \n Rien de concret.</a>
 * @since 1.0
*/
unsigned int Unsigned_int_recup_verify(const char* prompt);


/**
 * Cette fonction lance un chrono visuel (en secondes) en CLI à partir d'une valeur bien spécifié jusqu'à 0.
 * @param chrono Elle prend en paramètre un entier qui doit être en dessous de 10. Si la valeur passée est supérieure ou égale à 10, elle est automatiquement modifée à la valeur 9.
 * 
 * Différente de la procédure 'Chrono' car à la fin du temps imparti, elle ne nettoie pas la console.
 * Différente de la procédure 'Chrono_without_clear' car elle renvoie un entier qui permet de savoir si le chrono s'est arrêté tout seul ou s'il a été skip.
 * @since 3.0
*/
int Chrono_assassin(int chrono);


#endif
