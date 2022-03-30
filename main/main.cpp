// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: All_Ciphers.cpp
// Program Description: This program provides the 10 chiphers and you can choose from the list (Encode and decode)
// Last Modification Date: 30/3/2022
// Author1 and ID and Group: 20211012
// Author2 and ID and Group: 20210447
// Author3 and ID and Group: 20210063
// Teaching Assistant:
// Purpose: use the 10 ciphers
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std ;
// The start of the affine cipher functions
void AFFINE_CIPHER_ENCRYPTION(){
    string message  , result;
    int a  , b , c  , errorFree;
    char character ;
    cout << "First Enter the Coefficients A and B and C\n" ;
    // Take A and check if A is positve or negative
    cout << "Enter the Coefficients A\n" ;
    cin >> a ;
    while (a <= 0){
        cout << "You have to enter a positive integer\n" ;
        cout << "Enter the Coefficients A\n" ;
        cin >> a ;
        if (a > 0){
            break;
        }
    }
    // Take B and check if B is positve or negative
    cout << "Enter the Coefficients B\n" ;
    cin >> b ;
    while (b <= 0){
        cout << "You have to enter a positive integer\n" ;
        cout << "Enter the Coefficients B\n" ;
        cin >> b ;
        if (b > 0){
            break;
        }
    }
    // Take C and check if C is positve or negative and if (a * c) % 26 == 1
    cout << "Enter the Coefficients C\n" ;
    cin >> c ;
    errorFree = 0 ;
    while (errorFree < 2){
        if (c <= 0) {
            while (c <= 0) {
                errorFree = 0;
                cout << "You have to enter a positive integer\n";
                cout << "Enter the Coefficients C\n";
                cin >> c;
                if (c > 0) {
                    errorFree++;
                    break;
                }
            }
        }
        else {
            errorFree ++ ;
        }
        if ((a * c) % 26 != 1) {
            while ((a * c) % 26 != 1) {
                errorFree = 0;
                if (c > 0) {
                    cout << "You have to enter the C number as [(A * C) mod 26 = 1]\n";
                }else {
                    cout << "Enter a positive integer please\n" ;
                }
                cout << "Enter the Coefficients C\n";
                cin >> c;
                if ((a * c) % 26 == 1) {
                    errorFree++;
                    break;
                }
            }
        }
        else {
            errorFree ++ ;
        }
    }
    cin.ignore() ;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , message);
    for (int i = 0 ; i < message.length() ; i++){
        // Convert the lowercase characters to the uppercase
        if (islower(message[i])){
            message[i] = toupper(message[i]) ;
        }
        // Filttering the word to convert only the alphabet
        if (message[i] >= 65 and message[i] <= 90) {
            // Aplly the equation
            character = (((message[i] - 65) * a + b) % 26) + 65 ;
            result += character;
        }else {
            result += message[i] ;
        }
    }
    cout << "Cipherd message is --> "<< result << "\n";
}
void AFFINE_CIPHER_DECRYPTION(){
    string message  , result;
    char charecter ;
    int a  , b , c  , errorFree;
    char character ;
    cout << "First Enter the Coefficients A and B and C\n" ;
    // Take A and check if A is positve or negative
    cout << "Enter the Coefficients A\n" ;
    cin >> a ;
    while (a <= 0){
        cout << "You have to enter a positive integer\n" ;
        cout << "Enter the Coefficients A\n" ;
        cin >> a ;
        if (a > 0){
            break;
        }
    }
    // Take B and check if B is positve or negative
    cout << "Enter the Coefficients B\n" ;
    cin >> b ;
    while (b <= 0){
        cout << "You have to enter a positive integer\n" ;
        cout << "Enter the Coefficients B\n" ;
        cin >> b ;
        if (b > 0){
            break;
        }
    }
    // Take C and check if C is positve or negative and if (a * c) % 26 == 1
    cout << "Enter the Coefficients C\n" ;
    cin >> c ;
    errorFree = 0 ;
    while (errorFree < 2){
        if (c <= 0) {
            while (c <= 0) {
                errorFree = 0;
                cout << "You have to enter a positive integer\n";
                cout << "Enter the Coefficients C\n";
                cin >> c;
                if (c > 0) {
                    errorFree++;
                    break;
                }
            }
        }
        else {
            errorFree ++ ;
        }
        if ((a * c) % 26 != 1) {
            while ((a * c) % 26 != 1) {
                errorFree = 0;
                if (c > 0) {
                    cout << "You have to enter the C number as [(A * C) mod 26 = 1]\n";
                }else {
                    cout << "Enter a positive integer please\n" ;
                }
                cout << "Enter the Coefficients C\n";
                cin >> c;
                if ((a * c) % 26 == 1) {
                    errorFree++;
                    break;
                }
            }
        }
        else {
            errorFree ++ ;
        }
    }
    cin.ignore() ;
    cout << "Enter the sentence you want to decipher\n" ;
    getline(cin , message);
    for (int i = 0 ; i < message.length() ; i++){
        // Convert the lowercase characters to the uppercase
        if (islower(message[i])){
            message[i] = toupper(message[i]) ;
        }
        // Filttering the word to convert only the alphabet
        if (message[i] >= 65 and message[i] <= 90) {
            // Apply the equation
            charecter = c * ((message[i] - 65) - b) % 26 ;
            // Check if the output is negative so we add 26 to give the right modulos
            if (charecter < 0){
                charecter += 65 + 26 ;
            }else {
                charecter += 65 ;
            }
            result += charecter;
        }else {
            result += message[i] ;
        };
    }
    cout << "Plain message is --> "<<result << "\n";
}
void Affine (){
    string Choice ;
    cout << "------------------------\n";
    cout << "|  operation  | number |\n";
    cout << "------------------------\n";
    cout << "|   Cipher    |    1   |\n";
    cout << "|  Decipher   |    2   |\n";
    cout << "------------------------\n";
    cout << "Choose the operation you want to apply\n" ;
    cin >> Choice ;
    cin.ignore();
    if (Choice == "1"){
        AFFINE_CIPHER_ENCRYPTION();
    }else if (Choice == "2"){
        AFFINE_CIPHER_DECRYPTION();
    }else {
        while (true) {
            cout << "Invalid input\n";
            cout << "------------------------\n";
            cout << "|  operation  | number |\n";
            cout << "------------------------\n";
            cout << "|   Cipher    |    1   |\n";
            cout << "|  Decipher   |    2   |\n";
            cout << "------------------------\n";
            cin >> Choice ;
            cin.ignore();
            if (Choice == "1"){
                AFFINE_CIPHER_ENCRYPTION();
                break;
            }else if (Choice == "2"){
                AFFINE_CIPHER_DECRYPTION();
                break;
            }

        }
    }
}
// The end of the affine cipher functions

