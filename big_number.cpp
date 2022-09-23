#include <stdio.h>
#include <string.h>
#include <assert.h>
#define ARRAYSIZE 101

int main()
{
    int i = 0;
    char s1[ARRAYSIZE], s2[ARRAYSIZE];
    int num1[ARRAYSIZE] = { 0 };
    int num2[ARRAYSIZE] = { 0 };
    int ans[ARRAYSIZE] = { 0 };
    printf("Please enter your first big number :\n");
    scanf("%s", &s1);
    printf("Please enter your second big number :\n");
    scanf("%s", &s2);
    assert(s1[0] != 48);
    assert(s2[0] != 48);
    int count1 = 0;
    int count2 = 0;
    for (int i = 0;s1[i] != 0;i++) {
        count1++;
        num1[i] = s1[i] - 48;
    }
    for (int i = 0;s2[i] != 0;i++) {
        count2++;
        num2[i] = s2[i] - 48;
    }
    int over = 0;
    int max = 0;
    int Temp[ARRAYSIZE];
    if (count1 > count2) {
        over = (count1 - count2);
        max = count1;
        for (int i = 0;i <= (count2 - 1);i++) {
            Temp[i] = num2[i];
        }
        for (int i = 0;i <= over - 1;i++) {
            num2[i] = 0;
        }
        for (int i = over;i <= (count1 - 1);i++) {
            num2[i] = Temp[i - over];
        }
    }
    else if (count2 > count1) {
        over = (count2 - count1);
        max = count2;
        for (int i = 0;i <= (count1 - 1);i++) {
            Temp[i] = num1[i];
        }
        for (int i = 0;i <= over - 1;i++) {
            num1[i] = 0;
        }
        for (int i = over; i <= (count2 - 1);i++) {
            num1[i] = Temp[i - over];
        }
    }
    int bigger = 0;
    if (count1 == count2) 
    {
        max = count1;
        for (int i = 0; i < max - 1; i++) 
        {
            if (num1[i] > num2[i]) 
            {
                bigger++;
                break;
            }
            else 
            {
                break;
            }
        }
    }
    printf("\n");
    int choice;
    printf("Please choose the mode you want : (1) PLUS (2) MINUS\n");
    scanf("%d", &choice);
    if (choice == 1) {
        for (int i = (max - 1); i >= 0; i--)
        {
            ans[i] = num1[i] + num2[i];
            if (ans[i] >= 10 && i > 0)
            {
                ans[i] = ans[i]%10;
                num1[i - 1] ++;
            }
        }
    }
    else if (choice == 2)
    {
        if (count1 > count2) {
            for (int i = (max - 1); i >= 0; i--) {
                ans[i] = num1[i] - num2[i];
                if (ans[i] < 0)
                {
                    ans[i] = ans[i] + 10;
                    num1[i - 1] --;
                }
            }
        }
        else if (count2 > count1)
        {
            for (int i = (max - 1); i >= 0; i--) {
                ans[i] = num2[i] - num1[i];
                if (ans[i] < 0)
                {
                    ans[i] = ans[i] + 10;
                    num2[i - 1] --;
                }
            }
        }
        else if (count1 == count2 && bigger != 0)
        {
            for (int i = (max - 1); i >= 0; i--) {
                ans[i] = num1[i] - num2[i];
                if (ans[i] < 0)
                {
                    ans[i] = ans[i] + 10;
                    num1[i - 1] --;
                }
            }
         }
         else
        {            
            for (int i = (max - 1); i >= 0; i--) {
                 ans[i] = num2[i] - num1[i];
                 if (ans[i] < 0)
                 {
                     ans[i] = ans[i] + 10;
                     num2[i - 1] --;
                 }
            }
            
        }
    }
    printf("\n");
    printf("The answer is :\n");
    for (int i = 0; i < max; i++) 
    {
        printf("%d", ans[i]);
    }
    printf("\n");
    printf("Do you wanna try again ? (1)Yes (2)No\n");
    int answer = 0;
    scanf("%d", &answer);
    assert(answer > 0);
    if (answer == 1)
    {
        main();
    }
    else
    {
        printf("See you again~~\n");
    }
    return 0;
}
   
    
