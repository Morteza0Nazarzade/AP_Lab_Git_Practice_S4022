#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:

	Person(const string& name) {
		this->name = name;

	}
	Person(const string n, const int a) { name = n; age = a; }
	Person() {}
	string& getName() { return name; }
	const string& getName()const { return name; }
	bool operator <(const Person p)
	{
		if (this->name < p.name)
			return true;
		else
			return false;
	}
	bool operator ==(const Person p)
	{
		if (this->age == p.age)
			return true;
		else
			return false;
	}
	friend class Group;
private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getName();
	return out;
}


class Group {
public:

	Group(int max_lenght) {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(const Group& g)
	{
		this->cap = g.cap;
		this->size = g.size;
		this->members = new Person[this->cap];
		for (int i = 0; i < g.size; i++)
			this->members[i] = g.members[i];
	}
	void add(Person p) {
		if (this->size == this->cap) {
			return;
		}
		this->members[size] = p;
		this->size++;
	}
	void deletePerson(string name) {
		int i;
		for (i = 0; i < size; i++) {
			if (members[i].name == name)
				break;

		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}
	Group operator +(const Group g)
	{
		Group result(this->cap + g.cap);
		result.size = this->size + g.size;
		for (int i = 0; i < this->size; i++)
			result.members[i] = this->members[i];
		for (int i = 0; i < g.size; i++)
			result.members[i + this->size] = g.members[i];
		return result;
	}
	Group operator +=(const Group g)
	{
		Group temp = *this;
		this->cap += g.cap;
		this->size += g.size;
		delete[] this->members;
		this->members = new Person[this->cap];
		for (int i = 0; i < temp.size; i++)
			this->members[i] = temp.members[i];
		for (int i = 0; i < g.size; i++)
			this->members[i + temp.size] = g.members[i];
		return *this;
	}
	Group operator =(const Group g)
	{
		this->cap = g.cap;
		this->size = g.size;
		delete[] this->members;
		this->members = new Person[this->cap];
		for (int i = 0; i < this->size; i++)
			this->members[i] = g.members[i];
		return *this;
	}
	friend bool isGroupFull(Group g);
	friend ostream& operator<<(ostream& out, const Group& g);
	~Group() {
		delete[] members;
	}

private:
	int size;
	int cap;
	Person* members;

};

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}

ostream& operator<<(ostream& out, const Group& g) {
	for (int i = 0; i < g.size; i++)
		out << g.members[i] << "\t";
	return out;
}


int main()
{

	Person p1("somename");
	//had to change it from <p1> to <p2> to pervent redefinition
	Person p2("somename2");
	cout << p1 << p2;


	Group g1(5);
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	cout << isGroupFull(g1) << endl;


	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1 << endl;//should cout every person in it with a \t as the separator
	cout << g2 << endl;


	g3 = g1;
	cout << g3;
	g3 = g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;


	Person persons[10];
	Person Erfan("Erfan", 20);
	persons[1] = Erfan;
	for (int i = 0; i < 10; i++) {
		persons[i].getName() = to_string(rand() % 100);
	}
	sort(persons, persons + 10);//what operator should be overloaded for sort? :)

	for (int i = 0; i < 10; i++) {
		cout << persons[i].getName() << ' ';
	}

	cout << *find(persons, persons + 10, Erfan);




}
