#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/math/linear-algebra/basis/

/**
 * XOR Basis (Linear Basis)
 * 
 * Maintains a basis for the vector space over GF(2) (binary field) using XOR operations.
 * This allows efficient computation of:
 * - Maximum XOR value that can be formed from the inserted numbers
 * - Checking if a number can be represented as XOR of inserted numbers
 * - Finding the rank (dimension) of the vector space
 * 
 * The basis is stored such that each basis vector has a unique highest bit position,
 * which enables efficient greedy algorithms for maximum XOR queries.
 */
class XorBasis
{
    // Basis vectors: b[i] stores a basis vector with highest bit at position i
    // If b[i] == 0, there's no basis vector with highest bit at position i
    vector<int> b;

public:
    /**
     * Constructor
     * @param n Maximum number of bits (typically 32 for uint32_t, 64 for uint64_t)
     */
    XorBasis(int n) : b(n) {}

    /**
     * Insert a number into the basis
     * 
     * Uses Gaussian elimination to maintain a basis where each basis vector
     * has a unique highest bit position. This property ensures that:
     * 1. The basis is linearly independent
     * 2. Maximum XOR can be computed greedily
     * 
     * @param x The number to insert
     * 
     * Algorithm:
     * 1. While x is non-zero:
     *    - Find the highest bit position i of x
     *    - If no basis vector exists at position i, add x as a new basis vector
     *    - Otherwise, eliminate the highest bit of x by XORing with b[i]
     * 2. If x becomes 0, it means x was linearly dependent on existing basis
     */
    void insert(uint32_t x)
    {
        while (x)
        {
            int i = bit_width(x) - 1; // Find the highest bit position of x
            if (b[i] == 0)
            {             // x is linearly independent from existing basis
                b[i] = x; // Add x as a new basis vector with highest bit at position i
                return;
            }
            // Eliminate the highest bit of x by XORing with existing basis vector
            // This ensures each basis vector has a unique highest bit position,
            // which enables efficient greedy algorithms for max_xor
            x ^= b[i];
        }
        // Loop ended normally: x became 0, meaning x is linearly dependent
        // on existing basis vectors and doesn't add new information
    }

    /**
     * Compute the maximum XOR value that can be formed from the basis
     * 
     * Uses a greedy approach: from highest bit to lowest, decide whether to
     * include each basis vector in the XOR result. Since each basis vector
     * has a unique highest bit, we can greedily choose to include it if it
     * increases the result.
     * 
     * @return Maximum XOR value achievable from the basis
     * 
     * Algorithm:
     * - Start with res = 0
     * - For each basis vector from highest bit to lowest:
     *   - If XORing with the basis vector increases res, do it
     *   - This is equivalent to: res = max(res, res ^ b[i])
     */
    uint32_t max_xor()
    {
        uint32_t res = 0;
        // Greedy from high to low bits: higher bits are more valuable
        // Since each bit position has at most one basis vector, we only need
        // to consider XORing one vector per position. If it increases the result, use it.
        for (int i = b.size() - 1; i >= 0; i--)
        {
            res = max(res, res ^ b[i]);
        }
        return res;
    }
};
