/*
 * CEMC Problem of the Week - Problem E:
 * Fraction Distraction

Determine the number of solutions to the equation
 A       B       A+B
---  -  ---  =  -----
 B       A       AB

where A and B are both integers, −9 ≤ A ≤ 9, and −9 ≤ B ≤ 9. (Also A ≠ 0 and B ≠ 0.)

*/

#include <iostream>

int main()
{
    std::cout << "Problem E: Fraction Distraction" << std::endl;
    int count = 0;

    const int A_min = -2, A_max = 0;
    const int B_min = -2, B_max = 0;

/*

Naive solution: Brute force all possible values of A and B, O(n²):

## Intuition:

 A²     B²     A+B
---- - ---- = -----
 AB     AB     AB

therefore:

A² - B² = A+B,

*/
    for (int A = A_min; A <= A_max; A++)
    {
        if (A == 0) continue;
        for (int B = B_min; B <= B_max; B++)
        {
            if (B == 0) continue;
            if (A*A - B*B == A+B)
            {
                std::cout << "A: " << A << ", B: " << B << std::endl;
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
    count = 0;

    // A+B ≠ 0:
    int α_min_1 = std::max(B_min+1, A_min);
    int α_max_1 = std::min(B_max+1, A_max);
    int excluded = 0;

    if (α_min_1 <= α_max_1)
    {
        if (α_min_1 <= 1) excluded++; // removes (A: 1, B: 0)
        if (α_min_1 < 1) excluded++; // removes (A: 0, B: -1)
    }

    // A+B == 0:
    int α_min_2 = std::max(A_min, -B_max);
    int α_max_2 = std::min(A_max, -B_min);

    if (α_min_2 <= 0 && α_min_2 <= α_max_2) excluded++; // removes (A: 0, B: 0)

    int num_solutions = -excluded;
    if (α_min_1 <= α_max_1) num_solutions += α_max_1 - α_min_1 + 1;
    if (α_min_2 <= α_max_2) num_solutions += α_max_2 - α_min_2 + 1;

    std::cout << "range of valid solutions: [" << α_min_1 << ", " << α_max_1 << "] U [" << α_min_2 << ", " << α_max_2 << "], A != 0 and B != 0." << std::endl;
    std::cout << "Number of solutions: " << num_solutions << std::endl;
    std::cout << "Excluded:" << excluded << std::endl;

    for (int α = α_min_1; α <= α_max_1; α++)
    {
        int B = α - 1;
        std::cout << "A: " << α << ", B: " << B << std::endl;
    }

    for (int α = α_min_2; α <= α_max_2; α++)
    {
        int B = -α;
        std::cout << "A: " << α << ", B: " << B << std::endl;
    }

    return 0;
}
