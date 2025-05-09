#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define the Animal class
class Animal {
public:
    string name;
    string species;
    int age;
    string habitat;
    string diet;
    string sex;

    // Constructor to initialize the Animal object
    Animal(string name, string species, int age, string habitat, string diet, string sex) { 
        this->name = name;
        this->species = species;
        this->age = age;
        this->habitat = habitat;
        this->diet = diet;
        this->sex = sex;
        }
    
    // Method to display animal information
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Habitat: " << habitat << endl;
        cout << "Age: " << age << endl;
        cout << "Diet: " << diet << endl; 
        cout << "Sex: " << sex << endl;
    }

    // Method to make animal sound
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }

    // Method to have the animal eat
    void eat() {
        cout << name << " is eating " << diet << endl;
    }
};

// Define the Rhinoceros class as a subclass of Animal
class Rhinoceros : public Animal {
public:
    // Constructor to initialize the Rhinoceros object
    Rhinoceros(string name, string species, int age, string habitat, string diet, string sex) 
        : Animal(name, "Rhinoceros", age, habitat, diet, sex) {}

    // Override the makeSound method
    void makeSound() override {
        cout << "Grunts" << endl;
    }
};

// Definte the Komodo Dragon class as a subclass of Animal
class KomodoDragon : public Animal {
public:
    // Constructor to initialize the KomodoDragon object
    KomodoDragon(string name, string species, int age, string habitat, string diet, string sex) 
        : Animal(name, "Komodo Dragon", age, habitat, diet, sex) {}

    // Override the makeSound method
    void makeSound() override {
        cout << "Hisses" << endl;
    }
    };


// Beginning of the main function
int main() {
    // Create a vector to store animals
    vector<Animal*> zooAnimals;

    // Docket of animals in the zoo
    zooAnimals.push_back(new Rhinoceros("Ragnar", "White Rhinoceros", 11, "Grassland", "Grasses and shrubs", "Male"));
    zooAnimals.push_back(new Rhinoceros("Lagertha", "White Rhinoceros", 9,"Grassland", "Grasses and shrubs", "Female"));
    zooAnimals.push_back(new KomodoDragon("Gomez", "Komodo Dragon", 3, "Tropical Forest", "Meat", "Male"));
    zooAnimals.push_back(new KomodoDragon("Morticia", "Komodo Dragon", 5, "Tropical Forest", "Meat", "Female"));

    // Display information about each animal in the zoo
    for (Animal* animal : zooAnimals) {
        animal->displayInfo();
        animal->makeSound();
        animal->eat();
        cout << endl;
    }

    // Clean up memory
    for (Animal* animal : zooAnimals) {
        delete animal;
    }

    return 0;
}