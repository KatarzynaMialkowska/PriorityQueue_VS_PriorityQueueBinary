#include "priorityQueue.hxx"
#include "priorityQueueBinary.hxx"
#include "gnuplot.hxx"
#include <chrono>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>

void test(int N);

std::ofstream setPriorityQueueData, setPriorityQueueBinaryData;
std::string priorityQueuePlot("setPriorityQueueData.dat");
std::string priorityQueueBinaryPlot("setPriorityQueueBinaryData.dat");

std::string name_graphs("graphs");
std::string type("pdf");

std::uniform_int_distribution<int> dist1 ( 0,1000000 ); //klasa szablonowa
std::mt19937 gen ( time ( NULL ) ); //generator pseudolosowy Mersenne Twister 32bit  
int x, y;

int main() {
    
        /*dane potrzebne do wykresów*/
    setPriorityQueueData.open (priorityQueuePlot, std::ios::out | std::ios::app); 
    setPriorityQueueBinaryData.open (priorityQueueBinaryPlot, std::ios::out | std::ios::app); 


    test(100);
    test(2000);
    test(5000);
    test(10000);
    test(20000);
    test(40000);
    test(50000);

   /*Tworzenie wykresu*/
    gnuplot p;
    std::string setQP("\'./" + priorityQueuePlot + "\' u 1:2 w l");
    std::string setQPB("\'./" + priorityQueueBinaryPlot + "\' u 1:2 w l");
    

    p("set terminal " + type);
    p("set output \"" + name_graphs + '.' + type + "\""); 
    p("set xlabel 'data'");
    p("set ylabel 't/s'");
    p("set title 'priorityQueuePlot vs priorityQueueBinaryPlot'");

        p("set xrange [0:50000]");
        p("set yrange [0:0.03]");
    p("plot " + setQP + " , " + setQPB );
 

    setPriorityQueueData.close();
    setPriorityQueueBinaryData.close();


    return 0;
}

void test(int N) {

    priorityQueue<int> A;
    priorityQueueBinary<int> B;

    std::cout << "\t-TEST "<< N << " n-\n";
        for( int i = 0; i < N; i++ ) {
            x = dist1(gen);
            y = dist1(gen);
            //std::cout<<x<<" "<<y<<'\n';
            A.push(x, y);
            B.push(x, y);

        }

    /*test priorityQueue*/
    auto Sstart = std::chrono::high_resolution_clock::now();
        for( int i = 0; i < N; i++ ) {
            A.pop();
        }
    auto Send = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setQPElapsed = Send - Sstart;
    std::cerr << "setPriorityQueue elapsed time[s] =" << setQPElapsed.count() << std::endl;
        setPriorityQueueData << N << '\t' << setQPElapsed.count() << '\n';

    /*test priorityQueueBinary*/
    auto Lstart = std::chrono::high_resolution_clock::now();
        for( int i = 0; i < N; i++ ) {
            B.pop();
        }
    auto Lend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setQPBElapsed = Lend - Lstart;
    std::cerr << "setPriorityQueueBinary elapsed time[s] =" << setQPBElapsed.count() << std::endl;
        setPriorityQueueBinaryData << N << '\t' << setQPBElapsed.count() << '\n';


}

