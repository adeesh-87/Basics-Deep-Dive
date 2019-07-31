pub fn quick_sort(array: &mut [isize], left: usize, right: usize) {
    if left < right {
        let pivot = array[right];
        let mut i = left;
        let mut j = left;

        while j < right - 1 {
            if array[j] < pivot {
                array.swap(i, j);
                i += 1;
            }
            j += 1;
        }

        if array[right] < array[i] {
            array.swap(i, right);
        }

        quick_sort(array, left, i); 
        quick_sort(array, i + 1, right);
    }
}

