#include "./main.h"

void Infos_polyline() {
    system("clear");
    printf("\nLe saviez-vous ?\n");
    printf("L'élément SVG 'polyline' est une forme SVG basique qui crée des lignes entre plusieurs points.\nUn élément polyline est généralement utilisé pour créer des tracés ouverts car le dernier point n'est pas nécessairement connecté avec le premier. Lorsqu'on désire réaliser des formes fermées, on privilégiera l'élément 'polygon'.\n\nPour le créer il faut passer en paramètre les cordonnées de chaque point autant de fois qu'on veut :\nPosition sux X = x(n)\nPosition sux Y = y(n)\n\n");
}



void Recup_polyline_data(Head* head) {
    
    if(!Does_polyline_exist(head)) return;

    else{
        printf("Souhaitez vous lire la documentation pour concevoir une polyline ?\n");

        printf("Tapez une touche avant la fin du chrono pour skip :  ");
        Chrono(5);

        if (kbhit()) getchar();
        else Infos_polyline();

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
    if(!head) return 0;
    return 1;
}

int Does_point_exist(LinkPoint* point) {
    if(!point) return 0;
    return 1;
}

void Destroy_point(LinkPoint* point) {
    if(!Does_point_exist(point)){
        Print_in_red("Sub Shape not found.\n");
        return;
    }
    free(point);
}

void Destroy_polyline(Head* head) {
    if(!Does_polyline_exist(head)){
        Print_in_red("Shape not found.\n");
        return;
    }
    
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
    if(!Does_point_exist(point)){
        Print_in_red("Sub Shape not found.\n");
        return;
    }
    printf("Position sur X : %d\nPosition sur Y : %d\n\n", point->x, point->y);
}

void Display_polyline(Head* head) {
    if(!Does_polyline_exist(head)){
        Print_in_red("Shape not found.\n");
        return;
    }

    int point_counter = 0;
    LinkPoint* point = head->start;
    
    system("clear");
    printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT" POLY-LIGNES "RESET_STYLE BOLD_WHITE_TEXT" ========\n"RESET_STYLE);

    while(point != NULL){
        point_counter++;
        printf("\nPoint n° %d -\n", point_counter);
        Display_point(point);
        point = point->next;
    }

}

void Push_point(Head* head, LinkPoint* new_point) {
    LinkPoint* point = head->start;

    //Au cas ou la liste serait vide
    if(point == NULL) {
        head->start = new_point;
        return;
    }

    while(point->next != NULL) {
        point = point->next;
    }

    point->next = new_point;
    new_point->previous = point;

}

// int main(void) {

//     Head* head = Create_new_polyline();
//     Recup_polyline_data(head);
//     Display_polyline(head);
//     Destroy_polyline(head);

//     return EXIT_SUCCESS;
// }