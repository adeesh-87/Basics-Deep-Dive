mod quick_sort;

fn main() {
    let mut array = [7,3,2,8,1,48,55,12,24,15,24,21,15];
    quick_sort::quick_sort(&mut array,0,12);
    println!("{:?}",array)
}
