#ifndef RECTANGLE__MAIN_H
#define RECTANGLE__MAIN_H

#include "../common-fonctions/fonctions.h"
#include "../shapes-style/style.h"
#include "../../svg/main.h"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case


// STRUCTURE --------------
typedef struct {
    int x, y;
    unsigned int height, width, round;
}Rect;



// PROCEDURES --------------

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la création d'un rectangle en format SVG
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Element/circle"> En savoir plus sur les cercles SVG.</a>
*/
void Infos_rect();

/**
 * Cette procédure récupère les informations entrées par l'utilisateur pour créer un rectangle.
 * (Elle vérifie toujours si le pointeur n'est pas nul).
 * @param rect Prend en paramètre un pointeur sur le rectangle à créer, puis procède par un remplissage par adressse.
*/
void Recup_rect_data(Rect* rect);

/**
 * Cette procédure libère l'allocation mémoire faite à la création d'une instance de type 'Rect'.
 * @param rect Prend en paramètre un pointeur sur l'instance de Rectangle à détruire et le libère grâce au free.
*/
void Destroy_rect(Rect* rect);

/**
 * Cette procédure affiche les informations contenues dans une instance 'Rect' passée en paramètre.
 * @param rect Prends en paramètre un pointeur sur l'instance de Rectangle dont on souhaite afficher les informations.
*/
void Display_rect(Rect* rect);



// FONCTIONS ------------

/**
 * Cette fonction vérifie si le pointeur qui contient l'allocation sur un Rectangle existe (!=NULL)
 * @param rect Prend un pointeur sur 'Rect' et vérifie si il existe bien.
 * @return Retourne un True si le pointeur a bien reçu l'allocation et un False dans le cas contraire.
*/
int Does_rect_exist(Rect* rect);

/**
 * Cette fonction crée un rectangle en attribuant les valeurs qui lui sont passées aux attributs respectifs d'un 'rect' SVG.
 * @param x Valeur entière de la position du centre sur l'axe des abscisses (X).
 * @param y Valeur entière de la position du centre sur l'axe des ordonnées(Y).
 * @param height Valeur entière non signée de la hauteur du rectangle en pixels.
 * @param width Valeur entière non signée de la largeur du rectangle en pixels.
 * @param round Valeur entière non signée du rayon d'arrondi en pixels.
 * @return Retourne un pointeur sur la stucture 'Rect'
 en manipulant l'allocation mémoire. Il faut donc garder à l'esprit que le rectangle qui reçoit le retour de cette fonction doit être obligatoirement 'free' à la fin.
*/
Rect* Create_rect(int x, int y, unsigned int height, unsigned int width, unsigned int round);

int Modify_rect_menu();

void Modify_rect(Rect* rect);

void Export_rect(Rect* rect, Style* style);

#endif
