#ifndef ARRAY_LIST_IFRN
#define ARRAY_LIST_IFRN

class Vetor_dinamico{
    //Atributos e incease capacity
    private:
        int *array;
        int size_;
        int capacidade_;
        void increase_capacity(){ //auemntar capacidade
            capacidade_ += 100;
            int *novo = new int[capacidade_];
            for (int i = 0; i < size_; i++){
                novo[i] = array[i];
            }
            delete [] array; //apagar o antigo
            array = novo; //atribuir a variável 
        }
    public:
        //Construtor e destrutor 

        Vetor_dinamico(){ //construtor
            capacidade_ = 100;
            size_ = 0;
            array = new int[capacidade_];
        }
        ~Vetor_dinamico(){ //destrutor
            delete [] array;
        }

        //Metodos, onde:
        /*unsigned int size, unsigned int capacity, double percent_occupied, bool insert_at, bool remove_at, int get_at, void clear, void push_back, void push_front, bool pop_back, bool pop_front, int back, int front, bool remove, int find, int count, int sum */

        int back(){
            return this->array[size_ - 1];
        }
        //retorna o último elemento 

        unsigned int capacity(){
            return this->capacidade_;
        }
        //retorna a capacidade 

        void clear(){
            size_ = 0; //podia ser só isso
            capacidade_ += 100;
            delete [] this->array;
            array = new int[capacidade_];
        }
        //Deleta todo o array 

        int count(int v){
            int c = 0;
            for (int i = 0; i < this->size_; i++){
                if (array[i] == v) c++;
            }
            return c;
        }
        //me diz quantas ocorrencias do valor apareceu

        int find(int v){
            int ind = -1;
            for (int i = 0; i < this->size_; i++){
                if (array[i] == v){
                    ind = i;
                    break;
                }
            }
            return ind;
        }
        //Retornar indicie 

        int front(){
            return this->array[0];
        }
        //Retorna o primeiro elemento 

        int get_at(unsigned int index){
            if (index < 0 or index > this->size_) return -1;
            return this->array[index];
        }
        //Retorna o elemento pelo indicie apontado

        bool insert_at(int index, int v){
            if (index > this->size_ or index < 0) return false;
            if (this->capacidade_ == this->size_ ) increase_capacity();
            int atual = this->array[index], proximo = this->array[index + 1], ultimo = this->array[size_ - 1];
            this->array[index] = v; 
            for (int i = index + 1; i < this->size_; i++){
                proximo = this->array[i];
                this->array[i] = atual;
                atual = proximo;
            }
            this->array[this->size_] = ultimo;
            this->size_++;
            return true;
        }
        //Insrir elemento naquele indicie 

        int operator[](int index){
            return this->array[index];
        }
        //Igual o get_at mas pode acessar com [] em vez de .nome

        double percent_occupied(){
            if (this->capacidade_ == this->size_) return 1.0;
            else return (double)(double(this->size_) / double(this->capacidade_));
        }
        //retornar um valor entre 0 e 1 do quanto foi ocupado

        bool pop_back(){
            if (this->size_ <= 0) return false;
            this->size_--;
            return true;
        }
        //Remove o último elemento do array

        bool pop_front(){
            if (this->size_ <= 0) return false;
            for (int i = 0; i < this->size_ - 1; i++){
                this->array[i] = this->array[i + 1];
            }
            this->size_--;
            return true;
        }
        //Remove o primeir elemento do array

        void push_back(int v){
            if (this->capacidade_ == this->size_) increase_capacity();
            array[size_] = v;
            size_++; 
        }
        //insere na última posição  

        void push_front(int v){
            if (this->size_ == this->capacidade_) increase_capacity();
            this->size_++;
            for (int i = this->size_ - 1; i > 0; i--){
                this->array[i] = this->array[i - 1];
            }
            this->array[0] = v;
        }
        //insere na primeira posição

        bool remove(int v){
            for (int i = 0; i < this->size_; i++){
                if (this->array[i] == v){
                    for (int j = i; j < this->size_ - 1; j++) this->array[j] = this->array[j + 1];
                    this->size_--;
                    return true;
                }
            }
            return false;
        }
        //Remove o valor do array

        bool remove_at(unsigned int index){
            if (index > this->size_ or index < 0) return false;
            this->size_--;
            for (int i = index; i < this->size_; i++) this->array[i] = this->array[i + 1];
            return true;
        } 
        //Remove o elemento localizado no indicie dado

        unsigned int size(){
            return this->size_;
        }
        //retorna o tamanho

        int sum(){
            int s = 0;
            for(int i = 0; i < this->size_;i++) s += this->array[i];
            return s;
        }
        //Retorna o acumulador dos valores do array
};

#endif