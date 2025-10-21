#ifndef POLYLINE__MAIN_H
#define POLYLINE__MAIN_H

#include "../common-fonctions/fonctions.h"
#include "../shapes-style/style.h"
#include "../../svg/main.h"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case

typedef struct LinkPoint LinkPoint;

// STRUCTURE --------------
struct LinkPoint{
    int x, y;
    LinkPoint* previous;
    LinkPoint* next;
};

typedef struct {
    // int link_size;
    LinkPoint* start;
}Head;


// PROCEDURES --------------

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la création d'une Polyline en format SVG
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Element/circle"> En savoir plus sur les cercles SVG.</a>
*/
void Infos_polyline();

/**
 * Cette procédure récupère les informations entrées par l'utilisateur pour créer une Polyline.
 * (Elle vérifie toujours si le pointeur n'est pas nul).
 * @param head Prend en paramètre un pointeur sur la liste de lignes à créer, puis procède par un remplissage par adressse.
*/
void Recup_polyline_data(Head* head);

/**
 * Cette procédure libère l'allocation mémoire faite à la création d'une instance de type 'LinkPoint'.
 * @param point Prend en paramètre un pointeur sur l'instance de LinkPoint à détruire et le libère grâce au free.
*/
void Destroy_point(LinkPoint* point);

/**
 * Cette procédure libère l'allocation mémoire faite à la création d'une instance de type 'Head'.
 * @param head Prend en paramètre un pointeur sur l'instance de Head à détruire et le libère grâce au free.
 * 
 * Ici, il faut libérer toutes les autres instances de 'LinkPoint' qui font parties de la chaîne de liste pointée par 'head'.
*/
void Destroy_polyline(Head* head);

/**
 * Cette procédure affiche les informations contenues dans une instance 'LinkPoint' passée en paramètre.
 * @param point Prends en paramètre un pointeur sur l'instance de LinkPoint dont on souhaite afficher les informations.
*/
void Display_point(LinkPoint* point);

/**
 * Cette procédure affiche les informations contenues dans une instance 'Head' passée en paramètre.
 * @param head Prends en paramètre un pointeur sur l'instance de LinkPoint dont on souhaite afficher les informations.
*/
void Display_polyline(Head* head);

/**
 * Cette procédure ajoute un maillon 'LinkPoint' dans la chaîne 
 * @param head Prends en paramètre un pointeur sur l'instance de 'Head' qui pointe sur le début de la chaîne.
 * @param new_point Prends auuso en paramètre le maillon 'LinkPoint' à insérer en fin de chaîne.
*/
void Push_point(Head* head, LinkPoint* new_point);

// FONCTIONS ------------

/**
 * Cette fonction vérifie si le pointeur qui contient l'allocation sur une 'Head' existe (!=NULL)
 * @param head Prend un pointeur sur 'Head' et vérifie si il existe bien.
 * @return Retourne un True si le pointeur a bien reçu l'allocation et un False dans le cas contraire.
*/
int Does_polyline_exist(Head* head);

/**
 * Cette fonction vérifie si le pointeur qui contient l'allocation sur une ligne existe (!=NULL)
 * @param point Prend un pointeur sur 'LinkPoint' et vérifie si il existe bien.
 * @return Retourne un True si le pointeur a bien reçu l'allocation et un False dans le cas contraire.
*/
int Does_point_exist(LinkPoint* point);

/**
 * Cette fonction crée un maillon 'LinkPoint' en attribuant les valeurs qui lui sont passées aux attributs respectifs d'un 'LinkPoint'.
 * @param x Valeur entière de la position du point sur l'axe des abscisses(X).
 * @param y Valeur entière de la position du point sur l'axe des ordonnées(Y).
 * @return Retourne un pointeur sur la stucture 'LinkPoint' en manipulant l'allocation mémoire. Il faut donc garder à l'esprit que le LinkPoint qui reçoit le retour de cette fonction doit être obligatoirement 'free' à la fin.
*/
LinkPoint* Create_new_point(int x, int y);


/**
 * Cette fonction permet de créer une le pointeur sur le début d'un liste.
 * @return Retourne un pointeur de type 'Head'.
*/
Head* Create_new_polyline();



// PROCEDURES --------------

/**
 * Affiche et gère le menu de modification d'une polyline.
 * 
 * @return Code de retour selon le choix effectué.
 */
int Modify_polyline_menu();

/**
 * Supprime un maillon LinkPoint selon son index dans la chaîne.
 * 
 * @param head Pointeur sur le début de la liste.
 * @param index Index du maillon à supprimer.
 */
void Delete_point_by_index(Head* head, int index);

/**
 * Modifie les coordonnées d'un point existant.
 * 
 * @param point Pointeur sur le LinkPoint à modifier.
 */
void Modify_point(LinkPoint* point);

/**
 * Modifie une polyline existante.
 * 
 * @param head Pointeur sur la structure Head représentant la polyline.
 */
void Modify_polyline(Head* head);

/**
 * Exporte une polyline en SVG avec son style.
 * 
 * @param head Pointeur sur la polyline à exporter.
 * @param style Pointeur sur le style à appliquer.
 */
void Export_polyline(Head* head, Style* style);


#endif
