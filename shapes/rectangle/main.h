#ifndef RECTANGLE__MAIN_H
#define RECTANGLE__MAIN_H

#include "../common-fonctions/fonctions.h"
#include "../shapes-style/style.h"
#include "../../svg/main.h"

// Noms de structures, d'enums, d'unions :: PascalCase
// Noms de variables :: snake_case
// Noms de fonctions ou de procédures :: Big_snake_case

// STRUCTURE --------------
typedef struct {
    int x, y;
    unsigned int height, width, round;
} Rect;

// PROCEDURES --------------

/**
 * @brief Cette procédure affiche les informations sur la création d'un rectangle en SVG.
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Element/circle">En savoir plus sur les cercles SVG.</a>
 */
void Infos_rect();

/**
 * Récupère les informations saisies pour créer un rectangle.
 * Vérifie que le pointeur n'est pas nul avant de remplir.
 * 
 * @param rect Pointeur sur le rectangle à remplir.
 */
void Recup_rect_data(Rect* rect);

/**
 * Libère la mémoire allouée à un rectangle.
 * 
 * @param rect Pointeur sur l'instance à détruire.
 */
void Destroy_rect(Rect* rect);

/**
 * Affiche les informations d'un rectangle.
 * 
 * @param rect Pointeur sur l'instance à afficher.
 */
void Display_rect(Rect* rect);

// FONCTIONS ------------

/**
 * Vérifie si un rectangle existe (pointeur non nul).
 * 
 * @param rect Pointeur sur le rectangle à tester.
 * @return 1 si le rectangle existe, 0 sinon.
 */
int Does_rect_exist(Rect* rect);

/**
 * Crée un rectangle avec les paramètres donnés.
 * 
 * @param x Position X du centre.
 * @param y Position Y du centre.
 * @param height Hauteur du rectangle en pixels.
 * @param width Largeur du rectangle en pixels.
 * @param round Rayon d’arrondi.
 * @return Pointeur sur la structure Rect créée (à libérer avec free()).
 */
Rect* Create_rect(int x, int y, unsigned int height, unsigned int width, unsigned int round);

/**
 * Affiche et gère le menu de modification du rectangle.
 * 
 * @return Code de retour selon le choix effectué.
 */
int Modify_rect_menu();

/**
 * Modifie un rectangle existant.
 * 
 * @param rect Pointeur sur le rectangle à modifier.
 */
void Modify_rect(Rect* rect);

/**
 * Exporte un rectangle en SVG avec son style.
 * 
 * @param rect Pointeur sur le rectangle à exporter.
 * @param style Style à appliquer.
 */
void Export_rect(Rect* rect, Style* style);

#endif
