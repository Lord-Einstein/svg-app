#ifndef CLI_UI__MAIN_H
#define CLI_UI__MAIN_H

#include "../shapes/common-fonctions/fonctions.h"
#include "../parser/parser.h"

#include "../shapes/circle/main.h"
#include "../shapes/ellipse/main.h"
#include "../shapes/line/main.h"
#include "../shapes/path/path.h"
#include "../shapes/polygone/main.h"
#include "../shapes/polyline/main.h"
#include "../shapes/rectangle/main.h"
#include "../shapes/square/main.h"
#include "../shapes/group/groupe.h"

#include "../shapes/shapes-style/style.h"

/**
 * Enumération des types de formes disponibles.
 */
typedef enum AllShapesEnum_E {
    SHAPE_CIRCLE = 1,
    SHAPE_ELLIPSE,
    SHAPE_RECTANGLE,
    SHAPE_SQUARE,
    SHAPE_LINE,
    SHAPE_POLYGON,
    SHAPE_POLYLINE,
    SHAPE_PATH,
    SHAPE_GROUP,
    OUT
} AllShapesEnum;

/**
 * Enumération du premier menu principal.
 */
typedef enum FirstMenu_E {
    CREER = 1,
    CHARGER,
    QUITTER_FIRST
} FirstMenu;

/**
 * Enumération du second menu d'édition.
 */
typedef enum SecondMenu_E {
    MODIFIER = 1,
    STYLISER,
    EXPORTER,
    SUPPRIMER
} SecondMenu;

/**
 * Affiche le premier menu principal et retourne le choix de l'utilisateur.
 * 
 * @return Numéro correspondant au choix.
 */
int First_menu();

/**
 * Affiche le second menu complet et retourne le choix de l'utilisateur.
 * 
 * @return Numéro correspondant au choix.
 */
int Second_menu();

/**
 * Affiche le second menu incomplet et retourne le choix de l'utilisateur.
 * 
 * @return Numéro correspondant au choix.
 */
int Second_menu_incomplete();

/**
 * Affiche le menu de sélection des formes et retourne le choix de l'utilisateur.
 * 
 * @return Numéro correspondant à la forme choisie.
 */
int Menu_shapes();

/**
 * Boucle principale pour gérer un cercle avec style.
 * 
 * @param circle Pointeur vers le cercle.
 * @param style Pointeur vers le style appliqué.
 */
void Circle_loop(Circle* circle, Style* style);

/**
 * Édition générale d'un cercle dans l'univers graphique.
 */
void Circle_edit_universe();

/**
 * Boucle principale pour gérer une ellipse avec style.
 * 
 * @param ellipse Pointeur vers l'ellipse.
 * @param style Pointeur vers le style appliqué.
 */
void Ellipse_loop(Ellipse* ellipse, Style* style);

/**
 * Édition générale d'une ellipse dans l'univers graphique.
 */
void Ellipse_edit_universe();

/**
 * Boucle principale pour gérer un rectangle avec style.
 * 
 * @param rect Pointeur vers le rectangle.
 * @param style Pointeur vers le style appliqué.
 */
void Rect_loop(Rect* rect, Style* style);

/**
 * Édition générale d'un rectangle dans l'univers graphique.
 */
void Rect_edit_universe();

/**
 * Édition générale d'un carré dans l'univers graphique.
 */
void Square_edit_universe();

/**
 * Boucle principale pour gérer une ligne avec style.
 * 
 * @param line Pointeur vers la ligne.
 * @param style Pointeur vers le style appliqué.
 */
void Line_loop(Line* line, Style* style);

/**
 * Édition générale d'une ligne dans l'univers graphique.
 */
void Line_edit_universe();

/**
 * Boucle principale pour gérer une polyline avec style.
 * 
 * @param head Pointeur vers la Head de la polyline.
 * @param style Pointeur vers le style appliqué.
 */
void Polyline_loop(Head* head, Style* style);

/**
 * Édition générale d'une polyline dans l'univers graphique.
 */
void Polyline_edit_universe();

/**
 * Boucle principale pour gérer un path avec style.
 * 
 * @param head Pointeur vers la HeadPath du path.
 * @param style Pointeur vers le style appliqué.
 */
void Path_loop(HeadPath* head, Style* style);

/**
 * Édition générale d'un path dans l'univers graphique.
 */
void Path_edit_universe();

/**
 * Boucle principale pour gérer un polygone avec style.
 * 
 * @param head Pointeur vers la Head du polygone.
 * @param style Pointeur vers le style appliqué.
 */
void Polygone_loop(Head* head, Style* style);

/**
 * Édition générale d'un polygone dans l'univers graphique.
 */
void Polygone_edit_universe();

/**
 * Crée un bloc générique d'édition ou de création.
 */
void Create_bloc();

#endif
