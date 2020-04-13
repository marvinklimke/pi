// Calculate the value of pi using a sequential approach in Rust

use std::env;
use std::time::SystemTime;


fn main() {
    let args: Vec<String> = env::args().collect();

    let num_steps : u64 = if args.len() > 1 { args[1].parse().unwrap() } else { 1000000 };

    println!("Calculating pi in {} steps...", num_steps);

    let start = SystemTime::now();

    let mut total = 0.0;
    for i in 0..num_steps {
        let x = (i as f64 + 0.5) / num_steps as f64;
        total += 4.0 / (1.0 + x * x);
    }
    total /= num_steps as f64;

    let duration = start.elapsed().unwrap();

    println!("==> pi = {}", total);
    println!("Calculation took {} seconds.", duration.as_micros() as f64 / 1000000.0);
}
