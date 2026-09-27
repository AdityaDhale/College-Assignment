import java.util.*;

class Product {
    int id;
    String name;
    int quantity;
    double price;

    Product(int id, String name, int quantity, double price) {
        this.id = id;
        this.name = name;
        this.quantity = quantity;
        this.price = price;
    }

    public String toString() {
        return "ID: " + id +
               ", Name: " + name +
               ", Quantity: " + quantity +
               ", Price: Rs." + price;
    }
}

public class InventoryManagement {

    static ArrayList<Product> products = new ArrayList<>();

    // Add product
    static void addProduct(Scanner sc) {

        System.out.print("Enter Product ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Product Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Quantity: ");
        int quantity = sc.nextInt();

        System.out.print("Enter Price: ");
        double price = sc.nextDouble();

        products.add(new Product(id, name, quantity, price));

        System.out.println("Product added successfully!");
    }

    // Display products
    static void displayProducts() {

        if (products.isEmpty()) {
            System.out.println("No products available.");
            return;
        }

        System.out.println("\n===== PRODUCT LIST =====");

        for (Product p : products) {
            System.out.println(p);
        }
    }

    // Search product by name
    static void searchProduct(Scanner sc) {

        sc.nextLine();

        System.out.print("Enter product name: ");
        String name = sc.nextLine();

        boolean found = false;

        for (Product p : products) {
            if (p.name.equalsIgnoreCase(name)) {
                System.out.println("\nProduct Found:");
                System.out.println(p);
                found = true;
            }
        }

        if (!found) {
            System.out.println("Product not found.");
        }
    }

    // Update product
    static void updateProduct(Scanner sc) {

        System.out.print("Enter Product ID to update: ");
        int id = sc.nextInt();

        for (Product p : products) {

            if (p.id == id) {

                System.out.print("Enter new quantity: ");
                p.quantity = sc.nextInt();

                System.out.print("Enter new price: ");
                p.price = sc.nextDouble();

                System.out.println("Product updated successfully!");
                return;
            }
        }

        System.out.println("Product not found.");
    }

    // Delete product
    static void deleteProduct(Scanner sc) {

        System.out.print("Enter Product ID to delete: ");
        int id = sc.nextInt();

        Iterator<Product> it = products.iterator();

        while (it.hasNext()) {

            Product p = it.next();

            if (p.id == id) {
                it.remove();
                System.out.println("Product deleted successfully!");
                return;
            }
        }

        System.out.println("Product not found.");
    }

    // Sort by price
    static void sortByPrice() {

        products.sort(
            Comparator.comparingDouble(p -> p.price)
        );

        System.out.println("Products sorted by price.");
        displayProducts();
    }

    // Sort by quantity
    static void sortByQuantity() {

        products.sort(
            Comparator.comparingInt(p -> p.quantity)
        );

        System.out.println("Products sorted by quantity.");
        displayProducts();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int choice;

        do {

            System.out.println("\n===== SMART INVENTORY MANAGEMENT =====");
            System.out.println("1. Add Product");
            System.out.println("2. Display Products");
            System.out.println("3. Search Product by Name");
            System.out.println("4. Update Product");
            System.out.println("5. Delete Product");
            System.out.println("6. Sort by Price");
            System.out.println("7. Sort by Quantity");
            System.out.println("8. Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    addProduct(sc);
                    break;

                case 2:
                    displayProducts();
                    break;

                case 3:
                    searchProduct(sc);
                    break;

                case 4:
                    updateProduct(sc);
                    break;

                case 5:
                    deleteProduct(sc);
                    break;

                case 6:
                    sortByPrice();
                    break;

                case 7:
                    sortByQuantity();
                    break;

                case 8:
                    System.out.println("Thank you!");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 8);

        sc.close();
    }
}