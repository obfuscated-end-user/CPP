#include <iostream>
#include <vector>
#include <string>
class Product
{
public:
    int id;
    std::string name;
    int quantity;
    double price;
    Product(int id, std::string name, int quantity, double price) : id(id), name(name), quantity(quantity), price(price) {}
    void restock(int quantity) {
        this->quantity += quantity;
    }
    void updatePrice(double newPrice)
    {
        price = newPrice;
    }
};
class Warehouse
{
public:
    std::string name;
    std::vector<Product> inventory;
    Warehouse(std::string name) : name(name) {}
    void manageInventory()
    {
        int choice;
        do
        {
            std::cout << "\nWarehouse Menu:\n";
            std::cout << "1. Add product\n";
            std::cout << "2. Remove product\n";
            std::cout << "3. Restock product\n";
            std::cout << "4. Update product price\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                // Add product
                break;
            case 2:
                // Remove product
                break;
            case 3:
            {
                int productId;
                std::cout << "Enter product ID to restock: ";
                std::cin >> productId;
                int quantity;
                std::cout << "Enter quantity to restock: ";
                std::cin >> quantity;
                for (auto &product : inventory)
                {
                    if (product.id == productId)
                    {
                        product.restock(quantity);
                        std::cout << "Product restocked successfully.\n";
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                int productId;
                double newPrice;
                std::cout << "Enter product ID to update price: ";
                std::cin >> productId;
                std::cout << "Enter new price: ";
                std::cin >> newPrice;
                for (auto &product : inventory)
                {
                    if (product.id == productId)
                    {
                        product.updatePrice(newPrice);
                        std::cout << "Product price updated successfully.\n";
                        break;
                    }
                }
                break;
            }
            case 5:
                std::cout << "Exiting inventory management...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    }
};
class Supplier
{
public:
    int id;
    std::string name;
    std::string contactInfo;
    Supplier(int id, std::string name, std::string contactInfo)
        : id(id), name(name), contactInfo(contactInfo)
    {
    }
};
void stackMenu()
{
    class Stack
    {
    private:
        std::vector<int> elements;

    public:
        void push(int value)
        {
            elements.push_back(value);
            std::cout << "Pushed: " << value << "\n";
        }
        void pop()
        {
            if (elements.empty())
            {
                std::cout << "Stack is empty.\n";
                return;
            }
            int value = elements.back();
            elements.pop_back();
            std::cout << "Popped: " << value << "\n";
        }
        void display()
        {
            std::cout << "Stack elements: ";
            for (int element : elements)
            {
                std::cout << element << " ";
            }
            std::cout << "\n";
        }
    };
    Stack stack;
    int choice;
    do
    {
        std::cout << "\nStack Menu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Display\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int value;
            std::cout << "Enter value to push: ";
            std::cin >> value;
            stack.push(value);
            break;
        }
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 4:
            std::cout << "Exiting stack menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}
int main()
{
    int choice;
    do
    {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Stack menu\n";
        std::cout << "2. Inventory management\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            stackMenu();
            break;
        case 2:
        {
            Warehouse warehouse("Demo Warehouse");
            Product product1(1, "Laptop", 10, 1000);
            Product product2(2, "Monitor", 5, 500);
            warehouse.inventory.push_back(product1);
            warehouse.inventory.push_back(product2);
            warehouse.manageInventory();
            break;
        }
        case 3:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    return 0;
}
