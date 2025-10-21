#ifndef LINE__MAIN_H
#define LINE__MAIN_H

#include "../common-fonctions/fonctions.h"
#include "../shapes-style/style.h"
#include "../../svg/main.h"

// STRUCTURE --------------
/**
 * Représente une ligne avec deux points (x1, y1) et (x2, y2).
 */
typedef struct {
    int x1, y1, x2, y2;
} Line;

// PROCEDURES --------------

/**
 * Affiche les informations sur la création d'une ligne en SVG.
 * 
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Element/line">En savoir plus sur les lignes SVG.</a>
 */
void Infos_line();

/**
 * Récupère les informations saisies par l'utilisateur pour créer une ligne.
 * 
 * @param line Pointeur sur la structure Line à remplir.
 */
void Recup_line_data(Line* line);

/**
 * Libère la mémoire allouée pour une ligne.
 * 
 * @param line Pointeur sur la structure Line à détruire.
 */
void Destroy_line(Line* line);

/**
 * Affiche les informations d'une ligne.
 * 
 * @param line Pointeur sur la structure Line à afficher.
 */
void Display_line(Line* line);

// FONCTIONS ------------

/**
 * Vérifie si une ligne existe (pointeur non nul).
 * 
 * @param line Pointeur sur la structure Line à tester.
 * @return 1 si la ligne existe, 0 sinon.
 */
int Does_line_exist(Line* line);

/**
 * Crée une ligne avec les coordonnées fournies.
 * 
 * @param x1 Coordonnée X du premier point.
 * @param y1 Coordonnée Y du premier point.
 * @param x2 Coordonnée X du second point.
 * @param y2 Coordonnée Y du second point.
 * @return Pointeur vers la structure Line créée (à libérer avec free()).
 */
Line* Create_line(int x1, int y1, int x2, int y2);

/**
 * Affiche et gère le menu de modification d'une ligne.
 * 
 * @return Code correspondant au choix de l'utilisateur.
 */
int Modify_line_menu();

/**
 * Modifie une ligne existante.
 * 
 * @param line Pointeur sur la structure Line à modifier.
 */
void Modify_line(Line* line);

/**
 * Exporte une ligne en SVG avec le style fourni.
 * 
 * @param line Pointeur sur la structure Line à exporter.
 * @param style Pointeur sur la structure Style à appliquer.
 */
void Export_line(Line* line, Style* style);

#endif
