import java.time.*;

public class Main {

	public static void main(String[] args) {
		long numSteps = 1000000;
		if (args.length > 0) {
			numSteps = Integer.parseInt(args[0]);
		}

		System.out.println("Calculating pi in " + numSteps + " steps...");

		LocalDateTime start = LocalDateTime.now();

		double total = 0.0;
		for (long i = 0; i < numSteps; ++i) {
			double x = (i + 0.5) / numSteps;
			total += 4.0 / (1.0 + x * x);
		}
		total /= numSteps;

		LocalDateTime finish = LocalDateTime.now();
		double duration = Duration.between(start, finish).toNanos() / 1.0e9;

		System.out.println("==> pi = " + total);
		System.out.println("Calculation took " + duration + " seconds.");
	}

}
