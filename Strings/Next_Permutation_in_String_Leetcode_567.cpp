#include<iostream>
using namespace std;
// Function to compare both frequency arrays
bool IsFreqSame(int freq1[], int freq2[]){
    for(int i=0; i<26;i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}
bool CheckInclusion(string S1, string S2){
// Frequency array of s1
    int Freq[26] = {0};
// Store frequency of characters of s1
    for(int i=0;i<S1.length();i++){
        Freq[S1[i]- 'a']++ ;
    }
// Size of sliding window
    int WindowSize = S1.length();
// Traverse s2
    for(int i=0;i<S2.length();i++){
        int WindowIdx = 0, Idx = i;
 // Frequency array of current window of s2
        int WindowFreq[26] = {0};
        while(WindowIdx<WindowSize & Idx<S2.length()){
        // Add current character into window
            WindowFreq[S2[Idx] - 'a']++;
            WindowIdx++; Idx++;
        }
        //
        if(IsFreqSame(Freq, WindowFreq)){
            return true;
        }
    }
    return false;
}
int main(){
string S1 = "ab";
string S2 = "eidbaooo";
cout<<CheckInclusion(S1,S2);
}
/*

================ OPTIMIZED APPROACH =================

Idea:
Instead of creating frequency array for every window again and again,
maintain frequency of current window.

1. Store frequency of s1 in freq1[].
2. Create freq2[] for current window.
3. Traverse s2.
4. Add current character into window.
5. If window size exceeds s1 length,
   remove leftmost character.
6. Compare freq1 and freq2.
7. If same -> permutation found.

Example:

s1 = "ab"
s2 = "eidbaooo"

WindowSize = 2

i = 0
Window = e

i = 1
Window = ei

i = 2
Add d -> eid
Remove e -> id

i = 3
Add b -> idb
Remove i -> db

i = 4
Add a -> dba
Remove d -> ba

Window "ba" frequency matches "ab"
Return true.

Code:

for(int i = 0; i < s2.length(); i++){

    // Add current character
    freq2[s2[i] - 'a']++;

    // Remove leftmost character
    if(i >= windowSize){
        freq2[s2[i - windowSize] - 'a']--;
    }

    // Check frequencies
    if(isSame(freq1, freq2)){
        return true;
    }
}

Time Complexity : O(26 * n)
Space Complexity : O(26)

=====================================================

*/
/*

================ UNORDERED_MAP APPROACH =================

Idea:
Instead of using frequency arrays of size 26,
store character frequencies in unordered_map.

Why use unordered_map?
- Useful when characters are not limited to 'a' to 'z'.
- Can handle any ASCII character easily.

Steps:

1. Store frequency of s1 in freq1.
2. Create freq2 for current window.
3. Build first window of size s1.length().
4. Compare freq1 and freq2.
5. Slide the window:
   - Add new character.
   - Remove old character.
   - If frequency becomes 0, erase that key.
6. Compare maps after every slide.

--------------------------------------------------

Example:

s1 = "ab"
s2 = "eidbaooo"

WindowSize = 2

First Window:

ei

freq2:

e -> 1
i -> 1

Match ? NO

--------------------------------------------------

Slide Window:

Add d
Remove e

Window:

id

freq2:

i -> 1
d -> 1

Match ? NO

--------------------------------------------------

Slide Window:

Add b
Remove i

Window:

db

freq2:

d -> 1
b -> 1

Match ? NO

--------------------------------------------------

Slide Window:

Add a
Remove d

Window:

ba

freq2:

b -> 1
a -> 1

freq1:

a -> 1
b -> 1

Match ? YES

Return true.

--------------------------------------------------

Why erase() ?

Suppose:

e -> 1

After removing e:

e -> 0

Key 'e' is still present in map.

Map becomes:

e -> 0
i -> 1

But we want:

i -> 1

So:

if(freq2[ch] == 0)
{
    freq2.erase(ch);
}

This removes the key completely.

--------------------------------------------------

Code:

unordered_map<char,int> freq1;
unordered_map<char,int> freq2;

for(char ch : s1)
{
    freq1[ch]++;
}

// First window
for(int i = 0; i < windowSize; i++)
{
    freq2[s2[i]]++;
}

if(freq1 == freq2)
{
    return true;
}

// Sliding Window
for(int i = windowSize; i < s2.length(); i++)
{
    // Add new character
    freq2[s2[i]]++;

    // Remove old character
    freq2[s2[i - windowSize]]--;

    // Remove key if frequency becomes 0
    if(freq2[s2[i - windowSize]] == 0)
    {
        freq2.erase(s2[i - windowSize]);
    }

    if(freq1 == freq2)
    {
        return true;
    }
}

return false;

--------------------------------------------------

Time Complexity:
O(n)

Space Complexity:
O(k)

k = number of distinct characters

--------------------------------------------------

Note:

If question says:
"All characters are lowercase English letters"

Then frequency array (size 26) is usually better
than unordered_map because it is faster and simpler.

==================================================

*/