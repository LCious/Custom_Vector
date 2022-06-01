# Custom Vector #

## 1. Vector konteinerio funkcionalumo patikrinimas ##

Tikrinamas 5 funkcijų funkcionalumas, std::vector ir Custom Vector

```
std::vector :
push_back() 90, 60, 30
at(2) 30
size() 3
pop_back() (vector size): 2
clear() (vector size): 0

Custom vector :
push_back() 90, 60, 30
at(2) 30
size() 3
pop_back() (vector size): 2
clear() (vector size): 0
```
### Funkcijos: ###

#### push_back() ####
```cpp
template <class T>
void Vector<T>::push_back(const T& val){
    if(avail == limit)
        growTwice();
    unchecked_append(val);
        
}
```
#### at() ####
```cpp
template <class T>
typename Vector<T>::reference Vector<T>::at(size_type i) {
    if (i >= 0 && size() > i)
        return data[i];

    else throw std::out_of_range {"Vector::at"};
}
```
#### size() ####
```cpp
size_type size() const { return avail - data; }
```
#### pop_back() ####
```cpp
template <class T>
void Vector<T>::pop_back(){
    iterator it = avail;
    alloc.destroy(--it);
    avail--;
}
```
#### clear() ####
```cpp
template <class T>
void Vector<T>::clear() {
    iterator it = avail;
    while (it != data)
        alloc.destroy(--it);
    avail = data;
}
```
## 2. std::vector ir Custom Vector spartos/efektyvumo analize panaudojant push_back() funkciją ##
```
-----------------------------------------------------
std::vector '10000' elementu push_back laikas :0s.
custom vector '10000' elementu push_back laikas :0s.
-----------------------------------------------------
std::vector '100000' elementu push_back laikas :0.001s.
custom vector '100000' elementu push_back laikas :0.001s.
-----------------------------------------------------
std::vector '1000000' elementu push_back laikas :0.017s.
custom vector '1000000' elementu push_back laikas :0.023s.
-----------------------------------------------------
std::vector '10000000' elementu push_back laikas :0.161s.
custom vector '10000000' elementu push_back laikas :0.193s.
-----------------------------------------------------
std::vector '100000000' elementu push_back laikas :1.555s.
custom vector '100000000' elementu push_back laikas :1.925s.
```
## 3. Atminties perskirstymų tyrimas ##
Tenkinant salygą capacity() == size(), t.y. kai nelieka vietos capacity() naujiems elementams.
```
Reallocated: 28 times
Capacity: 134217727

Reallocated: 28 times
Capacity: 134217727
```
## Programos v2.0 spartos analinės palyginimas ##

| Masyvo dydis | std::vector | Vector klasė |
| :------------| :---------- | :----------- |
| 1000         | 0.085s      | 0.088s       |
| 10000        | 0.936s      | 0.899s       |
| 100000       | 11.15s      | 11.842s      |
| 1000000      | 136.011s    | 141.692s     |