// The start of the caesar cipher functions
void Caesar_Cipher_Encryption(){
    string message ;
    int shift ;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , message) ;
    cout << "Enter the shift amount\n" ;
    cin >> shift ;
    cin.ignore() ;
    // make the shift < 26 to apply it
    if (shift > 26){
        shift = shift % 26 ;
    }
    for (int i = 0 ; i  < message.length() ; i++){
        // convert the lowercase to the uppercase
        if (islower(message[i])){
            message[i] = toupper(message[i]) ;
        }
        // If the shift and the character > 90
        // we have to make it in the range of (65 , 90)
        // so we -26 (from the character + shift)
        // for example 'Z' = 90 so 90 + 3 = 93
        // if we -26 the result is 93 - 26 = 67 = 'C'
        if (shift + message[i] > 90){
            message[i] = message[i] + shift - 26 ;
        }else {
            // otherwise we add the shift directly
            message[i] = message[i] + shift;
        }
    }
    cout << "Cipherd message is --> " << message << "\n";
}
void Caesar_Cipher_Dencryption(){
    string message ;
    int shift ;
    cout << "Enter the message you want to decipher\n" ;
    getline(cin , message) ;
    cout << "Enter the shift amount\n" ;
    cin >> shift ;
    cin.ignore() ;
    // make the shift < 26 to apply it
    if (shift > 26){
        shift = shift % 26 ;
    }
    // Reverse the shift
    shift = shift * - 1;
    for (int i = 0 ; i  < message.length() ; i++){
        if (message[i] >= 65 and message[i] <= 90) {
            // convert the lowercase to the uppercase
            if (islower(message[i])){
                message[i] = toupper(message[i]) ;
            }
            // For note the shift is revesed so 3 is actualy -3
            // If the shift and the character < 65
            // we have to make it in the range of (65 , 90)
            // so we add 26 to (the character + shift)
            // for example 'A' = 65 so 65 - 3 = 62
            // if we add 26 the result is 62 + 26 = 88 = 'X'
            if (shift + message[i] < 65) {
                message[i] = message[i] + shift + 26;
            } else {
                message[i] = message[i] + shift;
            }
        }else {
            message[i] = message[i] + shift;
        }
    }
    cout << "Plain message is --> " << message << "\n";
}
void Caesar (){
    string Choice ;
    cout << "------------------------\n";
    cout << "|  operation  | number |\n";
    cout << "------------------------\n";
    cout << "|   Cipher    |    1   |\n";
    cout << "|  Decipher   |    2   |\n";
    cout << "------------------------\n";
    cout << "Choose the operation you want to apply\n" ;
    cin >> Choice ;
    cin.ignore();
    if (Choice == "1"){
        Caesar_Cipher_Encryption() ;
    }else if (Choice == "2"){
        Caesar_Cipher_Dencryption() ;
    }else {
        while (true) {
            cout << "Invalid input\n";
            cout << "------------------------\n";
            cout << "|  operation  | number |\n";
            cout << "------------------------\n";
            cout << "|   Cipher    |    1   |\n";
            cout << "|  Decipher   |    2   |\n";
            cout << "------------------------\n";
            cin >> Choice ;
            cin.ignore();
            if (Choice == "1"){
                Caesar_Cipher_Encryption() ;
                break;
            }else if (Choice == "2"){
                Caesar_Cipher_Dencryption() ;
                break;
            }

        }
    }
}
// The  end  of the caesar cipher functions

// The start of the Atbash cipher functions
void Atbash_Cipher_Encryption(){
    string message  , result ;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , message) ;
    for (int i = 0 ; i < message.length() ; i++){
        // Convert from upper ton lower
        if (islower(message[i])){
            message[i] = toupper(message[i]) ;
        }
        if (message[i] >= 65 and message[i] <= 90) {
            result += 90 - (message[i] - 65) ;
        }else {
            result += message[i] ;
        }
    }
    cout << "Cipherd message is --> " << result << "\n";
}
void Atbash_Cipher_Decryption(){
    string message  , result ;
    cout << "Enter the message you want to decipher\n" ;
    getline(cin , message) ;
    for (int i = 0 ; i < message.length() ; i++){
        // Convert from upper ton lower
        if (islower(message[i])){
            message[i] = toupper(message[i]) ;
        }
        if (message[i] >= 65 and message[i] <= 90) {
            result += 90 - (message[i] - 65) ;
        }else {
            result += message[i] ;
        }
    }
    cout << "Plain message is --> " << result << "\n" ;
}
void Atbash (){
    string Choice ;
    cout << "------------------------\n";
    cout << "|  operation  | number |\n";
    cout << "------------------------\n";
    cout << "|   Cipher    |    1   |\n";
    cout << "|  Decipher   |    2   |\n";
    cout << "------------------------\n";
    cout << "Choose the operation you want to apply\n" ;
    cin >> Choice ;
    cin.ignore();
    if (Choice == "1"){
        Atbash_Cipher_Encryption();
    }else if (Choice == "2"){
        Atbash_Cipher_Decryption();
    }else {
        while (true) {
            cout << "Invalid input\n";
            cout << "------------------------\n";
            cout << "|  operation  | number |\n";
            cout << "------------------------\n";
            cout << "|   Cipher    |    1   |\n";
            cout << "|  Decipher   |    2   |\n";
            cout << "------------------------\n";
            cin >> Choice ;
            cin.ignore();
            if (Choice == "1"){
                Atbash_Cipher_Encryption();
                break;
            }else if (Choice == "2"){
                Atbash_Cipher_Decryption();
                break;
            }
        }
    }
}
// The end of the Atbash cipher functions

