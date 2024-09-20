/*
 * CEMC Problem of the Week - Problem E:
 * Fraction Distraction

Determine the number of solutions to the equation
 A       B       A+B
---  -  ---  =  -----
 B       A       AB

where A and B are both integers, −9 ≤ A ≤ 9, and −9 ≤ B ≤ 9.

*/

#include <iostream>

int main()
{
    std::cout << "Problem E Fraction Distraction:" << std::endl;
    int count = 0;

/*

Naive solution: Brute force all possible values of A and B, O(n²):

## Intuition:

 A²     B²     A+B
---- - ---- = -----
 AB     AB     AB

therefore:

A² - B² = A+B,

*/
    for (int A = -9; A <= 9; A++)
    {
        for (int B = -9; B <= 9; B++)
        {
            if (A*A - B*B == A+B)
            {
                count++;
            }
        }
    }
    std::cout << "Number of solutions: " << count << std::endl;

/*
# Mathematical solution, O(1):

## Intuition:
A ∈ [A_min, A_max], B ∈ [B_min, B_max], A, B ∈ ℤ, A ≠ 0, B ≠ 0.

let the set α be the set of all valid values of A.


 A²     B²     A+B
---- - ---- = -----
 AB     AB     AB

therefore:

A² - B² = A+B,

(A+B)(A-B) = A+B,


## Where A+B ≠ 0:

A-B = 1,

B = A-1.

B < A, therefore:
the maximum is going to be where A is at its maximum, and the minimum is going to be where B is at its minimum.

therefore for the range of valid solutions where A+B ≠ 0:

α_min = max(B_min+1, A_min), α_max = min(B_max+1, A_max).


## Where A+B == 0:
B = -A,

A_min ≤ A ≤ A_max and B_min ≤ B ≤ B_max, so:

B_min ≤ -A ≤ B_max,

A_min ≤ A ≤ A_max AND -B_max ≤ A ≤ -B_min,

therefore for the range of valid solutions where A+B = 0:
α_min = max(A_min, -B_max), α_max = min(A_max, -B_min).
*/
    const int A_min = -9, A_max = 9;
    const int B_min = -9, B_max = 9;

    // A+B ≠ 0:
    const int α_min_1 = std::max(B_min+1, A_min);
    const int α_max_1 = std::min(B_max+1, A_max);

    // A+B == 0:
    const int α_min_2 = std::max(A_min, -B_max);
    const int α_max_2 = std::min(A_max, -B_min);

    std::cout << "Number of solutions: " << α_max_1 - α_min_1 + 1 + α_max_2 - α_min_2 + 1 << std::endl;

    return 0;
}
