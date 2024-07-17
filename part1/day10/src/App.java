import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class App {

    private static class Give {
        int high;
        int low;
    }

    public static class Bot {
        int microchip_count;
        ArrayList<Give> gives;

        Bot() {
            this.microchip_count = 0;
            this.gives = new ArrayList<>();
        }

    }

    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");
        Scanner input = new Scanner(file);

        ArrayList<Bot> bots = new ArrayList<>();

        while (input.hasNextLine()) {

            String line = input.nextLine();
            boolean gets = line.contains("goes");
            boolean gives = !gets;

            if (gets) {
                Pattern re = Pattern.compile("value ([0-9]*) goes to bot ([0-9]*)");
                Matcher matcher = re.matcher(line);
                matcher.find();

                int value = Integer.parseInt(matcher.group(1));
                int bot_number = Integer.parseInt(matcher.group(2));

                System.out.printf("%d %d\n", value, bot_number);
            }

            if (gives) {
                Pattern re = Pattern
                        .compile("bot ([0-9]*) gives low to (bot|output) ([0-9]*) and high to (bot|output) ([0-9]*)");
                Matcher matcher = re.matcher(line);
                matcher.find();

                int bot_number = Integer.parseInt(matcher.group(1));
                int low_number = Integer.parseInt(matcher.group(3));
                int high_number = Integer.parseInt(matcher.group(5));

                if (matcher.group(2).equals("output")) {
                    low_number = -low_number;
                }

                if (matcher.group(4).equals("output")) {
                    high_number = -high_number;
                }

                System.out.printf("%d %d %d\n", bot_number, low_number, high_number);

            }

        }

        input.close();

    }
}
