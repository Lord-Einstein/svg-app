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

typedef enum FirstMenu_E {
    CREER = 1,
    CHARGER,
    QUITTER_FIRST
} FirstMenu;

typedef enum SecondMenu_E {
    MODIFIER = 1,
    STYLISER,
    EXPORTER,
    SUPPRIMER
} SecondMenu;


int First_menu();

int Second_menu();
int Second_menu_incomplete();

int Menu_shapes();

void Circle_loop(Circle* circle, Style* style);
void Circle_edit_universe();

void Ellipse_loop(Ellipse* ellipse, Style* style);
void Ellipse_edit_universe();

void Rect_loop(Rect* rect, Style* style);
void Rect_edit_universe();

void Square_edit_universe();

void Line_loop(Line* line, Style* style);
void Line_edit_universe();

void Polyline_loop(Head* head, Style* style);
void Polyline_edit_universe();

void Path_loop(HeadPath* head, Style* style);
void Path_edit_universe();

void Polygone_loop(Head* head, Style* style);
void Polygone_edit_universe();

void Create_bloc();


#endif