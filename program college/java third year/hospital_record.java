import java.io.*;
import java.util.Scanner;

// Custom Exception for Invalid Age
class InvalidAgeException extends Exception {
    InvalidAgeException(String message) {
        super(message);
    }
}

public class HospitalPatientManager {

    static Scanner sc = new Scanner(System.in);

    // Add patient record
    static void addPatient() {

        try {
            System.out.print("Enter Patient ID: ");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter Patient Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Patient Age: ");
            int age = sc.nextInt();
            sc.nextLine();

            // Validate age
            if (age <= 0 || age > 120) {
                throw new InvalidAgeException(
                    "Invalid age! Age must be between 1 and 120."
                );
            }

            System.out.print("Enter Disease: ");
            String disease = sc.nextLine();

            // try-with-resources
            try (FileWriter file = new FileWriter("patients.txt", true)) {

                file.write(id + "," + name + "," + age + "," + disease + "\n");

                System.out.println("Patient record added successfully.");
            }

        } catch (InvalidAgeException e) {
            System.out.println("Error: " + e.getMessage());

        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());

        } catch (Exception e) {
            System.out.println("Invalid input!");
            sc.nextLine();
        }
    }

    // Display patient records
    static void displayPatients() {

        try (BufferedReader file =
                 new BufferedReader(new FileReader("patients.txt"))) {

            String line;

            System.out.println("\n===== PATIENT RECORDS =====");

            while ((line = file.readLine()) != null) {
                String[] data = line.split(",");

                System.out.println("Patient ID : " + data[0]);
                System.out.println("Name       : " + data[1]);
                System.out.println("Age        : " + data[2]);
                System.out.println("Disease    : " + data[3]);
                System.out.println("----------------------------");
            }

        } catch (FileNotFoundException e) {
            System.out.println("No patient records found.");

        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    public static void main(String[] args) {

        int choice;

        do {
            System.out.println("\n===== HOSPITAL PATIENT MANAGER =====");
            System.out.println("1. Add Patient");
            System.out.println("2. Display Patients");
            System.out.println("3. Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    addPatient();
                    break;

                case 2:
                    displayPatients();
                    break;

                case 3:
                    System.out.println("Thank you!");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 3);

        sc.close();
    }
}