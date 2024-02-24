#include <iostream>
#include <cmath> //niektóre interpretety nie rozpoznają stałej M_PI, trzeba ją wtedy zadeklarować ręcznie
using namespace std;

int N = 1000000; //N - Ilość powtórzeń
// double M_PI=3.141593

int main()
{
    double sumaA = 0;
    double iloczynB = 1;
    double sumaC = 0;
    //Wszystkie sumy policzę w jednej pętli, będą liczone równolegle
    for(int i = 1; i <= N; i++)
    {
        sumaA += (pow(-1, i + 1))/(2*i - 1);
        iloczynB *= (4 * pow(i,2))/((4 * pow(i,2)) - 1);
        sumaC += 1/pow(((2*i) - 1),2);
    }
    double wynikA = 4 * sumaA; //na koniec mnożę sumę razy 4
    double wynikB = 2 * iloczynB; //na koniec mnożę iloczyn razy 2
    double wynikC = sqrt(8*sumaC); //Pierwiastkuję sumę przemnożoną razy 8
    cout << wynikA << " roznica miedzy pi a przyblizeniem wyliczonym w sposob A: " << M_PI - wynikA << endl;
    cout << wynikB << " roznica miedzy pi a przyblizeniem wyliczonym w sposob B: " << M_PI - wynikB << endl;
    cout << wynikC << " roznica miedzy pi a przyblizeniem wyliczonym w sposob C: " << M_PI - wynikC << endl;
    //Możemy więc powiedzeć że najskuteczniejsza okazuje się metoda C
}
