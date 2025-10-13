#include "./main.h"

void Infos_rect() {
    system("clear");
    printf("\nLe saviez-vous ?\n");
    printf("Le 'rect' en SVG est un élément de la catégorie des Formes simples, utilisé pour créer des rectangles.\nPour le créer, il faut passer trois paramètres de base esentiels :\n\nLa position sur X du centre = x (entier);\nLa position sur Y du centre = y (entier);\nLa longueur (entier non signé) = height.\nLa largeur (entier non signé) = width.\n\nEnsuite il est possible de passer un paramètre facultatif :\nLe rayon de courbure pour des bords arrondis (entier non signé) = round.\n\n");
}

void Recup_rect_data(Rect* rect) {
    
    if(!Does_rect_exist(rect)) return;

    else{
        printf("Souhaitez vous lire la documentation pour concevoir un rectangle ?\n");

        printf("Tapez une touche avant la fin du chrono pour skip :  ");
        Chrono(5);

        if (kbhit()) getchar();
        else Infos_rect();

        rect->x = Int_recup_verify("Entrez la position X du centre : ");
        rect->y = Int_recup_verify("Entrez la position Y du centre : ");
        rect->height = Unsigned_int_recup_verify("Entrez la longueur de votre rectangle(px) : ");
        rect->width = Unsigned_int_recup_verify("Entrez la largeur de votre rectangle(px) : ");

        printf("Souhaitez vous ajouter des bords arrondis ?\n");
        printf("Tapez une touche avant la fin du chrono pour skip :  ");
        Chrono_without_clear(5);
        Delete_two_lines();

        if (kbhit()) {
            getchar(); 
            rect->round = 0;
            return;
        }
        else {
            rect->round = Unsigned_int_recup_verify("Entrez le rayon de l'arrondi de votre rectangle : ");
        }
    }

}

Rect* Create_rect(int x, int y, unsigned int height, unsigned int width, unsigned int round) {

    Rect* rect = malloc(sizeof(Rect));
    if(!rect) return NULL;

    rect->x = x;
    rect->y = y;
    rect->height = height;
    rect->width = width;
    rect->round = round;

    return rect;

}

int Does_rect_exist(Rect* rect) {
    if(!rect) {
        Print_in_red("\nShape Not Found !\n");
        return 0;
    }
    else
    return 1;
}

void Destroy_rect(Rect* rect) {
    if(!Does_rect_exist(rect)) return;
    free(rect);
}

void Display_rect(Rect* rect) {
    
    if(!Does_rect_exist(rect)) return;
    else{
        printf("\n");
        // system("clear");
        printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT" RECTANGLE "RESET_STYLE BOLD_WHITE_TEXT" ========\n"RESET_STYLE);

        printf("\nPosition sur l'axe X : %d", rect->x);
        printf("\nPosition sur l'axe Y : %d", rect->y);
        printf("\nLongueur (px) : %u", rect->height);
        printf("\nLargeur (px) : %u", rect->width);
        printf("\nRayon d'arrondi (px) : %u\n\n", rect->round);
        printf("\n");
    }
}

// int main(void) {

//     Rect* rect = Create_rect(0,0,0,0,0);
//     Recup_rect_data(rect);
//     Display_rect(rect);
//     Destroy_rect(rect);

//     return EXIT_SUCCESS;
// }