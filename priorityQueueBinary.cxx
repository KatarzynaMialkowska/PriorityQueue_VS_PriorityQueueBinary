#include "priorityQueueBinary.hxx"

int main() {

    priorityQueueBinary<std::string> A; 

    A.push (1,"ALA");
    A.push (221,"MA");
    A.push (111,"KOTA");
    A.push (0,"PSA");
    A.push (21,"SZCZURA");
    A.push (6,"ZAJACA");

    while(!A.empty()) {
      auto t = A.pop();
      std::cout << "[" << t.p << "] " << t.value <<'\n';
    }

   /* priorityQueueBinary<int> v;
    v.push(-11,1);
    v.push(5,2);
    v.push(2,3);
    v.push(33,4);
    v.push(22,5);
    v.push(12,6);
    v.push(13,7);

    std::cout<<'\n';
    std::cout<<"before\n";
    v.view();
    std::cout<<"after\n";
    v.heapsort();
    std::cout<<'\n';
    v.view();
    std::cout<<'\n';
    // type<int> t;
    auto t = v.pop();
    std::cout<<t.p<<" "<<t.value<<'\n';
    t = v.pop();
    std::cout<<t.p<<" "<<t.value<<'\n';
    t = v.pop();
    std::cout<<t.p<<" "<<t.value<<'\n';
    t = v.pop();
    std::cout<<t.p<<" "<<t.value<<'\n';

    std::cout<<'\n';
    v.view();
    std::cout<<'\n';

    v.push(32313,4);

     std::cout<<'\n';
    v.view();
    std::cout<<'\n';

    t = v.pop();
    std::cout<<t.p<<" "<<t.value<<'\n';
      t = v.pop();
    std::cout<<t.p<<" "<<t.value<<'\n';
      t = v.pop();
    std::cout<<t.p<<" "<<t.value<<'\n';

   std::cout<<'\n';
    v.view();
    std::cout<<'\n';
    // for(const auto &i : vec){
    //     std::cout << i << "\n";
    // }
    */
    return 0;
}