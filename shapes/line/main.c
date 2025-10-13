#include "./main.h"

void Infos_line() {
    system("clear");
    printf("\nLe saviez-vous ?\n");
    printf("Le 'line' en SVG est un élément de la catégorie des Formes simples, utilisé pour créer une ligne connectant deux points.\nPour le créer, il faut passer quatres paramètres de base esentiels :\n\nLa position sur X du premier point = x1 (entier);\nLa position sur Y du premier point = y1 (entier);\nLa position sur X du second point = x2 (entier).\nLa position sur Y du second point = y2 (entier).\n\n");
}

void Recup_line_data(Line* line) {
    
    if(!Does_line_exist(line)) return;

    else{
        printf("Souhaitez vous lire la documentation pour concevoir une ligne ?\n");

        printf("Tapez une touche avant la fin du chrono pour skip :  ");
        Chrono(5);

        if (kbhit()) getchar();
        else Infos_line();

        line->x1 = Int_recup_verify("Entrez la position X du premier point : ");
        line->y1 = Int_recup_verify("Entrez la position Y du premier point : ");
        line->x2 = Int_recup_verify("Entrez la position X du second point : ");
        line->y2 = Int_recup_verify("Entrez la position Y du second point : ");

    }

}

Line* Create_line(int x1, int y1, int x2, int y2) {

    Line* line = malloc(sizeof(Line));
    if(!line) return NULL;

    line->x1 = x1;
    line->y1 = y1;
    line->x2 = x2;
    line->y2 = y2;

    return line;
}

int Does_line_exist(Line* line) {
    if(!line) {
        Print_in_red("\nShape Not Found !\n");
        return 0;
    }
    else
    return 1;
}

void Destroy_line(Line* line) {
    if(!Does_line_exist(line)) return;
    free(line);
}

void Display_line(Line* line) {
    
    if(!Does_line_exist(line)) return;
    else{
        printf("\n");
        // system("clear");
        printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT" LIGNE "RESET_STYLE BOLD_WHITE_TEXT" ========\n"RESET_STYLE);

        printf("\nPosition sur l'axe X du premier point : %d", line->x1);
        printf("\nPosition sur l'axe Y du premier point : %d", line->y1);
        printf("\nPosition sur l'axe X du second point : %d", line->x2);
        printf("\nPosition sur l'axe Y du second point : %d\n\n", line->y2);

        printf("\n");
    }
}

// int main(void) {

//     Line* line = Create_line(0,0,0,0);
//     Recup_line_data(line);
//     Display_line(line);
//     Destroy_line(line);

//     return EXIT_SUCCESS;
// }