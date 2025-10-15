#ifndef CIRCLE__MAIN_H
#define CIRCLE__MAIN_H

#include "../common-fonctions/fonctions.h"
#include "../shapes-style/style.h"
#include "../../svg/main.h"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de variables :: snake_case
//Noms de fonctions ou de procédures :: Big_snake_case

// STRUCTURE -------------------

/**
 * @brief Structure représentant un Cercle SVG.
*/
typedef struct {
    int cx, cy;
    unsigned int rx;
} Circle;

// PROCEDURES --------------------------

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la création d'un cercle en format SVG
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Element/circle"> En savoir plus sur les cercles SVG.</a>
*/
void Infos_cercle();

/**
 * Cette procédure récupère les informations entrées par l'utilisateur pour créer un cercle.
 * @param circle Prend en paramètre un pointeur sur le cercle à créer, puis procède par un remplissage par adressse.
*/
void Recup_circle_data(Circle* circle);

/**
 * Cette procédure libère l'allocation mémoire faite à la création d'une instance de type 'Circle'.
 * @param circle Prends en paramètre un pointeur sur l'instance de cercle à détruire et le libère grâce au free.
*/
void Destroy_circle(Circle* circle);

/**
 * Cette procédure affiche les informations contenues dans une instance 'Circle' passée en paramètre.
 * @param circle Prends en paramètre un pointeur sur l'instance de cercle dont on souhaite afficher les informations.
*/
void Display_circle(Circle* circle);


// FONCTIONS --------------------

/**
 * Cette fonction crée un cercle en attribuant les valeurs qui lui sont passées aux attributs respectifs d'un cercle SVG.
 * @param cx Valeur entière de la position du centre sur l'axe des abscisses (X).
 * @param cy Valeur entière de la position du centre sur l'axe des ordonnées(Y).
 * @param rx Valeur entière non signée de la taille du rayon en pixels.
 * @return Retourne un pointeur sur la stucture 'Cercle'
 en manipulant l'allocation mémoire. Il faut donc garder à l'esprit que le cercle qui reçoit le retour de cette fonction doit être obligatoirement 'free' à la fin.
*/
Circle* Create_circle(int cx, int cy, unsigned int rx);


/**
 * Cette fonction vérifie si le pointeur qui contient l'allocation sur un Cercle existe (!=NULL)
 * @param circle Prend un pointeur sur 'Circle' et vérifie si il existe bien.
 * @return Retourne un True si le pointeur a bien reçu l'allocation et un False dans le cas contraire.
*/
int Does_circle_exist(Circle* circle);

void Modify_circle(Circle* circle);
int Modify_circle_menu();


void Export_circle(Circle* circle, Style* style);

#endif