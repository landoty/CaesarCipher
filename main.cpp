#include <iostream>
#include <string>

std::string encrypt(std::string cipherTxt)
{
    char currentLetter;
    int key;

    std::cout << "Enter an encryption key: ";
    std::cin >> key;

    for(int i = 0; i < cipherTxt.length(); ++i)
    {
        currentLetter = cipherTxt[i];
        //if letter is lowercase
        if(currentLetter >= 'a' && currentLetter <= 'z')
        {
            currentLetter += key;
            cipherTxt[i] = currentLetter;
            //bound by letters only. Will go to start of alphabet if goes past 'z'
            if(currentLetter > 'z')
            {
                currentLetter = currentLetter - 'z' + 'a' - 1;
            }
        }
        //else if letter is uppercase
        else if(currentLetter >= 'A' && currentLetter <= 'Z')
        {
            currentLetter += key;
            //still protected against spillover
            if(currentLetter > 'Z')
            {
                currentLetter = currentLetter - 'Z' + 'A' - 1;
            }
            cipherTxt[i] = currentLetter;
        }
    }
    return(cipherTxt);
}
std::string decrypt(std::string decipherTxt)
{
    char currentLetter;
    int key;

    std::cout << "Enter a decryption key: ";
    std::cin >> key;

    //algorithm is the same as encryption, but subtracts key instead of adding it
    for(int i = 0; i < decipherTxt.length(); ++i)
    {
        currentLetter = decipherTxt[i];
        if(currentLetter >= 'a' && currentLetter <= 'z')
        {
            currentLetter -= key;
            decipherTxt[i] = currentLetter;
            if(currentLetter > 'z')
            {
                //Same thought process again, instead protecting from letter being less than 'a'
                currentLetter = currentLetter + 'z' - 'a' + 1;
            }
        }
        else if(currentLetter >= 'A' && currentLetter <= 'Z')
        {
            currentLetter -= key;
            if(currentLetter > 'Z')
            {
                currentLetter = currentLetter + 'Z' - 'A' + 1;
            }
            decipherTxt[i] = currentLetter;
        }
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
