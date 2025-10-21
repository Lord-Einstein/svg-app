#ifndef CIRCLE__MAIN_H
#define CIRCLE__MAIN_H

#include "../common-fonctions/fonctions.h"
#include "../shapes-style/style.h"
#include "../../svg/main.h"

// STRUCTURE -------------------

/**
 * Structure représentant un Cercle SVG.
 */
typedef struct {
    int cx, cy;
    unsigned int rx;
} Circle;

// PROCEDURES --------------------------

/**
 * Affiche les informations sur la création d'un cercle en SVG.
 * 
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Element/circle">En savoir plus sur les cercles SVG.</a>
 */
void Infos_cercle();

/**
 * Récupère les informations saisies par l'utilisateur pour créer un cercle.
 * 
 * @param circle Pointeur sur la structure Circle à remplir.
 */
void Recup_circle_data(Circle* circle);

/**
 * Libère la mémoire allouée pour un cercle.
 * 
 * @param circle Pointeur sur la structure Circle à détruire.
 */
void Destroy_circle(Circle* circle);

/**
 * Affiche les informations contenues dans un cercle.
 * 
 * @param circle Pointeur sur la structure Circle à afficher.
 */
void Display_circle(Circle* circle);

// FONCTIONS --------------------

/**
 * Crée un cercle avec les coordonnées du centre et le rayon.
 * 
 * @param cx Coordonnée X du centre.
 * @param cy Coordonnée Y du centre.
 * @param rx Rayon du cercle.
 * @return Pointeur vers la structure Circle créée (à libérer avec free()).
 */
Circle* Create_circle(int cx, int cy, unsigned int rx);

/**
 * Vérifie si un cercle existe (pointeur non nul).
 * 
 * @param circle Pointeur sur la structure Circle à tester.
 * @return 1 si le cercle existe, 0 sinon.
 */
int Does_circle_exist(Circle* circle);

/**
 * Affiche et gère le menu de modification d'un cercle.
 * 
 * @param circle Pointeur sur la structure Circle à modifier.
 */
void Modify_circle(Circle* circle);

/**
 * Affiche le menu de modification d'un cercle.
 * 
 * @return Numéro correspondant au choix de l'utilisateur.
 */
int Modify_circle_menu();

/**
 * Exporte un cercle en SVG avec le style fourni.
 * 
 * @param circle Pointeur sur la structure Circle à exporter.
 * @param style Pointeur sur la structure Style à appliquer.
 */
void Export_circle(Circle* circle, Style* style);

#endif