// The start of Vignere the  cipher functions
void Vignere_Cipher_Encryption (){
    string message  , keyword , result;
    int key_count = 0 ;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , message) ;
    cout << "Enter the keyword \n" ;
    cin >> keyword;
    cin.ignore() ;
    for (int i = 0 ; i < message.length() ; i++){
        // From upper to lower so we can cipher it
        // If we want to include the lower case so
        // We change the mod number to the sum
        // Of the lower and the upper
        if (islower(message[i])){
            message[i] = toupper(message[i]) ;
        }
        if (message[i] >= 65 and message[i] <= 90){
            result += ((message[i] + keyword[key_count]) % 26 )+ 65 ;
            key_count++;
            if (key_count == keyword.length()){
                key_count = 0;
            }
        }else
            result += message[i] ;
    }
    cout << "Cipherd message is --> " << result << "\n";
}
void Vignere_Cipher_Decryption(){
    string message  , keyword , result;
    int key_count = 0 ;
    cout << "Enter the sentence you want to decipher\n" ;
    getline(cin , message) ;
    cout << "Enter the keyword \n" ;
    cin >> keyword ;
    cin.ignore() ;
    for (int i = 0 ; i < message.length() ; i++){
        // From upper to lower so we can cipher it
        // If we want to include the lower case so
        // We change the mod number to the sum
        // Of the lower and the upper
        if (islower(message[i])){
            message[i] = toupper(message[i]) ;
        }
        if (message[i] >= 65 and message[i] <= 90){
            if (message[i] < keyword[key_count]){
                result += (message[i] - keyword[key_count]) % 26 + 26 +65 ;
            }else {
                result += (message[i] - keyword[key_count]) % 26  +65 ;
            }
            key_count++;
            if (key_count == keyword.length()){
                key_count = 0;
            }
        }else {
            result += message[i] ;
        }
    }
    cout << "Plain message is --> " << result << "\n";
}
void Vignere (){
    string Choice ;
    cout << "------------------------\n";
    cout << "|  operation  | number |\n";
    cout << "------------------------\n";
    cout << "|   Cipher    |    1   |\n";
    cout << "|  Decipher   |    2   |\n";
    cout << "------------------------\n";
    cout << "Choose the operation you want to apply\n" ;
    cin >> Choice ;
    cin.ignore();
    if (Choice == "1"){
        Vignere_Cipher_Encryption();
    }else if (Choice == "2"){
        Vignere_Cipher_Decryption();
    }else {
        while (true) {
            cout << "Invalid input\n";
            cout << "------------------------\n";
            cout << "|  operation  | number |\n";
            cout << "------------------------\n";
            cout << "|   Cipher    |    1   |\n";
            cout << "|  Decipher   |    2   |\n";
            cout << "------------------------\n";
            cin >> Choice ;
            cin.ignore();
            if (Choice == "1"){
                Vignere_Cipher_Encryption();
                break;
            }else if (Choice == "2"){
                Vignere_Cipher_Decryption();
                break;
            }
        }
    }
}
// The end of Vignere the  cipher functions

// The start of the Baconian cipher functions

// Get the binary of the char for the decryption
string binary (char letter){
    int num = letter - 65 ;
    string binary ;
    while (num > 0){
        if (num % 2 == 0) {
            binary += '0' ;
        }else {
            binary += '1' ;
        }
        num = num / 2 ;
    }
    while (binary.length() < 5){
        binary += '0' ;
    }
    reverse(binary.begin() , binary.end()) ;
    // convert to "a" and "b"
    for (int i = 0 ; i < binary.length() ; i++){
        if (binary[i] == '0'){
            binary[i] = 'A';
        }else if (binary[i] == '1'){
            binary[i] = 'B' ;
        }
    }
    return binary ;
}
// Convert the decimal to the binary for the encryption
int decimal (string binary){
    for (int i = 0 ; i < binary.length() ; i++){
        if (binary[i] == 'A'){
            binary[i] = '0' ;
        }else if (binary[i] == 'B'){
            binary[i] = '1' ;
        }
    }
    int decimal = 0 , power = 0;
    reverse(binary.begin() , binary.end()) ;
    for (int i = 0 ; i < binary.length() ; i++){
        if (binary[i] == '1'){
            decimal += pow(2 , power) ;
        }
        power ++ ;
    }
    return decimal + 65 ;
}
void Baconian_Cipher_Encryption (){
    string message  , result;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , message);
    for (int i = 0 ; i  <message.length() ; i++){
        if (islower(message[i])){
            message[i] = toupper(message[i]) ;
        }
        if (message[i] >= 65  and message[i] <= 90){
            result += binary(message[i]) ;
        }else {
            result += message[i] ;
        }
    }
    cout << "Cipherd message is --> " << result << "\n";
}
void Baconian_Cipher_Decryption(){
    string message  , result , code;
    cout << "Enter the sentence you want to decipher\n" ;
    getline(cin , message);
    for (int i = 0 ; i  < message.length() ; i++){
        if (message[i] != ' '){
            for (int x = i ; x < i + 5 ; x++){
                code += message[x] ;
            }
            result += decimal(code) ;
            i += 4 ;
        }else {
            result += ' ' ;
        }
        code = "" ;
    }
    cout  << "Plain message is --> " << result << "\n";
}
void Baconian(){
    string Choice ;
    cout << "------------------------\n";
    cout << "|  operation  | number |\n";
    cout << "------------------------\n";
    cout << "|   Cipher    |    1   |\n";
    cout << "|  Decipher   |    2   |\n";
    cout << "------------------------\n";
    cout << "Choose the operation you want to apply\n" ;
    cin >> Choice ;
    cin.ignore();
    if (Choice == "1"){
        Baconian_Cipher_Encryption();
    }else if (Choice == "2"){
        Baconian_Cipher_Decryption();
    }else {
        while (true) {
            cout << "Invalid input\n";
            cout << "------------------------\n";
            cout << "|  operation  | number |\n";
            cout << "------------------------\n";
            cout << "|   Cipher    |    1   |\n";
            cout << "|  Decipher   |    2   |\n";
            cout << "------------------------\n";
            cin >> Choice ;
            cin.ignore();
            if (Choice == "1"){
                Baconian_Cipher_Encryption();
                break;
            }else if (Choice == "2"){
                Baconian_Cipher_Decryption();
                break;
            }
        }
    }
}
// The end of the Baconian cipher functions

