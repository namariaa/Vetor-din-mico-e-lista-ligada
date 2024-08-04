#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

class Linked_list{
    //Externamente é a mesma coisa que o array list só se altera em como os dados são armazenados internamente 
    //Classe em c++ sempre termina com ;
    private:
        struct Node{
            int valor;
            struct Node *next, *ant;
        };
        Node *head, *tail;                      //Armazena o primeiro e o último elemento 
        unsigned int size_;                     //Quantos elementos foram inseridos 

    public:
        //Construtor e destrutor 
        //Que devem ser da classe maior não do nó
        Linked_list(){
            this->head = nullptr;
            this->tail = nullptr;
            this->size_ = 0; 
        }
        //Contrutor 
        ~Linked_list(){
            Node *percorrer = this->head;       //Preciso do primeiro nó para assim só ir pegando o próximo 
            while (percorrer != nullptr){
                Node *elemento = percorrer; 
                percorrer = percorrer->next;
                delete elemento;
            }
        }
        //Destrutor
        
        //Metódos 
        int back(){
            return this->tail->valor;
        }
        //Retorna o último elemento da lista 

        //unsigned int capacity() --> Como não aramazena dados de forma contiua não possui capacidade 

        void clear(){
            Node *elemento = this->head;
            while (elemento != nullptr){
                Node *apagar = elemento;
                elemento = apagar->next;
                delete apagar;
            }
        }
        //Eliminar todos os elementos 

        int count(int v){
            Node *elemento = this->head; //O head == primeiro nó 
            int cont = 0;
            while (elemento != nullptr){
                if (elemento->valor == v) cont++;
                elemento = elemento->next;
            }
            return cont;
        }
        //Quantas vezes o elemento apontado repete

        int find(int v){
            int pos = 0;
            Node *elemento = this->head;
            while (elemento != nullptr){ //Pois depois do tail vai ser vazio
                if (elemento->valor == v) break;
                pos++;
                elemento = elemento->next;
            }
            if (pos == this->size_) return -1; //Pois isso significa que ele passou por todos e não foi para o break
            return pos;
        }
        //Retornar o indicie do elemento dado

        int front(){
            return this->head->valor;
        }
        //Retorna o "primeiro" elemeto, ou seja, o head

        int get_at(unsigned int index){
            Node *percorrer = this->head;
            int elemento = -1;
            unsigned int cont = 0;
            
            while (percorrer != nullptr){
                if (cont == index){
                    elemento = percorrer->valor;
                    break;
                } 
                percorrer = percorrer->next;
                cont++;
            }
            return elemento;
        }
        //Retorna o elemento no "indicie" dado

        bool insert_at(unsigned int index, int v){
            unsigned int pos = 0;
            Node *elemento = this->head;
            while (elemento != nullptr){
                if (pos == index - 1){
                    Node *no = new Node;
                    no->valor = v;
                    no->next = elemento->next;
                    elemento->next = no; //Elemento atual vai apontar para o novo nó
                    no->ant = elemento;
                    this->size_++;
                    return true;
                }
                pos++;
                elemento = elemento->next;
            }
            return false;
        }
        //Insere o valor dado no indicie indicado

        //double percent_occupied(){} --> Não possui capacidade delimitada 

        bool pop_back(){
            if (this->head == nullptr) return false;
            Node *anterior = this->tail->ant; //Mudar apenas quem é o tail 
            this->tail = anterior;
            this->size_--;
            return true;
        }
        //Remove o tail

        bool pop_front(){
            if (this->head == nullptr) return false;
            Node *anterior = this->head->next; //Mudar apenas quem é o head 
            this->head = anterior;
            this->size_--;
            return true;
        }
        //Remove o head

        void push_back(int v){
            Node *no = new Node;              
            no->valor = v;
            no->next = nullptr;
            no->ant = this->tail;           
            if (this->tail == nullptr){        
                this->head  = no;                  
            }
            else{
                this->tail->next = no;                 
            }
            this->tail = no;     
            this->size_++;
        }
        //inserir no final

        void push_front(int v){
            Node *no = new Node;               //Criando um nó novo
            no->valor = v;
            no->ant = nullptr;
            no->next = this->head;            //Não importa se é o primeiro ou o último a ser inserido tem que apontar o próximo
            if (this->head == nullptr){        //Caso seja o primeiro elemento a ser inserido 
                this->tail  = no;              //Por que não salva no head também ?      
            }
            else{
                this->head->ant = no;                 
            }
            this->head = no;     
            this->size_++;
        }
        //Insere um elemento no inicio 

        bool remove(int v){
            Node *elemento = this->head;
            while (elemento != nullptr){
                if (elemento->valor == v){
                    Node *anterior = elemento->ant;
                    anterior->next = elemento->next;
                    this->size_--;
                    return true;
                }
                elemento = elemento->next;
            }
            return false;
        }
        //Remove o valor dado

        bool remove_at(unsigned int index){
            Node *elemento = this->head;
            int pos = 0;
            while (elemento != nullptr){
                if (pos == index){
                    Node *anterior = elemento->ant;
                    anterior->next = elemento->next;
                    this->size_--;
                    return true;
                }
                pos++;
                elemento = elemento->next;
            }
            return false;
        }
        //Rmeove o valor no indicie dado

        unsigned int size(){
            return this->size_;
        }
        //Retorna quantos elementos já inserimos 

        int sum(){
            Node *elemento = this->head;
            int ac = 0;
            while (elemento != nullptr){
                ac += elemento->valor;
                elemento = elemento->next;
            } 
            return ac;
        }
        //Acumulador de todos os valores inseridos
};

#endif