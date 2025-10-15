#include "./main.h"


Svg* Create_new_svg() {
    Svg* svg = malloc(sizeof(Svg));
    if (!svg) return NULL;

    svg->view_box = malloc(sizeof(ViewBox));
    if (!svg->view_box) {
        free(svg);
        return NULL;
    }

    svg->width = 100;
    svg->height = 100;
    svg->xlmns = "http://www.w3.org/2000/svg";

    svg->view_box->minx = -50;
    svg->view_box->miny = -50;
    svg->view_box->width = 200;
    svg->view_box->height = 200;

    return svg;
}


int Does_svg_exist(Svg* svg) {
    if (!svg || !svg->view_box) {
        Print_in_red("\nSVG Not Found !\n");
        return 0;
    }
    return 1;
}


void Display_svg(Svg* svg) {
    if (!Does_svg_exist(svg)) return;

    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        DONNÉES DU SVG        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
    printf("\n");

    printf("• Largeur (width)  : "BOLD_WHITE_TEXT"%u%%"RESET_STYLE"\n", svg->width);
    printf("• Hauteur (height) : "BOLD_WHITE_TEXT"%u%%"RESET_STYLE"\n", svg->height);
    printf("• XMLNS            : "BOLD_WHITE_TEXT"%s"RESET_STYLE"\n", svg->xlmns);
    printf("\n");
    printf(BRIGHT_CYAN"ViewBox :"RESET_STYLE"\n");
    printf("  ↳ minX   : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", svg->view_box->minx);
    printf("  ↳ minY   : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", svg->view_box->miny);
    printf("  ↳ width  : "BOLD_WHITE_TEXT"%u"RESET_STYLE"\n", svg->view_box->width);
    printf("  ↳ height : "BOLD_WHITE_TEXT"%u"RESET_STYLE"\n\n", svg->view_box->height);
}


int Modify_svg_menu() {
    int choice = 0;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     MODIFIER LES PARAMS      │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN" 1) "RESET_STYLE" Modifier la largeur (width)\n");
    printf(BRIGHT_CYAN" 2) "RESET_STYLE" Modifier la hauteur (height)\n");
    printf(BRIGHT_CYAN" 3) "RESET_STYLE" Modifier la viewBox min sur X\n");
    printf(BRIGHT_CYAN" 4) "RESET_STYLE" Modifier la viewBox min sur Y\n");
    printf(BRIGHT_CYAN" 5) "RESET_STYLE" Modifier la viewBox width\n");
    printf(BRIGHT_CYAN" 6) "RESET_STYLE" Modifier la viewBox height\n");
    printf(BRIGHT_CYAN" 7) "RESET_STYLE" Annuler\n\n");

    choice = Int_recup_verify_with_padding( BRIGHT_GREEN"Choisissez la valeur à modifier : "RESET_STYLE, 1, 7);
    Delete_two_lines();
    return choice;
}


void Modify_svg(Svg* svg) {
    if (!Does_svg_exist(svg)) return;
    int value = 0, breaker = 0;

    do {
        system("clear");
        Display_svg(svg);
        value = Modify_svg_menu();

        switch (value) {
            case 1:
                svg->width = Unsigned_int_recup_verify(BRIGHT_GREEN"Nouvelle largeur (en %%): "RESET_STYLE);
                break;
            case 2:
                svg->height = Unsigned_int_recup_verify(BRIGHT_GREEN"Nouvelle hauteur (en %%): "RESET_STYLE);
                break;
            case 3:
                svg->view_box->minx = Int_recup_verify(BRIGHT_GREEN"Nouvelle valeur minX : "RESET_STYLE);
                break;
            case 4:
                svg->view_box->miny = Int_recup_verify(BRIGHT_GREEN"Nouvelle valeur minY : "RESET_STYLE);
                break;
            case 5:
                svg->view_box->width = Unsigned_int_recup_verify(BRIGHT_GREEN"Nouvelle largeur ViewBox : "RESET_STYLE);
                break;
            case 6:
                svg->view_box->height = Unsigned_int_recup_verify(BRIGHT_GREEN"Nouvelle hauteur ViewBox : "RESET_STYLE);
                break;
            case 7:
                return;
            default:
                Print_in_red("Entrée invalide !");
            break;
        }

        system("clear");
        Display_svg(svg);

        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│   CONTINUER LES MODIFS ?     │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);

        breaker = Chrono_assassin(5);
        system("clear");

    } while (!breaker);
}


void Export_svg(Svg* svg) {
    if (!Does_svg_exist(svg)) return;

    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     EXPORTATION DU SVG       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    char name[100];
    char file_name[120];

    printf("Entrez le nom du fichier à exporter : ");
    scanf("%99s", name);

    snprintf(file_name, sizeof(file_name), "%s.svg", name);

    FILE* write_file = fopen(file_name, "w");
    if (!write_file) {
        Print_in_red("Erreur lors de la création du fichier.\n");
        return;
    }

    fprintf(write_file,
        "<svg xmlns=\"%s\" width=\"%u%%\" height=\"%u%%\" viewBox=\"%d %d %u %u\">\n"
        "  <!-- SVG vide prêt à recevoir des formes -->\n"
        "</svg>\n",
        svg->xlmns,
        svg->width, svg->height,
        svg->view_box->minx, svg->view_box->miny,
        svg->view_box->width, svg->view_box->height
    );

    fclose(write_file);

    printf("\n");
    printf(BRIGHT_GREEN"Le fichier '%s' a été exporté avec succès.\n"RESET_STYLE, file_name);
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│      EXPORTATION TERMINÉE    │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
}



void Destroy_svg(Svg* svg) {
    if (!Does_svg_exist(svg)) return;
    free(svg->view_box);
    free(svg);
}

