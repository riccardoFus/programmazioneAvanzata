/*
    Modella queste relazioni. Costruisci le classi con tutti i costruttori, distruttori e metodi
    che ritieni opportuni. A questo punto:
        * Crea un metodo per la stampa di ogni classe tramite cout (le directory devono stampare le liste dei file)
        * Crea nel main un vettore dirs di Directory e inserisci tre directories di nome "DirA", "DirB" e "DirC"
        * In ogni Directory inserisci tre File la cui dimensione deve stare nel range [-500, 500]
        * Lancia un'eccezione se la dimensione generata è negativa, ma assicurati che il programma non si blocchi; stampa
        * stampa nel main il vettore ottenuto
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>
#define MAX 500
#define MIN -500
using namespace std;

int random(){
    return rand() % (MAX - MIN + 1) + MIN;
}

class File{
    private:
        string nome;
        int dimensione;
    public:
        File(string nome, int dimensione){
            this->nome = nome;
            if(dimensione >= 0){
                this->dimensione = dimensione;
            }else{
                throw "Dimensione negativa.";
            }
        }
        File(File&& f){
            this->nome = f.nome;
            f.nome = "";
            this->dimensione = f.dimensione;
            f.dimensione = 0;
        }
        ~File(){
            cout << "Distrutto File " << this->nome << endl;
        }
        friend ostream& operator << (ostream& os, const File& f);
};

ostream& operator << (ostream& os, const File& f){
    return os << "File " << f.nome << " di dimensione " << f.dimensione;
}

class Directory{
    private:
        string nome;
        int dimensione;
        list<File*> files;
    public:
        Directory(string nome){
            this->nome = nome;
            this->dimensione = 0;
        }
        ~Directory(){
            cout << "Distrutta Directory " << this->nome << endl;
            for(auto& file : this->files){
                delete file;
            }
        }
        void add_file(string nome, int dim){
            try{
                files.push_back(new File(nome, dim));
                this->dimensione += dim;
            }catch (const char* messaggio){
                cout << messaggio << endl;
                files.push_back(new File(nome, -dim));
                this->dimensione += -dim;
            }
        }
        friend ostream& operator << (ostream& os, const Directory& dir);
};

ostream& operator << (ostream& os, const Directory& dir){
    os << "Directory " << dir.nome << " " << dir.dimensione << endl;
    for(const auto& file : dir.files){
        os << "\t" << *file << endl;
    }
    return os;
}

int main(int argc, char ** argv){
    srand(time(NULL));
    
    vector<Directory> dirs;
    dirs.push_back(Directory("DirA"));
    dirs.push_back(Directory("DirB"));
    dirs.push_back(Directory("DirC"));

    dirs[0].add_file("file1.txt", random());
    dirs[0].add_file("file2.txt", random());
    dirs[0].add_file("file3.txt", random());
    dirs[1].add_file("file4.txt", random());
    dirs[1].add_file("file5.txt", random());
    dirs[1].add_file("file6.txt", random());
    dirs[2].add_file("file7.txt", random());
    dirs[2].add_file("file8.txt", random());
    dirs[2].add_file("file9.txt", random());

    for(const auto& dir : dirs){
        cout << dir << endl;
    }
    return 0;
}