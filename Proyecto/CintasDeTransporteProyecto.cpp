#include <iostream>
#include <vector>
#include <map>

#define MAX_CIN 50

using namespace std;


/**************************** CLASE QUEUE **********************************************/

template <class T>
class Queue{
private:
    T A[MAX_CIN];
    //int front, rear;
public:
    int front, rear;
    Queue();
    bool IsEmpty();
    bool IsFull();
    
    void push(T x);
    void pop();
    
    T get_Value(int i);
    
    int Front();
    void Print();
};

template <class T>
Queue<T>::Queue(){
    front = -1;
    rear = -1;
}

template <class T>
bool Queue<T>::IsEmpty()
{
    return (front == -1 && rear == -1);
}

template <class T>
bool Queue<T>::IsFull()
{
    return (rear+1)%MAX_CIN == front ? true : false;
}

template <class T>
void Queue<T>::push(T x)
{
    if(IsFull())
    {
        cout<<"Error: Queue is Full\n";
        return;
    }
    if (IsEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear+1)%MAX_CIN;
    }
    A[rear] = x;
}

template <class T>
void Queue<T>::pop()
{
    if(IsEmpty())
    {
        cout<<"Error: Queue is Empty\n";
        return;
    }
    else if(front == rear )
    {
        rear = front = -1;
    }
    else
    {
        front = (front+1)%MAX_CIN;
    }
}

template <class T>
T Queue<T>::get_Value(int i){
    return A[i];
}

template <class T>
int Queue<T>::Front()
{
    if(front == -1)
    {
        cout<<"Error: cannot return front from empty queue\n";
        return -1;
    }
    return A[front];
}

template <class T>
void Queue<T>::Print()
{
    int count = (rear+MAX_CIN-front)%MAX_CIN + 1;
    for(int i = 0; i <count; i++)
    {
        int index = (front+i) % MAX_CIN;
        cout<<A[index]<<" ";
    }
    cout<<"\n\n";
}



/******************************** CLASE CINTA EN TEMPLATE ************************************/
template <class T>
class Cinta{
private:
    int id;
    //T us[3];
    int t_in;
    int t_fin;
public:
    Queue<T> usuarios;
    T us[MAX_CIN];
    Cinta();
    Cinta(int i, int t_i, int t_f);
    
    int get_Id();
    void set_Id(int i);
    
    T get_User(int i);
    void push_User(T u);
    void pop_User();
    
    int get_terminal_inicio();
    void set_terminal_inicio(int t_i);
    
    int get_terminal_fin();
    void set_terminal_fin(int t_f);
};

template <class T>
Cinta<T>::Cinta(){
    id = NULL;
    t_in = NULL;
    t_fin = NULL;
}

template <class T>
Cinta<T>::Cinta(int i, int t_i, int t_f){
    id = i;
    t_in = t_i;
    t_fin = t_f;
}

template <class T>
int Cinta<T>::get_Id(){
    return id;
}

template <class T>
void Cinta<T>::set_Id(int i){
    id = i;
}

template <class T>
T Cinta<T>::get_User(int i){
    return usuarios.get_Value(i);
}

template <class T>
void Cinta<T>::push_User(T u){
    usuarios.push(u);
}

template <class T>
void Cinta<T>::pop_User(){
    usuarios.pop();
}

template <class T>
int Cinta<T>::get_terminal_inicio(){
    return t_in;
}

template <class T>
void Cinta<T>::set_terminal_inicio(int t_i){
    t_in = t_i;
}

template <class T>
int Cinta<T>::get_terminal_fin(){
    return t_fin;
}

template <class T>
void Cinta<T>::set_terminal_fin(int t_f){
    t_fin = t_f;
}



/******************************CLASE USUARIO ******************************************/
class Usuario{
private:
    int id;
    int terminal_inicio;
    int terminal_fin;
public:
    Usuario();
    Usuario(int i, int t_i, int t_f);
    
    void set_Id(int i);
    int get_Id();
    
    void set_initial_terminal(int i_t);
    int get_initial_terminal();
    
    void set_final_terminal(int f_t);
    int get_final_terminal();
};

Usuario::Usuario(){
    id = NULL;
    terminal_inicio = NULL;
    terminal_fin = NULL;
}

Usuario::Usuario(int i, int t_i, int t_f){
    id = i;
    terminal_inicio = t_i;
    terminal_fin = t_f;
}

void Usuario::set_Id(int i){
    id = i;
}

int Usuario::get_Id(){
    return id;
}

void Usuario::set_initial_terminal(int i_t){
    terminal_inicio = i_t;
}

