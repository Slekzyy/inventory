#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_ITEM 10
#define LENGTH 50

typedef struct {
    char nom[LENGTH];
    int taille;
}Objet;

typedef struct {
    Objet objets[MAX_ITEM];
    int nombre_obj;
}inventory;

void inventairy(inventory* inventaire){
    inventaire -> nombre_obj = 0;
}

void ajout(inventory *inventaire , const char *nom , int quantite){
    for(int i = 0 ; i < inventaire -> nombre_obj ; i++){
        if(strcmp(inventaire->objets[i].nom, nom) == 0) {
            inventaire->objets[i].taille += quantite;
            printf("Ajout de %d %s. Vous en avez maintenant %d.\n", quantite, nom, inventaire ->objets[i].taille);
            return;
        }
    }
    if(inventaire -> nombre_obj < MAX_ITEM) {
        strcpy(inventaire->objets[inventaire->nombre_obj].nom, nom);
        inventaire->objets[inventaire->nombre_obj].taille = quantite;
        inventaire->nombre_obj++;
        printf("Nouvel objet ajouté: %s (Quantité: %d)\n", nom, quantite);
    } 
    else {
        printf("L'inventaire est plein!\n");
    }
}


void addItems(inventory *inventaire){
    char nom[LENGTH];
    int quant;
    printf("entrer un objet dans l'inventaire\n");
    assert(scanf("%s",nom) == 1); //permet d'ajouter l'objet souhaitée dans l'inventaireS
    printf("désormais entrer la quantité de l'objet %s\n",nom);
    assert(scanf("%d",&quant) == 1); // permet d'ajouter le nbr d'objet souhaiter dans l'inventaire
    ajout(inventaire,nom,quant);
}


void request(inventory *inventaire){
    char accepter;
    do {
        addItems(inventaire);
        printf("voulez vous rajouter des objets\n");
        getchar();
        assert(scanf("%c",&accepter) == 1);
    } while (accepter == 'o');
}

void affichage(const inventory *inventaire){
    printf("--inventaire--\n");
    printf("nombre d'objet : %d\n",inventaire -> nombre_obj);
    if(inventaire -> nombre_obj == 0){
        printf("l'inventaire est vide\n");
    }
    else{
        for(int i = 0 ; i < inventaire -> nombre_obj ; i++){
            printf("%s (Quantité: %d)\n", inventaire->objets[i].nom, inventaire->objets[i].taille);
        }
    }
    printf("---------------\n");
}

void update(inventory *inventaire){
    inventairy(inventaire); // initialiser l'inventaire 
    request(inventaire); // demander à l'utilisateur si il veut rajouter des objets 
    affichage(inventaire); // affichage de l'inventaire 
}

int main(){
    inventory inventaire;
    bool cond = true;
    while(cond){
        update(&inventaire);
        char continuer;
        getchar();
        assert(scanf("%c",&continuer) == 1);
        if(continuer == 'n'){
            cond = false; // si l'utilisateur répond "non" alord faux ,on sort de la boucle 
        }
    }
    return EXIT_SUCCESS;
}

