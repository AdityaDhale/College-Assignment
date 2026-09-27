import java.util.*;
import java.util.concurrent.*;

class Bid {
    String bidder;
    double amount;
    String time;

    Bid(String bidder, double amount) {
        this.bidder = bidder;
        this.amount = amount;
        this.time = new Date().toString();
    }

    public String toString() {
        return bidder + " | Rs." + amount + " | " + time;
    }
}

class Auction {
    // Thread-safe collection
    private ConcurrentLinkedQueue<Bid> bids =
            new ConcurrentLinkedQueue<>();

    private double highestBid = 0;
    private String highestBidder = "";

    // Thread-safe bid processing
    public synchronized void placeBid(String bidder, double amount) {

        Bid bid = new Bid(bidder, amount);
        bids.add(bid);

        System.out.println(
            bidder + " placed bid: Rs." + amount
        );

        // Dynamically identify highest bid
        if (amount > highestBid) {
            highestBid = amount;
            highestBidder = bidder;

            System.out.println(
                "New highest bid: Rs." + highestBid
                + " by " + highestBidder
            );
        }
    }

    // Display all bids
    public void displayBids() {

        System.out.println("\n===== BID HISTORY =====");

        for (Bid bid : bids) {
            System.out.println(bid);
        }
    }

    // Display winner
    public void displayWinner() {

        System.out.println("\n===== AUCTION RESULT =====");
        System.out.println("Winner       : " + highestBidder);
        System.out.println("Highest Bid  : Rs." + highestBid);
    }
}

class Bidder implements Runnable {

    private Auction auction;
    private String name;
    private double bidAmount;

    Bidder(Auction auction, String name, double bidAmount) {
        this.auction = auction;
        this.name = name;
        this.bidAmount = bidAmount;
    }

    public void run() {
        auction.placeBid(name, bidAmount);
    }
}

public class RealTimeAuction {

    public static void main(String[] args)
            throws InterruptedException {

        Auction auction = new Auction();

        // Executor thread pool
        ExecutorService executor =
                Executors.newFixedThreadPool(4);

        System.out.println("===== REAL-TIME AUCTION =====");

        // Multiple bidders place bids in parallel
        executor.submit(
            new Bidder(auction, "Rahul", 5000)
        );

        executor.submit(
            new Bidder(auction, "Priya", 7000)
        );

        executor.submit(
            new Bidder(auction, "Amit", 6000)
        );

        executor.submit(
            new Bidder(auction, "Sneha", 9000)
        );

        // Stop accepting new tasks
        executor.shutdown();

        // Wait for all bidders
        executor.awaitTermination(
            10, TimeUnit.SECONDS
        );

        auction.displayBids();
        auction.displayWinner();
    }
}