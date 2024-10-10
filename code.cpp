#include <iostream>
#include <limits>

using namespace std;

void Mandelbrot(int n, float a, float b) {
    int i;
    float z0x=0, z0y=0;
    float x, y;
    float lx, ly;
    float infini = numeric_limits<float>::infinity();

    x = z0x; 
    y = z0y;
    cout <<"\n("<<x<<','<<y<<")   ";
    for(i = 1; i <= n; ++i)
    {
        x = (x*x) + a;
        y = (y*y) + b;
        lx = x;
        ly = y;
        if ((lx != infini) && (ly != infini)) {
            cout <<'('<<x<<','<<y<<")   ";
        }
    }
    cout <<"\n";
}

int main(int argc, char const *argv[])
{   
    float a, b;
    int n;

    cout <<"\nEntrez la valeur de n : ";
    cin >> n;
    cout <<"Entrez les coordonnees de c : ";
    cin >>a >>b;

    cout <<"\nLes "<<n<<" premiers termes de la suite de Mandelbrot pour c("<<a<<','<<b<<") sont : \n";
    Mandelbrot(n, a, b);

    return 0;
}