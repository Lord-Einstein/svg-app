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



// int Int_recup_verify_with_padding(const char* prompt, int max_value, int min_value) { //Juste pour être sûr que mon prompt ne sera pas modifié
//     int scanf_return = 0;
//     int a_int = 0;

//     do{

//         printf("%s", prompt);
//         Ignore_enter_until_other_key();
//         scanf_return = scanf("%d", &a_int);

//         if(scanf_return != 1){
//             Drain_buffer();
//             Print_in_red("Entrée invalide !");
//             fflush(stdout);
//             sleep(2);
//             Delete_two_lines();
//         }

//     }while((scanf_return != 1) && ((a_int < min_value) || (a_int > max_value)));
//     Drain_buffer();

//     return a_int;   

// }

float Float_recup_verify_with_padding(const char *prompt, float min_value, float max_value) {
    float a_float = 0.0f;
    int scanf_return = 0;
    char buffer[64]; // Lecture maximale de 63 caractères + '\0'

    do {
        printf("%s", prompt);
        fflush(stdout);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            Print_in_red("Erreur de lecture !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
            continue;
        }

        // Si entrée vide (juste ENTER)
        if (buffer[0] == '\n' || buffer[0] == '\r') {
            Delete_two_lines();
            fflush(stdout);
            continue;
        }

        // Conversion vers float
        scanf_return = sscanf(buffer, "%f", &a_float);

        // Vérifie la validité et la plage
        if (scanf_return != 1) {
            Print_in_red("Entrée invalide !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
            continue;
        }

        if (a_float < min_value || a_float > max_value) {
            Print_in_red("Valeur hors limites !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
            scanf_return = 0; // force la boucle à recommencer
        }

    } while (scanf_return != 1);

    return a_float;
}


int Int_recup_verify_with_padding(const char *prompt, int min_value, int max_value) {
    int a_int = 0;
    int scanf_return = 0;
    char buffer[64]; // Lecture maximale de 63 caractères + '\0'

    do {
        printf("%s", prompt);
        fflush(stdout);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            Print_in_red("Erreur de lecture !");
            fflush(stdout);
            sleep(1);
            Delete_two_lines();
            continue;
        }

        // Si l’utilisateur appuie juste sur "Entrée"
        if (buffer[0] == '\n' || buffer[0] == '\r') {
            Delete_two_lines();
            continue;
        }

        scanf_return = sscanf(buffer, "%d", &a_int);

        if (scanf_return != 1) {
            Print_in_red("Entrée invalide !");
            fflush(stdout);
            sleep(1);
            Delete_two_lines();
            continue;
        }

        // Vérification de la plage
        if (a_int < min_value || a_int > max_value) {
            Print_in_red("Entrée Invalide !");
            fflush(stdout);
            sleep(1);
            Delete_two_lines();
            scanf_return = 0; // force la répétition
        }

    } while (scanf_return != 1);

    return a_int;
}


int Int_recup_verify(const char *prompt) {
    int a_int = 0;
    int scanf_return = 0;
    char buffer[64]; // Lecture maximale de 63 caractères + celui ci '\0'

    do {
        printf("%s", prompt);
        fflush(stdout);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            Print_in_red("Erreur de lecture !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
            continue;
        }

        
        if (buffer[0] == '\n' || buffer[0] == '\r') {
            Delete_two_lines();
            fflush(stdout);
            continue;
        }

        
        scanf_return = sscanf(buffer, "%d", &a_int);

        
        if (scanf_return != 1) {
            Print_in_red("Entrée invalide !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
        }

    } while (scanf_return != 1);

    return a_int;
}


unsigned int Unsigned_int_recup_verify(const char *prompt) {
    int a_int = -1;
    unsigned int a_unsigned_int = 0;
    int scanf_return = 0;
    char buffer[64];

    do {
        printf("%s", prompt);
        fflush(stdout);

        // Lecture complète de la ligne
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            Print_in_red("Erreur de lecture !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
            continue;
        }

        
        if (buffer[0] == '\n' || buffer[0] == '\r') {
            Delete_two_lines();
            fflush(stdout);
            continue;
        }

        
        scanf_return = sscanf(buffer, "%d", &a_int);

        if ((scanf_return != 1) || (a_int < 0)) {
            Print_in_red("Entrée invalide !");
            fflush(stdout);
            sleep(2);
            Delete_two_lines();
        }

    } while ((scanf_return != 1) || (a_int < 0));

    a_unsigned_int = (unsigned int)a_int;
    return a_unsigned_int;
}


void Auto_write(const char *text, unsigned int delay_microseconds) {
    if (!text) return;

    system("stty -echo -icanon");

    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);
        usleep(delay_microseconds);
    }

    // Réactive la saisie clavier
    system("stty echo icanon");
}


void Ignore_extra_enters(void) {
    int c;

    // Tant qu'il y a des '\n' ou '\r' dans le buffer, on les consomme
    while ((c = getchar()) == '\n' || c == '\r');
    
    // Si on a lu un autre caractère (ex: 'D'), on le remet dans le flux
    if (c != EOF) ungetc(c, stdin);
}
