#include <iostream>
#include <sstream>
#include <omp.h>
#include <cstdlib>
#include <ctime>   

using namespace std;

int main() {
    srand(time(NULL));

    #pragma omp parallel num_threads(4)
    {
        stringstream Collecting;
        int tid = omp_get_thread_num();
        for (int i = 1; i <= 10; ++i) {
            int randomNumber;
            #pragma omp critical(rand_section)
            {
                randomNumber = rand() % 30 + 1;
            }
            Collecting << "Hello world " << randomNumber << "! Thread = " << tid << endl;
        }
        #pragma omp critical(output)
        {
            cout << Collecting.str();
        }
    }
    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}
