use std::io;
mod quick_sort;

fn main() {
    let mut vec_value: Vec<u32> = Vec::new();
    let mut buf = String::new(); 
    println!("Enter no of variables for Sort ");
    io::stdin().read_line(&mut buf).expect("Failed to Read line");
    let n: u32 = buf.trim().parse::<u32>().expect("Invalid Input");
    for _i in 0..n {
        let mut buf = String::new();
        io::stdin().read_line(&mut buf).expect("Failed to Read line");
        let num: u32 = buf.trim().parse::<u32>().expect("Invalid Input");
        vec_value.push(num);
    } 
    quick_sort::quick_sort(&mut vec_value,0,(n - 1) as usize);

    for v in vec_value.iter() {
        println!("{}",v )
    }
}
