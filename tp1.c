#include <stdio.h>
#include <stdlib.h>
typedef struct noeud {
    int valeur;
    struct noeud *suiv;
} noeud;

noeud *cree(int val) {
    noeud *Nvnoeud = (noeud *)malloc(sizeof(noeud));
    if (Nvnoeud == NULL) {
        printf("erreur d'allocation memoire.\n");
        exit(1);
    }
    Nvnoeud->valeur = val;
    Nvnoeud->suiv = NULL;
    return Nvnoeud;
}

noeud *ajoutdebut(noeud *debut, int val) {
    noeud *Nvnoeud = cree(val);
    Nvnoeud->suiv = debut;
    return Nvnoeud;
}

noeud *ajoutfin(noeud *debut, int val) {
    noeud *Nvnoeud = cree(val);
    if (debut == NULL) {
        debut = Nvnoeud;
    } else {
        noeud *ptr = debut;
        while (ptr->suiv != NULL) {
            ptr = ptr->suiv;
        }
        ptr->suiv = Nvnoeud;
    }
    return debut;
}

noeud *suppressionD(noeud *debut) {
    if (debut == NULL) {
        printf("la liste est deje vide.\n");
        return NULL;
    }
    noeud *tmp = debut;
    debut = debut->suiv;
    free(tmp);
    return debut;
}

noeud *suppressionF(noeud *debut) {
    if (debut == NULL) {
        printf("La liste est deje vide.\n");
        return NULL;
    }
    if (debut->suiv == NULL) {
        free(debut);
        return NULL;
    }
    noeud *ptr = debut;
    while (ptr->suiv->suiv != NULL) {
        ptr = ptr->suiv;
    }
    free(ptr->suiv);
    ptr->suiv = NULL;
    return debut;
}

noeud *suppressionP(noeud *debut, int pos) {
    if (debut == NULL) {
        printf("la liste est vide.\n");
        return NULL;
    }
    int size = taille(debut);
    if (pos < 1 || pos > size) {
        printf("la position est invalide.\n");
        return debut;
    }
    if (pos == 1) {
        noeud *tmp = debut;
        debut = debut->suiv;
        free(tmp);
        return debut;
    }
    noeud *ptr = debut;
    for (int i = 1; i < pos - 1; i++) {
        ptr = ptr->suiv;
    }
    noeud *temp = ptr->suiv;
    ptr->suiv = temp->suiv;
    free(temp);
    return debut;
}

int taille(noeud *debut) {
    int tl = 0;
    noeud *ptr = debut;
    while (ptr != NULL) {
        tl++;
        ptr = ptr->suiv;
    }
    return tl;
}

noeud *rechercher(noeud *debut, int val) {
    noeud *ptr = debut;
    while (ptr != NULL) {
        if (ptr->valeur == val) {
            return ptr;
        }
        ptr = ptr->suiv;
    }
    return NULL;
}

void affichage(noeud *debut) {
    noeud *tmp = debut;
    if (debut == NULL) {
        printf("la liste est vide.\n");
    } else {
        while (tmp != NULL) {
            printf("la valeur est : %d\n", tmp->valeur);
            tmp = tmp->suiv;
        }
    }
}

noeud *insertion(noeud *debut, int pos, int valeur) {
    int size = taille(debut);
    if (pos < 1 || pos > size + 1) {
        printf("position invalide !\n");
        return debut;
    }
    noeud *Nvnoeud = cree(valeur);
    if (pos == 1) {
        Nvnoeud->suiv = debut;
        debut = Nvnoeud;
    } else {
        noeud *tmp = debut;
        for (int i = 1; i < pos - 1; i++) {
            tmp = tmp->suiv;
        }
        Nvnoeud->suiv = tmp->suiv;
        tmp->suiv = Nvnoeud;
    }
    return debut;
}

noeud *modifierD(noeud *debut, int val) {
     noeud* Nvnoeud=cree(val);
     Nvnoeud->valeur=val;
     Nvnoeud->suiv=NULL;
     if(debut!=NULL)
        Nvnoeud->suiv=debut;
     debut=Nvnoeud;
     return debut;
}

noeud *modifierF(noeud *debut, int val) {
    if (debut == NULL) {
        printf("la liste est vide.\n");
        return NULL;
    }
    noeud *ptr = debut;
    while (ptr->suiv != NULL) {
        ptr = ptr->suiv;
    }
    ptr->valeur = val;
    return debut;
}

noeud *modifierP(noeud *debut, int val, int pos) {
    if (debut == NULL) {
        printf("la liste est vide.\n");
        return NULL;
    }
    int tl = taille(debut);
    if (pos < 1 || pos > tl) {
        printf("la position est invalide.\n");
        return debut;
    }
    noeud *ptr = debut;
    for (int i = 1; i < pos; i++) {
        ptr = ptr->suiv;
    }
    ptr->valeur = val;
    return debut;
}

int main() {
    noeud *debut = NULL;

    noeud *P = cree(10);
    noeud *B = cree(550);
    noeud *T = cree(100);

    debut = P;
    P->suiv = B;
    B->suiv = T;
    T->suiv = NULL;

    printf("l'adresse de debut est %p.\n", (void *)debut);
    printf("l'adresse de P est %p.\n", (void *)P);
    printf("l'adresse de B est %p.\n", (void *)B);
    printf("l'adresse de T est %p.\n", (void *)T);

    printf("\n ajout au debut :\n");
    debut = ajoutdebut(debut, 2000);
    affichage(debut);

    printf("\n la taille de la liste est %d.\n", taille(debut));

    printf("\n ajout a la fin :\n");
    debut = ajoutfin(debut, 300);
    affichage(debut);

    printf("\n suppression au debut :\n");
    debut = suppressionD(debut);
    affichage(debut);

    printf("\n suppression a la fin :\n");
    debut = suppressionF(debut);
    affichage(debut);

    printf("\n suppression a la position 2 :\n");
    debut = suppressionP(debut, 2);
    affichage(debut);

    printf("\n insertion a la position 2 :\n");
    debut = insertion(debut, 2, 60);
    affichage(debut);

    printf("\n modification du debut :\n");
    debut = modifierD(debut, 30);
    affichage(debut);

    printf("\n modification de la fin :\n");
    debut = modifierF(debut, 50);
    affichage(debut);

    printf("\n modification a la position 2 :\n");
    debut = modifierP(debut, 200, 2);
    affichage(debut);

    printf("\n recherche de la valeur 100 :\n");
    noeud *resultat = rechercher(debut, 100);
    if (resultat != NULL) {
        printf("la valeur 100 a ete trouvee a l'adresse %p.\n", (void *)resultat);
    } else {
        printf("la valeur 100 n'a pas ete trouvee.\n");
    }

    return 0;
}
