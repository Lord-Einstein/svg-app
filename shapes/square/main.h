#ifndef SQUARE__MAIN_H
#define SQUARE__MAIN_H

#include "../rectangle/main.h"

// Noms de structures, d'enums, d'unions :: PascalCase
// Noms de variables :: snake_case
// Noms de fonctions ou de procédures :: Big_snake_case

// PROCEDURES --------------

/**
 * Affiche à l'utilisateur les informations sur la création d'un carré au format SVG.
 * 
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Element/rect">En savoir plus sur les éléments SVG.</a>
 */
void Infos_square();

/**
 * Récupère les informations saisies par l'utilisateur pour créer un carré.
 * 
 * Vérifie que le pointeur n'est pas nul avant d'effectuer le remplissage.
 * 
 * @param square Pointeur sur le carré à créer, rempli par adresse.
 */
void Recup_square_data(Rect* square);

/**
 * Libère la mémoire allouée à une instance de type Rect.
 * 
 * @param square Pointeur sur l'instance de carré à détruire.
 */
void Destroy_square(Rect* square);

/**
 * Affiche les informations d'une instance Rect passée en paramètre.
 * 
 * @param square Pointeur sur l'instance de carré à afficher.
 */
void Display_square(Rect* square);


// FONCTIONS ------------

/**
 * Vérifie si un carré existe (pointeur non nul).
 * 
 * @param square Pointeur sur une structure Rect.
 * @return 1 si le carré existe, 0 sinon.
 */
int Does_square_exist(Rect* square);

/**
 * Crée un carré en initialisant ses attributs.
 * 
 * @param x Position du centre sur l’axe X.
 * @param y Position du centre sur l’axe Y.
 * @param height Hauteur du carré en pixels.
 * @param round Rayon d’arrondi en pixels.
 * @return Pointeur sur la structure Rect créée. 
 *         Doit être libéré avec free() après utilisation.
 */
Rect* Create_square(int x, int y, unsigned int height, unsigned int round);

/**
 * Affiche et gère le menu de modification d’un carré.
 * 
 * @return Code de retour selon le choix effectué.
 */
int Modify_square_menu();

/**
 * Modifie les propriétés d’un carré existant.
 * 
 * @param square Pointeur sur la structure Rect à modifier.
 */
void Modify_square(Rect* square);

/**
 * Exporte un carré en format SVG avec son style.
 * 
 * @param square Pointeur sur la structure Rect à exporter.
 * @param style Pointeur sur la structure Style à appliquer.
 */
void Export_square(Rect* square, Style* style);

#endif
