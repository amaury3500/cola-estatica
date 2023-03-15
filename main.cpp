#include <iostream>
#define TAM 50

class Constancia{
    private:
        std::string NombreAlm,NombreCarr;
        int MatAprob;
        float Prom;
    public:
        Constancia(){};

        friend std::ostream & operator<<(std::ostream &O, Constancia &x){
            O<<"\nNombre Alumno: "<<x.NombreAlm<<std::endl;
            O<<"Nombre de la Carrera: "<<x.NombreCarr<<std::endl;
            O<<"Total de materias aprobadas: "<<x.MatAprob<<std::endl;
            O<<"Promedio general: "<<x.Prom<<std::endl;
            return O;
        }

        friend std::istream & operator>>(std::istream &O, Constancia &x){
            std::cout<<"\nNombre Alumno: ";
            O>>x.NombreAlm;
            std::cout<<"Nombre de la Carrera: ";
            O>>x.NombreCarr;
            std::cout<<"Total de materias aprobadas: ";
            O>>x.MatAprob;
            std::cout<<"Promedio general: ";
            O>>x.Prom;
            return O;
        }
};

template<class T>
class Cola{

    private:
        T datos[TAM];
        int ult,Frente;
        bool elimina(int);

    public:
        Cola():ult(0),Frente(0){}
        bool Vacia()const;
        bool Llena()const;
        bool Enqueue(T&);
        bool Dequeue();
        T Front()const;
};

template<class T>
bool Cola<T>::Vacia()const
{
   return Frente==ult;
}

template<class T>
bool Cola<T>::Llena()const
{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::Enqueue(T& Dato)
{
    if(!Llena()){
        datos[ult]=Dato;
        ult++;
        return true;
    }else{
        return false;
    }
}

template<class T>
bool Cola<T>::Dequeue()
{
    if(!Vacia()){
        elimina(Frente);
        return true;
    }else{
        return false;
    }
}

template<class T>
T Cola<T>::Front()const
{
    if(!Vacia()){
        return datos[Frente];
    }
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(Vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

int main()
{
        int opc,cont;
        Cola<Constancia> Micola;
        Constancia x;
        do{
            system("cls");
            std::cout<<"\n\tCONSTANCIAS DE ESTUDIO"<<std::endl<<std::endl;
            std::cout<<"1. Generar solicitud para constancia."<<std::endl;
            std::cout<<"2. Recibir constancia."<<std::endl;
            std::cout<<"3. Salir."<<std::endl<<std::endl;
            std::cout<<"Ingrese una opcion: ";
            std::cin>>opc;

            switch(opc){

            case 1: system("cls");
                    cont++;
                    if(Micola.Llena()){
                        std::cout<<"La cola esta llena."<<std::endl;
                    }else{
                        std::cout<<"\n\tUsted tiene el turno #"<<cont<<" Ingrese sus datos: "<<std::endl;
                        std::cin>>x;
                    }
                    if(Micola.Enqueue(x)){
                        std::cout<<"\n"<<std::endl;
                    }else{
                        std::cout<<"\nError!, La Cola esta llena."<<std::endl;
                    }
                    system("pause");
                    break;

            case 2: system("cls");
                    if(Micola.Vacia()){
                        std::cout<<"La cola esta vacia."<<std::endl;
                    }else{
                        std::cout<<"\n\tElaborando constancia: "<<std::endl;
                        x=Micola.Front();
                        std::cout<<x<<std::endl;
                        Micola.Dequeue();
                    }
                    system("pause");
                    break;
        }
    }while(opc!=3);
}
