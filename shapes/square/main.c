#include "./main.h"

void Infos_square() {
    system("clear");
    printf("\nLe saviez-vous ?\n");
    printf("Le 'square' en SVG est un n'est pas un élément de la catégorie des Formes simples, il se base sur la forme 'rect' en imposant une largeur égale à la longueur.\nPour le créer, il faut passer trois paramètres de base esentiels :\n\nLa position sur X du centre = x (entier);\nLa position sur Y du centre = y (entier);\nLa longueur d'un côté (entier non signé) = side.\n\nEnsuite il est possible de passer un paramètre facultatif :\nLe rayon de courbure pour des bords arrondis (entier non signé) = round.\n\n");
}

void Recup_square_data(Rect* square) {
    
    if(!Does_square_exist(square)) return;

    else{
        printf("Souhaitez vous lire la documentation pour concevoir un carré ?\n");

        printf("Tapez une touche avant la fin du chrono pour skip :  ");
        Chrono(5);

        if (kbhit()) getchar();
        else Infos_square();

        square->x = Int_recup_verify("Entrez la position X du centre : ");
        square->y = Int_recup_verify("Entrez la position Y du centre : ");
        square->height = Unsigned_int_recup_verify("Entrez la longueur des côtés de votre carré (px) : ");
        square->width = square->height;

        printf("Souhaitez vous ajouter des bords arrondis ?\n");
        printf("Tapez une touche avant la fin du chrono pour skip :  ");
        Chrono_without_clear(5);
        Delete_two_lines();

        if (kbhit()) {
            getchar(); 
            square->round = 0;
            return;
        }
        else {
            square->round = Unsigned_int_recup_verify("Entrez le rayon de l'arrondi de votre carré : ");
        }
    }

}

Rect* Create_square(int x, int y, unsigned int height, unsigned int round) {

    Rect* square = malloc(sizeof(Rect));
    if(!square) return NULL;

    square->x = x;
    square->y = y;
    square->height = height;
    square->width = height;
    square->round = round;

    return square;

}

int Does_square_exist(Rect* square) {
    if(!square) {
        Print_in_red("\nShape Not Found !\n");
        return 0;
    }
    else
    return 1;
}

void Destroy_square(Rect* square) {
    if(!Does_square_exist(square)) return;
    free(square);
}

void Display_square(Rect* square) {
    
    if(!Does_square_exist(square)) return;
    else{
        system("clear");
        printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT" CARRE "RESET_STYLE BOLD_WHITE_TEXT" ========\n"RESET_STYLE);

        printf("\nPosition sur l'axe X : %d", square->x);
        printf("\nPosition sur l'axe Y : %d", square->y);
        printf("\nLongueur d'un côté (px) : %u", square->height);
        printf("\nRayon d'arrondi (px) : %u\n\n", square->round);
    }
}

// int main(void) {

//     Rect* square = Create_square(0,0,0,0);
//     Recup_square_data(square);
//     Display_square(square);
//     Destroy_square(square);

//     return EXIT_SUCCESS;
// }