// The start of the simple Substitution Cipher functions

// Get the alphabet aftert adding the word
vector<char> get_alphbet (string key){
    vector<char> alphabet ;
    for (int i = 0 ; i < key.length() ; i++){
        alphabet.push_back(key[i]) ;
    }
    for (int i = 65 ; i <= 90 ; i++){
        auto fnd = find(alphabet.begin() , alphabet.end() , i) ;
        if (fnd == alphabet.end()){
            alphabet.push_back(i) ;
        }
    }
    return alphabet ;
}
void simple_Substitution_Cipher_Encryption() {
    vector<char>alphabet ;
    string key  , message  , result ;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , message);
    cout << "Enter the key\n" ;
    cin >> key ;
    cin.ignore() ;
    alphabet = get_alphbet(key) ;
    for (int i = 0 ; i < message.length() ; i++){
        if (islower(message[i])){
            message[i] = toupper(message[i]);
        }
        if (message[i] >= 65  and message[i] <= 90){
            result += alphabet[message[i] - 65] ;
        }else {
            result += message[i] ;
        }
    }
    cout << "Cipherd message is --> "  << result << "\n";
}
void simple_Substitution_Cipher_Decryption() {
    vector<char>alphabet ;
    string key  , message  , cword;
    cout << "Enter the sentence you want to decipher\n" ;
    getline(cin , message) ;
    cout << "Enter the key\n" ;
    cin >> key ;
    cin.ignore() ;
    alphabet = get_alphbet(key) ;
    for (int i = 0 ; i < message.length() ; i++){
        if (islower(message[i])){
            message[i] = toupper(message[i]);
        }
        if (message[i] >= 65  and message[i] <= 90){
            auto fnd = find (alphabet.begin() , alphabet.end() , message[i]) ;
            int index = fnd - alphabet.begin() ;
            cword += index + 65 ;
        }else {
            cword += message[i] ;
        }
    }
    cout << "Plain message is --> "  << cword << "\n";
}
void simple_Substitution(){
    string Choice ;
    cout << "------------------------\n";
    cout << "|  operation  | number |\n";
    cout << "------------------------\n";
    cout << "|   Cipher    |    1   |\n";
    cout << "|  Decipher   |    2   |\n";
    cout << "------------------------\n";
    cout << "Choose the operation you want to apply\n" ;
    cin >> Choice ;
    cin.ignore();
    if (Choice == "1"){
        simple_Substitution_Cipher_Encryption();
    }else if (Choice == "2"){
        simple_Substitution_Cipher_Decryption();
    }else {
        while (true) {
            cout << "Invalid input\n";
            cout << "------------------------\n";
            cout << "|  operation  | number |\n";
            cout << "------------------------\n";
            cout << "|   Cipher    |    1   |\n";
            cout << "|  Decipher   |    2   |\n";
            cout << "------------------------\n";
            cin >> Choice ;
            cin.ignore();
            if (Choice == "1"){
                simple_Substitution_Cipher_Encryption();
                break;
            }else if (Choice == "2"){
                simple_Substitution_Cipher_Decryption();
                break;
            }
        }
    }
}
// The end of the simple Substitution Cipher functions

// The start of the Polybius Square Cipher functions

