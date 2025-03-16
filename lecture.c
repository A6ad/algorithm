#include <stdio.h>
long long factorial(int x)
{
    if(x==0)
    {
        return 1; // base case
    }
    return x * factorial(x-1);
}
int main() {
    
    printf("%lld",factorial(20));
    return 0;

}

// 10 april   cse 1101
// 13 april   cse 1104	
// 15 april   EEE 1102	
// 16 april   physics
// 17 april central viva


// theory final 
// 30 april  cse 1101	
// 6 may = EEE 1101	
// 12 may physics	
// 18 may math 1121	
// 22 may eng(HSS)	
