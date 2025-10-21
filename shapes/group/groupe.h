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

// STRUCTURES & ENUMS

/**
 * Union contenant tous les types de formes pouvant être stockées dans un groupe.
 */
typedef union CurrentShapesUnion {
    Circle* circle;
    Ellipse* ellipse;
    Line* line;
    HeadPath* path;
    Head* polygone;
    Head* polyline;
    Rect* rect;
    Rect* square;
    struct GroupStruct* group;
} CurrentShapes;

/**
 * Enumération des types de formes disponibles.
 */
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

/**
 * Représente un élément d'un groupe, contenant un type de forme et sa valeur.
 */
typedef struct GroupElementStruct {
    CurrentShapes current_shapes;
    Shapes shapes;
} GroupElement;

/**
 * Noeud de la liste chaînée d'un groupe.
 */
typedef struct GroupNodeStruct GroupNode;

struct GroupNodeStruct {
    GroupElement* node;
    GroupNode* next;
    GroupNode* previous;
};

/**
 * Structure représentant un groupe de formes SVG.
 */
typedef struct GroupStruct {
    char name[64];
    GroupNode* start;
} Group;

// PROCEDURES --------------

/**
 * Affiche les informations pour créer un groupe.
 */
void Infos_group();

/**
 * Affiche l'utilisation et les règles pour manipuler les groupes.
 */
void Infos_group_usage();

/**
 * Crée un nouveau groupe vide.
 * 
 * @return Pointeur vers le groupe créé.
 */
Group* Create_new_group();

/**
 * Crée un nouvel élément de groupe pour un type de forme donné.
 * 
 * @param shape_type Type de la forme à créer.
 * @return Pointeur vers le GroupElement créé.
 */
GroupElement* Create_new_group_element(Shapes shape_type);

/**
 * Crée un nouveau noeud de groupe contenant un élément.
 * 
 * @param element Pointeur vers le GroupElement à inclure dans le noeud.
 * @return Pointeur vers le GroupNode créé.
 */
GroupNode* Create_new_group_node(GroupElement* element);

/**
 * Vérifie si un groupe existe (pointeur non nul).
 * 
 * @param group Pointeur sur le groupe à tester.
 * @return 1 si le groupe existe, 0 sinon.
 */
int Does_group_exist(Group* group);

/**
 * Vérifie si un noeud de groupe existe (pointeur non nul).
 * 
 * @param node Pointeur sur le noeud à tester.
 * @return 1 si le noeud existe, 0 sinon.
 */
int Does_group_node_exist(GroupNode* node);

/**
 * Vérifie si un élément de groupe existe (pointeur non nul).
 * 
 * @param element Pointeur sur l'élément à tester.
 * @return 1 si l'élément existe, 0 sinon.
 */
int Does_group_element_exist(GroupElement* element);

/**
 * Ajoute un noeud (forme) à un groupe existant.
 * 
 * @param group Pointeur sur le groupe à compléter.
 * @param new_node Pointeur sur le noeud à ajouter.
 */
void Add_shape_to_group(Group* group, GroupNode* new_node);

/**
 * Libère la mémoire d'un élément de groupe.
 * 
 * @param element Pointeur sur le GroupElement à détruire.
 */
void Destroy_group_element(GroupElement* element);

/**
 * Libère la mémoire d'un noeud de groupe.
 * 
 * @param node Pointeur sur le GroupNode à détruire.
 */
void Destroy_group_node(GroupNode* node);

/**
 * Libère la mémoire d'un groupe complet, y compris tous ses noeuds et éléments.
 * 
 * @param group Pointeur sur le groupe à détruire.
 */
void Destroy_group(Group* group);

/**
 * Affiche un élément de groupe selon son type.
 * 
 * @param element Pointeur sur le GroupElement à afficher.
 */
void Display_group_element(GroupElement* element);

/**
 * Affiche toutes les formes contenues dans un groupe.
 * 
 * @param group Pointeur sur le groupe à afficher.
 */
void Display_group(Group* group);

/**
 * Récupère les informations de l'utilisateur pour remplir un groupe.
 * 
 * @param group Pointeur sur le groupe à remplir.
 */
void Recup_group_data(Group* group);

/**
 * Affiche le menu des types de formes pour ajout dans un groupe.
 * 
 * @return Numéro correspondant au type choisi.
 */
int Menu_group_shapes();

#endif
