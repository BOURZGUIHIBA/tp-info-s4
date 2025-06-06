#include <stdio.h>
#include <stdlib.h>

typedef struct noeud {
    int valeur;
    struct noeud *next;
    struct noeud *prev;
} noeud;

typedef noeud* liste;

liste cree(int val) {
    liste newE = (liste)malloc(sizeof(noeud));
    newE->valeur = val;
    newE->next = NULL;
    newE->prev = NULL;
    return newE;
}

liste insertD(liste head, int val) {
    liste newE = cree(val);
    newE->next = head;
    if(head != NULL) {
        head->prev = newE;
    }
    return newE;
}

liste insertF(liste head, int val) {
    liste newE = cree(val);
    if(head == NULL) {
        return newE;
    }
    liste tmp = head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newE;
    newE->prev = tmp;
    return head;
}

int taille(liste head) {
    int ct = 0;
    liste tmp = head;
    while(tmp != NULL) {
        ct++;
        tmp = tmp->next;
    }
    return ct;
}

liste insertP(liste head, int val, int pos) {
    int N = taille(head);
    if(pos < 0 || pos > N) {
        printf("position invalide .\n");
        return head;
    }
    if(pos == 0) {
        return insertD(head, val);
    }
    else if(pos == N) {
        return insertF(head, val);
    }
    else {
        liste tmp = head;
        int i ;
        for(i = 0; i < pos - 1; i++) {
            tmp = tmp->next;
        }
        liste newE = cree(val);
        newE->next = tmp->next;
        newE->prev = tmp;
        tmp->next->prev = newE;
        tmp->next = newE;
        return head;
    }
}

void afficher(liste head) {
    if(head == NULL) {
        printf("la liste est vide.\n");
    }
    else {
        liste tmp = head;
        while(tmp != NULL) {
            printf("\nla valeur %d | l'adresse %p", tmp->valeur, (void*)tmp);
            tmp = tmp->next;
        }
    }
}

void afficherI(liste fin) {
    liste tmp = fin;
    while(tmp != NULL) {
        printf("\nla valeur %d | l'adresse %p", tmp->valeur, (void*)tmp);
        tmp = tmp->prev;
    }
}

liste suppD(liste head){
    if(head!=NULL){
        liste tmp=head;
        head = head->next;
        free(tmp);
    }
    return head;
}

liste suppF(liste head){
    if(head!=NULL){
        if(head->next==NULL){
            free(head);
            head = NULL;
        }
    else{
        liste tmp=head;
        while(tmp->next!=NULL){
                tmp=tmp->next;
        }
        tmp->prev->next=NULL;
        free(tmp);
    }
   }
   return head;
}

liste suppP(liste head , int pos){
    if(head==NULL || pos<0 || pos>=taille(head)){
        printf("suppression impossible .\n");
    }
    else if (pos==0){
        head=suppD(head);
    }
    else{
        liste tmp=head;
        int i ;
        for(i=0;i>pos;i++){
            tmp=tmp->next;
        }
        tmp->prev->next=tmp->next;
        if(tmp->next!=NULL){
            tmp->next->prev=tmp->prev;
            free(tmp);
        }
        return head;
    }
}

void invrs(liste head){
    liste tmp=NULL;
    liste crt=head;
    while(crt!=NULL){
        tmp=crt->prev;
        crt->prev=crt->next;
        crt->next;
        crt=crt->prev;
    }
    if(tmp!=NULL){
        head=tmp->prev;
    }
}

void triC (liste head){
    int crt=0;
    liste tmp=head;
    while(head!=NULL){
        if(tmp->valeur > tmp->next->valeur){
            crt=tmp->next->valeur;
            tmp->next->valeur=tmp->valeur;
            tmp->valeur=crt;
        }
        tmp=tmp->next;
    }
}
liste recherche (liste head,int val){
    liste tmp=head;
    while(tmp!=NULL){
        if(tmp->valeur==val){
            return tmp;
        }
        else{
            tmp=tmp->next;
        }
        return head;
    }
}

liste modifierD(liste head, int val) {
   if (head != NULL) {
     head->valeur = val;
    }
    return head;
}

liste modifierF(liste head, int val) {
   if (head == NULL) {
    return NULL;
   }
   liste tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
    tmp->valeur = val;
  return head;
}

liste modifierP(liste head, int pos, int val) {
    if (pos < 1 || pos > taille(head)) {
       printf("Position invalide\n");
       return head;
       }
    liste tmp = head;
    for (int i = 1; i < pos; i++) {
       tmp = tmp->next;
    }
     tmp->valeur = val;
     return head;
}

int main() {
    liste head = NULL;

    noeud *P = cree(10);
    noeud *D = cree(550);
    noeud *F = cree(100);

    head = P;
    P->next = D;
    D->next = F;
    D->prev = P;
    F->prev = D;

    printf("\n\n***********************\n");

    printf("\n ajout debut :\n");
    head = insertD(head, 200);
    afficher(head);

    printf("\n\n***********************\n");

    printf("\n\n ajout fin :\n");
    head = insertF(head,2000);
    afficher(head);

    printf("\n\n***********************\n");

    printf("\n\n ajout position :\n");
    head = insertP(head,10,3);
    afficher(head);

    printf("\n\n***********************\n");

    printf("\n\n recherche valeur :\n");
    head = recherche(head,10);
    afficher(head);

    printf("\n\n***********************\n");

    printf("\n\n la liste inversee :\n");
    invrs(head);
    afficher(head);

    printf("\n\n***********************\n");

    printf("\n\n la taille de la liste est %d .\n",taille(head));

    printf("\n\n***********************\n");

    printf("\n\n supprimer debut : \n");
    head = suppD(head);
    afficher(head);

    printf("\n\n***********************\n");

    printf("\n\n supprimer fin : \n");
    head = suppF(head);
    afficher(head);

    printf("\n\n***********************\n");

    printf("\n\n supprimer position : \n");
    head = suppP(head,3);
    afficher(head);

    printf("\n\n***********************\n");

     printf("\n\n modifier debut : \n");
    head = modifierD(head,20);
    afficher(head);

    printf("\n\n***********************\n");

    printf("\n\n modifier fin: \n");
    head = modifierF(head,33);
    afficher(head);

    printf("\n\n***********************\n");

    printf("\n\n modifier position: \n");
    head = modifierP(head,2,5);
    afficher(head);

    printf("\n\n***********************\n");


    return 0;
}
