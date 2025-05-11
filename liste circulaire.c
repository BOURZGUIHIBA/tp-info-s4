#include <stdio.h>
#include <stdlib.h>
typedef struct noeud {
  int data;
  struct noeud *suivant;
}noeud;


noeud * cree(int v){
  noeud * newE=(noeud *)malloc(sizeof(noeud));
if(newE==NULL){
    printf("echec d'allocation.\n");
    exit(1);
}
  newE->data=v;
  newE->suivant = newE; // auto-référencement pour liste circulaire
  return newE;

}

noeud * ajouD (noeud * fin , int v){
    noeud * newE = cree(v);
    if (fin == NULL) {
        newE->suivant = newE;
        fin = newE;
    } else {
        newE->suivant = fin->suivant;
        fin->suivant = newE;
    }
    return fin;
    }
noeud * ajouF(noeud * fin , int v){
 noeud * newE=cree(v);
  if(fin!=NULL){
    newE->suivant=fin->suivant;
    fin->suivant=newE;
  }
  return newE;
}

noeud * suppD(noeud * fin){
    if(fin!=NULL){
      if(fin->suivant==fin){
        free(fin);
        fin=NULL;
      }
      else{
        noeud * tmp=fin->suivant;
        fin->suivant=tmp->suivant;
        free(tmp);
      }
    }
    return (fin);
}

noeud * suppF(noeud * fin){
    if(fin!=NULL){
        if(fin->suivant==fin){
            free(fin);
            fin=NULL;
        }
        else{
            noeud * tmp=fin->suivant;
            while(tmp->suivant!=fin){
                tmp=tmp->suivant;
            }
            tmp->suivant=fin->suivant;
            free(fin);
            fin=tmp;
        }
    }
    return fin;
}

void affichage(noeud * fin){
   if(fin == NULL)
{
        printf ("noeud *e vide.\n");
    }
    else{
        noeud * tmp=fin->suivant;
        do{
            printf("%d",tmp->data);
            tmp=tmp->suivant;
        }while(tmp!=fin->suivant);
    }
}

int main() {
    noeud *fin = NULL;

    // Ajout en fin (au début, équivalent à un ajout en tête si vide)
    fin = ajouF(fin, 10);
    fin = ajouF(fin, 20);
    fin = ajouF(fin, 30);

    printf("Liste après ajouts en fin : ");
    affichage(fin);
    printf("\n");

    // Ajout en début
    fin = ajouD(fin, 5);
    printf("Liste après ajout en début : ");
    affichage(fin);
    printf("\n");

    // Suppression en début
    fin = suppD(fin);
    printf("Liste après suppression en début : ");
    affichage(fin);
    printf("\n");

    // Suppression en fin
    fin = suppF(fin);
    printf("Liste après suppression en fin : ");
    affichage(fin);
    printf("\n");

    // Libération complète
    while (fin != NULL) {
        fin = suppD(fin);
    }
    printf("Liste après suppression complète : ");
    affichage(fin);
    printf("\n");

    return 0;
}

