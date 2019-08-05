fn merge(vec:&mut Vec<usize>, left:usize, mid: usize, right: usize) {
    println!("begin {:?} mid {} ",vec,mid);
    let mut first_half = vec[left..mid+1].to_vec();
    let mut second_half = vec[mid+1..right+1].to_vec();
    first_half.reverse();
    println!("FH {:?} ",first_half);    
    second_half.reverse();
    println!("SH {:?} ",second_half);    
    for i in left..right+1 {
        // check if first half empty remove the begin from second half to the vector else complier panics 
        if first_half.is_empty() {
            println!("In FHE {:?} ",vec[i]);
            vec[i] = second_half.pop().unwrap();
            continue; 
        }
        // likewise for the second half
        if second_half.is_empty() {
            println!("In SHE {:?} ",vec[i]);
            vec[i] = first_half.pop().unwrap();
            continue; 
        }

        if second_half.last() < first_half.last() {
            vec[i] = second_half.pop().unwrap();
            println!("In Vec Swap {:?} ",vec[i]);
        } else {
            vec[i] = first_half.pop().unwrap();
            println!("In Vec Swap {:?} ",vec[i]);
        }
    }
    println!("End {:?} ",vec);
}

pub fn merge_sort(vec: &mut Vec<usize>, left: usize, right: usize) {
    if left < right {
        let mid: usize = (left + right)/2;
        println!("{}",mid);
        merge_sort(vec, left, mid);
        merge_sort(vec, mid+1, right);
        merge(vec, left, mid, right);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn merge_sort_test_1(){
        let mut vec = vec![4,9,2,8,1];
        merge_sort(&mut vec,0,4);
        assert_eq!(vec,[1,2,4,8,9]);
    }

    #[test]    
    fn merge_sort_test_2(){
        let mut vec = vec![4,9,2,8,1,54,44,43,84];
        merge_sort(&mut vec,0,8);
        assert_eq!(vec,[1,2,4,8,9,43,44,54,84]);
    }
}