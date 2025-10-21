#ifndef ELLIPSE__MAIN_H
#define ELLIPSE__MAIN_H

#include "../circle/main.h"

// STRUCTURE -----------------
/**
 * Structure représentant une Ellipse SVG.
 * 
 * Extension d'un cercle auquel on rajoute le rayon sur l'axe Y.
 */
typedef struct {
    Circle* circle;
    unsigned int ry;
} Ellipse;

// PROCEDURES -----------------

/**
 * Affiche les informations pour créer une ellipse en SVG.
 * 
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Element/circle">En savoir plus sur les cercles SVG.</a>
 */
void Infos_ellipse();

/**
 * Récupère les informations de l'utilisateur pour créer une ellipse.
 * 
 * @param ellipse Pointeur sur la structure Ellipse à remplir.
 */
void Recup_ellipse_data(Ellipse* ellipse);

/**
 * Libère la mémoire allouée à une ellipse, y compris le cercle interne.
 * 
 * @param ellipse Pointeur sur l'instance d'Ellipse à détruire.
 */
void Destroy_ellipse(Ellipse* ellipse);

/**
 * Affiche les informations contenues dans une ellipse.
 * 
 * @param ellipse Pointeur sur l'instance d'Ellipse à afficher.
 */
void Display_ellipse(Ellipse* ellipse);

// FONCTIONS -----------------

/**
 * Crée une ellipse avec les coordonnées du centre et les rayons.
 * 
 * @param cx Coordonnée X du centre.
 * @param cy Coordonnée Y du centre.
 * @param rx Rayon sur l'axe X.
 * @param ry Rayon sur l'axe Y.
 * @return Pointeur vers la structure Ellipse créée (à libérer avec free()).
 */
Ellipse* Create_ellipse(int cx, int cy, unsigned int rx, unsigned int ry);

/**
 * Vérifie si une ellipse existe (pointeur non nul).
 * 
 * @param ellipse Pointeur sur l'ellipse à tester.
 * @return 1 si l'ellipse existe, 0 sinon.
 */
int Does_ellipse_exist(Ellipse* ellipse);

/**
 * Affiche le menu de modification d'une ellipse.
 * 
 * @return Code correspondant au choix de l'utilisateur.
 */
int Modify_ellipse_menu();

/**
 * Modifie une ellipse existante.
 * 
 * @param ellipse Pointeur sur l'instance d'Ellipse à modifier.
 */
void Modify_ellipse(Ellipse* ellipse);

/**
 * Exporte une ellipse en SVG avec le style fourni.
 * 
 * @param ellipse Pointeur sur l'instance d'Ellipse à exporter.
 * @param style Pointeur sur la structure Style à appliquer.
 */
void Export_ellipse(Ellipse* ellipse, Style* style);

#endif
