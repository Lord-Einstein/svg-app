#include "./main.h"

void Infos_polygone() {
    system("clear");
    printf("\nLe saviez-vous ?\n");
     
    printf("L'élément 'polygon' délimite une forme close composée d'un groupe de plusieurs segments de droites.\nLe dernier point est relié au premier afin de fermer la forme et de relier les traits entre eux. Pour créer une forme ouverte, voir l'élément 'polyline'.\n\nPour le créer il faut passer en paramètre les cordonnées de chaque point autant de fois qu'on veut :\nPosition sux X = x(n)\nPosition sux Y = y(n)\n\n");
}



void Recup_polygone_data(Head* head) {
    
    if(!Does_polyline_exist(head)) return;

    else{
        printf("Souhaitez vous lire la documentation pour concevoir un polygone ?\n");

        printf("Tapez une touche avant la fin du chrono pour skip :  ");
        Chrono(5);

        if (kbhit()) getchar();
        else Infos_polygone();

        int breaker = 0;
        do{
            LinkPoint* point = Create_new_point(0,0);

            point->x = Int_recup_verify("Entrez la position sur X du point : ");
            point->y = Int_recup_verify("Entrez la position sur Y du point : ");

            Push_point(head, point);

            printf("\n\nSouhaitez vous ajouter un point ?\n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            breaker = Chrono_assassin(5);
            Delete_six_lines();

        }while(breaker);
    }

}


void Display_polygone(Head* head) {
    if(!Does_polyline_exist(head)){
        Print_in_red("Shape not found.\n");
        return;
    }

    int point_counter = 0;
    LinkPoint* point = head->start;
    
    printf("\n");
    // system("clear");
    printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT" POLYGONE "RESET_STYLE BOLD_WHITE_TEXT" ========\n"RESET_STYLE);

    while(point != NULL){
        point_counter++;
        printf("\nPoint n° %d -\n", point_counter);
        Display_point(point);
        point = point->next;
    }
    printf("\n");
}


// int main(void) {

//     Head* head = Create_new_polyline();
//     Recup_polygone_data(head);
//     Display_polygone(head);
//     Destroy_polyline(head);

//     return EXIT_SUCCESS;
// }