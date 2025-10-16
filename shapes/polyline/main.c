#include "./main.h"

void Infos_polyline() {
    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        INFOS POLYLINE        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Le saviez-vous ?\n");
    printf("L'élément SVG 'polyline' est une forme SVG basique qui crée des lignes entre plusieurs points.\n");
    printf("Un élément polyline est généralement utilisé pour créer des tracés ouverts car le dernier point n'est pas nécessairement connecté avec le premier.\n");
    printf("Lorsqu'on désire réaliser des formes fermées, on privilégiera l'élément 'polygon'.\n\n");
    printf("Pour le créer, il faut passer en paramètre les coordonnées de chaque point autant de fois qu'on veut :\n");
    printf("  • "BOLD_WHITE_TEXT"x(n)"RESET_STYLE" : Position sur X du point (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"y(n)"RESET_STYLE" : Position sur Y du point (entier)\n\n");
}

void Recup_polyline_data(Head* head) {
    if(!Does_polyline_exist(head)) return;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│  INITIALISATION POLYLINE     │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Souhaitez vous lire la documentation pour concevoir une polyline ?\n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");
    Chrono(5);

    if (kbhit()) getchar();
    else Infos_polyline();

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

Head* Create_new_polyline() {
    Head* head = malloc(sizeof(Head));
    if(!head) return NULL;
    head->start = NULL;
    return head;
}

LinkPoint* Create_new_point(int x, int y) {
    LinkPoint* point = malloc(sizeof(LinkPoint));
    if(!point) return NULL;
    point->x = x;
    point->y = y;
    point->previous = NULL;
    point->next = NULL;
    return point;
}

int Does_polyline_exist(Head* head) {
    if(!head) {
        Print_in_red("\nShape Not Found !\n");
        return 0;
    }
    return 1;
}

int Does_point_exist(LinkPoint* point) {
    if(!point) {
        Print_in_red("Sub Shape not found.\n");
        return 0;
    }
    return 1;
}

void Destroy_point(LinkPoint* point) {
    if(!Does_point_exist(point)) return;
    free(point);
}

void Destroy_polyline(Head* head) {
    if(!Does_polyline_exist(head)) return;

    LinkPoint* point = head->start;
    LinkPoint* temp;

    if(point != NULL){
        while(point->next != NULL) {
            temp = point;
            point = point->next;
            Destroy_point(temp);
        }
        free(point);
    }

    free(head);
}

void Display_point(LinkPoint* point) {
    if(!Does_point_exist(point)) return;
    printf("Position sur X : %d\nPosition sur Y : %d\n\n", point->x, point->y);
}

void Display_polyline(Head* head) {
    if(!Does_polyline_exist(head)) return;

    int point_counter = 0;
    LinkPoint* point = head->start;

    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        DONNÉES POLYLINE      │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    while(point != NULL){
        point_counter++;
        printf("Point %d : ["BOLD_WHITE_TEXT"%d"RESET_STYLE", "BOLD_WHITE_TEXT"%d"RESET_STYLE"]\n", point_counter, point->x, point->y);
        point = point->next;
    }
    printf("\n");
}

void Push_point(Head* head, LinkPoint* new_point) {
    LinkPoint* point = head->start;
    if(point == NULL) {
        head->start = new_point;
        return;
    }
    while(point->next != NULL) point = point->next;
    point->next = new_point;
    new_point->previous = point;
}

int Modify_polyline_menu() {
    int choice = 0;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│    MODIFIER LA POLYLINE      │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Agir sur un point existant\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Ajouter un point\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Supprimer un point\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Quitter\n\n");

    choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez une option : "RESET_STYLE, 1, 4);
    Delete_two_lines();
    return choice;
}


void Delete_point_by_index(Head* head, int index) {
    if (!Does_polyline_exist(head)) {
        Print_in_red("Shape not found.\n");
        return;
    }

    if (index <= 0) {
        Auto_write(BRIGHT_RED"\nIndex invalide ..."RESET_STYLE, 30000);
        sleep(2);
        system("clear");
        return;
    }

    LinkPoint* point = head->start;
    int current_index = 1;

    // Il est où ce point déjà ?
    while (point != NULL && current_index < index) {
        point = point->next;
        current_index++;
    }

    if (!Does_point_exist(point)) {
        Auto_write(BRIGHT_RED"\nPoint inexistant ..."RESET_STYLE, 30000);
        sleep(2);
        system("clear");
        return;
    }

    printf(BRIGHT_CYAN"\n╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"  SUPPRESSION DU POINT N°%d   \n"RESET_STYLE, index);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Point à supprimer : [ X = %d, Y = %d ]\n\n", point->x, point->y);
    printf("Confirmez-vous la suppression ?\n");
    printf(BRIGHT_GREEN"Attendez la fin du chrono pour confirmer ou appuyez sur une touche avant pour annuler :  "RESET_STYLE);

    int breaker = Chrono_assassin(5);

    if (!breaker) {
        Auto_write(BRIGHT_RED"\nSuppression annulée...\n"RESET_STYLE, 30000);
        sleep(2);
        system("clear");
        return;
    }

    //seul élément
    if (point->previous == NULL && point->next == NULL) {
        head->start = NULL;
    }
      //si7 le premier
    else if (point->previous == NULL) {
        head->start = point->next;
        point->next->previous = NULL;
    }
    //dernier
    else if (point->next == NULL) {
        point->previous->next = NULL;
    }
    //au milieu
    else {
        point->previous->next = point->next;
        point->next->previous = point->previous;
    }

    free(point);

                    
    Auto_write(BRIGHT_RED"\n\nPoint supprimé."RESET_STYLE, 30000);
    Auto_write(BRIGHT_YELLOW"\n\nRetour ...\n"RESET_STYLE, 30000);
    sleep(1);

}



void Modify_point(LinkPoint* point) {
    if(!Does_point_exist(point)) return;
    int choice = 0, breaker = 0;

    do {
        system("clear");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│    MODIFIER UN POINT         │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

        Display_point(point);
        printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier X\n");
        printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier Y\n");
        printf(BRIGHT_CYAN"  3)"RESET_STYLE" Quitter\n\n");

        choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 3);
        Delete_two_lines();

        switch(choice) {
            case 1:
                point->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                break;
            case 2:
                point->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                break;
            case 3:
                return;
        }

        system("clear");
        // Display_point(point);
        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│ CONTINUER LES MODIFICATIONS ?│\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
        breaker = Chrono_assassin(5);
        system("clear");

    } while(!breaker);
}

void Modify_polyline(Head* head) {
    if(!Does_polyline_exist(head)) return;

    int choice = 0, breaker = 0;

    do {
        system("clear");
        Display_polyline(head);
        choice = Modify_polyline_menu();

        switch(choice) {
            case 1: {
                system("clear");
                Display_polyline(head);
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
                    Display_polyline(head);
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
                Display_polyline(head);
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

            default:
                Print_in_red("INVALID ! ");
            break;
        }

        system("clear");
        // Display_polyline(head);
        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│  CONTINUER LES MODIFS ?      │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
        breaker = Chrono_assassin(5);
        system("clear");

    } while(!breaker);
}

void Export_polyline(Head* head, Style* style) {
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

    fprintf(write_file, "  <polyline points=\"");

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
    printf("Souhaitez-vous ouvrir le fichier pour visualiser votre polyline ? \n");
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
