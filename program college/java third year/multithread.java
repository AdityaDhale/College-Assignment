class BankAccount {

    private int balance = 1000;

    // Deposit method
    public void deposit(int amount) {
        balance = balance + amount;
        System.out.println(
            Thread.currentThread().getName()
            + " deposited Rs." + amount
            + " | Balance = Rs." + balance
        );
    }

    // Withdraw method
    public void withdraw(int amount) {

        if (balance >= amount) {
            balance = balance - amount;

            System.out.println(
                Thread.currentThread().getName()
                + " withdrew Rs." + amount
                + " | Balance = Rs." + balance
            );
        } else {
            System.out.println(
                Thread.currentThread().getName()
                + " cannot withdraw Rs." + amount
                + " | Insufficient Balance"
            );
        }
    }

    public int getBalance() {
        return balance;
    }
}

// Synchronized Bank Account
class SafeBankAccount {

    private int balance = 1000;

    public synchronized void deposit(int amount) {

        balance = balance + amount;

        System.out.println(
            Thread.currentThread().getName()
            + " deposited Rs." + amount
            + " | Balance = Rs." + balance
        );
    }

    public synchronized void withdraw(int amount) {

        if (balance >= amount) {

            balance = balance - amount;

            System.out.println(
                Thread.currentThread().getName()
                + " withdrew Rs." + amount
                + " | Balance = Rs." + balance
            );

        } else {
            System.out.println(
                Thread.currentThread().getName()
                + " cannot withdraw Rs." + amount
                + " | Insufficient Balance"
            );
        }
    }

    public int getBalance() {
        return balance;
    }
}

// Customer Thread
class Customer extends Thread {

    SafeBankAccount account;

    Customer(SafeBankAccount account, String name) {
        super(name);
        this.account = account;
    }

    public void run() {

        account.deposit(500);
        account.withdraw(300);
        account.withdraw(200);
    }
}

public class SmartBankingSimulator {

    public static void main(String[] args)
            throws InterruptedException {

        System.out.println("===== SMART BANKING SIMULATOR =====");

        SafeBankAccount account = new SafeBankAccount();

        Customer c1 = new Customer(account, "Customer-1");
        Customer c2 = new Customer(account, "Customer-2");
        Customer c3 = new Customer(account, "Customer-3");

        // Start multiple threads
        c1.start();
        c2.start();
        c3.start();

        // Wait for all threads
        c1.join();
        c2.join();
        c3.join();

        System.out.println("\nFinal Balance = Rs."
                + account.getBalance());
    }
}