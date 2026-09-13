#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    int productId;
    string productName;
    double price;
    int stockQuantity;

    // Static variable
    static int totalProducts;

public:
    // Constructor
    Product(int id, string name, double p, int stock)
        : productId(id),
          productName(name),
          price(p),
          stockQuantity(stock)
    {
        totalProducts++;
    }

    // Inline functions
    inline int getId() const
    {
        return productId;
    }

    inline string getName() const
    {
        return productName;
    }

    inline double getPrice() const
    {
        return price;
    }

    // Update stock quantity
    void updateStock(int quantity)
    {
        stockQuantity = quantity;
    }

    // Static function
    static int getTotalProducts()
    {
        return totalProducts;
    }

    // Display product details
    void display() const
    {
        cout << "ID: " << productId
             << " | Product: " << productName
             << " | Price: Rs. " << price
             << " | Stock: " << stockQuantity
             << endl;
    }

    // Destructor
    ~Product()
    {
        totalProducts--;
    }
};

// Initialize static variable
int Product::totalProducts = 0;

int main()
{
    // Create three product objects
    Product p1(1001, "Laptop", 55000, 15);
    Product p2(1002, "Mouse", 450, 50);
    Product p3(1003, "Keyboard", 1200, 30);

    // Display product catalog
    cout << "=== Product Catalog ===" << endl;

    p1.display();
    p2.display();
    p3.display();

    // Display total number of products
    cout << "\nTotal Products in Catalog: "
         << Product::getTotalProducts()
         << endl;

    return 0;
}