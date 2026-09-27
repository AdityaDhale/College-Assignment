import java.util.Scanner;

class Student {
    String name;
    int[] marks;
    int total;
    double average;
    char grade;

    Student(String name, int subjects) {
        this.name = name;
        marks = new int[subjects];
    }

    // Calculate total, average and grade
    void calculate(int subjects) {
        total = 0;

        for (int i = 0; i < subjects; i++) {
            total += marks[i];
        }

        average = (double) total / subjects;

        if (average >= 90)
            grade = 'A';
        else if (average >= 75)
            grade = 'B';
        else if (average >= 60)
            grade = 'C';
        else if (average >= 40)
            grade = 'D';
        else
            grade = 'F';
    }

    void display() {
        System.out.println(
            name + "\t" + total + "\t" +
            String.format("%.2f", average) + "\t" + grade
        );
    }
}

public class StudentGradeManagement {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = sc.nextInt();

        System.out.print("Enter number of subjects: ");
        int subjects = sc.nextInt();

        Student[] students = new Student[n];

        // Accept student details
        for (int i = 0; i < n; i++) {

            sc.nextLine();

            System.out.println("\nEnter details for Student " + (i + 1));

            System.out.print("Enter name: ");
            String name = sc.nextLine();

            students[i] = new Student(name, subjects);

            for (int j = 0; j < subjects; j++) {
                System.out.print("Enter marks for Subject "
                        + (j + 1) + ": ");
                students[i].marks[j] = sc.nextInt();
            }

            students[i].calculate(subjects);
        }

        // Sort students according to average marks
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                if (students[i].average < students[j].average) {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }

        // Display ranked list
        System.out.println("\n===== STUDENT RANK LIST =====");
        System.out.println("Rank\tName\tTotal\tAverage\tGrade");

        for (int i = 0; i < n; i++) {
            System.out.print((i + 1) + "\t");
            students[i].display();
        }

        sc.close();
    }
}