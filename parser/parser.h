#ifndef PARSER__PARSER_H
#define PARSER__PARSER_H

#include <ctype.h>

#include "../CLI_UI/main.h"
#include "../shapes/common-fonctions/fonctions.h"

#include "../shapes/circle/main.h"
#include "../shapes/ellipse/main.h"
#include "../shapes/line/main.h"
#include "../shapes/path/path.h"
#include "../shapes/polygone/main.h"
#include "../shapes/polyline/main.h"
#include "../shapes/rectangle/main.h"
#include "../shapes/square/main.h"

#include "../svg/main.h"

/**
 * Retourne la longueur d'une chaîne de caractères.
 * 
 * @param s Chaîne de caractères.
 * @return Longueur de la chaîne.
 */
int my_strlen(const char* s);

/**
 * Compare deux chaînes de caractères.
 * 
 * @param s1 Première chaîne.
 * @param s2 Deuxième chaîne.
 * @return 0 si les chaînes sont identiques, non-zero sinon.
 */
int my_strcmp(const char* s1, const char* s2);

/**
 * Duplique une chaîne de caractères.
 * 
 * @param s Chaîne à dupliquer.
 * @return Pointeur vers la nouvelle chaîne allouée dynamiquement.
 */
char* my_strdup(const char* s);

/**
 * Copie les n premiers caractères d'une chaîne source vers une destination.
 * 
 * @param dest Destination.
 * @param src Source.
 * @param n Nombre de caractères à copier.
 */
void my_strcpy_n(char* dest, const char* src, int n);

/**
 * Vérifie si le fichier donné est un fichier SVG.
 * 
 * @param filename Nom du fichier.
 * @return 1 si c'est un fichier SVG, 0 sinon.
 */
int Is_Svg_File(const char* filename);

/**
 * Ignore les espaces et tabulations dans le contenu à partir de la position donnée.
 * 
 * @param content Contenu de texte.
 * @param pos Pointeur sur la position courante dans le texte.
 */
void Skip_Whitespace(const char* content, int* pos);

/**
 * Ignore tous les caractères jusqu'à rencontrer le caractère spécifié.
 * 
 * @param content Contenu de texte.
 * @param pos Pointeur sur la position courante.
 * @param c Caractère à atteindre.
 * @param size Taille totale du contenu.
 */
void Skip_Until_Char(const char* content, int* pos, char c, long size);

/**
 * Extrait un attribut et sa valeur dans le contenu XML.
 * 
 * @param content Contenu XML.
 * @param pos Pointeur sur la position courante.
 * @param attr_name Tableau pour stocker le nom de l'attribut.
 * @param attr_value Tableau pour stocker la valeur de l'attribut.
 * @param max_len Taille maximale des buffers.
 * @return 1 si extraction réussie, 0 sinon.
 */
int Extract_Attribute(const char* content, int* pos, char* attr_name, char* attr_value, int max_len);

/**
 * Convertit une chaîne en entier.
 * 
 * @param str Chaîne à convertir.
 * @return Valeur entière.
 */
int Parse_Int(const char* str);

/**
 * Parse un élément rectangle dans le contenu SVG.
 * 
 * @param content Contenu SVG.
 * @param pos Pointeur sur la position courante.
 * @param size Taille totale du contenu.
 * @return Pointeur vers le Rect créé (à libérer avec free()).
 */
Rect* Parse_Rect_Element(const char* content, int* pos, long size);

/**
 * Parse un élément cercle dans le contenu SVG.
 * 
 * @param content Contenu SVG.
 * @param pos Pointeur sur la position courante.
 * @param size Taille totale du contenu.
 * @return Pointeur vers le Circle créé.
 */
Circle* Parse_Circle_Element(const char* content, int* pos, long size);

/**
 * Parse un élément ellipse dans le contenu SVG.
 * 
 * @param content Contenu SVG.
 * @param pos Pointeur sur la position courante.
 * @param size Taille totale du contenu.
 * @return Pointeur vers l'Ellipse créé.
 */
Ellipse* Parse_Ellipse_Element(const char* content, int* pos, long size);

/**
 * Parse un élément ligne dans le contenu SVG.
 * 
 * @param content Contenu SVG.
 * @param pos Pointeur sur la position courante.
 * @param size Taille totale du contenu.
 * @return Pointeur vers le Line créé.
 */
Line* Parse_Line_Element(const char* content, int* pos, long size);

/**
 * Parse un élément polyline dans le contenu SVG.
 * 
 * @param content Contenu SVG.
 * @param pos Pointeur sur la position courante.
 * @param size Taille totale du contenu.
 * @return Pointeur vers la Head de la polyline créée.
 */
Head* Parse_Polyline_Element(const char* content, int* pos, long size);

/**
 * Parse une commande Path depuis les données.
 * 
 * @param cmd Caractère représentant la commande.
 * @param data Chaîne contenant les données de la commande.
 * @param path Pointeur vers la HeadPath à remplir.
 */
void Parse_Path_Command(char cmd, const char* data, HeadPath* path);

/**
 * Parse l'attribut 'd' d'un Path.
 * 
 * @param path_data Chaîne de l'attribut 'd'.
 * @return Pointeur vers la HeadPath créée.
 */
HeadPath* Parse_Path_Attribute(const char* path_data);

/**
 * Parse un fichier SVG et retourne sa structure.
 * 
 * @param filename Nom du fichier SVG.
 * @return Pointeur vers le Svg créé.
 */
Svg* Parse_Svg_File(const char* filename);

/**
 * Lance l'analyse complète d'un fichier SVG pour créer la structure interne.
 */
void Parser();

#endif
