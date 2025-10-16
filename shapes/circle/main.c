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
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Modifier la taille du rayon\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Annuler\n\n");

    choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez la valeur à modifier : "RESET_STYLE,1,4);
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
            case 4:
                return;
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


void Export_circle(Circle* circle, Style* style) { 
    if (!Does_circle_exist(circle)) return;
    if (!Does_style_exist(style)) return;

    int breaker = 0;
    char name[40];
    char file_name[70]; //La ref vers mon répertoire de génération prends envirion 27 déjà ... 
    char command[100];

    system("clear");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     EXPORTATION EN SVG       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Entrez le nom du fichier à exporter : ");
    scanf("%39s", name);
    snprintf(file_name, sizeof(file_name), "../Generated_Files/%s.svg", name); //C'est plus safe que sprintf vu qu'on peu préciser la limite directement avec la taille du char's chain à balancer. à ret'nir

    Svg* svg = Create_new_svg();
    if (!svg) { Print_in_red("SVG Not Found.\n"); return; }


    system("clear");
    Display_svg(svg);

    Drain_buffer();

    printf(BRIGHT_CYAN"\n╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     FAIRE DES MODIFS ?       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
    printf("Souhaitez vous utiliser les paramètres d'SVG par défaut ? \n");
    printf(BRIGHT_GREEN"Attendez la fin du chrono pour modifier ou appuyer une touche avant pour skip :  "RESET_STYLE);

    breaker = Chrono_assassin(5);
    system("clear");

    if(breaker) {
        Modify_svg(svg);
    }

    system("clear");

    FILE* write_file = fopen(file_name, "w");
    if (!write_file) {
        Print_in_red("Impossible de créer le fichier.\n");
        Destroy_svg(svg);
        return;
    }

    fprintf(write_file,
        //Juste l'enveloppe avec les params du svg lui même
        "<svg xmlns=\"%s\" width=\"%u%%\" height=\"%u%%\" viewBox=\"%d %d %u %u\">\n",
        svg->xlmns, svg->width, svg->height, svg->view_box->minx, svg->view_box->miny, svg->view_box->width, svg->view_box->height );

    
    fprintf(write_file, "  <circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"rgba(%d,%d,%d,%.2f)\" stroke=\"rgba(%d,%d,%d,%.2f)\" stroke-width=\"%d\"",
        circle->cx, circle->cy, circle->rx, style->Rf, style->Gf, style->Bf, style->Af, style->Rs, style->Gs, style->Bs, style->As, style->stroke_width );


    int transform_params = ( style->translate_x || style->translate_y || style->rotation || (style->scale_x != 1) || (style->scale_y != 1) );
    if (transform_params){
        fprintf(write_file, " transform=\"");

        if (style->translate_x || style->translate_y)
            fprintf(write_file, "translate(%d,%d) ", style->translate_x, style->translate_y);

        if (style->rotation)
            fprintf(write_file, "rotate(%d,%d,%d) ", style->rotation, style->rotation_cx, style->rotation_cy);

        if (style->scale_x != 1 || style->scale_y != 1)
            fprintf(write_file, "scale(%d,%d) ", style->scale_x, style->scale_y);

        fprintf(write_file, "\"");
    }

    //Ah fallait fermer tout cà !
    fprintf(write_file, " />\n</svg>\n");
    fclose(write_file);

    Progress_bar_animation(2);
    sleep(1);
    system("clear");


    printf(BRIGHT_CYAN"\n╭────────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│      OUVRIR LE FICHIER ?       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰────────────────────────────────╯\n\n"RESET_STYLE);
    printf("Souhaitez vous ouvrir le fichier pour visualiser votre forme ? \n");
    printf(BRIGHT_GREEN"Attendez la fin du chrono pour l'ouvrir ou appuyer une touche avant pour skip :  "RESET_STYLE);

    breaker = Chrono_assassin(5);
    if(breaker) {
        snprintf(command, sizeof(command) ,"explorer.exe \"..\\Generated_Files\\%s.svg\"", name); //Heureusement qu'il y'a le cractère d'échapemment !!
        system(command);
    }

    
    Auto_write("\n\n"BRIGHT_YELLOW"Retour au menu précédent...\n\n"RESET_STYLE, 25000);
    
    system("clear");
    Destroy_svg(svg);
}
