import java.util.Scanner;

public class StudentMarksAnalyzer {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] marks = new int[100];
        int n = 0;
        int choice;

        do {
            System.out.println("\n===== STUDENT MARKS ANALYZER =====");
            System.out.println("1. Enter Marks");
            System.out.println("2. Display Marks");
            System.out.println("3. Calculate Total and Average");
            System.out.println("4. Find Highest and Lowest Marks");
            System.out.println("5. Display Pass/Fail");
            System.out.println("6. Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter number of subjects: ");
                    n = sc.nextInt();

                    for (int i = 0; i < n; i++) {
                        System.out.print("Enter marks for Subject "
                                + (i + 1) + ": ");
                        marks[i] = sc.nextInt();
                    }

                    System.out.println("Marks entered successfully!");
                    break;

                case 2:
                    if (n == 0) {
                        System.out.println("No marks entered.");
                    } else {
                        System.out.println("\n--- Student Marks ---");

                        for (int i = 0; i < n; i++) {
                            System.out.println("Subject "
                                    + (i + 1) + ": " + marks[i]);
                        }
                    }
                    break;

                case 3:
                    if (n == 0) {
                        System.out.println("No marks entered.");
                    } else {
                        int total = 0;

                        for (int i = 0; i < n; i++) {
                            total += marks[i];
                        }

                        double average = (double) total / n;

                        System.out.println("Total Marks = " + total);
                        System.out.println("Average Marks = " + average);
                    }
                    break;

                case 4:
                    if (n == 0) {
                        System.out.println("No marks entered.");
                    } else {
                        int highest = marks[0];
                        int lowest = marks[0];

                        for (int i = 1; i < n; i++) {

                            if (marks[i] > highest) {
                                highest = marks[i];
                            }

                            if (marks[i] < lowest) {
                                lowest = marks[i];
                            }
                        }

                        System.out.println("Highest Marks = " + highest);
                        System.out.println("Lowest Marks = " + lowest);
                    }
                    break;

                case 5:
                    if (n == 0) {
                        System.out.println("No marks entered.");
                    } else {
                        for (int i = 0; i < n; i++) {

                            if (marks[i] >= 40) {
                                System.out.println("Subject "
                                        + (i + 1) + ": PASS");
                            } else {
                                System.out.println("Subject "
                                        + (i + 1) + ": FAIL");
                            }
                        }
                    }
                    break;

                case 6:
                    System.out.println("Thank you!");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 6);

        sc.close();
    }
}