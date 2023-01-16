#include<iostream>
#include <bits/stdc++.h>


template<typename Iterator, typename Predicate> Iterator mymax(
		Iterator first, Iterator last, Predicate pred) {
	
    Iterator max_iter = first;

    while (first != last) {
        if (pred(*first, *max_iter))
            *max_iter = *first;
        first++;
    }
    return max_iter;
}

int gt_int(int first, int second) {
    if (first > second)
        return 1;
    return 0;
}


int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
int main(){
    const int* maxint = mymax( &arr_int[0], &arr_int[sizeof(arr_int)/sizeof(*arr_int)], gt_int);
    std::cout << *maxint << "\n";

    std::vector<int> v{ 1, 3, 5, 7, 4, 6, 9, 2, 0 };
    const int maxint_vector = *mymax(v.begin(), v.end(), gt_int);
    std::cout << maxint_vector << "\n";

    // std::set<int> s = {1, 3, 5, 7, 4, 6, 9, 2, 0};
    // const int maxint_set = *mymax(s.begin(), s.end(), gt_int);
    // std::cout << maxint_set << "\n";
}