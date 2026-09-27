import java.util.Scanner;

public class PersonalFinanceTracker {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String[] category = new String[100];
        double[] amount = new double[100];

        int n = 0;
        int choice;

        do {
            System.out.println("\n===== PERSONAL FINANCE TRACKER =====");
            System.out.println("1. Add Expense");
            System.out.println("2. Display All Expenses");
            System.out.println("3. Display Category-wise Total");
            System.out.println("4. Highest and Lowest Expense");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter expense category (Food/Travel/Shopping): ");
                    category[n] = sc.next();

                    System.out.print("Enter expense amount: ");
                    amount[n] = sc.nextDouble();

                    n++;

                    System.out.println("Expense added successfully!");
                    break;

                case 2:
                    if (n == 0) {
                        System.out.println("No expenses recorded.");
                    } else {
                        System.out.println("\n--- All Expenses ---");

                        for (int i = 0; i < n; i++) {
                            System.out.println(
                                (i + 1) + ". " + category[i]
                                + " = Rs." + amount[i]
                            );
                        }
                    }
                    break;

                case 3:
                    double food = 0;
                    double travel = 0;
                    double shopping = 0;

                    for (int i = 0; i < n; i++) {

                        if (category[i].equalsIgnoreCase("Food")) {
                            food += amount[i];
                        }
                        else if (category[i].equalsIgnoreCase("Travel")) {
                            travel += amount[i];
                        }
                        else if (category[i].equalsIgnoreCase("Shopping")) {
                            shopping += amount[i];
                        }
                    }

                    System.out.println("\n--- Category-wise Total ---");
                    System.out.println("Food     : Rs." + food);
                    System.out.println("Travel   : Rs." + travel);
                    System.out.println("Shopping : Rs." + shopping);
                    break;

                case 4:
                    if (n == 0) {
                        System.out.println("No expenses recorded.");
                    } else {

                        double highest = amount[0];
                        double lowest = amount[0];

                        int highIndex = 0;
                        int lowIndex = 0;

                        for (int i = 1; i < n; i++) {

                            if (amount[i] > highest) {
                                highest = amount[i];
                                highIndex = i;
                            }

                            if (amount[i] < lowest) {
                                lowest = amount[i];
                                lowIndex = i;
                            }
                        }

                        System.out.println("\n--- Highest and Lowest Expense ---");

                        System.out.println(
                            "Highest Expense: " +
                            category[highIndex] +
                            " = Rs." + highest
                        );

                        System.out.println(
                            "Lowest Expense: " +
                            category[lowIndex] +
                            " = Rs." + lowest
                        );
                    }
                    break;

                case 5:
                    System.out.println("Thank you for using Personal Finance Tracker!");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 5);

        sc.close();
    }
}