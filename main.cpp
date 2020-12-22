#include <iostream>
#include <string>

std::string encrypt(std::string cipherTxt)
{
    char currentLetter;
    int key;

    std::cout << "Enter an encryption key: ";
    std::cin >> key;
    //Since the alphabet is 26 letters long, this will make a key between 1 and 26
    while(key > 26)
    {
        key -= 26;
    }
    for(int i = 0; i < cipherTxt.length(); ++i)
    {
        currentLetter = cipherTxt[i];
        //if letter is lowercase
        if(currentLetter >= 'a' && currentLetter <= 'z')
        {
            //bound by letters only. Will go to start of alphabet if goes past 'z'
            //or if key puts current letter past the values of ascii letters
            if(currentLetter + key > 'z')
            {
                currentLetter = currentLetter + key - 'z' + 'a' - 1;
            }
            else
            {
                currentLetter += key;
            }
        }
        //else if letter is uppercase
        else if(currentLetter >= 'A' && currentLetter <= 'Z')
        {
            //still protected against spillover
            if(currentLetter + key > 'Z')
            {
                currentLetter = currentLetter + key - 'Z' + 'A' - 1;
            }
            else
            {
                currentLetter += key;
            }
        }
        cipherTxt[i] = currentLetter;
    }
    return(cipherTxt);
}
std::string decrypt(std::string decipherTxt)
{
    char currentLetter;
    int key;

    std::cout << "Enter a decryption key: ";
    std::cin >> key;
    while(key > 26)
    {
        key -= 26;
    }
    //algorithm is the same as encryption, but subtracts key instead of adding it
    for(int i = 0; i < decipherTxt.length(); ++i)
    {
        currentLetter = decipherTxt[i];
        if(currentLetter >= 'a' && currentLetter <= 'z')
        {
            if(currentLetter - key < 'a')
            {
                //Same thought process again, instead protecting from letter being less than 'a'
                currentLetter = currentLetter - key + 'z' - 'a' + 1;
            }
            else
            {
                currentLetter -= key;
            }
        }
        else if(currentLetter >= 'A' && currentLetter <= 'Z')
        {
            if(currentLetter - key < 'A')
            {
                currentLetter = currentLetter - key + 'Z' - 'A' + 1;
            }
            else
            {
                currentLetter -= key;
            }
        }
        decipherTxt[i] = currentLetter;
    }
    return(decipherTxt);
}
int main(int argc, char** argv)
{
    if(argc != 3)
    {
        std::cout << "Invalid input. Enter as \"./ceaser <plaintext> <e for encrypt or d decrypt>\"\n";
    }
    //assignging to strings makes the proceeding logic function correctly
    else
    {
        std::string plainText = argv[1];
        std::string type = argv[2];
        if(type == "encrypt" || type == "Encrypt")
        {
            std::cout << encrypt(plainText) << "\n";
        }
        else if(type == "decrypt" || type == "Decrypt")
        {
            std::cout << decrypt(plainText) << "\n";
        }
        //in case user doesn't enter 'encrypt' or 'decrypt' or text contains spacees
        else
        {
        std::cout << "Invalid input. Enter as \"./ceaser <plaintext> <e for encrypt or d decrypt>\"\nUse quotations if cipher text contains spaces\n";
        }
    }
    return 0;
}