// Get the place of the letter by equation
// The table is
//    0 1 2  3  4
//0   a b c  d  e
//1   f g h i/j k
//2   l m n o   p
//3   q r s t   u
//4   v w x y   z
// I didn't make a 2d array but is make an equation
tuple<int , int> Get_place(char letter){
    if (letter >= 65 and letter <=69){
        return {0 , letter - 65} ;
    }
    if (letter >= 70 and letter <=75){
        if (letter == 'J'){
            letter = 'I' ;
        }
        if (letter == 'K'){
            letter = 'J' ;
        }
        return {1 , letter - 65 - 5 * 1} ;
    }
    if (letter >= 76 and letter <=80){
        return {2 , letter - 66 - 5 * 2} ;
    }
    if (letter >= 81 and letter <=85){
        return {3 , letter - 66 - 5 * 3} ;
    }
    if (letter >= 86 and letter <=90){
        return {4 , letter - 66 - 5 * 4} ;
    }
}
// Here we get the ascii of the letter
char Get_letter(int x , int y){
    if (x == 0 and y >=0 and y <=4){
        return 65 + y ;
    }
    if (x == 1 and y >=0 and y <=4){
        if (y == 4){
            return 65 + y + 5 * 1 + 1 ;
        }else {
            return 65 + y + 5 * 1;
        }
    }
    if (x == 2 and y >=0 and y <=4){
        return 65 + y + 5 * 2 + 1;
    }
    if (x == 3 and y >=0 and y <=4){
        return 65 + y + 5 * 3 + 1;
    }
    if (x == 4 and y >=0 and y <=4){
        return 65 + y + 5 * 4 + 1;
    } else {
        return 0 ;
    }
}
void Polybius_Square_Cipher_Encryption (){
    string message  , result , number_line;
    int x , y  , number_enter;
    vector<int>lst ;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , message) ;
    cout << "Enter the numbers of the table separated by spaces\n" ;
    for (int i = 0 ; i < 5 ; i++){
        cin >> number_enter ;
        lst.push_back(number_enter) ;
    }
    for (int i = 0; i < message.length() ; i++){
        if (islower(message[i])){
            message[i] = toupper(message[i]) ;
        }
        if (message[i] >= 65 and message[i] <= 90){
            tie(x , y) = Get_place(message[i]) ;
            result += to_string(lst[x]) ;
            result += to_string(lst[y]) ;
        } else {
            result += message[i] ;
        }
    }
    cout << "Cipherd message is --> "  <<  result << "\n";
}
void Polybius_Square_Cipher_Decryption(){
    string message , result , x ,y , number , number_enter;
    int counter = 0 , posx , posy ;
    vector<string>lst ;
    cout << "Enter the sentence you want to decipher\n" ;
    getline(cin , message) ;
    cout << "Enter the numbers of the table separated by spaces\n" ;
    for (int i = 0 ; i < 5 ; i++){
        cin >> number_enter ;
        lst.push_back(number_enter) ;
    }
    cin.ignore();
    for (int i = 0; i < message.length() ; i++){
        if (counter == 2){
            // Separate x and y
            x = string(1 ,number[0]) ;
            y = string(1 ,number[1]) ;
            // Find the x and y in the vector
            auto fnd1 = find(lst.begin() , lst.end() , x) ;
            auto fnd2 = find(lst.begin() , lst.end() , y) ;
            // Get the position of x and y in the vector
            posx = fnd1 - lst.begin() ;
            posy = fnd2 - lst.begin() ;
            result += Get_letter(posx , posy) ;
            counter = 0 ;
            number = "" ;
        }
        if (message[i] != ' ') {
            number += message[i];
            counter++;
        }
        else {
            result += " " ;
        }
    }
    // Here we add the last x and y because there if there is no space in the end of the ciphered message
    if (not isspace(message[message.length() - 1])) {
        x = string(1, number[0]);
        y = string(1, number[1]);
        auto fnd1 = find(lst.begin(), lst.end(), x);
        auto fnd2 = find(lst.begin(), lst.end(), y);
        posx = fnd1 - lst.begin();
        posy = fnd2 - lst.begin();
        result += Get_letter(posx, posy);
    }
    cout  << "Plain message is --> "  << result << "\n";
}
void Polybius_Square(){
    string Choice ;
    cout << "------------------------\n";
    cout << "|  operation  | number |\n";
    cout << "------------------------\n";
    cout << "|   Cipher    |    1   |\n";
    cout << "|  Decipher   |    2   |\n";
    cout << "------------------------\n";
    cout << "Choose the operation you want to apply\n" ;
    cin >> Choice ;
    cin.ignore();
    if (Choice == "1"){
        Polybius_Square_Cipher_Encryption ();
    }else if (Choice == "2"){
        Polybius_Square_Cipher_Decryption();
    }else {
        while (true) {
            cout << "Invalid input\n";
            cout << "------------------------\n";
            cout << "|  operation  | number |\n";
            cout << "------------------------\n";
            cout << "|   Cipher    |    1   |\n";
            cout << "|  Decipher   |    2   |\n";
            cout << "------------------------\n";
            cin >> Choice ;
            cin.ignore();
            if (Choice == "1"){
                Polybius_Square_Cipher_Encryption ();
                break;
            }else if (Choice == "2"){
                Polybius_Square_Cipher_Decryption();
                break;
            }
        }
    }
}
// The end of the Polybius Square Cipher functions

