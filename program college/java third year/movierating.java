import java.util.*;

class Movie {
    String title;
    String genre;
    double rating;
    int year;

    Movie(String title, String genre, double rating, int year) {
        this.title = title;
        this.genre = genre;
        this.rating = rating;
        this.year = year;
    }

    public String toString() {
        return String.format(
            "%-20s %-12s %.1f   %d",
            title, genre, rating, year
        );
    }
}

public class MovieAnalyzer {

    static ArrayList<Movie> movies = new ArrayList<>();

    // Add movies
    static void addMovies() {
        movies.add(new Movie("Inception", "Sci-Fi", 8.8, 2010));
        movies.add(new Movie("Titanic", "Romance", 7.9, 1997));
        movies.add(new Movie("Avengers", "Action", 8.0, 2012));
        movies.add(new Movie("Interstellar", "Sci-Fi", 8.7, 2014));
        movies.add(new Movie("The Dark Knight", "Action", 9.0, 2008));
        movies.add(new Movie("Notebook", "Romance", 7.8, 2004));
    }

    // Display movies
    static void displayMovies() {
        System.out.println("\n======================================================");
        System.out.printf("%-20s %-12s %-8s %s%n",
                "Title", "Genre", "Rating", "Year");
        System.out.println("======================================================");

        for (Movie m : movies) {
            System.out.println(m);
        }
    }

    // Sort by rating
    static void sortByRating() {
        movies.sort(Comparator.comparingDouble(
                (Movie m) -> m.rating
        ).reversed());

        System.out.println("\nMovies sorted by rating:");
        displayMovies();
    }

    // Sort by year
    static void sortByYear() {
        movies.sort(Comparator.comparingInt(
                (Movie m) -> m.year
        ));

        System.out.println("\nMovies sorted by year:");
        displayMovies();
    }

    // Filter by genre
    static void filterByGenre(Scanner sc) {
        sc.nextLine();

        System.out.print("Enter genre: ");
        String genre = sc.nextLine();

        System.out.println("\nMovies in " + genre + " genre:");

        boolean found = false;

        for (Movie m : movies) {
            if (m.genre.equalsIgnoreCase(genre)) {
                System.out.println(m);
                found = true;
            }
        }

        if (!found) {
            System.out.println("No movies found in this genre.");
        }
    }

    // Find highest-rated movie in each genre
    static void highestRatedByGenre() {

        HashMap<String, Movie> highest = new HashMap<>();

        for (Movie m : movies) {

            if (!highest.containsKey(m.genre) ||
                m.rating > highest.get(m.genre).rating) {

                highest.put(m.genre, m);
            }
        }

        System.out.println("\n===== HIGHEST RATED MOVIE BY GENRE =====");

        for (Map.Entry<String, Movie> entry : highest.entrySet()) {
            Movie m = entry.getValue();

            System.out.printf(
                "%-12s : %s (%.1f)%n",
                entry.getKey(), m.title, m.rating
            );
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        addMovies();

        int choice;

        do {
            System.out.println("\n===== ONLINE MOVIE RATING ANALYZER =====");
            System.out.println("1. Display Movies");
            System.out.println("2. Sort by Rating");
            System.out.println("3. Sort by Year");
            System.out.println("4. Filter by Genre");
            System.out.println("5. Highest Rated Movie by Genre");
            System.out.println("6. Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    displayMovies();
                    break;

                case 2:
                    sortByRating();
                    break;

                case 3:
                    sortByYear();
                    break;

                case 4:
                    filterByGenre(sc);
                    break;

                case 5:
                    highestRatedByGenre();
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