pub fn quick_sort(array: &mut [isize], left: usize, right: usize) {
	if left < right {
		let pivot = array[right];
		let mut i = left;
		let mut j = left;
		while j < right {
			if array[j] < pivot {
				array.swap(i, j);
				i += 1;
			}
			j += 1;
		}
		array.swap(i, right);
		if i > 0 {
			quick_sort(array, left, i - 1);
		}
		if i < right {
			quick_sort(array, i + 1, right);
		}
	}
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn quick_sort_test_1() {
        let mut array = [3,4,2,1,3];
        quick_sort(&mut array,0,4);
        assert!(array==[1,2,3,3,4]);
    }

    #[test]
    fn quick_sort_test_2() {
        let mut array1 = [7,3,2,8,1,233,88,102,48,55,12,24,24,21,15];
        quick_sort(&mut array1,0,14);
        assert!(array1 ==[1, 2, 3, 7, 8, 12, 15, 21, 24, 24, 48, 55, 88, 102, 233])
    }
}