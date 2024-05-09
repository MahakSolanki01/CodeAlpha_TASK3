#include <iostream>
#include<algorithm>
#include <string>
#include <stdexcept>
#include <cmath>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

using namespace std;

// Function to handle math operations
string handleMath(const string& user_input) {
    int problem;
    double o1, o2;
    cout << "What kind of problem do you have\n";
    cout << "1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n";
    cin >> problem;

    switch (problem) {
        case 1:
            cout << "Enter first number : \n";
            cin >> o1;
            cout << "Enter second number : \n";
            cin >> o2;
            cout << "The result is " << o1 + o2 << endl;
            break;

        case 2:
            cout << "Enter first number : \n";
            cin >> o1;
            cout << "Enter second number : \n";
            cin >> o2;
            cout << "The result is " << o1 - o2 << endl;
            break;

        case 3:
            cout << "Enter first number : \n";
            cin >> o1;
            cout << "Enter second number : \n";
            cin >> o2;
            cout << "The result is " << o1 * o2 << endl;
            break;

        case 4:
            cout << "Enter first number : \n";
            cin >> o1;
            cout << "Enter second number : \n";
            cin >> o2;
            if (o2 == 0) {
                return "Error: Division by zero!";
            } else {
                cout << "The result is " << o1 / o2 << endl;
            }
            break;

        default:
            return "Invalid choice!";
            break;
    }
    return "";
}

// Function to generate a random quote
string getRandomQuote() {
    // Seed the random number generator
    srand(time(0));

    // Array of quotes
    string quotes[] = {
        "The greatest glory in living lies not in never falling, but in rising every time we fall.\n- Nelson Mandela.",
        "In the end, it's not the years in your life that count. It's the life in your years.\n- Abraham Lincoln.",
        "Life is what happens when you're busy making other plans.\n- John Lennon."
    };

    // Generate a random index within the range of the array
    int index = rand() % (sizeof(quotes) / sizeof(quotes[0]));

    // Return the randomly selected quote
    return quotes[index];
}
//function to generate a random joke
string getRandomJoke() {
    // Seed the random number generator
    srand(time(0));

    // Array of jokes
    string jokes[] = {
        "Why did the scarecrow win an award? Because he was outstanding in his field!",
        "Why don't skeletons fight each other? They don't have the guts.",
        "What do you call fake spaghetti? An impasta."
    };

    // Generate a random index within the range of the array
    int index = rand() % (sizeof(jokes) / sizeof(jokes[0]));

    // Return the randomly selected joke
    return jokes[index];
}

// Function to get a response based on user input
string getResponse(const string& user_input) {
    string lowercase_input = user_input;
    // Convert input to lowercase for case-insensitive comparison
    transform(lowercase_input.begin(), lowercase_input.end(), lowercase_input.begin(), ::tolower);

    if (lowercase_input == "hi" || lowercase_input == "hello") {
        return "Hello! How can I help you today?";
    } else if (lowercase_input == "how are you") {
        return "I'm doing well, thank you for asking! How about you?";
    } else if (lowercase_input == "bye") {
        return "Goodbye! Have a great day!";
    } else if (lowercase_input == "joke") {
        return getRandomJoke();
    } else if (lowercase_input == "weather") {
        return " The weather is sunny today ";
    } else if (lowercase_input == "does santa clause exist") {
        return "Santa Claus exists in the hearts and imaginations of many people around the world, especially during the holiday season.\nWhile there isn't a literal, physical Santa Claus flying around delivering presents, the spirit of giving, kindness, and generosity that Santa represents is very real and impactful.\nPeople often embody the essence of Santa Claus by performing acts of charity, spreading joy, and bringing smiles to others during the festive season.\nSo in that sense, Santa Claus exists in the goodwill and joy shared among people during the holidays.";
    } else if (lowercase_input == "quote") {
        return getRandomQuote();
    } else if (lowercase_input == "maths") {
        return handleMath(user_input);
    } else if (lowercase_input == "what is c++") {
        return "C++ is a powerful and versatile programming language derived from C, known for its efficiency, flexibility, and support for both procedural and object-oriented programming paradigms.";
    } else if (lowercase_input == "what are your hobbies") {
        return "I don't have hobbies in the traditional sense since I'm not a human.";
    } else if (lowercase_input == "you can ask me anything") {
        string name, hobbies, favMovie, favSong;
        int birthday;
        
        cout << "What is your name? ";
        cin >> name;
        
        cout << "Your birthday? ";
        cin >> birthday;
        
        cout << "What are your hobbies? ";
        cin.ignore(); // Ignore newline character left in the buffer
        getline(cin, hobbies);
        
        cout << "What is your favorite movie? ";
        getline(cin, favMovie);
        
        cout << "What is your favorite song? ";
        getline(cin, favSong);
        
        cout << "Okay, I got that. Here are your responses:" << endl;
        cout << "Your Name: " << name << endl;
        cout << "Your Birthday: " << birthday << endl;
        cout << "Your Hobbies: " << hobbies << endl;
        cout << "Your Favorite Movie: " << favMovie << endl;
        cout << "Your Favorite Song: " << favSong << endl;
        
        // No need to return anything here
        return "";
    } else {
        return "Sorry, I didn't understand that.";
    }
}

int main() {
    cout << "-------------Welcome to the Chatbot-------------\n";
    cout << "You can start the conversation\n";
    cout << "Enter 'exit' to end the conversation\n";
    cout << "You: ";

    string user_input;
    getline(cin, user_input);

    while (user_input != "exit") {
        string response = getResponse(user_input);
        cout << "Chatbot: " << response << endl;

        cout << "\nYou: ";
        getline(cin, user_input);
    }

    return 0;
}

