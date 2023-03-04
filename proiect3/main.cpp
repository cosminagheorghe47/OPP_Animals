#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Snapshot{
private:
    //nevertebrate nev;
    string nume;
public:
    Snapshot(string num){
        //nev=n;
        nume=num;
    }
    void restore( ) {
        //nev.setnume(nume);
    }

};

class nevertebrate{
protected:
    string nume;
public:
    nevertebrate(string n="necunoscut")
    {
        nume=n;
    }
    virtual void citire();
    virtual void afisare();
    nevertebrate& operator= (nevertebrate&);
    friend ostream& operator<<(ostream&, nevertebrate&);
    friend istream& operator>>(istream&, nevertebrate&);
    virtual ~nevertebrate(){cout<<"\n~nevertebrate\n";}

    Snapshot  *Save() {
    return new Snapshot(this->nume);}
    void setnume(string n)
    {
        nume=n;
    }
};
void nevertebrate::citire()
{
    cout<<"Nume nevertebrat: ";
    cin>>nume;
}
void nevertebrate::afisare()
{
    cout<<"Nume nevertebrat: "<<nume;
}
ostream& operator<<(ostream& out, nevertebrate& c)
{
    out<<"Nume nevertebrat: "<<c.nume<<endl;
    return out;
}
nevertebrate& nevertebrate::operator= (nevertebrate& ob)
{
    if (this != &ob)
    {
        nume=ob.nume;
    }
    return *this;
}
istream& operator>>(istream& in, nevertebrate& c)
{
    cout<<"Nume nevertebrat: ";
    in>>c.nume;
    return in;
}

///                       MEMENTO

/*class Snapshot{
private:
    //nevertebrate nev;
    string nume;
public:
    Snapshot(string num){
        //nev=n;
        nume=num;
    }
    void restore( nevertebrate& nev) {
        nev.setnume(nume);
    }

};*/

