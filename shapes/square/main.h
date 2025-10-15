#ifndef SQUARE__MAIN_H
#define SQUARE__MAIN_H

#include "../rectangle/main.h"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case


// PROCEDURES --------------

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la création d'un carré en format SVG
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Element/circle"> En savoir plus sur les SVG.</a>
*/
void Infos_square();

/**
 * Cette procédure récupère les informations entrées par l'utilisateur pour créer un carré.
 * (Elle vérifie toujours si le pointeur n'est pas nul).
 * @param square Prend en paramètre un pointeur sur le carré à créer, puis procède par un remplissage par adressse.
*/
void Recup_square_data(Rect* square);

/**
 * Cette procédure libère l'allocation mémoire faite à la création d'une instance de type 'Rect'.
 * @param square Prend en paramètre un pointeur sur l'instance de Square à détruire et le libère grâce au free.
*/
void Destroy_square(Rect* square);

/**
 * Cette procédure affiche les informations contenues dans une instance 'Rect' passée en paramètre.
 * @param square Prends en paramètre un pointeur sur l'instance de Square dont on souhaite afficher les informations.
*/
void Display_square(Rect* square);



// FONCTIONS ------------

/**
 * Cette fonction vérifie si le pointeur qui contient l'allocation sur un Carré existe (!=NULL)
 * @param square Prend un pointeur sur 'Rect' et vérifie si il existe bien.
 * @return Retourne un True si le pointeur a bien reçu l'allocation et un False dans le cas contraire.
*/
int Does_square_exist(Rect* square);

/**
 * Cette fonction crée un rectangle en attribuant les valeurs qui lui sont passées aux attributs respectifs d'un 'rect' SVG.
 * @param x Valeur entière de la position du centre sur l'axe des abscisses (X).
 * @param y Valeur entière de la position du centre sur l'axe des ordonnées(Y).
 * @param height Valeur entière non signée de la hauteur du rectangle en pixels.
 * @param round Valeur entière non signée du rayon d'arrondi en pixels.
 * @return Retourne un pointeur sur la stucture 'Rect'
 en manipulant l'allocation mémoire. Il faut donc garder à l'esprit que le rectangle qui reçoit le retour de cette fonction doit être obligatoirement 'free' à la fin.
*/
Rect* Create_square(int x, int y, unsigned int height, unsigned int round);

int Modify_square_menu();

void Modify_square(Rect* square);

void Export_square(Rect* square, Style* style);

#endif
