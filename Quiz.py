quiz = [
    {
        "question": "What is the capital of France?",
        "options": ["1. Paris", "2. London", "3. Berlin", "4. Madrid"],
        "answer": "1"
    },
    {
        "question": "Which is the largest planet in our solar system?",
        "options": ["1. Earth", "2. Jupiter", "3. Saturn", "4. Mars"],
        "answer": "2"
    },
    {
        "question": "Who wrote the play 'Hamlet'?",
        "options": ["1. Leo Tolstoy", "2. William Shakespeare", "3. Mark Twain", "4. Charles Dickens"],
        "answer": "2"
    },
    {
        "question": "What is the smallest prime number?",
        "options": ["1. 0", "2. 1", "3. 2", "4. 3"],
        "answer": "3"
    },
    {
        "question": "Which element has the chemical symbol 'O'?",
        "options": ["1. Oxygen", "2. Gold", "3. Silver", "4. Osmium"],
        "answer": "1"
    }
]

def quiz_application():
    score = 0

    print("Welcome to the Quiz!\n")

    for i, q in enumerate(quiz):
        print(f"Question {i + 1}: {q['question']}")
        for option in q['options']:
            print(option)
        
        # Get user input and validate
        answer = input("Enter the option number (1/2/3/4): ")
        
        if answer == q['answer']:
            print("Correct!\n")
            score += 1
        else:
            print(f"Wrong! The correct answer was option {q['answer']}.\n")

    print(f"Quiz Over! Your final score is {score} out of {len(quiz)}.")

if __name__ == "__main__":
    quiz_application()