int Usuario::get_initial_terminal(){
    return terminal_inicio;
}

void Usuario::set_final_terminal(int f_t){
    terminal_fin = f_t;
}
int Usuario::get_final_terminal(){
    return terminal_fin;
}


/*********************************** CLASE TERMINAL **************************************/

class Terminal{
private:
    int id;
public:
    map<Terminal *,vector<Cinta<Usuario> > > m;
    Terminal();
    Terminal(int i);
    
    int get_Id();
    void set_Id(int i);
};

Terminal::Terminal(){
    id = NULL;
}

Terminal::Terminal(int i){
    id = i;
}


int Terminal::get_Id(){
    return id;
}

void Terminal::set_Id(int i){
    id = i;
}



int main(int argc, char const *argv[]) {
    
    vector<Usuario> us;
    Usuario *u = new Usuario();
    
    /* -- Usuario 0 -- */
    u->set_Id(0);
    u->set_initial_terminal(1);
    u->set_final_terminal(2);
    us.push_back(*u);
    
    /* -- USUARIO 1 -- */
    u->set_Id(1);
    u->set_initial_terminal(2);
    u->set_final_terminal(1);
    us.push_back(*u);
    
    /* -- USUARIO 2 -- */
    u->set_Id(2);
    u->set_initial_terminal(1);
    u->set_final_terminal(2);
    us.push_back(*u);
    
    Cinta<Usuario> *c1 = new Cinta<Usuario>();
    
    c1->set_Id(0);
    c1->set_terminal_inicio(1);
    c1->set_terminal_fin(2);
    
    c1->push_User(us[0]);
    c1->push_User(us[1]);
    c1->push_User(us[2]);
    
    cout << "ID CINTA: " << c1->get_Id() << "\tTer in: " << c1->get_terminal_inicio() << "\tTer fin: " << c1->get_terminal_fin() << endl;
    
    cout << endl << endl;
    
    cout << "Usuarios de cinta " << c1->get_Id() << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\t-ID: " << c1->get_User(i).get_Id() << "\tT_i: " << c1->get_User(i).get_initial_terminal() << "\tF_t: " << c1->get_User(i).get_final_terminal() <<endl;
    }
    
    Terminal *t1 = new Terminal();
    t1->set_Id(1);
    Terminal *t2 = new Terminal();
    t2->set_Id(2);
    Terminal *t3 = new Terminal();
    t2->set_Id(3);
    
    t1->m[t2].push_back(*c1);
    
    cout << "Terminal: " << t1->get_Id() << " Cintas: " << t1->m[t2].size() << endl;
    
    cout << endl << endl;
    cout << "USUARIOS DE LA CINTA " << t1->m[t2][0].get_Id() << endl;
    cout << t1->m[t2][0].usuarios.front << endl;
    cout << t1->m[t2][0].usuarios.rear << endl;
    
    int count = (t1->m[t2][0].usuarios.rear + MAX_CIN - t1->m[t2][0].usuarios.front) % MAX_CIN + 1;
    for(int i = 0; i <count; i++)
    {
        int index = (t1->m[t2][0].usuarios.front+i) % MAX_CIN;
        cout<<t1->m[t2][0].get_User(index).get_Id() << " ";
    }
    
    t1->m[t2][0].pop_User();
    cout << endl;
    count = (t1->m[t2][0].usuarios.rear + MAX_CIN - t1->m[t2][0].usuarios.front) % MAX_CIN + 1;
    for(int i = 0; i <count; i++)
    {
        int index = (t1->m[t2][0].usuarios.front+i) % MAX_CIN;
        cout<<t1->m[t2][0].get_User(index).get_Id() << " ";
    }
    cout << endl;
    
    Terminal *t4 = new Terminal();
    t4->set_Id(4);
    
    Cinta<Usuario> *c2 = new Cinta<Usuario>();
    
    //c2->set_Id(1);
    //c2->set_terminal_inicio(4);
    //c2->set_terminal_fin(1);
    
    t4->m[t1];
    t4->m[t1].push_back(*c2);
    t4->m[t1][0].set_Id(1);
    t4->m[t1][0].set_terminal_inicio(4);
    t4->m[t1][0].set_terminal_fin(1);
    
    Usuario *u1 = new Usuario();
    
    t4->m[t1][0].push_User(*u1);
    t4->m[t1][0].us[0].set_Id(11);
    t4->m[t1][0].us[0].set_initial_terminal(4);
    t4->m[t1][0].us[0].set_final_terminal(1);
    
    return 0;
}
