# CEMC Problem of the Week
# [Problem E. Fraction Distraction](https://cemc.uwaterloo.ca/sites/default/files/documents/2024/POTWE-24-N-02-P.pdf)
Determine the number of solutions to the equation

A / B - B / A = (A + B) / (AB)

where A and B are both integers, −9 ≤ A ≤ 9, and −9 ≤ B ≤ 9.

---

Naive solution: Brute force all possible values of A and B, O(n²):

## Intuition:

A² / (AB) - B² / (AB) = (A+B) / (AB),

therefore:

A² - B² = A+B,

```cpp
int count = 0;

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
```

---

# Mathematical solution, O(1):

## Intuition:
A ∈ [A_min, A_max], B ∈ [B_min, B_max], A, B ∈ ℤ.

let the set α be the set of all values of A that satisfy the equation,

A² / (AB) - B² / (AB) = (A+B) / (AB),

therefore:

A² - B² = A+B,

(A+B)(A-B) = A+B,


## Where A+B !≠ 0:

A-B = 1,

B = A-1,

B_min ≤ B ≤ B_max,

B_min ≤ A-1 ≤ B_max,

B_min+1 ≤ A ≤ B_max+1, AND A_min ≤ A ≤ A_max, therefore:

max(B_min+1, A_min) ≤ α ≤ min(B_max+1, A_max), A+B ≠ 0


## Where A+B == 0:
B = -A,

A_min ≤ A ≤ A_max and B_min ≤ B ≤ B_max, so:

B_min ≤ -A ≤ B_max,

-B_max ≤ A ≤ -B_min, AND A_min ≤ A ≤ A_max, therefore:

max(-B_max, A_min) ≤ α ≤ min(-B_min, A_max), A+B = 0

therefore for the range of valid solutions where A+B = 0:
α_min2 = max(A_min, -B_max), α_max2 = min(A_max, -B_min).

```cpp
const int A_min = -9, A_max = 9;
const int B_min = -9, B_max = 9;

// A+B ≠ 0:
const int α_min_1 = std::max(B_min+1, A_min);
const int α_max_1 = std::min(B_max+1, A_max);

// A+B == 0:
const int α_min_2 = std::max(A_min, -B_max);
const int α_max_2 = std::min(A_max, -B_min);

const int count = α_max_1 - α_min_1 + 1 + α_max_2 - α_min_2 + 1;

std::cout << "Number of solutions: " << count << std::endl;
```