class vertebrate{
protected:
    int vechime;
public:
    vertebrate(int v=0)
    {
        vechime=v;
    }
    void citire();
    friend ostream& operator<<(ostream&, vertebrate&);
    friend istream& operator>>(istream&, vertebrate&);
    vertebrate& operator= (vertebrate&);
    ~vertebrate(){cout<<"\n~vertebrate\n";}
};
void vertebrate::citire()
{
    cout<<"Vechime vertebrat: ";
    cin>>vechime;
}
ostream& operator<<(ostream& out, vertebrate& c)
{
    out<<"Vechime vertebrat: "<<c.vechime<<endl;
    return out;
}
istream& operator>>(istream& in, vertebrate& c)
{
    cout<<"Vechime vertebrat: ";
    in>>c.vechime;
    return in;
}
vertebrate& vertebrate::operator= (vertebrate& ob)
{
    if (this != &ob)
    {
        vechime=ob.vechime;
    }
    return *this;
}
class mamifere:public  vertebrate
{
    string nume;
public:
    mamifere(string n="necunoscut", int vec=0):vertebrate(vec)
    {
        nume=n;
    }
    void citire();
    friend ostream& operator<<(ostream&, mamifere&);
    friend istream& operator>>(istream&, mamifere&);
    mamifere& operator=(mamifere&);
    ~mamifere(){cout<<"\n~mamifere\n";}
};
void mamifere :: citire()
{
    vertebrate::citire();
    cout<<"nume: ";
    cin>>nume;
}
ostream& operator<<(ostream& out, mamifere& c)
{
    out<<dynamic_cast<vertebrate&>(c);
    out<<"nume:  "<<c.nume<<endl;
    return out;
}
istream& operator>>(istream& in, mamifere& c)
{
    cin>>dynamic_cast<vertebrate&>(c);
    cout<<"Nume ";
    cin>>c.nume;
}
mamifere& mamifere::operator=(mamifere& ob)
{
    if (this != &ob)
    {
        vertebrate::operator=(ob);
        nume=ob.nume;
    }
    return *this;
}
class pesti:public  vertebrate
{
    string nume;
    bool rapitor;
    int lungime;
public:
    pesti(string n="necunoscut",bool r=0,int l=0, int vec=0):vertebrate(vec)
    {
        nume=n;
        rapitor=r;
        lungime=l;
    }
    void citire();
    friend ostream& operator<<(ostream&, pesti&);
    friend istream& operator>>(istream&, pesti&);
    pesti& operator=(pesti&);
    int getlungime()
    {
        return lungime;
    }
    bool getrapitor()
    {
        return rapitor;
    }
    ~pesti(){cout<<"\n~pesti\n";}
};
void pesti :: citire()
{
    vertebrate::citire();
    cout<<"nume: ";
    cin>>nume;
    cout<<"rapitor? ";
    cin>>rapitor;
    cout<<"lungime: ";
    cin>>lungime;

}
ostream& operator<<(ostream& out, pesti& c)
{
    out<<dynamic_cast<vertebrate&>(c);
    out<<"nume:  "<<c.nume<<" lungime: "<<c.lungime;
    if(c.rapitor==1)
    {
        cout<<" rapitor";
    }
    else{cout<<" nu e rapitor";}
    cout<<endl;
    return out;
}
istream& operator>>(istream& in, pesti& c)
{
    cin>>dynamic_cast<vertebrate&>(c);
    cout<<"Nume: ";
    cin>>c.nume;
    cout<<"E rapitor? ";
    cin>>c.rapitor;
    cout<<"Lungime: ";
    cin>>c.lungime;
}
pesti& pesti::operator=(pesti& ob)
{
    if (this != &ob)
    {
        vertebrate::operator=(ob);
        nume=ob.nume;
        rapitor=ob.rapitor;
        lungime=ob.lungime;
    }
    return *this;
}
class pasari:public  vertebrate
{
    string nume;
public:
    pasari(string n="necunoscut", int vec=0):vertebrate(vec)
    {
        nume=n;
    }
    void citire();
    friend ostream& operator<<(ostream&, pasari&);
    friend istream& operator>>(istream&, pasari&);
    pasari& operator=(pasari&);
    ~pasari(){cout<<"\n~pasari\n";}
};
void pasari :: citire()
{
    vertebrate::citire();
    cout<<"nume: ";
    cin>>nume;
}
ostream& operator<<(ostream& out, pasari& c)
{
    out<<dynamic_cast<vertebrate&>(c);
    out<<"nume:  "<<c.nume<<endl;
    return out;
}
istream& operator>>(istream& in, pasari& c)
{
    cin>>dynamic_cast<vertebrate&>(c);
    cout<<"Nume ";
    cin>>c.nume;
}
pasari& pasari::operator=(pasari& ob)
{
    if (this != &ob)
    {
        vertebrate::operator=(ob);
        nume=ob.nume;
    }
    return *this;
}
class reptile:public  vertebrate
{
    string nume;
public:
    reptile(string n="necunoscut", int vec=0):vertebrate(vec)
    {
        nume=n;
    }
    void citire();
    friend ostream& operator<<(ostream&, reptile&);
    friend istream& operator>>(istream&, reptile&);
    reptile& operator=(reptile&);
    ~reptile(){cout<<"\n~reptile\n";}
};
void reptile :: citire()
{
    vertebrate::citire();
    cout<<"nume: ";
    cin>>nume;
}
ostream& operator<<(ostream& out, reptile& c)
{
    out<<dynamic_cast<vertebrate&>(c);
    out<<"nume:  "<<c.nume<<endl;
    return out;
}
istream& operator>>(istream& in, reptile& c)
{
    cin>>dynamic_cast<vertebrate&>(c);
    cout<<"Nume ";
    cin>>c.nume;
}
reptile& reptile::operator=(reptile& ob)
{
    if (this != &ob)
    {
        vertebrate::operator=(ob);
        nume=ob.nume;
    }
    return *this;
}
/*class Singleton {
private:
    static Singleton* instance;
    Singleton(){
    cout << "Constructor called";
    }
public:
    static Singleton* getinstance() {
    if (instance == NULL) {
    instance = new Singleton;
    }
    return instance;
    }
};
Singleton* Singleton:: instance;*/

