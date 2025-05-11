#include<stdio.h>
#include<stdlib.h>
typedef struct Noeud{
  int valeur ;
  struct Noeud *suivant ;  
}Noeud ;
Noeud* ajout(){
 Noeud *ptr;
  ptr = (Noeud*)malloc( sizeof(Noeud) ) ;
  if( !ptr ){
    printf("allocation echouée\n") ;
    return NULL ;
  }   
  ptr->suivant = NULL ;
 return ptr ; 
}
void Enfiler( Noeud **top , int val ){
 Noeud *ptr, *tmp;
  tmp = ajout() ;
  if( tmp ){
    tmp->valeur = val ;
    if( !( *top ) ){
        *top =  tmp ;
    }
    else{
        ptr = *top ;
        while( ptr->suivant ){
          ptr = ptr->suivant ;
        }
        ptr->suivant = tmp ;
    }
  }
}
void Defiler( Noeud **top ){
 Noeud *ptr ;
  if( !( *top ) ){
    printf("la liste est vide\n") ;
  }
  else{
    ptr = *top ;
    *top = (*top)->suivant ;
    free(ptr) ;
  }   
}
void afficher( Noeud *top ){
 Noeud *ptr;
 int I;
  for( ptr = top , I = 1 ; ptr ; ptr = ptr->suivant , I++ ){
     printf("l'element %d dans la file est : %d \n",I,ptr->valeur) ;
  }   
  if( I == 1 ){
    printf("la liste est vide\n") ;
  }
}
void viderFile( Noeud **top ){
 Noeud *ptr;   
  while( *top ){
   ptr = *top ;
   *top = (*top)->suivant ;
   free(ptr) ;
  }    
}
int main( ){
 Noeud *top = NULL;
 int I, val;
  Enfiler(&top,10) ;
  Enfiler(&top,20) ;
  Enfiler(&top,30) ; 
  afficher(top) ;
  Defiler(&top) ;
  afficher(top) ;
  for( I = 1 ; I <= 2 ; I++ ){
    printf("saisir la valeur numero %d que vous voulez inserer : ",I) ;
    scanf("%d",&val) ;
    Enfiler(&top,val) ;
  }
  afficher(top) ;
  viderFile(&top) ;
  afficher(top) ;
 return 0 ;   
}