// The start of the Morse Code functions
string  Morse_code_Encryption () {
    string result , messgae;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , messgae);
    for (int i = 0; i < messgae.length(); i++) {
        if (messgae[i] == 'a' or messgae[i] == 'A') {
            result += ".- ";
        }
        if (messgae[i] == 'b' or messgae[i] == 'B') {
            result += "-... ";
        }
        if (messgae[i] == 'c' or messgae[i] == 'C') {
            result += "-.-. ";
        }
        if (messgae[i] == 'd' or messgae[i] == 'D') {
            result += "-.. ";
        }
        if (messgae[i] == 'e' or messgae[i] == 'E') {
            result += ". ";
        }
        if (messgae[i] == 'f' or messgae[i] == 'F') {
            result += "..-.";
        }
        if (messgae[i] == 'g' or messgae[i] == 'G') {
            result += "--. ";
        }
        if (messgae[i] == 'h' or messgae[i] == 'H') {
            result += ".... ";
        }
        if (messgae[i] == 'i' or messgae[i] == 'I') {
            result += ".. ";
        }
        if (messgae[i] == 'j' or messgae[i] == 'J') {
            result += ".--- ";
        }
        if (messgae[i] == 'k' or messgae[i] == 'K') {
            result += "-.- ";
        }
        if (messgae[i] == 'l' or messgae[i] == 'L') {
            result += ".-.. ";
        }
        if (messgae[i] == 'm' or messgae[i] == 'M') {
            result += "-- ";
        }
        if (messgae[i] == 'n' or messgae[i] == 'N') {
            result += "-. ";
        }
        if (messgae[i] == 'o' or messgae[i] == 'O') {
            result += "--- ";
        }
        if (messgae[i] == 'p' or messgae[i] == 'P') {
            result += ".--. ";
        }
        if (messgae[i] == 'q' or messgae[i] == 'Q') {
            result += "--.- ";
        }
        if (messgae[i] == 'r' or messgae[i] == 'R') {
            result += ".-. ";
        }
        if (messgae[i] == 's' or messgae[i] == 'S') {
            result += "... ";
        }
        if (messgae[i] == 't' or messgae[i] == 'T') {
            result += "- ";
        }
        if (messgae[i] == 'u' or messgae[i] == 'U') {
            result += "..- ";
        }
        if (messgae[i] == 'v' or messgae[i] == 'V') {
            result += "...- ";
        }
        if (messgae[i] == 'w' or messgae[i] == 'W') {
            result += ".-- ";
        }
        if (messgae[i] == 'x' or messgae[i] == 'X') {
            result += "-..- ";
        }
        if (messgae[i] == 'y' or messgae[i] == 'Y') {
            result += "-.-- ";
        }
        if (messgae[i] == 'z' or messgae[i] == 'Z') {
            result += "--.. ";
        }
        if (messgae[i] == ' ') {
            result+= "    ";
        }
    }
    cout << "Cipherd message is --> "<< result << "\n" ;
}
// To get the the letter from morse code
string getcode(string morse_code) {
    if (morse_code == ".-") {
        return "a";
    }
    if (morse_code == ".-") {
        return "a";
    }
    if (morse_code == "-... ") {
        return "b";
    }
    if (morse_code == "-.-.") {
        return "c";
    }
    if (morse_code == "-..") {
        return "d";
    }
    if (morse_code == ".") {
        return "e";
    }
    if (morse_code == "..-.") {
        return "f";
    }
    if (morse_code == "--.") {
        return "g";
    }
    if (morse_code == "....") {
        return "h";
    }
    if (morse_code == "..") {
        return "i";
    }
    if (morse_code == ".---") {
        return "j";
    }
    if (morse_code == "-.-") {
        return "k";
    }
    if (morse_code == ".-..") {
        return "l";
    }
    if (morse_code == "--") {
        return "m";
    }
    if (morse_code == "-.") {
        return "n";
    }
    if (morse_code == "---") {
        return "o";
    }
    if (morse_code == ".--.") {
        return "p";
    }
    if (morse_code == "--.-") {
        return "q";
    }
    if (morse_code == ".-.") {
        return "r";
    }
    if (morse_code == "...") {
        return "s";
    }
    if (morse_code == "-") {
        return "t";
    }
    if (morse_code == "..-") {
        return "u";
    }
    if (morse_code == "...-") {
        return "v";
    }
    if (morse_code == ".--") {
        return "w";
    }
    if (morse_code == "-..-") {
        return "x";
    }
    if (morse_code == "-.--") {
        return "y";
    }
    if (morse_code == " --..") {
        return "z";
    }
}
string  Morse_code_Decryption() {
    string echar_morse , result , message;
    int  u = 0 , count_space = 0;
    cout << "Enter the sentence you want to decipher\n" ;
    getline(cin , message);
    for (int i = 0; i < message.length() - 1 ; i++) {
        if (message[i] == ' ' and message[i + 1] != ' ') {
            for (int x = u;x < i; x++) {
                echar_morse += message[x];
            }
            u = i + 1 ;
            result += getcode(echar_morse);
            echar_morse = "";
        }
        // This to count the spaces and add space to the result and ignore other spaces
        if (message [i] == ' ' and message[i + 1] == ' ' ) {
            while (message[i] == ' '){
                i += 1;
                count_space ++ ;
            }
            for (int x = u ;x < i - count_space  ; x++) {
                echar_morse += message[x];
            }
            u = i + 1 ;
            result += getcode(echar_morse);
            echar_morse = "";
            result += " ";
            u -- ;
        }
        count_space = 0 ;
    }
    echar_morse = "" ;
    for (int x = u; x < message.length(); x++) {
        echar_morse += message[x];
    }
    echar_morse.erase(remove(echar_morse.begin() , echar_morse.end() , ' ') , echar_morse.end()) ;
    result += getcode(echar_morse);
    result += "\n" ;
    cout << "Plain message is --> " <<  result;
}
void Morse_code(){
    string Choice ;
    cout << "------------------------\n";
    cout << "|  operation  | number |\n";
    cout << "------------------------\n";
    cout << "|   Cipher    |    1   |\n";
    cout << "|  Decipher   |    2   |\n";
    cout << "------------------------\n";
    cout << "Choose the operation you want to apply\n" ;
    cin >> Choice ;
    cin.ignore();
    if (Choice == "1"){
        Morse_code_Encryption();
    }else if (Choice == "2"){
        Morse_code_Decryption();
    }else {
        while (true) {
            cout << "Invalid input\n";
            cout << "------------------------\n";
            cout << "|  operation  | number |\n";
            cout << "------------------------\n";
            cout << "|   Cipher    |    1   |\n";
            cout << "|  Decipher   |    2   |\n";
            cout << "------------------------\n";
            cin >> Choice ;
            cin.ignore();
            if (Choice == "1"){
                Morse_code_Encryption();
                break;
            }else if (Choice == "2"){
                Morse_code_Decryption();
                break;
            }
        }
    }
}
// The end of the Morse Code functions

// The start of  XOR Cipher functions