/*
template <class T>
class AtlasZoologic
{
    int nranimale;
    list<T*> animal;
public:
    AtlasZoologic<T> operator+=(const T &);
};
template <class T>
AtlasZoologic<T> AtlasZoologic<T>:: operator+=(const T &c)
{
    animal.push_back(c);
    nranimale++;
    return *this;
}*/

template <class T>
class AtlasZoologic
{
    static int nranimale;
    list<T*> animal;
public:
    void afisaret();
    AtlasZoologic<T> operator+=( T * );
};
template <class T>
int AtlasZoologic<T>::nranimale=0;
template <class T>
void AtlasZoologic<T>::afisaret()
{
    cout<<nranimale<<"  ";
    for(auto pp=animal.begin();pp!=animal.end();pp++)
    {
        cout<<*dynamic_cast<T*>(*pp);
    }
}
template <>
void AtlasZoologic<pesti>::afisaret()
{
    cout<<nranimale<<"  ";
    for(auto pp=animal.begin();pp!=animal.end();pp++)
    {
        cout<<*dynamic_cast<pesti*>(*pp);
    }
    int nrpesti=0;
        for(auto ppp=animal.begin();ppp!=animal.end();ppp++)
        {
            if((*dynamic_cast<pesti*>(*ppp)).getrapitor()==1 &&  (*dynamic_cast<pesti*>(*ppp)).getlungime()>=1)
            {
                nrpesti++;
            }
        }
        cout<<"Numarul de pesti rapitori mai lungi de 1 metru este "<<nrpesti<<endl;
}

template <class T>
AtlasZoologic<T> AtlasZoologic<T>:: operator+=( T *c)
{
    animal.push_back(c);
    nranimale++;

    return *this;
}

/*
template <class T>
class AtlasZoologic
{
    static int nranimale;
    list<T*> animal;
public:
    void afisaret();
    AtlasZoologic<T> operator+=( T & );
};
template <class T>
int AtlasZoologic<T>::nranimale=0;
template <class T>
void AtlasZoologic<T>::afisaret()
{
    cout<<nranimale<<"  ";
    for(auto pp=animal.begin();pp!=animal.end();pp++)
    {
        cout<<*dynamic_cast<T*>(*pp);
    }
}
template <>
void AtlasZoologic<pesti>::afisaret()
{
    cout<<nranimale<<"  ";
    for(auto pp=animal.begin();pp!=animal.end();pp++)
    {
        cout<<*dynamic_cast<pesti*>(*pp);
    }
    int nrpesti=0;
        for(auto ppp=animal.begin();ppp!=animal.end();ppp++)
        {
            if((*dynamic_cast<pesti*>(*ppp)).getrapitor()==1 &&  (*dynamic_cast<pesti*>(*ppp)).getlungime()>=1)
            {
                nrpesti++;
            }
        }
        cout<<"Numarul de pesti rapitori mai lungi de 1 metru este "<<nrpesti<<endl;
}
template <class T>
AtlasZoologic<T> AtlasZoologic<T>:: operator+=( T &c)
{
    animal.push_back(&c);
    nranimale++;
    return *this;
}

*/

