#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// 1

typedef struct {
    int numero;
    char nom[50];
    char prenom[50];
    char adresse[100];
    int annee_adhesion;
} Adherent;

typedef struct {
    int numero;
    char titre[100];
    int annee_edition;
    char auteur[50];
    char domaine[50];
} Ouvrage;

typedef struct {
    int numeroAdherent;
    int numeroOuvrage;
    char date_location[15];
    char date_retour[15];
} Location;


Adherent adherents[MAX];
int nb_adherents = 0;

Ouvrage ouvrages[MAX];
int nb_ouvrages = 0;

Location locations[MAX];
int nb_locations = 0;

// 2

int trouverAdherent(int num) {
    for (int i = 0; i < nb_adherents; i++) {
        if (adherents[i].numero == num) return i;
    }
    return -1;
}

int trouverOuvrage(int num) {
    for (int i = 0; i < nb_ouvrages; i++) {
        if (ouvrages[i].numero == num) return i;
    }
    return -1;
}

int confirmerSuppression() {
    char choix;
    printf("Etes-vous sur de vouloir supprimer ? (O/N) : ");
    scanf(" %c", &choix);
    return (choix == 'O' || choix == 'o');
}

// 3

void ajouterOuvrage() {
    if (nb_ouvrages >= MAX) { printf("Erreur : Capacite atteinte.\n"); return; }
    Ouvrage o;
    printf("Numero de l'ouvrage : "); scanf("%d", &o.numero);
    if (trouverOuvrage(o.numero) != -1) { printf("Erreur : Ce numero existe deja.\n"); return; }
    printf("Titre : "); scanf(" %[^\n]", o.titre);
    printf("Annee d'edition : "); scanf("%d", &o.annee_edition);
    printf("Auteur : "); scanf(" %[^\n]", o.auteur);
    printf("Domaine : "); scanf(" %[^\n]", o.domaine);
    ouvrages[nb_ouvrages++] = o;
    printf("Ouvrage ajoute.\n");
}

void modifierOuvrage() {
    int num, pos;
    printf("Numero de l'ouvrage a modifier : "); scanf("%d", &num);
    pos = trouverOuvrage(num);
    
    if (pos == -1) {
        printf("[!] Ouvrage introuvable.\n");
        return;
    }

    printf("\n--- Modification de l'ouvrage %d ---\n", num);
    printf("Nouveau Titre [%s] : ", ouvrages[pos].titre); 
    scanf(" %[^\n]", ouvrages[pos].titre);
    
    printf("Nouvel Auteur [%s] : ", ouvrages[pos].auteur); 
    scanf(" %[^\n]", ouvrages[pos].auteur);
    
    printf("Nouvelle Annee [%d] : ", ouvrages[pos].annee_edition); 
    scanf("%d", &ouvrages[pos].annee_edition);
    
    printf("Nouveau Domaine [%s] : ", ouvrages[pos].domaine); 
    scanf(" %[^\n]", ouvrages[pos].domaine);
    
    printf("\n[*] Modification effectuee avec succes.\n");
}

void supprimerOuvrage() {
    int num, pos;
    printf("Numero de l'ouvrage a supprimer : "); scanf("%d", &num);
    pos = trouverOuvrage(num);
    if (pos != -1 && confirmerSuppression()) {
        for (int i = pos; i < nb_ouvrages - 1; i++) ouvrages[i] = ouvrages[i + 1];
        nb_ouvrages--;
        printf("Suppression effectuee.\n");
    }
}

void rechercherOuvrage() {
    int num, pos;
    printf("Entrez le numero de l'ouvrage recherche : "); scanf("%d", &num);
    pos = trouverOuvrage(num);
    if (pos != -1) {
        printf("\n--- INFORMATIONS SUR L'OUVRAGE ---\n");
        printf("ID              : %d\n", ouvrages[pos].numero);
        printf("Titre           : %s\n", ouvrages[pos].titre);
        printf("Auteur          : %s\n", ouvrages[pos].auteur);
        printf("Annee d'edition : %d\n", ouvrages[pos].annee_edition);
        printf("Domaine         : %s\n", ouvrages[pos].domaine);
        printf("------------------------------------\n");
    } else {
        printf("[!] Aucun ouvrage trouve avec ce numero.\n");
    }
}

void listerOuvrages() {
    printf("\n--- Liste des Ouvrages ---\n");
    for (int i = 0; i < nb_ouvrages; i++)
        printf("ID: %d | Titre: %s | Domaine: %s\n", ouvrages[i].numero, ouvrages[i].titre, ouvrages[i].domaine);
}

void menuOuvrages() {
    int choix;
    do {
        printf("\n--- GESTION OUVRAGES ---\n1. Ajouter\n2. Modifier\n3. Supprimer\n4. Rechercher\n5. Lister\n6. Retour\nChoix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterOuvrage(); break;
            case 2: modifierOuvrage(); break;
            case 3: supprimerOuvrage(); break;
            case 4: rechercherOuvrage(); break;
            case 5: listerOuvrages(); break;
        }
    } while (choix != 6);
}

// 4

