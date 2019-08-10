#include<iostream>
template<typename T>
class List{
    private:
        ListItem<T>* _begin;
        ListItem<T>* _end;
        size_t _length;
    public:
        void insert_front(T value);
        void inert_end(T value);
        void display(std::ostream &os = std::cout) const;
};
template<typename T>
class ListItem{
    private:
        T _value;
        ListItem<T>* _next;
    public:
        T value() const { return _value; }
        ListItem<T>* next() const { return _next; };
};



int main(){

}