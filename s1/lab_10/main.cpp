#include <iostream>
#include <vector>

class Animal {
private:
    unsigned int m_id;
    std::string m_kind;
    std::string m_name;
    std::string m_weight;
public:
    Animal(unsigned int id, std::string kind,
           std::string name,
           std::string weight) {
        m_id = id;
        m_kind = kind;
        m_name = name;
        m_weight = weight;
    }

    std::string name() {
        return m_name;
    };

    std::string kind() {
        return m_kind;
    };

    std::string weight() {
        return m_weight;
    };
};

class Zoo {
private:
    std::string m_name;
    int m_workers;
    std::vector<Animal *> m_animals;
public:
    Zoo(std::string name, int workers) {
        m_name = name;
        m_workers = workers;
    }

    void addAnimal(Animal *animal) {
        m_animals.push_back(animal);
    }

    void listAnimals() {
        for (int i = 0; i < m_animals.size(); i++) {
            std::cout << "Kind: " << m_animals[i]->kind() << " Name: " << m_animals[i]->name() << " Weight: "
                      << m_animals[i]->weight()
                      << "kg" << std::endl;
        }
    }
};

int main() {
    Zoo zoo = Zoo("Best Zoo", 10);
    Animal *tiger = new Animal(981233, "Tiger", "Frosty", "200");
    Animal *elephant = new Animal(726234, "Elephant", "Wise", "4000");
    zoo.addAnimal(tiger);
    zoo.addAnimal(elephant);
    zoo.listAnimals();

}
