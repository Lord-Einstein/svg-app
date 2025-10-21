#ifndef PATH__PATH_H
#define PATH__PATH_H


#include "../common-fonctions/fonctions.h"
#include "../shapes-style/style.h"
#include "../../svg/main.h"

// #define scanf(...) (Drain_buffer(), scanf(__VA_ARGS__))


//STRUCTURES & UNIONS & ENUMS

/**
 * @brief Stucture représentant un point de coordonnées X et Y en entier.
*/
typedef struct Point{
    int x, y;
}Point;

/**
 * @brief Enumérations des commandes utilisées pour l'élément SVG 'Path'.
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
}Commands;

/**
 * @brief Stucture rassemblant les paramètres respectifs de la commande MoveTo en tant qu'attributs
*/
typedef struct MoveTo{
    Point* p;
}MoveTo;

/**
 * @brief Stucture rassemblant les paramètres respectifs de la commande LineTo en tant qu'attributs
*/
typedef struct LineTo{
    Point* p;
}LineTo;

/**
 * @brief Stucture rassemblant les paramètres respectifs de la commande HorizontalLineTo en tant qu'attributs
*/
typedef struct HLineTo{
    int x;
}HLineTo;

/**
 * @brief Stucture rassemblant les paramètres respectifs de la commande VerticalLineTo en tant qu'attributs
*/
typedef struct VLineTo{
    int x;
}VLineTo;

/**
 * @brief Stucture rassemblant les paramètres respectifs de la commande CubicCurve en tant qu'attributs
*/
typedef struct CubicCurve{
    Point* point1;
    Point* point2;
    Point* point3;
}CubicCurve;

/**
 * @brief Stucture rassemblant les paramètres respectifs de la commande SmoothCubicCurve en tant qu'attributs
*/
typedef struct SmoothCubicCurve{
    Point* point1;
    Point* point2;
}SmoothCubicCurve;

/**
 * @brief Stucture rassemblant les paramètres respectifs de la commande QuadraCurve en tant qu'attributs
*/
typedef struct QuadraCurve{
    Point* point1;
    Point* point2;
}QuadraCurve;

/**
 * @brief Stucture rassemblant les paramètres respectifs de la commande SmoothQuadraCurve en tant qu'attributs
*/
typedef struct SmoothQuadraCurve{
    Point* p;
}SmoothQuadraCurve;

/**
 * @brief Stucture rassemblant les paramètres respectifs de la commande Close en tant qu'attributs
*/
typedef struct Close{
}Close;

/**
 * @brief Union de toutes les structures de commande de l'élément 'Path'.
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
}Current_Command;

/**
 * @brief Structure générale d'un sous-élément de 'Path', constituée de l'une des commandes (d'où l'union) et du type de la commande (d'où l'enum).
*/
typedef struct Path_element{
    Current_Command current_command;
    Commands commands;
}Path_element;

/**
 * @brief Déclaration de la structure Node qui représente un noeud de la liste 'Path' et donc représente une entité générale d'éléments de Path et les liens avec les autres noeuds.
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
 * @brief Structure propre aux listes (en tête d'une liste et donc référence première vers les autres cases), représentant ainsi le 'Path' en lui même.
*/
typedef struct {
    Node* start;
}HeadPath;


//PROCEDURES ---------------

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la création d'un Path en format SVG.
*/
void Infos_path();

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la commande Move To de l'élément Path.
*/
void Infos_M();

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la commande Line To de l'élément Path.
*/
void Infos_L();

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la commande Horizontal Line To de l'élément Path.
*/
void Infos_H();

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la commande Vertical Line To de l'élément Path.
*/
void Infos_V();

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la commande Cubic Bezier Curve de l'élément Path.
*/
void Infos_C();

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la commande Smooth Cubic Bezier Curve de l'élément Path.
*/
void Infos_S();

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la commande Quadratic Bezier Curve de l'élément Path.
*/
void Infos_Q();

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la commande Smooth Quadratic Bezier Curve de l'élément Path.
*/
void Infos_T();

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la commande Close de l'élément Path.
*/
void Infos_Z();




/**
 * Cette procédure libère l'allocation mémoire faite à la création d'une instance de type 'Path'.
 * Il faut en l'occurence penser à bien prévoir toutes les possibilités de free adaptées à chaque commande de Path.
 * @param node Prend en paramètre un pointeur sur l'instance de Path à détruire et le libère grâce au free.
*/
void Destroy_path_element(Node* node);

/**
 * Cette procédure libère l'allocation mémoire faite à la création d'une instance de type 'Head'.
 * @param head Prend en paramètre un pointeur sur l'instance de Head à détruire et le libère grâce au free.
 * 
 * Ici, il faut libérer toutes les autres instances de 'Path' qui font parties de la chaîne de liste pointée par 'head'.
*/
void Destroy_path(HeadPath* head);

/**
 * Cette procédure affiche les informations contenues dans l'élément passé en paramètre en fonction de son type et étant donné qu'il y'a plusieurs commandes possibles.
 * @param node Prend en paramètre l'élément dont on veut afficher les informations et adopte un cas de lecture en fonction de son type.
 */
void Display_path_element(Node* node);

/**
 * Cette procédure affiche les informations contenues dans tous les éléments contenus dans la liste 'Path' passée en passé en paramètre.
 * @param head Prend en paramètre la liste Path courante.
 */
void Display_path(HeadPath* head);

/**
 * Procédure complète de récupération des informations permettant de créer un 'Path' complet.
 * Elle inclut une fonction de filtrage des entrées de l'utilisateur, de tri pour identifier la commande à créer ..... ainsi qu'une boucle de répétition afin de permettre la reprise de tout le processus de création.
 * @param head Prend en paramètre la liste 'Path' qu'on souhaite remplir.
 */
void Recup_path_data(HeadPath* head);

/** 
 * Cette procédure permet d'ajouter un noeud ou une commande à la lite 'Path'.
 * @param head La référence d'en tête de la liste 'Path' à compléter.
 * @param new_node Le nouveau noeud ou sous commande à ajouter à la liste 'Path' courante.
*/
void Add_path_element(HeadPath* head, Node* new_node);


//FONCTIONS ----- Description JavaDoc à Faire !!!!

int Menu_commands();
int Does_path_element_exist(Node* node);
int Does_path_exist(HeadPath* head);

Node* Create_new_path_element(int commands);
Close* Create_new_close();
SmoothQuadraCurve* Create_new_smooth_quadra_curve(Point* p);
QuadraCurve* Create_new_quadra_curve(Point* point1, Point* point2);
SmoothCubicCurve* Create_new_smooth_cubic_curve(Point* point1, Point* point2);
CubicCurve* Create_new_cubic_curve(Point* point1, Point* point2, Point* point3);
VLineTo* Create_new_v_line_to(int x);
HLineTo* Create_new_h_line_to(int x);
LineTo* Create_new_line_to(Point* point);
MoveTo* Create_new_move_to(Point* point);
Point* Create_new_couple(int x, int y);
HeadPath* Create_new_path();


void Display_path_element_detailed(Node* node);
void Display_path_list(HeadPath* head);
int Modify_path_element_menu();
void Modify_path_element(Node* node);
void Delete_path_element_by_index(HeadPath* head, int index);
int Modify_path_menu();
void Modify_path(HeadPath* head);
Node* Get_path_element_by_index(HeadPath* head, int index);
void Export_path(HeadPath* head, Style* style);

void Recup_path_data(HeadPath* head);

#endif