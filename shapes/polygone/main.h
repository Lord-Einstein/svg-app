#ifndef POLYGONE__MAIN_H
#define POLYGONE__MAIN_H

#include "../polyline/main.h"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case


// PROCEDURES --------------

/**
 * @brief Cette procédure affiche à l'utilisateur les informations sur la création d'un Polygone en format SVG
 * @see <a href="https://developer.mozilla.org/en-US/docs/Web/SVG/Reference/Element/circle"> En savoir plus sur les Polygone SVG.</a>
*/
void Infos_polygone();

/**
 * Cette procédure affiche les informations contenues dans une instance 'Head' passée en paramètre.
 * @param head Prends en paramètre un pointeur sur l'instance de Polygone dont on souhaite afficher les informations.
*/
void Display_polygone(Head* head);


/**
 * Cette procédure récupère les informations entrées par l'utilisateur pour créer un Polygone.
 * (Elle vérifie toujours si le pointeur n'est pas nul).
 * @param head Prend en paramètre un pointeur sur la liste de Polygone à créer, puis procède par un remplissage par adressse.
*/
void Recup_polygone_data(Head* head);



/**
 * Modifie un polygone existant.
 * 
 * @param head Pointeur sur la structure Head représentant le polygone à modifier.
 */

void Modify_polygone(Head* head);


/**
 * Exporte un polygone en SVG avec son style associé.
 * 
 * @param head Pointeur sur la structure Head représentant le polygone à exporter.
 * @param style Pointeur sur la structure Style à appliquer.
 */

void Export_polygone(Head* head, Style* style);

#endif
