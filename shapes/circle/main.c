#include "./main.h"

void Infos_cercle() {
    system("clear");
    printf("\nLe saviez-vous ?\n");
    printf("Le 'circle' en SVG est un élément de la catégorie des Formes simples, utilisé pour créer des cercles, en se basant sur un centre et un rayon.\nPour le créer, il faut passer trois paramètres de base esentiels :\n\nLa position sur X du centre = cx (entier);\nLa position sur Y du centre = cy (entier);\nLa taille du rayon(entier non signé) = rx\n\n");
}

void Recup_circle_data(Circle* circle) {

    if(!Does_circle_exist(circle)){
        return;
    } 
    else{
        printf("Souhaitez vous lire la documentation pour concevoir un cercle ?\n");
        printf("Tapez une touche avant la fin du chrono pour skip :  ");

        Chrono(5);

        
        if (kbhit()) getchar();//je vide le buffer, juste au cas où.
        else Infos_cercle();

        printf(BRIGHT_CYAN"CREATION DE CERCLE.\n\n"RESET_STYLE);
        circle->cx = Int_recup_verify("Entrez la position X du centre : ");
        circle->cy = Int_recup_verify("Entrez la position Y du centre : ");
        circle->rx = Unsigned_int_recup_verify("Entrez le rayon de votre cercle(px) : ");
    }

    system("clear");

}


Circle* Create_circle(int cx, int cy, unsigned int rx) {
    Circle* circle = malloc(sizeof(Circle));

    if (!circle) return NULL;

    circle->cx = cx;
    circle->cy = cy;
    circle->rx = rx;

    return circle;
}

int Does_circle_exist(Circle* circle) {
    if(!circle) {
        Print_in_red("\nShape Not Found !\n");
        return 0;
    }
    else{
        return 1;
    }
}

void Destroy_circle(Circle* circle) {
    if(!Does_circle_exist(circle)) return; // Je vérifie toujours que le pointeur existe pour éviter le Segfault de mes deux !!!
    free(circle);
}

void Display_circle(Circle* circle) {
    if(!Does_circle_exist(circle)) return;
    else{
        // system("clear");
        printf("\n");
        printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT" CERCLE "RESET_STYLE BOLD_WHITE_TEXT" ========\n"RESET_STYLE);
        printf("\nPosition sur l'axe X : %d", circle->cx);
        printf("\nPosition sur l'axe Y : %d", circle->cy);
        printf("\nRayon(px) : %u\n\n", circle->rx);
        printf("\n\n");
    }
}

unsigned int Modify_circle_menu() {
    unsigned int choice = 0;
    printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT" MODIFIER CERCLE "RESET_STYLE BOLD_WHITE_TEXT" ========\n"RESET_STYLE);
    printf("\n1) Modifier la position sur X.\n2) Modifier la position sur Y.\n3) Modifier la taille du rayon\n\n");

    choice = Unsigned_int_recup_verify("Choisissez la valeur à modifier : ");
    Delete_two_lines();
    return choice;
}

void Modify_circle(Circle* circle) {
    
    if (!Does_circle_exist(circle)) return;
    int value = 0, breaker = 0;

    do
    {
        system("clear");
        Display_circle(circle);

        value = Modify_circle_menu();
        if(value < 1) value = 1;
        if(value > 3) value = 3;

        switch (value)
        {
            case 1:
                circle->cx = Int_recup_verify("Entrez la position X du centre : ");
            break;
            case 2:
                circle->cy = Int_recup_verify("Entrez la position Y du centre : ");
            break;
            case 3:
                circle->rx = Unsigned_int_recup_verify("Entrez le rayon de votre cercle(px) : ");
            break;
            
            default:
                Print_in_bright_red("Entrée invalide");
            break;
        }
        
        printf("\n\nSouhaitez vous continuer les modifications ?\n");
        printf("Tapez une touche avant la fin du chrono pour skip :  ");
        breaker = Chrono_assassin(5);
        Delete_six_lines();

        system("clear");

    } while (!breaker);
    

}



//  int main(void) {

//     Circle* circle = Create_circle(0,0,0);
//     Recup_circle_data(circle);
//     Display_circle(circle);
//     Modify_circle(circle);
//     Destroy_circle(circle);

//     return EXIT_SUCCESS;
// }

