#ifndef ELLIPSE__MAIN_H
#define ELLIPSE__MAIN_H

#include "../circle/main.h"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case

// STRUCTURE ----------------- 
/**
 * @brief Structure représentant une Ellipse SVG.
 * 
 * Qui n'est en réalité une extension du Cercle auquel on rajoute la taille d'un rayon sur Y
*/
typedef struct {
    Circle* circle;
    unsigned int ry;
} Ellipse;

// PROCEDURES -----------------

/**
 * @brief Cette procédure affiche à l'utilisateur les informations utiles pour la création d'une ellipse en format SVG.
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Element/circle"> En savoir plus sur les cercles SVG.</a>
*/
void Infos_ellipse();

/**
 * Cette procédure récupère les informations entrées par l'utilisateur pour créer une ellipse.
 * À noter que cette procédure exploite celle de recup de cercle car quand on y pense il suffit de créer un cercle puis de lui ajouter le paramètre du rayon sur y.
 * @param ellipse Prend en paramètre un pointeur sur l'ellipse à créer, puis procède par un remplissage par adressse.
*/
void Recup_ellipse_data(Ellipse* ellipse);

/**
 * Cette procédure libère l'allocation mémoire faite à la création d'une instance de type 'Ellipse'.
 * Puisque l'Ellipse est juste une structure qui se greffe sur celle du cercle et là complète, il faut faire bien attention à free le cercle et ensuite l'ellipse elle-même
 * @param ellipse Prends en paramètre un pointeur sur l'instance de l'ellipse à détruire et le libère grâce au free.
*/
void Destroy_ellipse(Ellipse* ellipse);

/**
 * Cette procédure affiche les informations contenues dans une instance 'Ellipse' passée en paramètre.
 * @param ellipse Prends en paramètre un pointeur sur l'instance d'ellipse dont on souhaite afficher les informations.
*/
void Display_ellipse(Ellipse* ellipse);



// FONCTIONS --------------------

/**
 * Cette fonction crée un cercle en attribuant les valeurs qui lui sont passées aux attributs respectifs d'une ellipse SVG.
 * @param cx Valeur entière de la position du centre sur l'axe des abscisses (X).
 * @param cy Valeur entière de la position du centre sur l'axe des ordonnées(Y).
 * @param rx Valeur entière non signée de la taille du rayon sur X en pixels.
 * @param ry Valeur entière non signée de la taille du rayon sur Y en pixels.
 * @return Retourne un pointeur sur la stucture 'Ellipse'
 en manipulant l'allocation mémoire. Il faut donc garder à l'esprit que l'ellipse qui reçoit le retour de cette fonction doit être obligatoirement 'free' à la fin.
*/
Ellipse* Create_ellipse(int cx, int cy, unsigned int rx, unsigned int ry);

/**
 * Cette fonction vérifie si le pointeur qui contient l'allocation sur une Ellipse existe (!=NULL)
 * @param ellipse Prend un pointeur sur 'Ellipse' et vérifie si il existe bien.
 * @return Retourne un True si le pointeur a bien reçu l'allocation et un False dans le cas contraire.
*/
int Does_ellipse_exist(Ellipse* ellipse);

int Modify_ellipse_menu();

void Modify_ellipse(Ellipse* ellipse);

void Export_ellipse(Ellipse* ellipse, Style* style);

#endif