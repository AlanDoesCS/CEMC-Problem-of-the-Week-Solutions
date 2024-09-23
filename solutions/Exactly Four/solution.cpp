/*
 * CEMC Problem of the Week - Problem E:
 * Exactly Four

A machine dispenses four kinds of tokens. Red tokens are worth 25 points, blue
tokens are worth 10 points, green tokens are worth 5 points, and yellow tokens
are worth 1 point. The machine never runs out of tokens to dispense.
To get tokens from the machine, people enter a total number of points, and the
machine will dispense the fewest number of tokens that total that number of
points. For example, if someone enters 30 points, the machine will dispense 1 red
token and 1 green token, because their total value is 25 + 5 = 30 points, and this
total cannot be obtained using fewer tokens.
For how many different total numbers of points will the machine dispense exactly
4 tokens?

      Red         Blue       Green       Yellow

     /----\      /----\      /----\      /----\
    |  25  |    |  10  |    |   5  |    |   1  |
     \----/      \----/      \----/      \----/

*/

#include <iostream>
#include <set>

int factorial(int n)
{
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int num_combinations(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n-k));
}

int main()
{
    std::cout << "Problem E: Exactly Four" << std::endl;

    const int red = 25, blue = 10, green = 5, yellow = 1;

/*
Solution 1: Brute force all possible values of red, blue and green tokens (yellow are the remainder), O(n³):

## Intuition:

points = 25r+10b+5g+1y
points = 25r+10b+5g+1(max_tokens−(r+b+g)) = 25r+10b+5g+max_tokens−r−b−g
= 24r+9b+4g+max_tokens
*/
    std::set<int> unique_points;
    const int max_tokens = 4;

    for (int r = 0; r <= max_tokens; r++)
    {
        for (int b = 0; b >= 0 && b <= max_tokens-r; b++)
        {
            for (int g = 0; g >= 0 && g <= max_tokens-(r+b); g++)
            {
                const int y = max_tokens - (r+b+g);
                int points = r*red + b*blue + g*green + y*yellow;
                unique_points.insert(points);
            }
        }
    }

    std::cout << "Number of different total numbers of points: " << unique_points.size() << std::endl;

/*
Solution 2: Mathematical solution, O(...): -- TODO: I dont know how to remove duplicates!!

## Intuition:
Stars and bars formula:

C(n+k−1,k−1)

where:
n is the total number tokens,
k is the number of types of tokens

n = 4,
k = 4.
*/

    const int n = 4, k = 4;

    int combinations = num_combinations(n+k-1, k-1);

    std::cout << "Number of different total numbers of points: " << combinations << std::endl;

    return 0;
}
