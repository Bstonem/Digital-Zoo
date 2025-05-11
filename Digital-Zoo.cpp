#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------- Diet Class ----------
// Represents the type of diet and its description
class Diet {
private:
    string type;

public:
    Diet(string type) : type(type) {}

    string getType() const {
        return type;
    }

    string getDescription() const {
        if (type == "Herbivore")
            return "eats grasses, plants, and shrubs.";
        else if (type == "Carnivore")
            return "eats meat.";
        else
            return "has an unknown diet.";
    }
};

// ---------- Habitat Class ----------
// Represents the type of habitat and its description
class Habitat {
private:
    string type;

public:
    Habitat(string type) : type(type) {}

    string getType() const {
        return type;
    }

    string getDescription() const {
        if (type == "Grassland")
            return "lives in wide open grassy plains.";
        else if (type == "Tropical Forest")
            return "lives in dense tropical forests.";
        else
            return "has an unspecified habitat.";
    }
};

// ---------- Base Animal Class ----------
class Animal {
public:
    string name;
    string species;
    int age;
    Habitat habitat;  // Composition: has-a Habitat
    Diet diet;        // Composition: has-a Diet
    string sex;

    // Constructor with diet and habitat types
    Animal(string name, string species, int age, string habitatType, string dietType, string sex)
        : name(name), species(species), age(age), habitat(habitatType), diet(dietType), sex(sex) {}

    virtual ~Animal() {}

    // Virtual function for polymorphic behavior
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }

    // Displays animal's information
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Habitat: " << habitat.getType() << endl;
        cout << "Age: " << age << endl;
        cout << "Diet: " << diet.getType() << endl;
        cout << "Sex: " << sex << endl;
    }

    // Describes what the animal eats
    void eat() {
        cout << name << " " << diet.getDescription() << endl;
    }

    // Describes the animal's habitat
    void describeHabitat() {
        cout << name << " " << habitat.getDescription() << endl;
    }
};

// ---------- Rhinoceros Subclass ----------
class Rhinoceros : public Animal {
public:
    Rhinoceros(string name, string species, int age, string habitat, string diet, string sex)
        : Animal(name, species, age, habitat, diet, sex) {}

    void makeSound() override {
        cout << "Makes grunting sounds." << endl;
    }
};

// ---------- KomodoDragon Subclass ----------
class KomodoDragon : public Animal {
public:
    KomodoDragon(string name, string species, int age, string habitat, string diet, string sex)
        : Animal(name, species, age, habitat, diet, sex) {}

    void makeSound() override {
        cout << "Makes hissing sounds." << endl;
    }
};

// ---------- Main Function ----------
int main() {
    // Create a vector to hold pointers to Animal objects
    // This allows for polymorphic behavior
    vector<Animal*> zooAnimals;

    // Add animals to the zoo
    zooAnimals.push_back(new Rhinoceros("Ragnar", "White Rhinoceros", 11, "Grassland", "Herbivore", "Male"));
    zooAnimals.push_back(new Rhinoceros("Lagertha", "White Rhinoceros", 9, "Grassland", "Herbivore", "Female"));
    zooAnimals.push_back(new KomodoDragon("Bjorn", "Komodo Dragon", 3, "Tropical Forest", "Carnivore", "Male"));
    zooAnimals.push_back(new KomodoDragon("Torvi", "Komodo Dragon", 5, "Tropical Forest", "Carnivore", "Female"));

    // Loop through each animal and display its behavior
    for (Animal* animal : zooAnimals) {
        animal->displayInfo();
        animal->makeSound();
        animal->eat();
        animal->describeHabitat();
        cout << endl;
    }

    // Clean up allocated memory
    for (Animal* animal : zooAnimals) {
        delete animal;
    }

    return 0;
}
