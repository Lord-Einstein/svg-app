#ifndef SVG__MAIN_H
#define SVG__MAIN_H

#include "../common-h.h"
#include "../shapes/common-fonctions/fonctions.h"

// Noms de structures, d'enums, d'unions :: PascalCase
// Noms de variables :: snake_case
// Noms de fonctions ou de procédures :: Big_snake_case

/**
 * Représente la zone visible d’un SVG.
 */
typedef struct {
    int minx;              /**< Coordonnée X minimale (0 par défaut). */
    int miny;              /**< Coordonnée Y minimale (0 par défaut). */
    unsigned int width;    /**< Largeur de la vue (200 par défaut). */
    unsigned int height;   /**< Hauteur de la vue (200 par défaut). */
} ViewBox;

/**
 * Représente la structure principale d’un fichier SVG.
 */
typedef struct {
    unsigned int width;    /**< Largeur du SVG (100% par défaut). */
    unsigned int height;   /**< Hauteur du SVG (100% par défaut). */
    const char* xlmns;     /**< Espace de noms XML du SVG. */
    ViewBox* view_box;     /**< Pointeur vers la structure ViewBox. */
} Svg;

/**
 * Affiche le contenu d’un SVG.
 * 
 * @param svg Pointeur vers la structure Svg à afficher.
 */
void Display_svg(Svg* svg);

/**
 * Crée un nouveau SVG et renvoie son pointeur.
 * 
 * @return Pointeur vers le SVG créé.
 */
Svg* Create_new_svg();

/**
 * Vérifie si un SVG existe.
 * 
 * @param svg Pointeur vers la structure Svg à vérifier.
 * @return 1 si le SVG existe, 0 sinon.
 */
int Does_svg_exist(Svg* svg);

/**
 * Affiche et gère le menu de modification du SVG.
 * 
 * @return Code de retour selon le choix effectué.
 */
int Modify_svg_menu();

/**
 * Modifie les propriétés d’un SVG existant.
 * 
 * @param svg Pointeur vers la structure Svg à modifier.
 */
void Modify_svg(Svg* svg);

/**
 * Exporte un SVG vers un fichier.
 * 
 * @param svg Pointeur vers la structure Svg à exporter.
 */
void Export_svg(Svg* svg);

/**
 * Libère la mémoire utilisée par un SVG.
 * 
 * @param svg Pointeur vers la structure Svg à détruire.
 */
void Destroy_svg(Svg* svg);

#endif
