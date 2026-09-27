import java.util.Scanner;

// Rentable Interface
interface Rentable {
    double calculateRent(int hours);
}

// Base class
class Vehicle {
    String vehicleNumber;
    String brand;

    Vehicle(String vehicleNumber, String brand) {
        this.vehicleNumber = vehicleNumber;
        this.brand = brand;
    }
}

// Car class
class Car extends Vehicle implements Rentable {

    Car(String vehicleNumber, String brand) {
        super(vehicleNumber, brand);
    }

    public double calculateRent(int hours) {
        return hours * 200;
    }
}

// Bike class
class Bike extends Vehicle implements Rentable {

    Bike(String vehicleNumber, String brand) {
        super(vehicleNumber, brand);
    }

    public double calculateRent(int hours) {
        return hours * 100;
    }
}

// Truck class
class Truck extends Vehicle implements Rentable {

    Truck(String vehicleNumber, String brand) {
        super(vehicleNumber, brand);
    }

    public double calculateRent(int hours) {
        return hours * 500;
    }
}

// Main class
public class VehicleRentalSystem {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("===== VEHICLE RENTAL SYSTEM =====");

        System.out.println("1. Car");
        System.out.println("2. Bike");
        System.out.println("3. Truck");

        System.out.print("Enter vehicle type: ");
        int choice = sc.nextInt();

        sc.nextLine();

        System.out.print("Enter vehicle number: ");
        String number = sc.nextLine();

        System.out.print("Enter vehicle brand: ");
        String brand = sc.nextLine();

        System.out.print("Enter rental hours: ");
        int hours = sc.nextInt();

        Vehicle vehicle;
        Rentable rentable;

        if (choice == 1) {
            vehicle = new Car(number, brand);
            rentable = (Car) vehicle;
        }
        else if (choice == 2) {
            vehicle = new Bike(number, brand);
            rentable = (Bike) vehicle;
        }
        else if (choice == 3) {
            vehicle = new Truck(number, brand);
            rentable = (Truck) vehicle;
        }
        else {
            System.out.println("Invalid vehicle type!");
            sc.close();
            return;
        }

        double rent = rentable.calculateRent(hours);

        // Invoice
        System.out.println("\n========== RENTAL INVOICE ==========");
        System.out.println("Vehicle Number : " + vehicle.vehicleNumber);
        System.out.println("Brand          : " + vehicle.brand);
        System.out.println("Rental Hours   : " + hours);
        System.out.println("Total Rent     : Rs." + rent);
        System.out.println("====================================");

        sc.close();
    }
}