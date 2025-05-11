#include <stdio.h>
#include <stdlib.h>

typedef struct etudiant{
    int id;
    char nom[50];
    float moyenne;
} etudiant;
typedef struct noeud {
    etudiant data;
    struct noeud *next;
    struct noeud *prev;
}noeud;
typedef noeud* liste;

liste creeETD(etudiant E) {
    liste newE = (liste)malloc(sizeof(noeud));
    newE->data = E;
    newE->next = NULL;
    newE->prev = NULL;
    return newE;
    }


int longueur(liste head) {
    int nE = 0;
    liste tmp = head;
    while(tmp != NULL) {
        nE++;
        tmp = tmp->next;
    }
    return nE;
}

liste insertD(liste head, etudiant E) {
    liste newE = creeETD(E);
    newE->next = head;
    if(head != NULL) {
        head->prev = newE;
    }
    return newE;
}

liste insertF(liste head, etudiant E) {
    liste newE = creeETD(E);
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


liste insertP(liste head, etudiant E, int pos) {
    int N = longueur(head);
    if(pos < 0 || pos > N+1) {
        printf("position invalide .\n");
        return head;
    }
    if(pos == 0) {
        return insertD(head,E);
    }
    else if(pos == N+1) {
        return insertF(head,E);
    }
    else {
        liste tmp = head;
        int i ;
        for(i = 0; i < pos - 1; i++) {
            tmp = tmp->next;
        }
        liste newE = creeETD(E);
        newE->next = tmp->next;
        newE->prev = tmp;
        tmp->next->prev = newE;
        tmp->next = newE;
        return head;
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
    if(head==NULL || pos<0 || pos>= longueur(head)){
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

void afficher(liste head) {
    if(head == NULL) {
        printf("la liste est vide.\n");
    }
    else {
        liste tmp = head;
        while(tmp != NULL) {
            printf("\n %d %s%.2f\t\n",tmp->data.id,tmp->data.nom,tmp->data.moyenne);
            tmp = tmp->next;
        }
    }
}

void afficherI(liste fin) {
    liste tmp = fin;
    while(tmp != NULL) {
        printf("\n %d %s%.2f\t\n",tmp->data.id,tmp->data.nom,tmp->data.moyenne);
        tmp = tmp->prev;
    }
}

void triC (liste head){
    int mn=0;
    liste tmp=head;
    while(head!=NULL){
        if(tmp->data.moyenne > tmp->next->data.moyenne){
            mn = tmp->next->data.moyenne;
            tmp->next->data.moyenne = tmp->data.moyenne;
            tmp->data.moyenne = mn;
        }
        tmp=tmp->next;
    }
}




int main()
{

    return 0;
}
