#include <stdio.h>
#include <cs50.h>

// Declare functions
int count_digits(long n);
int checksum_value(long n);
void card_type(long n, int digits);

int main(void)
{
    // Declare variables
    long n = get_long("Number ");
    int digits = count_digits(n);
    int checksum = checksum_value(n);

    // Check card validity
    if (checksum == 0 && (digits > 12 && digits < 17))
    {
        card_type(n, digits);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Card type verification function
void card_type(long n, int digits)
{
    int digits_left = digits;
    int first_digit = 0;
    int second_digit = 0;

    // Iterate through n to reach the first and second digits
    while (n != 0)
    {
        n /= 10;
        digits_left--;
        if (digits_left == 1)
        {
            first_digit = n % 10;
        }
        else if (digits_left == 2)
        {
            second_digit = n % 10;
        }
    }
    // Condition to check which credit card
    if (first_digit == 3 && (second_digit == 4 || second_digit == 7) && digits == 15)
    {
        printf("AMEX\n");
    }
    else if (first_digit == 5 && (second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4 || second_digit == 5) && digits == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (first_digit == 4 && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Checksum function
int checksum_value(long n)
{
    int count = 0;
    int sum = 0;
    int accumulator = 0;

    // Iterate through n and apply arithmetic
    while (n != 0)
    {
        int current_digit = n % 10;
        if (count % 2 == 1) // Factoring every other digit starting with second-to-last
        {
            int factor_digit = current_digit * 2;
            while (factor_digit != 0)
            {
                accumulator += factor_digit % 10;
                factor_digit /= 10;
            }
        }
        else if (count % 2 == 0) // Adding the the leftover digits together
        {
            sum += current_digit;
        }
        n /= 10;
        count++;
    }
    sum += accumulator; // Final sum
    return sum % 10;
}

// Count number of digits function
int count_digits(long n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
