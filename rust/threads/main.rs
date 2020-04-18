// Calculate the value of pi using threads in Rust

use std::env;
use std::thread;
use std::time::SystemTime;


fn thread_function(begin: usize, end: usize, num_steps: usize) -> f64 {
    let mut subtotal = 0.0;
    for i in begin..end {
        let x = (i as f64 + 0.5) / num_steps as f64;
        subtotal += 4.0 / (1.0 + x * x);
    }
    subtotal / num_steps as f64
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let num_threads: usize = if args.len() > 2 { args[2].parse().unwrap() } else { 4 };
    let num_steps: usize = if args.len() > 1 { args[1].parse().unwrap() } else { 1000000 };

    println!("Calculating pi using {} threads in {} steps...", num_threads, num_steps);

    let start = SystemTime::now();

    let mut threads = vec![];
    for i in 0..num_threads {
        let begin = i * num_steps / num_threads;
        let end = (i + 1) * num_steps / num_threads;
        threads.push(thread::spawn(move || {
            thread_function(begin, end, num_steps)
        }));
    }

    let mut total = 0.0;
    for thread in threads {
        total += thread.join().unwrap();
    }

    let duration = start.elapsed().unwrap();

    println!("==> pi = {}", total);
    println!("Calculation took {} seconds.", duration.as_micros() as f64 / 1000000.0);
}
