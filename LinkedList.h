#include<stdio.h>
#include<stdlib.h>


typedef struct elm
{
    int val;
    struct elm* suiv;
}elm;



elm* AjouterFin(elm* l,int x)
{
    elm* el=(elm*)malloc(sizeof(elm));

    el->val=x;
    el->suiv=NULL;

    if(l==NULL)
        return el;
    else
    {    
        elm* tmp=l;

        while(tmp->suiv!=NULL)
            tmp=tmp->suiv;

        tmp->suiv=el;

        return l;
    }
}


elm* AjouterFinRec(elm* l,int x)
{
    if(l==NULL)
    {
        elm* el=(elm*)malloc(sizeof(elm));

        el->val=x;
        el->suiv=NULL;

        return el;
    }
    else
    {
        l->suiv=AjouterFinRec(l->suiv,x);

        return l;
    }
}


elm* AjouterDebut(elm* l,int x)
{
    elm* el=(elm*)malloc(sizeof(elm));

    el->val=x;

    if(l==NULL)
        el->suiv=NULL;
    else
        el->suiv=l;
    
    return el;
}


elm* Supprimer(elm* l,int x)
{
    if(l==NULL)   
        return NULL;
    else
    {
        if(l->val==x)
        {
            elm* ptr_suiv=l->suiv;

            free(l);
            return ptr_suiv;
        }
        else
        {
            elm* tmp=l;

            tmp=Supprimer(tmp->suiv,x);
            l->suiv=tmp;

            return l;
        }
    }
}


elm* SupprimerOcc(elm* l,int x)
{
    elm* tmp=l;
    int n;

    while (tmp!=NULL)
    {
        if(tmp->val==x)
            n++;
        tmp=tmp->suiv;
    }

    for(int i=0;i<n;i++)
        l=Supprimer(l,x);

    return l;
}


void AfficherListe(elm* l)
{
    while(l!=NULL)
    {
        printf("%d --> ",l->val);
        l=l->suiv;
    }
    printf("NULL\n");
}