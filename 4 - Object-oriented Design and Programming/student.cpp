#include <iostream>
#include <string>
using namespace std;

enum class Discipline { ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE };
string dName[] = {"Archeology", "Biology", "Computer Science"};

class Person
{
    protected:
        string name;
    public:
        Person()
        {
            name = "";
        }

        Person(const string& pName)
        {
            name = pName;
        }

        void setName(const string& pName)
        {
            name = pName;
        }

        string getName() const
        {
            return name;
        }
};

class Faculty : public Person
{
    private:
        Discipline department;

    public:
        Faculty(const string& fname, Discipline d)
        {
            name = fname;
            department = d;
        }

        void setDepartment(Discipline d)
        {
            department = d;
        }

        Discipline getDepartment() const
        {
            return department;
        }
};

class Student : public Person
{
    private:
        Discipline major;
        Person* advisor;

    public:
        Student(const string& sname, Discipline d, Person* adv)
        {
            name = sname;
            major = d;
            advisor = adv;
        }

        void setMajor(Discipline d)
        {
            major = d;
        }

        Discipline getMajor() const
        {
            return major;
        }

        void setAdvisor(Person* p)
        {
            advisor = p;
        }

        Person* getAdvisor() const
        {
            return advisor;
        }
};

int main()
{
    Faculty* prof = new Faculty("Indiana Jones", Discipline::ARCHEOLOGY);
    Student* st = new Student("Sean Bolster", Discipline::ARCHEOLOGY, prof);
    
    cout << "Professor " << prof->getName() << " teaches "
         << dName[static_cast<int>(prof->getDepartment())]
         << "." << endl;

    Person* pAdvisor = st->getAdvisor();
    
    cout << st->getName() << "\'s advisor is "
         << pAdvisor->getName() << ".";
    cout << endl;

    delete prof;
    prof = nullptr;

    delete st;
    st = nullptr;

    return 0;
}


/*
Sample Output: 

Professor Indiana Jones teaches Archeology.
Sean Bolster's advisor is Indiana Jones.
*/