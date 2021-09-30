#include "priorityQueue.hxx"

int main() {
    priorityQueue<std::string> A; 

    A.push (1,"ALA");
    A.push (221,"MA");
    A.push (111,"KOTA");
    A.push (0,"PSA");
    A.push (21,"SZCZURA");
    A.push (6,"ZAJACA");

    while(!A.empty()) {
        std::cout << "[" << A.front_priority() << "] " << A.front() <<'\n';
        A.pop();
    }
} 
