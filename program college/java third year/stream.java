import java.util.*;
import java.util.stream.*;

class Employee {
    String name;
    String department;
    double salary;

    Employee(String name, String department, double salary) {
        this.name = name;
        this.department = department;
        this.salary = salary;
    }

    public String toString() {
        return name + " - " + department + " - Rs." + salary;
    }
}

public class EmployeeDataInsights {

    public static void main(String[] args) {

        List<Employee> employees = Arrays.asList(
            new Employee("Rahul", "IT", 60000),
            new Employee("Priya", "HR", 45000),
            new Employee("Amit", "IT", 70000),
            new Employee("Sneha", "Sales", 50000),
            new Employee("Rohan", "HR", 48000),
            new Employee("Neha", "IT", 65000),
            new Employee("Kiran", "Sales", 55000)
        );

        // 1. Average salary of each department
        System.out.println("===== AVERAGE SALARY BY DEPARTMENT =====");

        employees.stream()
            .collect(Collectors.groupingBy(
                e -> e.department,
                Collectors.averagingDouble(e -> e.salary)
            ))
            .forEach((department, average) ->
                System.out.println(
                    department + " : Rs." + average
                )
            );

        // 2. Department with highest and lowest headcount
        Map<String, Long> headcount = employees.stream()
            .collect(Collectors.groupingBy(
                e -> e.department,
                Collectors.counting()
            ));

        String highestDepartment = headcount.entrySet()
            .stream()
            .max(Map.Entry.comparingByValue())
            .get()
            .getKey();

        String lowestDepartment = headcount.entrySet()
            .stream()
            .min(Map.Entry.comparingByValue())
            .get()
            .getKey();

        System.out.println("\n===== DEPARTMENT HEADCOUNT =====");

        headcount.forEach((department, count) ->
            System.out.println(department + " : " + count)
        );

        System.out.println(
            "\nHighest Headcount Department: "
            + highestDepartment
        );

        System.out.println(
            "Lowest Headcount Department: "
            + lowestDepartment
        );

        // 3. Filter employees by salary threshold
        Scanner sc = new Scanner(System.in);

        System.out.print(
            "\nEnter salary threshold: Rs."
        );

        double threshold = sc.nextDouble();

        System.out.println(
            "\n===== EMPLOYEES ABOVE SALARY THRESHOLD ====="
        );

        employees.stream()
            .filter(e -> e.salary >= threshold)
            .forEach(e -> System.out.println(e));

        sc.close();
    }
}