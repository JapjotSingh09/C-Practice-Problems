/*************************************************
            SIEVE OF ERATOSTHENES

Question:
2 se N tak saare prime numbers print/count karo.

Time Complexity: O(N log log N)
Space Complexity: O(N)

**************************************************/

/*
STEP 1:
Sabhi numbers ko pehle prime maan lo.

vector<bool> prime(n+1, true);

Example:
n = 10

Index:  0 1 2 3 4 5 6 7 8 9 10
Value:  T T T T T T T T T T T
*/

/*
0 aur 1 prime nahi hote.

Prime number:
Jiske exactly 2 factors ho:
1 aur khud number.

Isliye:

prime[0] = false;
prime[1] = false;
*/

/*
Outer Loop:

for(int i = 2; i*i <= n; i++)

i*i <= n ka matlab:
i <= sqrt(n)

Example:
n = 50

sqrt(50) ≈ 7

To loop:
2, 3, 4, 5, 6, 7

tak hi chalega.

Kyun?

Har composite number ka ek factor
sqrt(n) se chhota ya barabar hota hai.
*/

/*
if(prime[i])

Agar i abhi bhi true hai,
matlab i prime hai.

Agar false hai,
matlab kisi chhote number ne ise pehle hi mark kar diya.

Example:

i = 2
4 6 8 10 mark

i = 3
9 12 15 mark

i = 4

4 already false hai.

Isliye 4 ke multiples dobara mark nahi karte.
*/

/*
j = i*i kyu?

Example:

i = 5

5*2 = 10  --> 2 ne pehle hi mark kiya.
5*3 = 15  --> 3 ne pehle hi mark kiya.
5*4 = 20  --> 2 ne pehle hi mark kiya.
5*5 = 25  --> pehli baar mark hoga.

Isliye:

j = i*i
*/

/*
j += i kyu?

Agar i = 5

j = 25

25
30
35
40
45

Har baar 5 add kar rahe hain.

Taaki 5 ke saare multiples mil jaaye.
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<bool> prime(n + 1, true);

    prime[0] = false;
    prime[1] = false;

    for(int i = 2; i * i <= n; i++) {

        if(prime[i]) {

            for(int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(prime[i]) {
            cout << i << " ";
        }
    }
}