// Convert the Hex to decimal
int DECIMAL (string hex){
    int power = 0  , result = 0 ;
    reverse(hex.begin() , hex.end()) ;
    for (int i = 0 ; i < hex.length() ; i++){
        if (isdigit(hex[i])){
            result += stoi(string(1 , hex[i])) * pow(16, power) ;
            power ++ ;
        }else {
            if (islower(hex[i])){
                hex[i] = toupper(hex[i]) ;
            }
            result += (hex[i] - 65 )+ 10;
            power ++ ;
        }
    }
    return result ;
}
// Convert the decimal to Hex
string HEX (int num){
    string result ;
    char convet ;
    // rev to check if we reverse the number of not
    bool rev = true ;
    if (num == 0){
        result = "0" ;
    }
    if (num < 16){
        result += "0" ;
        rev = false ;
    }
    while (num > 0){
        if (num - (16 * (num / 16)) < 10) {
            result += to_string(num - (16 * (num / 16)));
        }else {
            convet = (num - (16 * (num / 16)) - 10 )+ 65 ;
            result += convet ;
        }
        num /= 16 ;
    }
    if (rev) {
        reverse(result.begin(), result.end());
    }
    return  result ;
}
void XOR_CIPHER_BY_ASCII_ENCRYPTION (){
    string message  , result ;
    char  secret_char ;
    vector<string>hex_lst ;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , message) ;
    cout << "Enter the secret char\n" ;
    cin >> secret_char ;
    cin.ignore() ;
    for (int i = 0 ; i < message.length() ; i++){
        result +=  message[i] ^ secret_char ;
        hex_lst.push_back(HEX( message[i] ^ secret_char)) ;
    }
    cout  << "Cipherd message is --> "  <<  result << "\n";
    cout << "HEX\n" ;
    for (auto i = hex_lst.begin() ; i != hex_lst.end() ; i++){
        cout << *i ;
    }
    cout << "\n" ;
}
void XOR_CIPHER_BY_ASCII_DECRYPTION (){
    string message  , result ;
    char  secret_char ;
    vector<string>hex_lst ;
    cout << "Enter the sentence you want to decipher\n" ;
    getline(cin , message) ;
    cout << "Enter the secret char\n" ;
    cin >> secret_char ;
    cin.ignore() ;
    for (int i = 0 ; i < message.length() ; i++){
        result +=  message[i] ^ secret_char ;
        hex_lst.push_back(HEX( message[i] ^ secret_char)) ;
    }
    cout << "Plain message is --> "  << result << "\n";
    cout << "HEX\n" ;
    for (auto i = hex_lst.begin() ; i != hex_lst.end() ; i++){
        cout << *i ;
    }
    cout << "\n" ;
}
void XOR_CIPHER_BY_HEX_ENCRYPTION (){
    string hex  , merge , result;
    char secret_char ;
    int decimal_char , decimal_secret ;
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , hex) ;
    cout << "Enter the hex of the secret char\n";
    cin >> secret_char ;
    cin.ignore() ;
    decimal_secret = DECIMAL(string(1 , secret_char));
    for (int i = 0 ; i < hex.length() ; i+=2){
        merge = string (1 , hex[i]) + string(1 , hex[i+1]);
        decimal_char = DECIMAL(merge) ;
        result += decimal_char ^ decimal_secret ;
    }
    cout  << "Cipherd message is --> "  <<  result << "\n";
}
void XOR_CIPHER_BY_HEX_DECRYPTION (){
    string hex  , merge , result;
    char secret_char ;
    int decimal_char , decimal_secret ;
    cout << "Enter the sentence you want to decipher\n" ;
    getline(cin , hex) ;
    cout << "Enter the hex of the secret char\n";
    cin >> secret_char ;
    cin.ignore() ;
    decimal_secret = DECIMAL(string(1 , secret_char));
    for (int i = 0 ; i < hex.length() ; i+=2){
        merge = string (1 , hex[i]) + string(1 , hex[i+1]);
        decimal_char = DECIMAL(merge) ;
        result += decimal_char ^ decimal_secret ;
    }
    cout << "Plain message is --> "  << result << "\n";
}
int XOR_CIPHER (){
    string operation ;
    cout << "------------------------------------------------\n" ;
    cout << "|         Operation          |    Number       |\n" ;
    cout << "------------------------------------------------\n" ;
    cout << "| Cipher encryption by ASCII |       1         |\n" ;
    cout << "| Cipher decryption by ASCII |       2         |\n" ;
    cout << "| Cipher encryption by HEX   |       3         |\n" ;
    cout << "| Cipher decryption by HEX   |       4         |\n" ;
    cout << "|         EXIT               |       5         |\n" ;
    cout << "------------------------------------------------\n" ;
    cout << "Enter the number of the operation\n" ;
    cin >> operation ;
    cin.ignore() ;
    if (operation == "1"){
        XOR_CIPHER_BY_ASCII_ENCRYPTION () ;
    }
    if (operation == "2"){
        XOR_CIPHER_BY_ASCII_DECRYPTION () ;
    }
    if (operation == "3"){
        XOR_CIPHER_BY_HEX_ENCRYPTION () ;
    }
    if (operation == "4"){
        XOR_CIPHER_BY_HEX_DECRYPTION () ;
    }
    if (operation == "5"){
        return 0 ;
    }
}
// The end of  XOR Cipher functions

// The start of the Rail-fence Cipher functions

