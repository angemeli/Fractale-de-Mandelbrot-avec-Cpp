#include <iostream>
#include <complex>

/* 
Zn = x + yi
c = a + bi
Z(n+1) = Zn² + c
       = (x + yi)² + c
       = x² - y² + 2xyi + a + bi
       

Re(Z) = x² - y² + a
Im(Z) = 2xy + b

module(Z) = racine carrée de (Re²(Z) + Im²(Z))
*/

using namespace std;

float expo(float a, unsigned int b)  /*Pour calculer la puissance d'un nombre*/
{
    if (a==0 && b==0) {
        return 0;
    }
    unsigned int i = 1;
    float p = 1;
    for(i=1; i<=b; ++i)
    {
        p*=a;
    }
    return p;
}

int Mandelbrot(float a, float b, int max_iterations) {
    int n = 0;
    float z = 0;
    float re_z, im_z; /*Parties réelles et immaginaires de Z(n+1)*/
    float x = 0, y = 0; /*Parties réelles et immaginaires de Zn*/
    float mod_carre_z = 0; /*Représente ici le carré du module de z(n+1)*/

    while(mod_carre_z<=4 && n<=max_iterations) /*Vérifie que pour chaque itération, le module soit inférieur à 2, donc que son carré soit inférieur à 4*/
    {   
        re_z = expo(x,2) - expo(y,2) + a;
        im_z = 2*x*y + b;
        mod_carre_z = expo(re_z,2) + expo(im_z,2);
        
        x = re_z; 
        y = im_z;
        
        n += 1;
    }
    return n;
}

int main(int argc, char const *argv[])
{   
    double abscisse = 80, ordonnee = 40;
    double nombre_iterations = 100;
    float a, b;
    int i,j,m;

    for(j=0; j<ordonnee; ++j)
    {
        for(i=0; i<abscisse; ++i)
        {   
            /*Transformation des coordonnées (x, y) en coordonnées complexes*/
            a = (i/abscisse)*4 - 2; /*Échelle de -2 à 2*/
            b = (j/ordonnee)*4 - 2; /*Échelle de -2 à 2*/

            /*Calculer le nombre d'itérations pour le point complexe*/
            complex(a,b);

            m = Mandelbrot(a,b,nombre_iterations);
            if (m == nombre_iterations) {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
    }
    
    return 0;
}