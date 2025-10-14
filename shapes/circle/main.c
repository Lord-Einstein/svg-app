#include "./main.h"

void Infos_cercle() {
    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│         INFOS CERCLE         │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Le saviez-vous ?\n");
    printf("L’élément "BOLD_WHITE_TEXT"<circle>"RESET_STYLE" en SVG appartient à la famille des formes simples.\n");
    printf("Il sert à tracer un cercle à partir d’un "BOLD_WHITE_TEXT"centre (cx, cy)"RESET_STYLE" et d’un "BOLD_WHITE_TEXT"rayon (r)"RESET_STYLE".\n\n");

    printf(BRIGHT_CYAN"Paramètres nécessaires :\n"RESET_STYLE);
    printf("  • "BOLD_WHITE_TEXT"cx"RESET_STYLE" : Position X du centre (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"cy"RESET_STYLE" : Position Y du centre (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"r"RESET_STYLE"  : Taille du rayon (entier non signé)\n\n");
}

void Recup_circle_data(Circle* circle) {
    if (!Does_circle_exist(circle)) return;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│    INITIALISATION CERCLE     │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Souhaitez-vous afficher la documentation pour créer un cercle ?\n");
    printf("Appuyez sur une touche avant la fin du chrono pour passer :  ");

    Chrono(5);

    if (kbhit()) getchar();
    else Infos_cercle();

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     CRÉATION DU CERCLE       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    circle->cx = Int_recup_verify("Entrez la position X du centre : ");
    circle->cy = Int_recup_verify("Entrez la position Y du centre : ");
    circle->rx = Unsigned_int_recup_verify("Entrez le rayon de votre cercle (px) : ");

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
    if (!circle) {
        Print_in_red("\nShape Not Found !\n");
        return 0;
    }
    return 1;
}

void Destroy_circle(Circle* circle) {
    if (!Does_circle_exist(circle)) return;
    free(circle);
}

void Display_circle(Circle* circle) {
    if (!Does_circle_exist(circle)) return;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        DONNÉES CERCLE        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);

    printf("\n");
    printf("•  Position X du centre : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", circle->cx);
    printf("•  Position Y du centre : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", circle->cy);
    printf("•  Rayon (px)  : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", circle->rx);
    printf("\n");
}

int Modify_circle_menu() {
    int choice = 0;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│      MODIFIER LE CERCLE      │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier la position sur X\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier la position sur Y\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Modifier la taille du rayon\n\n");

    choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez la valeur à modifier : "RESET_STYLE,1,3);
    Delete_two_lines();
    return choice;
}

void Modify_circle(Circle* circle) {
    if (!Does_circle_exist(circle)) return;
    int value = 0, breaker = 0;

    do {
        system("clear");
        Display_circle(circle);
        value = Modify_circle_menu();

        switch (value) {
            case 1:
                circle->cx = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X du centre : "RESET_STYLE);
                break;
            case 2:
                circle->cy = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y du centre : "RESET_STYLE);
                break;
            case 3:
                circle->rx = Unsigned_int_recup_verify(BRIGHT_GREEN"Nouveau rayon du cercle (px) : "RESET_STYLE);
                break;
            default:
                Print_in_red("Entrée invalide !");
                break;
        }

        system("clear");
        Display_circle(circle);

        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│   CONTINUER LES MODIFS ?     │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);

        breaker = Chrono_assassin(5);
        system("clear");

    } while (!breaker);
}

// void Export_circle(Circle* circle) {
//     if (!Does_circle_exist(circle)) return;



// }