class MeniuInteractiv {
public:
    static MeniuInteractiv* getInstanta(){
        if(instanta == nullptr)
        {
            instanta = new MeniuInteractiv();
        }
        return instanta;
    }
    static void deleteInstanta(){
        if(instanta != nullptr)
            delete instanta;
        instanta = nullptr;
    }
    ~MeniuInteractiv(){cout<<"\ndestruct\n";}
    void adaugaanimal();
    void afisanimal();
private:
    static MeniuInteractiv* instanta;
    AtlasZoologic<reptile> rep;
    AtlasZoologic<mamifere> mam;
    AtlasZoologic<pesti> pes;
    AtlasZoologic<pasari> pas;
    AtlasZoologic<vertebrate> ver;
    AtlasZoologic<nevertebrate> never;
};
MeniuInteractiv* MeniuInteractiv::instanta=nullptr;
void MeniuInteractiv::adaugaanimal()
{
    string tip;
    cout<<"Ce tip de animal?";
    cin>>tip;
    if(tip=="reptila")
    {
        /*reptile b;
        cin>>b;
        rep+=b;*/
        reptile *c= new reptile;
        (*c).citire();
        rep+=c;
        ver+=c;
        //rep.afisaret();
    }
    if(tip=="peste")
    {/*
        pesti p;
        cin>>p;
        pes+=p;*/
        pesti *d= new pesti;
        (*d).citire();
        pes+=d;
        ver+=d;
    }
    if(tip=="mamifer")
    {/*
        mamifere m;
        cin>>m;
        mam+=m;*/
        mamifere *e= new mamifere;
        (*e).citire();
        mam+=e;
        ver+=e;
    }
    if(tip=="pasare")
    {/*
        mamifere m;
        cin>>m;
        mam+=m;*/
        pasari *l= new pasari;
        (*l).citire();
        pas+=l;
        ver+=l;
    }
    if(tip=="nevertebrat")
    {/*
        mamifere m;
        cin>>m;
        mam+=m;*/
        nevertebrate *n= new nevertebrate;
        (*n).citire();
        never+=n;
    }
    if(tip=="vertebrat")
    {/*
        mamifere m;
        cin>>m;
        mam+=m;*/
        vertebrate *m= new vertebrate;
        (*m).citire();
        ver+=m;
    }
}
void MeniuInteractiv::afisanimal()
{
    cout<<"Pesti:\n";
    pes.afisaret();
    cout<<endl;
    cout<<"Mamifere:\n";
    mam.afisaret();
    cout<<endl;
    cout<<"Reptile:\n";
    rep.afisaret();
    cout<<endl;
    cout<<"Pasare:\n";
    pas.afisaret();
    cout<<endl;
    cout<<"Nevertabrate:\n";
    never.afisaret();
    cout<<endl;
    cout<<"Vertabrate:\n";
    ver.afisaret();
    cout<<endl;
}
int main()
{/*
    reptile b("la la la",2);
    reptile c("nanana",9);
    mamifere d("LALA",5);
    mamifere e("NANA",6);
    pesti f("ttt",1,3,4);
    pesti g("tttt",1,7,4);
    pesti h("ttttt",1,0,4);
    AtlasZoologic<reptile> a;
    AtlasZoologic<mamifere> aa;
    AtlasZoologic<pesti> aaa;
    a+=b;
    a+=c;
    aa+=d;
    aa+=e;
    aaa+=f;
    aaa+=g;
    aaa+=h;
    a.afisaret();
    aa.afisaret();
    aaa.afisaret();
    /*AtlasZoologic<reptile> a;
    reptile *c= new reptile;
    (*c).citire();
    a+=c;
    a.afisaret();*/

    int optiune;
    MeniuInteractiv* m = m->getInstanta();
    //MeniuInteractiv* m ;
    cout << "1.Adauga animal\n";
    cout << "2.Afis animal\n";
    cin>>optiune;
    while(optiune!=0)
    {
        if(optiune==1)
        {
             m->adaugaanimal();
        }
        if(optiune==2)
        {
             m->afisanimal();
        }
        cout << "1.Adauga animal\n";
        cout << "2.Afis animal\n";
        cin>>optiune;
    }
    m->deleteInstanta();
    return 0;
}
