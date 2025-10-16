#include "./main.h"

void Infos_polygone() {
    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        INFOS POLYGONE        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Le saviez-vous ?\n");
    printf("L'élément SVG 'polygon' délimite une forme close composée d'un groupe de plusieurs segments de droites.\n");
    printf("Le dernier point est relié au premier afin de fermer la forme et de relier les traits entre eux.\n");
    printf("Pour créer une forme ouverte, voir l'élément 'polyline'.\n\n");
    printf("Pour le créer, il faut passer en paramètre les coordonnées de chaque point autant de fois qu'on veut :\n");
    printf("  • "BOLD_WHITE_TEXT"x(n)"RESET_STYLE" : Position sur X du point (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"y(n)"RESET_STYLE" : Position sur Y du point (entier)\n\n");
}

void Recup_polygone_data(Head* head) {
    if(!Does_polyline_exist(head)) return;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│  INITIALISATION POLYGONE     │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Souhaitez vous lire la documentation pour concevoir un polygone ?\n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");
    Chrono(5);

    if (kbhit()) getchar();
    else Infos_polygone();

    int breaker = 0;
    do {
        system("clear");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│      CREATION DE POINT       │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

        LinkPoint* point = Create_new_point(0,0);
        point->x = Int_recup_verify("Entrez la position sur X du point : ");
        point->y = Int_recup_verify("Entrez la position sur Y du point : ");
        Push_point(head, point);

        printf("\n\nSouhaitez vous ajouter un point ?\n");
        printf(BRIGHT_GREEN"Tapez une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
        breaker = Chrono_assassin(5);
        Delete_six_lines();

    } while(!breaker);

    system("clear");
}

void Display_polygone(Head* head) {
    if(!Does_polyline_exist(head)) return;

    int point_counter = 0;
    LinkPoint* point = head->start;

    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        DONNÉES POLYGONE      │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    while(point != NULL){
        point_counter++;
        printf("Point %d : ["BOLD_WHITE_TEXT"%d"RESET_STYLE", "BOLD_WHITE_TEXT"%d"RESET_STYLE"]\n", point_counter, point->x, point->y);
        point = point->next;
    }
    printf("\n");
}

void Modify_polygone(Head* head) {
    if(!Does_polyline_exist(head)) return;

    int choice = 0, breaker = 0;

    do {
        system("clear");
        Display_polygone(head);

        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│    MODIFIER LE POLYGONE      │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

        printf(BRIGHT_CYAN"  1)"RESET_STYLE" Agir sur un point existant\n");
        printf(BRIGHT_CYAN"  2)"RESET_STYLE" Ajouter un point\n");
        printf(BRIGHT_CYAN"  3)"RESET_STYLE" Supprimer un point\n");
        printf(BRIGHT_CYAN"  4)"RESET_STYLE" Quitter\n\n");

        choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez une option : "RESET_STYLE, 1, 4);
        Delete_two_lines();

        switch(choice) {
            case 1: {
                system("clear");
                Display_polygone(head);
                int index = Int_recup_verify(BRIGHT_GREEN"Sur quel point souhaitez-vous agir ? : "RESET_STYLE);
                LinkPoint* current = head->start;
                int counter = 1;
                while(current && counter < index) {
                    current = current->next;
                    counter++;
                }
                if(!current) {
                    Print_in_red("Point inexistant.\n");
                    sleep(2);
                } else Modify_point(current);
                break;
            }
            case 2: {
                int cont = 0;
                do {
                    system("clear");
                    LinkPoint* new_point = Create_new_point(0,0);
                    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                    printf(BRIGHT_CYAN"│      AJOUTER UN POINT ?      │\n"RESET_STYLE);
                    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
                    new_point->x = Int_recup_verify(BRIGHT_GREEN"Entrez la position X du nouveau point : "RESET_STYLE);
                    new_point->y = Int_recup_verify(BRIGHT_GREEN"Entrez la position Y du nouveau point : "RESET_STYLE);
                    Push_point(head, new_point);
                    system("clear");
                    Display_polygone(head);
                    printf("\n");
                    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                    printf(BRIGHT_CYAN"│  AJOUTER UN AUTRE POINT ?    │\n"RESET_STYLE);
                    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
                    printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
                    cont = Chrono_assassin(5);
                    system("clear");
                } while(!cont);
                break;
            }
            case 3:
                system("clear");
                Display_polygone(head);
                int index = Int_recup_verify(BRIGHT_GREEN"Sur quel point souhaitez-vous agir ? : "RESET_STYLE);
                LinkPoint* current = head->start;
                int counter = 1;
                while(current && counter < index) {
                    current = current->next;
                    counter++;
                }
                if(!current) {
                    Print_in_red("Point inexistant.\n");
                    sleep(2);
                } else Delete_point_by_index(head, index);
            break;

            case 4:
                return;
        }

        system("clear");
        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│  CONTINUER LES MODIFS ?      │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
        breaker = Chrono_assassin(5);
        system("clear");

    } while(!breaker);
}

void Export_polygone(Head* head, Style* style) {
    if (!Does_polyline_exist(head)) return;
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
    if (!svg) {
        Print_in_red("SVG Not Found.\n");
        return;
    }

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

    fprintf(write_file, "  <polygon points=\"");

    LinkPoint* point = head->start;
    while(point != NULL) {
        fprintf(write_file, "%d,%d ", point->x, point->y);
        point = point->next;
    }

    fprintf(write_file,
        "\" fill=\"rgba(%d,%d,%d,%.2f)\" stroke=\"rgba(%d,%d,%d,%.2f)\" stroke-width=\"%d\"",
        style->Rf, style->Gf, style->Bf, style->Af, style->Rs, style->Gs, style->Bs, style->As,
        style->stroke_width);

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

    Progress_bar_animation(2);
    sleep(1);
    system("clear");

    printf(BRIGHT_CYAN"\n╭────────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│      OUVRIR LE FICHIER ?       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰────────────────────────────────╯\n\n"RESET_STYLE);
    printf("Souhaitez-vous ouvrir le fichier pour visualiser votre polygone ? \n");
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
