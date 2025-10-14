#ifndef SHAPES_STYLE__STYLE_H
#define SHAPES_STYLE__STYLE_H


#include "../common-fonctions/fonctions.h"

typedef struct StyleStruct {
    int stroke_width, translate_x, translate_y, rotation, rotation_cx, rotation_cy, scale_x, scale_y;
    char* stroke;
    char* fill;
}Style;

typedef enum BlocStyleUnion{
    FILL,
    STROKE,
    S_WIDTH,
    ROTATE,
    SCALE,
    TRANSLATE
}BlocStyle;


void Infos_style();

Style* Create_style();

int Does_style_exist(Style* style);

char* Color_menu();

void Recup_style_data(Style* style);

void Display_style(Style* style );

void Destroy_style(Style* style);

#endif