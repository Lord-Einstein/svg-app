#ifndef PATH__PATH_H
#define PATH__PATH_H

#include "../common-fonctions/fonctions.h"
#include "../shapes-style/style.h"
#include "../../svg/main.h"

// STRUCTURES & UNIONS & ENUMS
/**
 * Représente un point avec des coordonnées X et Y.
 */
typedef struct Point{
    int x, y;
} Point;

/**
 * Enumération des commandes possibles pour un élément SVG Path.
 */
typedef enum Commands{
    MOVE_TO,
    LINE_TO,
    H_LINE_TO,
    V_LINE_TO,
    CUBIC_CURVE,
    SMOOTH_CUBIC_CURVE,
    QUADRA_CURVE,
    SMOOTH_QUADRA_CURVE,
    CLOSE
} Commands;

/**
 * Paramètres de la commande MoveTo.
 */
typedef struct MoveTo{
    Point* p;
} MoveTo;

/**
 * Paramètres de la commande LineTo.
 */
typedef struct LineTo{
    Point* p;
} LineTo;

/**
 * Paramètres de la commande HorizontalLineTo.
 */
typedef struct HLineTo{
    int x;
} HLineTo;

/**
 * Paramètres de la commande VerticalLineTo.
 */
typedef struct VLineTo{
    int x;
} VLineTo;

/**
 * Paramètres de la commande CubicCurve.
 */
typedef struct CubicCurve{
    Point* point1;
    Point* point2;
    Point* point3;
} CubicCurve;

/**
 * Paramètres de la commande SmoothCubicCurve.
 */
typedef struct SmoothCubicCurve{
    Point* point1;
    Point* point2;
} SmoothCubicCurve;

/**
 * Paramètres de la commande QuadraCurve.
 */
typedef struct QuadraCurve{
    Point* point1;
    Point* point2;
} QuadraCurve;

/**
 * Paramètres de la commande SmoothQuadraCurve.
 */
typedef struct SmoothQuadraCurve{
    Point* p;
} SmoothQuadraCurve;

/**
 * Paramètres de la commande Close.
 */
typedef struct Close{
} Close;

/**
 * Union des structures de commande d'un Path.
 */
typedef union Current_Command{
    MoveTo* move_to;
    LineTo* line_to;
    HLineTo* h_line_to;
    VLineTo* v_line_to;
    CubicCurve* cubic_curve;
    SmoothCubicCurve* smooth_cubic_curve;
    QuadraCurve* quadra_curve;
    SmoothQuadraCurve* smooth_quadra_curve;
    Close* close;
} Current_Command;

/**
 * Structure représentant un élément de Path.
 */
typedef struct Path_element{
    Current_Command current_command;
    Commands commands;
} Path_element;

/**
 * Noeud de la liste Path.
 */
typedef struct Node_s Node;

struct Node_s
{
    char type;
    Path_element* path_element;
    Node* previous;
    Node* next;
};

/**
 * Structure représentant la liste Path (tête).
 */
typedef struct {
    Node* start;
} HeadPath;

// PROCEDURES ---------------

/**
 * Affiche les informations sur la création d'un Path en SVG.
 */
void Infos_path();

/**
 * Affiche les informations sur la commande Move To (M) d'un Path.
 */
void Infos_M();

/**
 * Affiche les informations sur la commande Line To (L) d'un Path.
 */
void Infos_L();

/**
 * Affiche les informations sur la commande Horizontal Line To (H) d'un Path.
 */
void Infos_H();

/**
 * Affiche les informations sur la commande Vertical Line To (V) d'un Path.
 */
void Infos_V();

/**
 * Affiche les informations sur la commande Cubic Bezier Curve (C) d'un Path.
 */
void Infos_C();

/**
 * Affiche les informations sur la commande Smooth Cubic Bezier Curve (S) d'un Path.
 */
void Infos_S();

/**
 * Affiche les informations sur la commande Quadratic Bezier Curve (Q) d'un Path.
 */
void Infos_Q();

/**
 * Affiche les informations sur la commande Smooth Quadratic Bezier Curve (T) d'un Path.
 */
void Infos_T();

/**
 * Affiche les informations sur la commande Close (Z) d'un Path.
 */
void Infos_Z();

/**
 * Libère la mémoire d'un élément Path.
 * 
 * @param node Pointeur sur le Node à détruire.
 */
void Destroy_path_element(Node* node);

/**
 * Libère la mémoire d'un HeadPath complet et de tous ses éléments.
 * 
 * @param head Pointeur sur la tête de la liste Path.
 */
void Destroy_path(HeadPath* head);

/**
 * Affiche les informations d'un élément Path selon son type.
 * 
 * @param node Pointeur sur le Node à afficher.
 */
void Display_path_element(Node* node);

/**
 * Affiche tous les éléments d'un HeadPath.
 * 
 * @param head Pointeur sur la liste Path à afficher.
 */
void Display_path(HeadPath* head);

/**
 * Récupère les informations de l'utilisateur pour créer un Path complet.
 * 
 * @param head Pointeur sur la liste Path à remplir.
 */
void Recup_path_data(HeadPath* head);

/**
 * Ajoute un élément à la liste Path.
 * 
 * @param head Pointeur sur la tête de la liste Path.
 * @param new_node Pointeur sur le Node à ajouter.
 */
void Add_path_element(HeadPath* head, Node* new_node);