void ajouterAdherent() {
    if (nb_adherents >= MAX) return;
    Adherent a;
    printf("Numero : "); scanf("%d", &a.numero);
    if (trouverAdherent(a.numero) != -1) { printf("Existe deja.\n"); return; }
    printf("Nom : "); scanf(" %[^\n]", a.nom);
    printf("Prenom : "); scanf(" %[^\n]", a.prenom);
    printf("Adresse : "); scanf(" %[^\n]", a.adresse);
    printf("Annee : "); scanf("%d", &a.annee_adhesion);
    adherents[nb_adherents++] = a;
}

void modifierAdherent() {
    int num, pos;
    printf("ID de l'adherent a modifier : "); scanf("%d", &num);
    pos = trouverAdherent(num);
    
    if (pos == -1) {
        printf("[!] Adherent introuvable.\n");
        return;
    }

    printf("\n--- Modification de l'adherent %d ---\n", num);
    printf("Nouveau Nom [%s] : ", adherents[pos].nom); 
    scanf(" %[^\n]", adherents[pos].nom);
    
    printf("Nouveau Prenom [%s] : ", adherents[pos].prenom); 
    scanf(" %[^\n]", adherents[pos].prenom);
    
    printf("Nouvelle Adresse [%s] : ", adherents[pos].adresse); 
    scanf(" %[^\n]", adherents[pos].adresse);
    
    printf("Nouvelle Annee Adhesion [%d] : ", adherents[pos].annee_adhesion); 
    scanf("%d", &adherents[pos].annee_adhesion);
    
    printf("\n[*] Profil mis a jour.\n");
}

void supprimerAdherent() {
    int num, pos;
    printf("ID a supprimer : "); scanf("%d", &num);
    pos = trouverAdherent(num);
    if (pos != -1 && confirmerSuppression()) {
        for (int i = pos; i < nb_adherents - 1; i++) adherents[i] = adherents[i + 1];
        nb_adherents--;
    }
}

void rechercherAdherent() {
    int num, pos;
    printf("Entrez l'ID de l'adherent recherche : "); scanf("%d", &num);
    pos = trouverAdherent(num);
    if (pos != -1) {
        printf("\n--- INFORMATIONS SUR L'ADHERENT ---\n");
        printf("ID               : %d\n", adherents[pos].numero);
        printf("Nom              : %s\n", adherents[pos].nom);
        printf("Prenom           : %s\n", adherents[pos].prenom);
        printf("Adresse          : %s\n", adherents[pos].adresse);
        printf("Annee d'adhesion : %d\n", adherents[pos].annee_adhesion);
        printf("------------------------------------\n");
    } else {
        printf("[!] Aucun adherent trouve.\n");
    }
}

void listerAdherents() {
    for (int i = 0; i < nb_adherents; i++)
        printf("ID: %d | %s %s\n", adherents[i].numero, adherents[i].nom, adherents[i].prenom);
}

void menuAdherents() {
    int choix;
    do {
        printf("\n--- GESTION ADHERENTS ---\n1. Ajouter\n2. Modifier\n3. Supprimer\n4. Rechercher\n5. Lister\n6. Retour\nChoix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterAdherent(); break;
            case 2: modifierAdherent(); break;
            case 3: supprimerAdherent(); break;
            case 4: rechercherAdherent(); break;
            case 5: listerAdherents(); break;
        }
    } while (choix != 6);
}

// 5

void ajouterLocation() {
    Location l;
    printf("ID Adherent : "); scanf("%d", &l.numeroAdherent);
    if (trouverAdherent(l.numeroAdherent) == -1) return;
    printf("ID Ouvrage : "); scanf("%d", &l.numeroOuvrage);
    if (trouverOuvrage(l.numeroOuvrage) == -1) return;
    printf("Date (JJ/MM/AAAA) : "); scanf("%s", l.date_location);
    locations[nb_locations++] = l;
    printf("Enregistre.\n");
}

void supprimerLocation() {
    int idA, idO, found = -1;
    printf("ID Adherent : "); scanf("%d", &idA);
    printf("ID Ouvrage : "); scanf("%d", &idO);
    for(int i=0; i<nb_locations; i++) {
        if(locations[i].numeroAdherent == idA && locations[i].numeroOuvrage == idO) { found = i; break; }
    }
    if (found != -1) {
        for (int i = found; i < nb_locations - 1; i++) locations[i] = locations[i+1];
        nb_locations--;
        printf("Location supprimee.\n");
    }
}

void listerLocations() {
    for (int i = 0; i < nb_locations; i++)
        printf("A: %d -> O: %d le %s\n", locations[i].numeroAdherent, locations[i].numeroOuvrage, locations[i].date_location);
}

void menuLocations() {
    int choix;
    do {
        printf("\n--- GESTION LOCATIONS ---\n1. Nouvelle\n2. Supprimer\n3. Lister\n4. Retour\nChoix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterLocation(); break;
            case 2: supprimerLocation(); break;
            case 3: listerLocations(); break;
        }
    } while (choix != 4);
}

//6

int main() {
    int choix;
    do {
        printf("\n============== BIBLIOTHEQUE ==============\n");
        printf("1. Gestion des Ouvrages\n2. Gestion des Adherents\n3. Gestion des Locations\n4. QUITTER\n");
        printf("==========================================\nChoix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: menuOuvrages(); break;
            case 2: menuAdherents(); break;
            case 3: menuLocations(); break;
        }
    } while (choix != 4);
    return 0;
}