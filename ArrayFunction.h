//                              /               \   
//                             ((__-^^'---'^^-__))
//                              `-_---'   '---_-' 
//                               <__|o'   'o|__>
//                                  \       /  
//                              .-'. ):   :( .'-.
// ,-.                        .'  :   :o_o:   :  '.   .   , ,---, , ,---, ,
//(   `      ,-              /   /     "-"     \   \  |\ /|    /  |    /  |
// `-.  ,-.  |  . . ,-: ;-. :   ;               :   : | V |   /   |   /   |      
//.   ) | |  |- | | | | | | :  `-._           _.-`  : |   |  /    |  /    |      
// `-'  `-'  |  `-| `-` ' '  :     ""--. .--""     :  '   ' '---' ' '---' '       
//          -'  `-'           '.  _    ; ;       .'          
//                             {"".''._.-._.''.""}
//                              \       :       /
//                               \     / \     /
//                                '-..'   '..-'


#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

void SaisirTab(int t[],int n)
{
    int i;
    
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("t[%d]=",i);
        scanf("%d",&t[i]);
    }
    printf("\n");
}

void AfficherTab(int t[],int n)
{
    int i;

    printf("\n");
    for(i=0;i<n;i++)
        printf("%d\t",t[i]);

    printf("\n");
}

void EchangerTab(float t[],int i,int j)
{
    float k;

    k=t[i];
    t[i]=t[j];
    t[j]=k;
}

void SupprimerTab(int t[], int n, int j)
{
    int i;

    for(i=j;i<n;i++)
        t[i]=t[i+1];

    AfficherTab(t,n-1);
}

void InsererTab(int t[], int n)
{
    int i,x,j;

    printf("Donnez l'element à inserer:");
    scanf("%d",&x);
    printf("Donnez l'indice de l'element à inserer:");
    scanf("%d",&j);

    for(i=n+1;i>j;i--)
        t[i]=t[i-1];

    t[j]=x;
    AfficherTab(t,n+1);
}

int MaxTab(int t[], int i_min, int i_max)
{
    int i,max=t[i_min];
    
    if(i_min>i_max)
        return EXIT_FAILURE;
    for(i=i_min;i<=i_max;i++)  
        if(t[i]>max)  max=t[i];

    return max;
}

int MinTab(int t[], int i_min, int i_max)
{
    int i,min=t[i_min];

    if(i_min>i_max)
        return EXIT_FAILURE;
    for(i=i_min;i<=i_max;i++)  
    {
        if(t[i]<min)
            min=t[i];
    }

    return min;
}

int IndiceMinTab(int t[],int i_min,int i_max)
{
    int i,IndMin=i_min;

    if(i_min>i_max)
        return EXIT_FAILURE;
    for(i=i_min;i<=i_max;i++)  
        if(t[i]<t[IndMin])
            IndMin=i;

    return IndMin;;
}

int RechercherTab(int t[],int x,int i_min,int i_max)
{
    int i;

    for(i=i_min;i<=i_max && t[i]==x;i++)
        return i;
}

int OccurenceTab(int t[],int x,int i_min,int i_max)
{
    int i,k=0;

    for(i=i_min;i<=i_max && t[i]==x;i++,k++)
    
    return k;
}

long somme(int t[],int i_min,int i_max)
{
    if(i_min==i_max)
        return t[i_min];
    else
        return t[i_max]+somme(t,i_min,i_max-1);
}

long produit(int t[],int i_min,int i_max)
{
    if(i_min==i_max)
        return t[i_min];
    else
        return t[i_max]*somme(t,i_min,i_max-1);
}

//LES TRIS

void TriSelection(int t[],int i_min,int i_max)
{
    int i;

    for(i=i_min;i<=i_max;i++)
        EchangerTab(t,IndiceMinTab(t,i,i_max),i);
}

void TriInsertion(int t[],int i_min,int i_max)
{
    int i,j;

    for(i=i_min;i<=i_max;i++)
        for(j=i_min;j<=i;j++)
            if(t[i]<t[j]) EchangerTab(t,i,j);
}

void TriBulle(int t[],int i_min,int i_max)
{
    int i,j;

    for(i=i_max;i<=i_min;i--)
        for(j=i_min;j<=i;j++)
            if(t[j]>t[j+1]) EchangerTab(t,i,j);
}

void TriRapide (int t[],int n)
{
    int mur=0,i,pivot=t[n-1];
    if (n<=1) return;
    
    for(i=0;i<n;i++)
    {
        if (t[i]<=pivot)
        {
            if (mur!=i)
                EchangerTab(t,mur,i);
            mur ++;
        }
    }
    TriRapide(t,mur-1);
    TriRapide(t,n-mur+1);
}

void TriFusion(int t[],int imin,int imax)
{
    int imil;
    
    if(imin<imax)
    {
        imil=(imin+imax)/2;
        TriFusion(t,imin,imil);
        TriFusion(t,imil+1,imax);
        fusionner(t,imin,imil,imax);
    }
}

void fusionner(int t[],int imin,int imil,int imax)
{
    int S[imax-imin+1];
    int i,j,k;
    //construction de S a partir de t
    //premier partie
    for(i=imin,j=0;i<=imil;i++,j++)
    {
        S[j]=t[i];
    }
    // deuxieme partie
    
    for(i=imax,j=imil-imin+1;i>imil;i--,j++)
    {
        S[j]=t[i];
    }
    //construction de t a partir de S
    j=imax-imin;
    for(k=imin,i=0;k<imax;k++)
    {
        if(S[i]<S[j])
        {
            t[k]=S[i];
            i++;
        }
        else
        {
            t[k]=S[j];
            j--;
        }
    }
}