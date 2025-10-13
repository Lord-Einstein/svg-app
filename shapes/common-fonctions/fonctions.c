#include "./fonctions.h"


// PROCEDURES -------------------



//PROCEDURES DE MISE EN FORME

// Couleurs normales
void Print_in_black(const char* prompt)   { printf(BLACK"%s"RESET_STYLE, prompt); }
void Print_in_red(const char* prompt)     { printf(RED"%s"RESET_STYLE, prompt); }
void Print_in_green(const char* prompt)   { printf(GREEN"%s"RESET_STYLE, prompt); }
void Print_in_yellow(const char* prompt)  { printf(YELLOW"%s"RESET_STYLE, prompt); }
void Print_in_blue(const char* prompt)    { printf(BLUE"%s"RESET_STYLE, prompt); }
void Print_in_magenta(const char* prompt) { printf(MAGENTA"%s"RESET_STYLE, prompt); }
void Print_in_cyan(const char* prompt)    { printf(CYAN"%s"RESET_STYLE, prompt); }
void Print_in_white(const char* prompt)   { printf(WHITE"%s"RESET_STYLE, prompt); }

// Couleurs vives
void Print_in_bright_black(const char* prompt)   { printf(BRIGHT_BLACK"%s"RESET_STYLE, prompt); }
void Print_in_bright_red(const char* prompt)     { printf(BRIGHT_RED"%s"RESET_STYLE, prompt); }
void Print_in_bright_green(const char* prompt)   { printf(BRIGHT_GREEN"%s"RESET_STYLE, prompt); }
void Print_in_bright_yellow(const char* prompt)  { printf(BRIGHT_YELLOW"%s"RESET_STYLE, prompt); }
void Print_in_bright_blue(const char* prompt)    { printf(BRIGHT_BLUE"%s"RESET_STYLE, prompt); }
void Print_in_bright_magenta(const char* prompt) { printf(BRIGHT_MAGENTA"%s"RESET_STYLE, prompt); }
void Print_in_bright_cyan(const char* prompt)    { printf(BRIGHT_CYAN"%s"RESET_STYLE, prompt); }
void Print_in_bright_white(const char* prompt)   { printf(BRIGHT_WHITE"%s"RESET_STYLE, prompt); }






void Delete_two_lines(){
    printf("\r" DELETE_CURRRENT_LINE); // efface la ligne courante
    printf("\r" REMOUNT_ON_LAST_LINE); // remonte d’une ligne
    printf("\r" DELETE_CURRRENT_LINE); // puis efface cette ligne
}

void Delete_six_lines(){
    printf("\r" DELETE_CURRRENT_LINE); // efface la ligne courante
    printf("\r" REMOUNT_ON_LAST_LINE); // remonte d’une ligne
    printf("\r" DELETE_CURRRENT_LINE); // efface cette ligne
    printf("\r" REMOUNT_ON_LAST_LINE); // remonte d’une ligne
    printf("\r" DELETE_CURRRENT_LINE); // efface cette ligne
    printf("\r" REMOUNT_ON_LAST_LINE); // remonte d’une ligne
    printf("\r" DELETE_CURRRENT_LINE); // efface cette ligne
    printf("\r" REMOUNT_ON_LAST_LINE); // remonte d’une ligne
    printf("\r" DELETE_CURRRENT_LINE); // efface cette ligne
    printf("\r" REMOUNT_ON_LAST_LINE); // remonte d’une ligne
    printf("\r" DELETE_CURRRENT_LINE); // efface cette ligne
}

void Delete_a_consol_line(){
    printf("\r                                                                                            \r");
}


// FIN DES PROCEDURES DE MISE EN FORME



void Chrono(int chrono) {
    if(chrono > 9) chrono = 9;
    while(chrono >= 0 && !kbhit()){

        printf("\b%d", chrono); //À noter que %2d oblige un aff sur deux car avec un space devant sinon %02d le fait rn remplaçant space par 0
        chrono--;
        sleep(1);

    }
    system("clear");
    printf("\n");
}

void Chrono_without_clear(int chrono) {
    if(chrono >= 9) chrono = 9;
    while(chrono > 0 && !kbhit()){

        printf("\b%d", chrono); //À noter que %2d oblige un aff sur deux car avec un space devant sinon %02d le fait rn remplaçant space par 0
        chrono--;
        sleep(1);

    }
}

// int Chrono_assassin(int chrono) {
//     if(chrono > 9) chrono = 9;
//     while(chrono >= 0 && !kbhit()){

//         printf("\b%d", chrono);
//         chrono--;
//         sleep(1);

//     }
//     if(chrono < 0) return 1;
//     return 0;
// }

int Chrono_assassin(int chrono) {
    if (chrono > 9) chrono = 9;

    while (chrono >= 0) {

        printf("\b%d", chrono);

        chrono--;
        sleep(1);

        if (kbhit()) {
            getchar(); // vide le reste du buffer si nécessaire
            return 0; 
        }

    }

    return 1;
}

void Drain_buffer() {
    int c; //C'est mieux qu'un char, d'toutes façons getchar renvoie un int !!
    while((c = getchar()) != '\n' && c != EOF);
}



// FONCTIONS ---------------------

int Int_recup_verify(const char* prompt){ //Juste pour être sûr que mon prompt ne sera pas modifié
    int scanf_return = 0;
    int a_int = 0;

    do{

        printf("%s", prompt);
        scanf_return = scanf("%d", &a_int);

        if(scanf_return != 1){
            Drain_buffer();
            Print_in_red("Entrée invalide !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
        }

    }while(scanf_return != 1);
    Drain_buffer();

    return a_int;   

}

int Int_recup_verify_with_padding(const char* prompt, int max_value, int min_value) { //Juste pour être sûr que mon prompt ne sera pas modifié
    int scanf_return = 0;
    int a_int = 0;

    do{

        printf("%s", prompt);
        scanf_return = scanf("%d", &a_int);

        if(scanf_return != 1){
            Drain_buffer();
            Print_in_red("Entrée invalide !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
        }

    }while((scanf_return != 1) && ((a_int < min_value) || (a_int > max_value)));
    Drain_buffer();

    return a_int;   

}

unsigned int Unsigned_int_recup_verify(const char* prompt) { //Juste pour être sûr que mon prompt ne sera pas modifié
    int scanf_return = 0, a_int = 0;
    unsigned int a_unsigned_int = 0;

    do{

        printf("%s", prompt);
        scanf_return = scanf("%d", &a_int);

        if((scanf_return != 1)  || (a_int < 0)){
            Drain_buffer();
            Print_in_red("Entrée invalide !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
        }

    }while((scanf_return != 1) || (a_int < 0));
    a_unsigned_int = (unsigned int)a_int;
    Drain_buffer();

    return a_unsigned_int;   

}
