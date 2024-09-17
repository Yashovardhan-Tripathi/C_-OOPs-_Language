#include <iostream>
#include <vector>
#include <memory>

// Abstract Base Class Animal
class Animal
{
public:
    // Constructor to initialize name and species
    Animal(const std::string &name, const std::string &species)
        : name(name), species(species) {}

    virtual ~Animal() = default;

    // Pure virtual functions for derived classes to implement
    virtual void makeSound() const = 0;
    virtual void move() const = 0;
    virtual void interact() const = 0;

    // Accessor methods
    std::string getName() const { return name; }
    std::string getSpecies() const { return species; }

private:
    std::string name;    // Name of the animal
    std::string species; // Species of the animal
};

// Concrete Class Lion
class Lion : public Animal
{
public:
    Lion(const std::string &name) : Animal(name, "Lion") {}

    void makeSound() const override
    {
        std::cout << getName() << " roars!" << std::endl;
    }

    void move() const override
    {
        std::cout << getName() << " prowls around." << std::endl;
    }

    void interact() const override
    {
        std::cout << getName() << " growls at the visitors." << std::endl;
    }

    void hunt() const
    {
        std::cout << getName() << " is hunting." << std::endl;
    }
};

// Concrete Class Elephant
class Elephant : public Animal
{
public:
    Elephant(const std::string &name) : Animal(name, "Elephant") {}

    void makeSound() const override
    {
        std::cout << getName() << " trumpets!" << std::endl;
    }

    void move() const override
    {
        std::cout << getName() << " lumbers along." << std::endl;
    }

    void interact() const override
    {
        std::cout << getName() << " lets visitors feed it." << std::endl;
    }

    void swingTrunk() const
    {
        std::cout << getName() << " swings its trunk." << std::endl;
    }
};

// Concrete Class Monkey
class Monkey : public Animal
{
public:
    Monkey(const std::string &name) : Animal(name, "Monkey") {}

    void makeSound() const override
    {
        std::cout << getName() << " chatters!" << std::endl;
    }

    void move() const override
    {
        std::cout << getName() << " swings from trees." << std::endl;
    }

    void interact() const override
    {
        std::cout << getName() << " plays with visitors." << std::endl;
    }

    void climb() const
    {
        std::cout << getName() << " climbs a tree." << std::endl;
    }
};

// Abstract Base Class Bird
class Bird : public Animal
{
public:
    Bird(const std::string &name) : Animal(name, "Bird") {}

    // Pure virtual function for flying
    virtual void fly() const = 0;
};

// Concrete Class Parrot
class Parrot : public Bird
{
public:
    Parrot(const std::string &name) : Bird(name) {}

    void makeSound() const override
    {
        std::cout << getName() << " squawks!" << std::endl;
    }

    void move() const override
    {
        std::cout << getName() << " flutters around." << std::endl;
    }

    void interact() const override
    {
        std::cout << getName() << " mimics sounds for visitors." << std::endl;
    }

    void fly() const override
    {
        std::cout << getName() << " flies in the aviary." << std::endl;
    }
};

// Concrete Class Eagle
class Eagle : public Bird
{
public:
    Eagle(const std::string &name) : Bird(name) {}

    void makeSound() const override
    {
        std::cout << getName() << " screeches!" << std::endl;
    }

    void move() const override
    {
        std::cout << getName() << " soars in the sky." << std::endl;
    }

    void interact() const override
    {
        std::cout << getName() << " observes visitors from a distance." << std::endl;
    }

    void fly() const override
    {
        std::cout << getName() << " flies high above the zoo." << std::endl;
    }
};

// ZooKeeper Class
class ZooKeeper
{
public:
    // Method to perform daily routine with animals
    void performDailyRoutine(const std::vector<std::shared_ptr<Animal>> &animals)
    {
        for (const auto &animal : animals)
        {
            animal->makeSound();
            animal->move();
            animal->interact();
        }
    }
};

// Visitor Class
class Visitor
{
public:
    // Method to visit zoo and interact with animals
    void visitZoo(const std::vector<std::shared_ptr<Animal>> &animals)
    {
        for (const auto &animal : animals)
        {
            animal->interact();
        }
    }
};

// Main Program
int main()
{
    // Creating instances of Lion, Elephant, Monkey, Parrot, and Eagle
    std::vector<std::shared_ptr<Animal>> animals;
    animals.push_back(std::make_shared<Lion>("Leo"));
    animals.push_back(std::make_shared<Elephant>("Ella"));
    animals.push_back(std::make_shared<Monkey>("Momo"));
    animals.push_back(std::make_shared<Parrot>("Polly"));
    animals.push_back(std::make_shared<Eagle>("Eddie"));

    // Demonstrating ZooKeeper
    ZooKeeper zookeeper;
    zookeeper.performDailyRoutine(animals);

    // Demonstrating Visitor
    Visitor visitor;
    visitor.visitZoo(animals);

    return 0;
}
