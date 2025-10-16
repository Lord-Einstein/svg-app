#include "./main.h"

void Infos_line() {
    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│          INFOS LIGNE         │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Le saviez-vous ?\n");
    printf("Le 'line' en SVG est un élément de la catégorie des Formes simples, utilisé pour créer une ligne connectant deux points.\n");
    printf("Pour le créer, il faut passer quatre paramètres de base essentiels :\n\n");
    printf("  • "BOLD_WHITE_TEXT"x1"RESET_STYLE" : Position X du premier point (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"y1"RESET_STYLE" : Position Y du premier point (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"x2"RESET_STYLE" : Position X du second point (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"y2"RESET_STYLE" : Position Y du second point (entier)\n\n");
}

void Recup_line_data(Line* line) {
    if(!Does_line_exist(line)) return;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│   INITIALISATION DE LA LIGNE │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Souhaitez vous lire la documentation pour concevoir une ligne ?\n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");
    Chrono(5);

    if (kbhit()) getchar();
    else Infos_line();

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│       CRÉATION DE LIGNE      │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    line->x1 = Int_recup_verify("Entrez la position X du premier point : ");
    line->y1 = Int_recup_verify("Entrez la position Y du premier point : ");
    line->x2 = Int_recup_verify("Entrez la position X du second point : ");
    line->y2 = Int_recup_verify("Entrez la position Y du second point : ");

    system("clear");
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
    return 1;
}

void Destroy_line(Line* line) {
    if(!Does_line_exist(line)) return;
    free(line);
}

void Display_line(Line* line) {
    if(!Does_line_exist(line)) return;

    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│         DONNÉES LIGNE        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("•  Position X1 : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", line->x1);
    printf("•  Position Y1 : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", line->y1);
    printf("•  Position X2 : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", line->x2);
    printf("•  Position Y2 : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n\n", line->y2);
}

int Modify_line_menu() {
    int choice = 0;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│       MODIFIER LA LIGNE      │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier X1\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier Y1\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Modifier X2\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Modifier Y2\n");
    printf(BRIGHT_CYAN"  5)"RESET_STYLE" Annuler\n\n");

    choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez la valeur à modifier : "RESET_STYLE, 1, 5);
    Delete_two_lines();
    return choice;
}

void Modify_line(Line* line) {
    if(!Does_line_exist(line)) return;

    int value = 0, breaker = 0;

    do {
        system("clear");
        Display_line(line);
        value = Modify_line_menu();

        switch(value) {
            case 1:
                line->x1 = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X1 : "RESET_STYLE);
                break;
            case 2:
                line->y1 = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y1 : "RESET_STYLE);
                break;
            case 3:
                line->x2 = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X2 : "RESET_STYLE);
                break;
            case 4:
                line->y2 = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y2 : "RESET_STYLE);
                break;
            case 5:
                return;
            default:
                Print_in_red("Entrée invalide !");
                break;
        }

        system("clear");
        Display_line(line);

        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│    CONTINUER LES MODIFS ?    │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"\nAppuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);

        breaker = Chrono_assassin(5);
        system("clear");

    } while (!breaker);
}

void Export_line(Line* line, Style* style) {
    if (!Does_line_exist(line)) return;
    if (!Does_style_exist(style)) return;

    int breaker = 0;
    char name[40];
    char file_name[70];
    char command[100];

    system("clear");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     EXPORTATION EN SVG       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Entrez le nom du fichier à exporter : ");
    scanf("%39s", name);
    snprintf(file_name, sizeof(file_name), "../Generated_Files/%s.svg", name);

    Svg* svg = Create_new_svg();
    if (!svg) { Print_in_red("SVG Not Found.\n"); return; }

    system("clear");
    Display_svg(svg);
    Drain_buffer();

    printf(BRIGHT_CYAN"\n╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     FAIRE DES MODIFICATIONS ?│\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
    printf("Souhaitez-vous utiliser les paramètres d'SVG par défaut ?\n");
    printf(BRIGHT_GREEN"Attendez la fin du chrono pour modifier ou appuyez sur une touche avant pour skip :  "RESET_STYLE);

    breaker = Chrono_assassin(5);
    system("clear");

    if (breaker) Modify_svg(svg);

    FILE* write_file = fopen(file_name, "w");
    if (!write_file) {
        Print_in_red("Impossible de créer le fichier.\n");
        Destroy_svg(svg);
        return;
    }

    fprintf(write_file,
        "<svg xmlns=\"%s\" width=\"%u%%\" height=\"%u%%\" viewBox=\"%d %d %u %u\">\n",
        svg->xlmns, svg->width, svg->height,
        svg->view_box->minx, svg->view_box->miny,
        svg->view_box->width, svg->view_box->height );

    fprintf(write_file,
        "  <line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"rgba(%d,%d,%d,%.2f)\" stroke-width=\"%d\"",
        line->x1, line->y1, line->x2, line->y2,
        style->Rs, style->Gs, style->Bs, style->As,
        style->stroke_width );

    int transform_params = ( style->translate_x || style->translate_y || style->rotation || (style->scale_x != 1) || (style->scale_y != 1) );
    if (transform_params) {
        fprintf(write_file, " transform=\"");
        if (style->translate_x || style->translate_y)
            fprintf(write_file, "translate(%d,%d) ", style->translate_x, style->translate_y);
        if (style->rotation)
            fprintf(write_file, "rotate(%d,%d,%d) ", style->rotation, style->rotation_cx, style->rotation_cy);
        if (style->scale_x != 1 || style->scale_y != 1)
            fprintf(write_file, "scale(%d,%d) ", style->scale_x, style->scale_y);
        fprintf(write_file, "\"");
    }

    fprintf(write_file, " />\n</svg>\n");
    fclose(write_file);

    Progress_bar_animation(8);
    sleep(3);
    system("clear");

    printf(BRIGHT_CYAN"\n╭────────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│      OUVRIR LE FICHIER ?       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰────────────────────────────────╯\n\n"RESET_STYLE);
    printf("Souhaitez-vous ouvrir le fichier pour visualiser votre ligne ? \n");
    printf(BRIGHT_GREEN"Attendez la fin du chrono pour l'ouvrir ou appuyez sur une touche avant pour skip :  "RESET_STYLE);

    breaker = Chrono_assassin(5);
    if (breaker) {
        snprintf(command, sizeof(command), "explorer.exe \"..\\Generated_Files\\%s.svg\"", name);
        system(command);
    }

    Auto_write("\n\n"BRIGHT_YELLOW"Retour au menu précédent...\n\n"RESET_STYLE, 25000);
    system("clear");
    Destroy_svg(svg);
}
