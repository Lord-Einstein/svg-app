#include "./main.h"


//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case


void Infos_ellipse() {
    system("clear");
    printf("\nLe saviez-vous ?\n");
    printf("Le 'ellipse' en SVG est un élément de la catégorie des Formes simples, utilisé pour créer des ellipses, en se basant sur un centre et un rayon.\nPour le créer, il faut passer quatres paramètres de base esentiels :\n\nLa position sur X du centre = cx (entier);\nLa position sur Y du centre = cy (entier);\nLa taille du rayon sur X (entier non signé) = rx\nLa taille du rayon sur Y (entier non signé) = ry\n\n");
}

void Recup_ellipse_data(Ellipse* ellipse) {

    if(!Does_ellipse_exist(ellipse)){
        return;
    }
    else{
        printf("Souhaitez vous lire la documentation pour concevoir une ellipse ?\n");
        printf("Tapez une touche avant la fin du chrono pour skip :  ");

        Chrono(5);

        
        if (kbhit()) getchar();//je vide le buffer, juste au cas où.
        else Infos_ellipse();

        ellipse->circle->cx = Int_recup_verify("Entrez la position X du centre : ");
        ellipse->circle->cy = Int_recup_verify("Entrez la position Y du centre : ");
        ellipse->circle->rx = Unsigned_int_recup_verify("Entrez le rayon sur X de votre ellipse(px) : ");
        ellipse->ry = Unsigned_int_recup_verify("Entrez le rayon sur Y de votre ellipse(px) : ");
    }
    
}

Ellipse* Create_ellipse(int cx, int cy, unsigned int rx, unsigned int ry) {
    Ellipse* ellipse = malloc(sizeof(Ellipse));

    if(!ellipse) return NULL; //Faut que le pointeur sur l'ellipse existe avant d'y mettre celui du cercle

    ellipse->circle = Create_circle(cx, cy, rx);
    if(!ellipse->circle) return NULL;

    ellipse->ry = ry;

    return ellipse;
}

int Does_ellipse_exist(Ellipse* ellipse) {
    if(!ellipse) {
        Print_in_red("\nShape Not Found !\n");
        return 0;
    }
    else if (!(ellipse->circle)) {
        Print_in_red("\nSub Shape Not Found !\n");
        return 0;
    }
    else{
        return 1;
    }
}

void Destroy_ellipse(Ellipse* ellipse) {
    if(!Does_ellipse_exist(ellipse)) return; 
    Destroy_circle(ellipse->circle); //Bah ouais faut libérer le pointeur sur le cercle d'abord. Pas de memory leak aujourd'hui !
    free(ellipse);
}


void Display_ellipse(Ellipse* ellipse) {

    if(!Does_ellipse_exist(ellipse)){
        return;
    }
    else{
        // system("clear");
        printf("\n");
        printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT" ELLIPSE "RESET_STYLE BOLD_WHITE_TEXT" ========\n"RESET_STYLE);
        printf("\nPosition sur l'axe X : %d", ellipse->circle->cx);
        printf("\nPosition sur l'axe Y : %d", ellipse->circle->cy);
        printf("\nRayon sur l'axe X (px) : %u", ellipse->circle->rx);
        printf("\nRayon sur l'axe Y (px) : %u\n\n", ellipse->ry);
        printf("\n");
    }
}

// int main(void) {

//     Ellipse* ellipse = Create_ellipse(0,0,0,0);
//     Recup_ellipse_data(ellipse);
//     Display_ellipse(ellipse);
//     Destroy_ellipse(ellipse);

//     return EXIT_SUCCESS;
// }

