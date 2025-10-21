#ifndef SHAPES_STYLE__STYLE_H
#define SHAPES_STYLE__STYLE_H

#include "../common-fonctions/fonctions.h"

typedef struct StyleStruct {
    int stroke_width, translate_x, translate_y, rotation, rotation_cx, rotation_cy, scale_x, scale_y, Rs, Gs, Bs, Rf, Gf, Bf;
    float As, Af;
} Style;

typedef enum BlocStyleUnion {
    FILL = 1,
    STROKE,
    S_WIDTH,
    ROTATE,
    SCALE,
    TRANSLATE, // ADD EXIT ?
    EXIT
} BlocStyle;

/**
 * Affiche les informations relatives au style SVG.
 */
void Infos_style();

/**
 * Crée une nouvelle instance de style.
 * 
 * @return Pointeur vers la structure Style créée.
 */
Style* Create_style();

/**
 * Vérifie si un style existe (pointeur non nul).
 * 
 * @param style Pointeur sur la structure Style à vérifier.
 * @return 1 si le style existe, 0 sinon.
 */
int Does_style_exist(Style* style);

/**
 * Récupère les informations saisies par l'utilisateur pour définir un style.
 * 
 * @param style Pointeur sur la structure Style à remplir.
 */
void Recup_style_data(Style* style);

/**
 * Affiche les informations d'un style existant.
 * 
 * @param style Pointeur sur la structure Style à afficher.
 */
void Display_style(Style* style);

/**
 * Libère la mémoire allouée à une structure Style.
 * 
 * @param style Pointeur sur la structure Style à détruire.
 */
void Destroy_style(Style* style);

#endif
