mod quick_sort;

fn main() {
    let mut array = [7,3,2,8,1,233,88,102,48,55,12,24,24,21,15];
    quick_sort::quick_sort(&mut array,0,14);
    println!("{:?}",array)
}
