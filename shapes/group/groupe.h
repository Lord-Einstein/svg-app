#ifndef GROUP__GROUPE_H
#define GROUP__GROUPE_H

#include "../common-fonctions/fonctions.h"

#include "../circle/main.h"
#include "../ellipse/main.h"
#include "../line/main.h"
#include "../path/path.h"
#include "../polygone/main.h"
#include "../polyline/main.h"
#include "../rectangle/main.h"
#include "../square/main.h"

typedef struct GroupStruct Group;

typedef union CurrentShapesUnion {
    Circle* circle;
    Ellipse* ellipse;
    Line* line;
    HeadPath* path;
    Head* polygone;
    Head* polyline;
    Rect* rect;
    Rect* square;
    Group* group;
} CurrentShapes;

typedef enum ShapesEnum {
    CIRCLE,
    ELLIPSE,
    RECTANGLE,
    SQUARE,
    LINE,
    POLYGON,
    POLYLINE,
    PATH,
    GROUP
} Shapes;

typedef struct GroupElementStruct {
    CurrentShapes current_shapes;
    Shapes shapes;
} GroupElement;

typedef struct GroupNodeStruct GroupNode;

struct GroupNodeStruct {
    GroupElement* node;
    GroupNode* next;
    GroupNode* previous;
};

typedef struct GroupStruct {
    char name[64];
    GroupNode* start;
} Group;

// ==== FONCTIONS D’AFFICHAGE ====
void Infos_group();
void Infos_group_usage();

// ==== FONCTIONS DE CRÉATION ====
Group* Create_new_group();
GroupElement* Create_new_group_element(Shapes shape_type);
GroupNode* Create_new_group_node(GroupElement* element);

// ==== FONCTIONS D’UTILITÉ ====
int Does_group_exist(Group* group);
int Does_group_node_exist(GroupNode* node);
int Does_group_element_exist(GroupElement* element);

// ==== FONCTIONS DE GESTION ====
void Add_shape_to_group(Group* group, GroupNode* new_node);
void Destroy_group_element(GroupElement* element);
void Destroy_group_node(GroupNode* node);
void Destroy_group(Group* group);

// ==== FONCTIONS D’AFFICHAGE ====
void Display_group_element(GroupElement* element);
void Display_group(Group* group);

// ==== FONCTION D’INTERACTION ====
void Recup_group_data(Group* group);
int Menu_group_shapes();

#endif