// FONCTIONS ---------------

/**
 * Affiche le menu des commandes Path et retourne le choix.
 * 
 * @return Numéro de la commande sélectionnée.
 */
int Menu_commands();

/**
 * Vérifie si un élément Path existe.
 * 
 * @param node Pointeur sur le Node à tester.
 * @return 1 si l'élément existe, 0 sinon.
 */
int Does_path_element_exist(Node* node);

/**
 * Vérifie si un HeadPath existe.
 * 
 * @param head Pointeur sur la tête de la liste Path.
 * @return 1 si le HeadPath existe, 0 sinon.
 */
int Does_path_exist(HeadPath* head);

/**
 * Crée un nouvel élément Path selon le type de commande.
 * 
 * @param commands Type de commande.
 * @return Pointeur sur le Path_element créé.
 */
Node* Create_new_path_element(int commands);

/**
 * Crée une structure Close.
 * 
 * @return Pointeur vers la structure Close.
 */
Close* Create_new_close();

/**
 * Crée une structure SmoothQuadraCurve.
 * 
 * @param p Pointeur sur le point associé.
 * @return Pointeur vers la structure SmoothQuadraCurve.
 */
SmoothQuadraCurve* Create_new_smooth_quadra_curve(Point* p);

/**
 * Crée une structure QuadraCurve.
 * 
 * @param point1 Premier point.
 * @param point2 Second point.
 * @return Pointeur vers la structure QuadraCurve.
 */
QuadraCurve* Create_new_quadra_curve(Point* point1, Point* point2);

/**
 * Crée une structure SmoothCubicCurve.
 * 
 * @param point1 Premier point.
 * @param point2 Second point.
 * @return Pointeur vers la structure SmoothCubicCurve.
 */
SmoothCubicCurve* Create_new_smooth_cubic_curve(Point* point1, Point* point2);

/**
 * Crée une structure CubicCurve.
 * 
 * @param point1 Premier point.
 * @param point2 Deuxième point.
 * @param point3 Troisième point.
 * @return Pointeur vers la structure CubicCurve.
 */
CubicCurve* Create_new_cubic_curve(Point* point1, Point* point2, Point* point3);

/**
 * Crée une structure VLineTo.
 * 
 * @param x Coordonnée X.
 * @return Pointeur vers la structure VLineTo.
 */
VLineTo* Create_new_v_line_to(int x);

/**
 * Crée une structure HLineTo.
 * 
 * @param x Coordonnée X.
 * @return Pointeur vers la structure HLineTo.
 */
HLineTo* Create_new_h_line_to(int x);

/**
 * Crée une structure LineTo.
 * 
 * @param point Pointeur vers le point associé.
 * @return Pointeur vers la structure LineTo.
 */
LineTo* Create_new_line_to(Point* point);

/**
 * Crée une structure MoveTo.
 * 
 * @param point Pointeur vers le point associé.
 * @return Pointeur vers la structure MoveTo.
 */
MoveTo* Create_new_move_to(Point* point);

/**
 * Crée un nouveau couple de coordonnées (Point).
 * 
 * @param x Coordonnée X.
 * @param y Coordonnée Y.
 * @return Pointeur vers la structure Point.
 */
Point* Create_new_couple(int x, int y);

/**
 * Crée un nouveau HeadPath vide.
 * 
 * @return Pointeur vers la structure HeadPath.
 */
HeadPath* Create_new_path();

/**
 * Affiche un élément Path en détail.
 * 
 * @param node Pointeur sur le Node à afficher.
 */
void Display_path_element_detailed(Node* node);

/**
 * Affiche la liste complète d'un HeadPath.
 * 
 * @param head Pointeur sur la tête de la liste Path.
 */
void Display_path_list(HeadPath* head);

/**
 * Affiche le menu de modification d'un élément Path.
 * 
 * @return Numéro du choix sélectionné.
 */
int Modify_path_element_menu();

/**
 * Modifie un élément Path existant.
 * 
 * @param node Pointeur sur le Node à modifier.
 */
void Modify_path_element(Node* node);

/**
 * Supprime un élément Path selon son index.
 * 
 * @param head Pointeur sur la tête de la liste Path.
 * @param index Index de l'élément à supprimer.
 */
void Delete_path_element_by_index(HeadPath* head, int index);

/**
 * Affiche le menu de modification d'un Path complet.
 * 
 * @return Numéro du choix sélectionné.
 */
int Modify_path_menu();

/**
 * Modifie un Path complet.
 * 
 * @param head Pointeur sur la tête du Path à modifier.
 */
void Modify_path(HeadPath* head);

/**
 * Récupère un élément Path par son index.
 * 
 * @param head Pointeur sur la tête du Path.
 * @param index Index de l'élément recherché.
 * @return Pointeur vers le Node trouvé.
 */
Node* Get_path_element_by_index(HeadPath* head, int index);

/**
 * Exporte un Path complet en SVG avec le style fourni.
 * 
 * @param head Pointeur sur la tête de la liste Path.
 * @param style Pointeur sur la structure Style à appliquer.
 */
void Export_path(HeadPath* head, Style* style);

/**
 * Récupère les données pour remplir un Path (duplicata de Recup_path_data, inclut filtrage et boucles).
 * 
 * @param head Pointeur sur la tête de la liste Path.
 */
void Recup_path_data(HeadPath* head);

#endif
