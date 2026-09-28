#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define mn INT_MIN
#define mx INT_MAX
 
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
long long  __builtin_ctz(long long y) {
    ll sum = 0;
    for (auto i = 0; i < 64; i++) {
        if ((y >> i) & 1)
            break;
        else sum++;
        
    }
    return sum;
}
long long  __builtin_clz(long long y) {
    ll sum = 0;
    for (auto i = 63; i >=0; i--) {
        if ((y >> i) & 1)
            break;
        else sum++;

    }
    return sum;
}
long long __builtin_popcount(long long y)
{
    ll sum = 0;
    for (ll i = 63; i >= 0; i--) {
        if ((y >> i) & 1)sum++;
    }
    return sum;
}
long long __lg(long long y)
{
    ll s = -1;
    for (ll i = 63; i >= 0; i--) {
        if ((y >> i) & 1)return i;
    }
    return s;
}

//bit manipulation
void solve() {

//bitwise operators
// binary operations
//And &
int x = 2,b=4;//0010 0100  int is signed 32 bit
 cout << (x & b) << el; //0000
 //or (|)
 cout << (x | b) << el; //0110
 //xor (^)
 cout << (x ^ b) << el; //0110

//unary operators
//not(~)
cout << (~x) << el; //-3 
cout << x << el;

////shift operators
////shift right(>>(k)) = n/2^k
////shift left(<<(k))  =n*2^k
int a = 4;//0100
a >>= 1;//0010
cout << a << el;
a <<= 2;//1000;
cout << a << el;

//////bitwise operations
//////turn on bit (x)
int n = 5, pos = 3;
n |= (1 << pos);//0101 |1000=1101
cout << n << el;//13

//turn off bit(x)
n = 2, pos = 1;//0010
n &= ~(1 << pos);//0010 &1101=0000
cout << n << el;//0

////flip bit(x)
n = 2, pos = 1;//0010
n ^= (1 << pos);//0010 ^0010=0000;
cout << n << el;//0

////check bit(x)
n = 5, pos = 2;//0101
(n & (1 << pos)) ? cout << "bit is on\n" : cout << "bit is off\n";//bit is on 
n = 5, pos = 1;//0101
(n & (1 << pos)) ? cout << "bit is on\n" : cout << "bit is off\n";//bit is off



////bitset
    bitset<5>z=4; //1001  count ones
    cout << z << el;//binary rep
    cout << z.count()<<el; 
   z.set(); //make all bits ones
    cout << z << el;
   cout<< z.any()<<el;//if there any bit is one returns true
   cout << z.none()<<el;// return true if there is no ones 

 bitset < 5> c = 2;
 cout << c.to_string()<<el;

 int n; cin >> n;
  // bitset<n>s;         //error  <>should be constant
 const int N = 4;
  bitset<N>ss;//ok
 
long long y = 2;
bitset<4>s(y); //bitset deal with unsigned numbers only 
   cout << s << el;

   s = ~s;
   cout << s << el; //13
   cout << s.to_ulong() << el; //convert to decimal
   cout << s.to_ullong() << el;//unsigned long long
   cout << s.all() << el;//if all bits are one return true;
  // cout << s.flip() << el;//flips all bits;
  cout << __builtin_clz(y) << el; // position first one from left & numbers of leading zeros
 cout << __builtin_ctz(y) << el; //position first one from right & numbers of trailing zeros
  int nofones =__builtin_popcount(y); //numbers of ones

int nofzeros = 64 - nofones;
cout << nofzeros << el;

 long long  x = 0b0110; //bits
cout << x << el;
  //cout << __lg(y) << el;//highest bit with 1 
int h = 2,l=3;
  //2= 0010 1=0001 -> 0010  & 0010 =2 
  //3=0101  1=0001 ->  0100 & 0100 =4
 
if (1 << __lg(h) == h)cout << "This number is power of 2\n";
if (1 << __lg(l) != l)cout << "This number is not a power of 2\n";

//every 64 bit the processor do them at once
bitset<64>ss;//o(1) 64/54
bitset<110>x;//complexity(110/64) memory and time



//BitsetManipulation's applications
//complete search (n<20)
const int p = 4;
   int k = 2;
   int arr[p]{ 1,2,3,4 };
  //complexity: 0:(2^n)-1  
   for (int mask = 0; mask < (1 << n); mask) //(1<<n) *2^n
   {
       ll sum = 0;
       for (int i = 0; i <p; i++) {
           if (mask >> i & 1)sum += arr[i];
       }
       if (sum == k)cout<<"Found\n";
   }
}
int main()
{
    //freopen("smallest.in", "r", stdin);
    fastIO();
    int testcases=1; 
    for (int testcase = 0; testcase < testcases; testcase++)
        // p();
        solve();
    return 0;

}

