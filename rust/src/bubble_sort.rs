pub fn bubble_sort(vec:&mut Vec<usize>,size: usize) {
    for i in 0..size {
        for j in 0..size-1{
            if vec[j] > vec[j+1] {
                vec.swap(j,j+1);
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn bubble_sort_test_1() {
        let mut array = vec![3,4,2,1,3];
        bubble_sort(&mut array, 5);
        assert!(array == [1,2,3,3,4]);
    }

    #[test]
    fn bubble_sort_test_2() {
        let mut array = vec![7,3,2,8,1,233,88,102,48,55,12,24,24,21,15];
        bubble_sort(&mut array, 15);
        assert!(array == [1, 2, 3, 7, 8, 12, 15, 21, 24, 24, 48, 55, 88, 102, 233])
    }
}