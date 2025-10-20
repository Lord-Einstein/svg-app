#ifndef COMMON_FONCTIONS__FONCTIONS_H
#define COMMON_FONCTIONS__FONCTIONS_H

#define _XOPEN_SOURCE 700
#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <unistd.h>



#include "../../other/kbhit.h"
#include "../../common-h.h"
//DEFINE DE MISE EN FORME

//Petite explication : Pour les formats de style en console, on utilise la notation ASCII \033[code_style(gras);code_couleur(bleu...);code_bg_color(white..)ET un 'm' après lesconfigurations puis le texte....

//Cractères spéciaux pour la gestion des lignes en console
#define REMOUNT_ON_LAST_LINE "\033[1A"
#define DELETE_CURRRENT_LINE "\033[2K"

//Caractères spéciaux pour la gestion des décorations de texte
#define BOLD_WHITE_TEXT  "\033[1;37m"
#define UNDERLINE_WHITE_TEXT  "\033[4;37m"

//Caractères de RESET des modifications de style en console
#define RESET_STYLE  "\033[0m"


// --- Couleurs de texte (avant-plan) ---
#define BLACK        "\033[30m"
#define RED          "\033[31m"
#define GREEN        "\033[32m"
#define YELLOW       "\033[33m"
#define BLUE         "\033[34m"
#define MAGENTA      "\033[35m"
#define CYAN         "\033[36m"
#define WHITE        "\033[37m"

// --- Couleurs vives (texte clair) ---
#define BRIGHT_BLACK   "\033[90m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"



// PROCEDURES -----------------------


/**
 * @brief Affiche du texte en noir dans la console.
 * @param prompt Texte à afficher en noir.
 */
void Print_in_black(const char* prompt);

/**
 * @brief Affiche du texte en rouge dans la console. 
 * @param prompt Texte à afficher en rouge (souvent utilisé pour les erreurs).
 */
void Print_in_red(const char* prompt);

/**
 * @brief Affiche du texte en vert dans la console. 
 * @param prompt Texte à afficher en vert (souvent utilisé pour les validations).
 */
void Print_in_green(const char* prompt);

/**
 * @brief Affiche du texte en jaune dans la console. 
 * @param prompt Texte à afficher en jaune (utile pour les avertissements).
 */
void Print_in_yellow(const char* prompt);

/**
 * @brief Affiche du texte en bleu dans la console.
 * @param prompt Texte à afficher en bleu.
 */
void Print_in_blue(const char* prompt);

/**
 * @brief Affiche du texte en magenta dans la console.
 * @param prompt Texte à afficher en magenta.
 */
void Print_in_magenta(const char* prompt);

/**
 * @brief Affiche du texte en cyan dans la console.
 * @param prompt Texte à afficher en cyan.
 */
void Print_in_cyan(const char* prompt);

/**
 * @brief Affiche du texte en blanc dans la console.
 * @param prompt Texte à afficher en blanc.
 */
void Print_in_white(const char* prompt);


// COULEURS VIVES


/**
 * @brief Affiche du texte en noir clair (gris foncé) dans la console.
 * @param prompt Texte à afficher.
 */
void Print_in_bright_black(const char* prompt);

/**
 * @brief Affiche du texte en rouge vif dans la console.
 * @param prompt Texte à afficher.
 */
void Print_in_bright_red(const char* prompt);

/**
 * @brief Affiche du texte en vert vif dans la console.
 * @param prompt Texte à afficher.
 */
void Print_in_bright_green(const char* prompt);

/**
 * @brief Affiche du texte en jaune vif dans la console.
 * @param prompt Texte à afficher.
 */
void Print_in_bright_yellow(const char* prompt);

/**
 * @brief Affiche du texte en bleu vif dans la console.
 * @param prompt Texte à afficher.
 */
void Print_in_bright_blue(const char* prompt);

/**
 * @brief Affiche du texte en magenta vif dans la console.
 * @param prompt Texte à afficher.
 */
void Print_in_bright_magenta(const char* prompt);

/**
 * @brief Affiche du texte en cyan vif dans la console.
 * @param prompt Texte à afficher.
 */
void Print_in_bright_cyan(const char* prompt);

/**
 * @brief Affiche du texte en blanc vif dans la console.
 * @param prompt Texte à afficher.
 */
void Print_in_bright_white(const char* prompt);








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

// int Chrono_assassine(int chrono);

void Ignore_extra_enters(void);

void Auto_write(const char *text, unsigned int delay_microseconds);

float Float_recup_verify_with_padding(const char *prompt, float min_value, float max_value);

void Progress_bar_animation(int duration_sec);

void msleep(int ms);

void enable_input(void);

void disable_input(void);

void clear_screen(void);



#endif