// To erase a character from a string
string ERASER (string wword , char want){
    wword.erase(remove(wword.begin() , wword.end()  , want) , wword.end()) ;
    return wword ;
}
void Rail_fence_Cipher_Encryption(){
    int  counter , n = 0 ,  keynumber;
    bool test  , test2  ;
    string message  ;
    cout << "Enter the key\n";
    cin >> keynumber;
    cin.ignore();
    cout << "Enter the message you want to cipher\n" ;
    getline(cin , message) ;
    message = ERASER(message , ' ' ) ;
    // Set the 2d array by the key and the length of the word
    string board [keynumber ][message.length()] ;
    // Tests for the zig zga
    test2 = true ;
    test = false ;
    // Set the 2d array by ' '
    for (int i = 0 ; i < keynumber ; i++){
        for (int j = 0 ; j < message.length() ; j++){
            board[i][j] = " " ;
        }
    }
    // To fill the 2d array by characters in zig zay way
    for (int i = 0 ; i < message.length() ; i++){
        board[n][i] = message[i] ;
        if (test2) {
            n++;
            if (n == keynumber){
                test2 = false ;
                test = true ;
                counter = 0 ;
            }
        }
        if (test){
            if (counter == 0) {
                n -= 2;
                counter = 1 ;
            }else {
                n-- ;
            }

            if (n == 0){
                test2 = true ;
                test = false ;
            }
        }
    }
    // Fill the empty indices by '.'
    for (int i = 0 ; i < keynumber ; i++){
        for (int j = 0 ; j < message.length() ; j++){
            if (board[i][j] == " "){
                board[i][j] = "." ;
            }
        }
    }
    // print the 2d array after fill it
    cout << "Cipherd message is " << "\n" ;
    for (int i = 0 ; i < keynumber ; i++){
        for (int j = 0 ; j < message.length() ; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
void Rail_fence_Cipher_Dencryption (){
    string line  , result;
    bool test2 = true , test ;
    vector<string>lst ;
    int key  , n = 0 , counter ;
    cout << "Enter the key\n" ;
    cin >> key ;
    cin.ignore() ;
    cout << "Enter the sentence you want to decipher\n" ;
    // To append the lines in the vector and call it in the way od lst[0][0] and so one
    for (int i = 0 ; i  < key ; i++){
        getline(cin , line) ;
        line = ERASER(line , ' ') ;
        lst.push_back(line) ;
    }
    // For reading the zig zag
    for (int i = 0 ; i < lst[0].length() ; i++){
        result += lst[n][i] ;
        if (test2) {
            n++;
            if (n == key){
                test2 = false ;
                test = true ;
                counter = 0 ;
            }
        }
        if (test){
            if (counter == 0) {
                n -= 2;
                counter = 1 ;
            }else {
                n-- ;
            }

            if (n == 0){
                test2 = true ;
                test = false ;
            }
        }
    }
    cout << "Plain message is --> "  << result << "\n";
}
void Rail_fence(){
    string Choice ;
    cout << "------------------------\n";
    cout << "|  operation  | number |\n";
    cout << "------------------------\n";
    cout << "|   Cipher    |    1   |\n";
    cout << "|  Decipher   |    2   |\n";
    cout << "------------------------\n";
    cout << "Choose the operation you want to apply\n" ;
    cin >> Choice ;
    cin.ignore();
    if (Choice == "1"){
        Rail_fence_Cipher_Encryption();
    }else if (Choice == "2"){
        Rail_fence_Cipher_Dencryption();
    }else {
        while (true) {
            cout << "Invalid input\n";
            cout << "------------------------\n";
            cout << "|  operation  | number |\n";
            cout << "------------------------\n";
            cout << "|   Cipher    |    1   |\n";
            cout << "|  Decipher   |    2   |\n";
            cout << "------------------------\n";
            cin >> Choice ;
            cin.ignore();
            if (Choice == "1"){
                Rail_fence_Cipher_Encryption();
                break;
            }else if (Choice == "2"){
                Rail_fence_Cipher_Dencryption();
                break;
            }
        }
    }
}
// The end of the Rail-fence Cipher functions
int Choose_function(){
    string choise ;
    cout << "----------------------------------"<< "  "<<"--------------------------------------" <<"  "<< "-------------------------------------\n";
    cout << "|   operation   |     number     |"<< "  "<<"|   operation       |     number     |" <<"  "<< "|    operation    |     number      |\n";
    cout << "----------------------------------"<< "  "<<"--------------------------------------" <<"  "<< "-------------------------------------\n";
    cout << "| Affine Cipher |        1       |"<< "  "<<"|  Baconian Cipher  |       5        |" <<"  "<< "|   XOR Cipher    |       9         |\n";
    cout << "| Caesar Cipher |        2       |"<< "  "<<"|Simple Substitution|       6        |" <<"  "<< "|Rail-fence Cipher|       10        |\n";
    cout << "| Atbash Cipher |        3       |"<< "  "<<"|  PolybiusSquare   |       7        |" <<"  "<< "|      EXIT       |        0        |\n";
    cout << "| Vignere Cipher|        4       |"<< "  "<<"|    Morse code     |       8        |" <<"  "<< "|                 |                 |\n";
    cout << "----------------------------------"<< "  "<<"--------------------------------------" <<"  "<< "------------------------------------\n";
    cout << "Choose the chipher you want to do\n" ;
    cin >> choise ;
    cin.ignore() ;
    if (choise == "1"){
        Affine();
    }else if (choise == "2"){
        Caesar();
    }
    else if (choise == "3"){
        Atbash();
    }
    else if (choise == "4"){
        Vignere();
    }
    else if (choise == "5"){
        Baconian();
    }
    else if (choise == "6"){
        simple_Substitution();
    }
    else if (choise == "7"){
        Polybius_Square();
    }
    else if (choise == "8"){
        Morse_code();
    }
    else if (choise == "9"){
        XOR_CIPHER();
    }
    else if (choise == "10"){
        Rail_fence();
    }
    else if (choise == "0"){
        return 0;
    }else {
        cout << "Invalid input\n" ;
    }
    Choose_function() ;
}

int main() {
    Choose_function();
}