#include <bits/stdc++.h>

using namespace std;

/**
 * KMP (Knuth-Morris-Pratt) string matching algorithm
 * http://oi-wiki.org/string/kmp/
 */
struct KMP
{
    /**
     * Calculate the prefix function (pi array) for pattern p
     * pi[i] = length of longest proper prefix which is also a suffix of p[0..i]
     * This allows us to skip characters when matching fails
     * 
     * @param p: pattern string
     * @return: pi array where pi[i] is the longest prefix-suffix length for p[0..i]
     */
    vector<int> calcPi(const string &p)
    {
        vector<int> pi(p.size());
        int match = 0; // length of current longest prefix-suffix match
        
        // Start from index 1 since pi[0] is always 0
        for (int i = 1; i < p.size(); i++)
        {
            char v = p[i];
            // If mismatch, backtrack to the previous longest prefix-suffix
            // This is the key optimization: reuse already computed prefix-suffix info
            while (match > 0 && p[match] != v)
            {
                match = pi[match - 1];
            }
            // If characters match, extend the prefix-suffix length
            if (p[match] == v)
            {
                match++;
            }
            pi[i] = match;
        }
        return pi;
    }
    
    /**
     * Find all starting positions where pattern p occurs in text s
     * Uses the prefix function to avoid re-checking characters
     * 
     * @param s: text string to search in
     * @param p: pattern string to search for
     * @return: vector of starting indices (0-indexed) where p appears in s
     */
    vector<int> kmp(const string &s, const string &p)
    {
        // Edge case: empty pattern matches at every position
        if (p.empty())
        {
            vector<int> pos(s.size() + 1);
            for (int i = 0; i <= s.size(); i++) {
                pos[i] = i;
            }
            return pos;
        }
        
        // Precompute prefix function for pattern
        vector<int> pi = calcPi(p);
        vector<int> pos; // stores all match positions
        int match = 0; // current length of matched prefix
        
        // Scan through text s
        for (int i = 0; i < s.size(); i++)
        {
            char v = s[i];
            // On mismatch, use pi array to skip ahead without re-checking
            // This is the core KMP optimization
            while (match > 0 && p[match] != v)
                match = pi[match - 1];
            
            // If current character matches, extend the match
            if (p[match] == v)
                match += 1;
            
            // Full pattern match found
            if (match == p.size())
            {
                pos.push_back(i - p.size() + 1); // record starting position
                // Continue searching by using pi to find next possible match
                match = pi[match - 1];
            }
        }
        return pos;
    }
};