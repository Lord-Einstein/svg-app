#ifndef LINE__MAIN_H
#define LINE__MAIN_H

#include "../common-fonctions/fonctions.h"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case


// STRUCTURE --------------
typedef struct {
    int x1, y1, x2, y2;
}Line;



// PROCEDURES --------------

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la création d'une ligne en format SVG
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Element/circle"> En savoir plus sur les cercles SVG.</a>
*/
void Infos_line();

/**
 * Cette procédure récupère les informations entrées par l'utilisateur pour créer une ligne.
 * (Elle vérifie toujours si le pointeur n'est pas nul).
 * @param line Prend en paramètre un pointeur sur la ligne à créer, puis procède par un remplissage par adressse.
*/
void Recup_line_data(Line* line);

/**
 * Cette procédure libère l'allocation mémoire faite à la création d'une instance de type 'Line'.
 * @param line Prend en paramètre un pointeur sur l'instance de Line à détruire et le libère grâce au free.
*/
void Destroy_line(Line* line);

/**
 * Cette procédure affiche les informations contenues dans une instance 'Line' passée en paramètre.
 * @param line Prends en paramètre un pointeur sur l'instance de Line dont on souhaite afficher les informations.
*/
void Display_line(Line* line);



// FONCTIONS ------------

/**
 * Cette fonction vérifie si le pointeur qui contient l'allocation sur une ligne existe (!=NULL)
 * @param line Prend un pointeur sur 'Line' et vérifie si il existe bien.
 * @return Retourne un True si le pointeur a bien reçu l'allocation et un False dans le cas contraire.
*/
int Does_line_exist(Line* line);

/**
 * Cette fonction crée une Ligne en attribuant les valeurs qui lui sont passées aux attributs respectifs d'un 'Line' SVG.
 * @param x1 Valeur entière de la position du premier point sur l'axe des abscisses (X).
 * @param y1 Valeur entière de la position du premier point sur l'axe des ordonnées(Y).
 * @param x2 Valeur entière de la position du second point sur l'axe des abscisses(X).
 * @param y2 Valeur entière de la position du second point sur l'axe des ordonnées(Y).
 * @return Retourne un pointeur sur la stucture 'Line' en manipulant l'allocation mémoire. Il faut donc garder à l'esprit que le lineangle qui reçoit le retour de cette fonction doit être obligatoirement 'free' à la fin.
*/
Line* Create_line(int x1, int y1, int x2, int y2);


#endif
