#pragma once
#include <iostream>
#include <vector>
#include <iterator>

template <class T>
class priorityQueueBinary {
    struct type {
            int p;
            T value;
            type() = default;
            type(int x, T y) : p(x), value(y) {};
    };
    int largest {0}, length{0};
    int  l, r, node;
    type first;
    std::vector<type> v_{first}; // Zaczynamy od 1

    void heapify(std::vector<type> &a, int n, int i) {
        l = LEFT(i);
        r = RIGHT(i);
    
        if(l < n && a[l].p > a[i].p){
            largest = l;
        }else largest = i;
        
        if(r < n && a[r].p > a[largest].p){
            largest = r;
        }

        if(largest != i){
            std::swap(a[i],a[largest]);
            heapify(a, n, largest);
        }
    
    } // Umieszcza wartość korzenia i w odpowiednim miejscu

    int PARENT(int i){ return i/2; } // Obliczanie rodzica
    int LEFT(int i){ return 2*i; } // Obliczanie lewego dziecka
    int RIGHT(int i){ return 2*i+1; } // Obliczanie prawego dziecka

public:
    void build(const std::vector<type> &a) {
        for(int j = 0; j < a.size(); j++)
            v_.push_back(a[j]);
        length = v_.size();
        for(int i = length/2; i > 0 ; i--){
            heapify(v_, v_.size(), i);
        }
    } // Kopiuje zawartość wektora a do wewnętrznej tablicy kopca, a następnie naprawia jego strukturę wykorzystując metodę heapify()

    void push(int prio, T x) {
        type temp(prio, x);
        if(empty()){
            v_.push_back(temp);
        }else{
            int j;
            node = v_.size();
            v_.push_back(temp); 
            j = PARENT(node);

            while(node > 1 && v_[j].p < prio) {
                v_[node] = v_[j];
                node = j;
                j = PARENT(node);
            }
            v_[node] = temp;
        }
    } // Wstawia element do kopca

    type pop() { 
        if(empty())throw std::out_of_range("EMPTY"); 
            type temp = v_[1];
        std::swap(v_[1],v_[v_.size()-1]);
        v_.pop_back();
        //node = v_.size()-1;
        heapify(v_, v_.size(), 1);
        return std::move(temp);
    } // Usuwa element z kopca i zwraca usuniety element

    int& top(){ return v_.back(); } // Zwraca referncję do ostatniego elementu

    int size(){ return v_.size()-1; } // Zwraca liczbę elementów w kopcu

    bool empty(){ return v_.size()==1; } // Sprawdza czy kopiec jest pusty

    bool check() {
        if(empty()) 
            return true;
        node = 1;
        while(node <= PARENT(size())){
            if(v_[node] <= v_[RIGHT(node)] || v_[node] <= v_[LEFT(node)])
                return false; 
            ++node;
        }
        return true;
    } // Sprawdza czy właściwość kopca jest zachowana

    void heapsort(std::vector<type>&a){
        build(a);
        node = v_.size()-1;
        for(int i = node; i > 1; i--){
            std::swap(v_[1],v_[i]);
            heapify(v_, i ,1);
        }
        for(int i = 0; i<a.size();i++)
            a[i] = v_[i+1];
    } // Sortuje rosnąco kolejke priorytetową wedlug priorytetu

    void heapsort(){
        node = v_.size()-1;
        for(int i = node; i > 1; i--){
            std::swap(v_[1],v_[i]);
            heapify(v_, i ,1);
        }
    } // Sortuje rosnąco kolejke wedlug priorytetu

    void view(){
        std::cout << "PRIORITY - VALUE\n";
        for(auto i : v_){
            std::cout<<i.p<<" - "<<i.value<<'\n';
        }
    } // Wyświetla kolejke priorytetową

};