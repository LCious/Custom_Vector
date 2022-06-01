#include <vector>
#include <chrono>
#include "vector.hpp"

using namespace std::chrono;

void TEST_1(){   //Funkciju testavimas
    std::cout << "Pradedamas TEST1: " << endl;
    std::vector<int> real;      //Real vector
    Vector<int> custom;         //Custom vector
    std::cout << "std::vector : " << endl;
    real.push_back(90);
    real.push_back(60);
    real.push_back(30);
    cout << "push_back() " << real[0] << ", " << real[1] << ", "
    << real[2]<< endl;
    cout << "at(2) " << real.at(2) << endl;
    cout << "size() " << real.size() << endl;
    real.pop_back();
    cout << "pop_back() (vector size): " << real.size() << endl;
    real.clear();
    cout << "clear() (vector size): " << real.size() << endl;
    //--
    cout << endl << "Custom vector : " << endl;
    custom.push_back(90);
    custom.push_back(60);
    custom.push_back(30);
    cout << "push_back() " << custom[0] << ", " << custom[1] << ", "
    << custom[2] << endl;
    cout << "at(2) " << custom.at(2) << endl;
    cout << "size() " << custom.size() << endl;
    custom.pop_back();
    cout << "pop_back() (vector size): " << custom.size() << endl;
    custom.clear();
    cout << "clear() (vector size): " << custom.size() << endl;
}

void TEST_2(){                   // PUSH_BACK() testavimas
    std::vector<int> real;
    Vector<int> custom;
    int sz[5] = { 10000, 100000, 1000000, 10000000, 100000000 };
    std::cout << "Pradedamas TEST2: " << endl;
    for(int i = 0; i < 5; i++){ 
        std::cout << "-----------------------------------------------------" << endl;
        std::chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        for (int j = 0; j <= sz[i]; j++){
            real.push_back(j);   
        }
        std::cout << "std::vector '" << sz[i] << "' elementu push_back laikas :" << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

        std::chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        for (int j = 0; j <= sz[i]; j++){
            custom.push_back(j);   
        }
        std::cout << "custom vector '" << sz[i] << "' elementu push_back laikas :" << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t2).count() / 1000. << "s." << endl;
    }
}

void TEST_3(){              //atminties perskirstymai užpildant 100000000 elementų. Perskirstymas įvyksta tada, kai yra patenkinama sąlyga: capacity() == size()
    std::vector<int> real;
    Vector<int> custom;
    int sz = 100000000;
    int Count = 0, capacity;
    bool didReallocate = false;
    std::cout << "Pradedamas TEST 3: " << endl;
    for (int i = 0; i < sz; i++) {
        if (real.size() == real.capacity()) {
            Count++; 
            didReallocate = true;
        }
        real.push_back(i);
        if (didReallocate) {
            capacity = real.capacity();
            didReallocate = false;
        }
    }
    std::cout << "Reallocated: " << Count << " times" << endl;
    std::cout << "Reached capacity: " << capacity << endl << endl;
    Count = 0;
    capacity = 0;
    for(int i = 0; i < sz; i++) {
        if (custom.size() == custom.capacity()) {
            Count++; 
            didReallocate = true;
        }
        custom.push_back(i);
        if (didReallocate) {
            capacity = custom.capacity();
            didReallocate = false;
        }
    }
    std::cout << "Reallocated: " << Count << " times" << endl;
    std::cout << "Capacity: " << capacity << endl;
}

int main(){
    int choice;
    std::cout << "Testavimo budai: 1 ||  2 ||  3: " << endl
    << "1. (FUNKCIJU TESTAVIMAS) " << endl
    << "2. (PUSH_BACK PALYGINIMAS) " << endl
    << "3. (ATMINTIES PERSKIRSTYMAS V1.5 UZDUOTYJE) " << endl;
    cin >> choice;
    cout << endl;
    if(choice == 1) TEST_1();
    else if(choice == 2) TEST_2();
    else if(choice == 3) TEST_3();
    else{
        std::cout << "Blogai ivesta, programa uzdaroma";
        return 0;
    }
    std::cout << endl;
    system("pause");
}