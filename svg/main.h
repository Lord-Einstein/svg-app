#ifndef SVG__MAIN_H
#define SVG__MAIN_H

#include "../common-h.h"
#include "../shapes/common-fonctions/fonctions.h"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case


typedef struct {
    int minx; //-50% default
    int miny; //-50% default
    unsigned int width; //200 default
    unsigned int height; // 200 default

}ViewBox;

typedef struct{

    unsigned int width; //100% default
    unsigned int height; //100% default
    const char* xlmns;
    ViewBox* view_box;

}Svg;

void Display_svg(Svg* svg);

Svg* Create_new_svg();

int Does_svg_exist(Svg* svg);

int Modify_svg_menu();

void Modify_svg(Svg* svg);

void Export_svg(Svg* svg);

void Destroy_svg(Svg* svg);

#endif

