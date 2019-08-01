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

