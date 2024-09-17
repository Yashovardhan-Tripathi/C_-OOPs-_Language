#include <iostream>
using namespace std;
int stringLength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
void stringCopy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
void stringReverse(char *str)
{
    int left = 0;
    int right = stringLength(str) - 1;
    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}
int isPalindrome(const char *str)
{
    int left = 0;
    int right = stringLength(str) - 1;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
void stringConcatenate(char *dest, const char *src)
{
    int dest_len = stringLength(dest);
    int i = 0;
    while (src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
}
int countSubstringOccurrences(const char *str, const char *substr)
{
    int occurrences = 0;
    int str_len = stringLength(str);
    int substr_len = stringLength(substr);
    for (int i = 0; i <= str_len - substr_len; i++)
    {
        int j;
        for (j = 0; j < substr_len; j++)
        {
            if (str[i + j] != substr[j])
            {
                break;
            }
        }
        if (j == substr_len)
        {
            occurrences++;
        }
    }
    return occurrences;
}
int main()
{
    char str1[100] = "Hello, world!";
    char str2[100] = "racecar";
    char str3[100] = "My name is ";
    char str4[100] = "John Doe";
    char str5[100] = "abcabcabcabc";
    char substr[100] = "abc";
    cout << "String Length of str1: " << stringLength(str1) << endl;

    char copy[100];
    stringCopy(copy, str1);
    cout << "Copy of str1: " << copy << endl;
    stringReverse(str2);
    cout << "Reverse of str2: " << str2 << endl;
    cout << "Is str2 a palindrome? ";
    if (isPalindrome(str2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    stringConcatenate(str3, str4);
    cout << "Concatenated string: " << str3 << endl;
    return 0;
}
