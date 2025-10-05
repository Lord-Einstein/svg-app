#include "./main.h"
#include "../other/khbit.c"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case

typedef struct{

    unsigned int width; //100% default
    unsigned int height; //100% default
    const char* xlmns;
    ViewBox* view_box;

} Svg;

typedef struct {
    int minx; //-50 default
    int miny; //-50% default
    unsigned int width; //200 default
    unsigned int height; // 200 default

} ViewBox;

typedef struct {
    int cx;
    int cy;
    unsigned int rx;
} Circle;

typedef struct {
    Circle* circle;
    unsigned int ry;
} Ellipse;


void Infos_cercle() {
    printf("\nLe saviez-vous ?\n");
    printf("Le 'circle' en SVG est un élément de la catégorie des Formes simples, utilisé pour créer des cercles, en se basant sur un centre et un rayon.\nPour le créer, il faut passer trois paramètres de base esentiels : \nLa position sur X du centre = cx;\nLa position sur Y du centre = cy;\nLa taille du rayon(px) = rx");
}

void Recup_circle_data(Circle* circle) {

    int chrono = 5;

    printf("Create a cercle...\n");
    printf("Souhaitez vous lire la documentation pour concevoir un cercle ?\n");
    printf("Tapez une touche avant la fin du chrono pour skip :");

    do{

        printf("  \b%d", chrono);
        chrono--;
        sleep(1);

    }while(chrono > 0 && !kbhit());

    if (kbhit()) getchar(); //Ah merde, fallait vider le buffer !
    else Infos_cercle();

}




// --- Ton code inchangé ---
int main() {
    int chrono = 5;

    printf("Souhaitez vous lire la documentation pour concevoir un cercle ?\n");
    printf("Tapez une touche avant la fin du chrono pour skip :");

    do {
        printf("  \b%d", chrono);
        fflush(stdout);  // juste pour que ton compteur s'affiche en temps réel
        chrono--;
        sleep(1);
    } while (chrono > 0 && !kbhit());

    if (kbhit()) {
        getchar(); // consomme la touche pour vider le buffer
        printf("\nSkip !\n");
    } else {
        printf("\nTemps écoulé !\n");
    }

    return 0;
}



Circle* Create_circle(int cx, int cy, unsigned int rx) {
    Circle* circle = malloc(sizeof(Circle));

    if (!circle) return NULL;

    circle->cx = cx;
    circle->cy = cy;
    circle->rx = rx;

    return circle;
}

void Destroy_circle(Circle* circle) {
    if(!circle) return; // Je vérifie toujours que le pointeur existe pour éviter le Segfault de mes deux !!!
    free(circle);
}



int Data_type_verifier(){}

Ellipse* Create_ellipse(int cx, int cy, unsigned int rx, unsigned int ry) {
    Ellipse* ellipse = malloc(sizeof(Ellipse));

    if(!ellipse) return NULL;

    ellipse->circle = Create_circle(cx, cy, rx);
    if(!ellipse->circle) return NULL;
    ellipse->ry = ry;

    return ellipse;
}

void Destroy_ellipse(Ellipse* ellipse) {
    if(!ellipse) return; 
    Free_circle(ellipse->circle); //Bah ouais faut libérer le pointeur sur le cercle d'abord. Pas de memory leak aujourd'hui !
    free(ellipse);
}

void Display_circle(Circle* circle) {
    system("clear");
    printf("\n========CIRCLE========\n");
    printf("\nPosition sur l'axe X : %d", circle->cx);
    printf("\nPosition sur l'axe Y : %d", circle->cx);
    printf("\nRayon(px) : %u", circle->rx);
}

void Display_circle(Ellipse* ellipse) {
    system("clear");
    printf("\n========ELLIPSE========\n");
    printf("\nPosition sur l'axe X : %d", ellipse->circle->cx);
    printf("\nPosition sur l'axe Y : %d", ellipse->circle->cy);
    printf("\nRayon sur l'axe X (px) : %u", ellipse->circle->rx);
    printf("\nRayon sur l'axe Y(px) : %u", ellipse->ry);
}

void Edit_circle(Circle *circle) {

}



int main(void) {



    return EXIT_SUCCESS;
}

