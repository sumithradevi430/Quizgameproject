#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a quiz question
struct Question {
    char question[100];
    char options[4][50];
    int correct_option;
};

// Function to display a question
void displayQuestion(struct Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

// Function to get user's answer
int getUserAnswer() {
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

// Function to check user's answer
int checkAnswer(int userChoice, struct Question q) {
    if (userChoice == q.correct_option) {
        printf("Wow ! , Correct Answer!,Congratulations....\n");
        return 1;
    } else {
        printf("Oops!, You missed this time... The correct answer is: %d. %s\n", q.correct_option, q.options[q.correct_option - 1]);
        return 0;
    }
}

int main() {
    int total_questions = 100; // Number of questions
    int score = 0;

    // Define the questions
    struct Question questions[100] = {
        {"What is the capital of France?", {"London", "Paris", "Berlin", "Rome"}, 2},
        {"Who is the first President of the United States?", {"George Washington", "Thomas Jefferson", "Abraham Lincoln", "John Adams"}, 1},
        {"What is the largest planet in our solar system?", {"Mars", "Venus", "Jupiter", "Saturn"}, 3},
        // Add more questions here...
        {"What is the largest ocean on Earth?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 4},
        {"Who wrote 'To Kill a Mockingbird'?", {"Harper Lee", "F. Scott Fitzgerald", "J.K. Rowling", "Stephen King"}, 1},
        {"What is the chemical symbol for gold?", {"Au", "Ag", "Fe", "Hg"}, 1},
        {"Which country is known as the 'Land of the Rising Sun'?", {"China", "Japan", "South Korea", "Vietnam"}, 2},
        {"What is the capital of Australia?", {"Sydney", "Melbourne", "Canberra", "Perth"}, 3},
        {"Who painted the Mona Lisa?", {"Leonardo da Vinci", "Vincent van Gogh", "Pablo Picasso", "Michelangelo"}, 1},
       
        {"Who was the first person to step on the moon?", {"Buzz Aldrin", "Neil Armstrong", "Yuri Gagarin", "John Glenn"}, 2},
        {"What is the main ingredient in guacamole?", {"Tomato", "Onion", "Avocado", "Chili"}, 3},
        {"What is the longest river in the world?", {"Nile", "Amazon", "Yangtze", "Mississippi"}, 2},
        {"What is the currency of Japan?", {"Yen", "Dollar", "Euro", "Pound"}, 1},
        {"Who discovered penicillin?", {"Alexander Fleming", "Marie Curie", "Albert Einstein", "Isaac Newton"}, 1},
      
    };

  
    for (int i = 0; i < total_questions; i++) {
        printf("\nQuestion %d:\n", i + 1);
        displayQuestion(questions[i]);
        int userChoice = getUserAnswer();
        score += checkAnswer(userChoice, questions[i]);
    }

    printf("\nQuiz completed!\n");
    printf("Your score is: %d/%d\n", score, total_questions);

    return 0;
}
