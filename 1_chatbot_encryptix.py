print("Welcome to ChatBot!")

while True:
    user_input = input("You: ").lower()

    if "hello" in user_input or "hi" in user_input:
        print("ChatBot: Hello! How can I assist you today?")
    elif "how are you" in user_input:
        print("ChatBot: I'm doing well, thanks! How about you?")
    elif "what is your name" in user_input:
        print("ChatBot: My name is ChatBot, nice to meet you!")
    elif "goodbye" in user_input or "bye" in user_input:
        print("ChatBot: Goodbye! It was nice chatting with you.")
        break
    elif "thanks" in user_input or "thank you" in user_input:
        print("ChatBot: You're welcome!")
    else:
        print("ChatBot: I didn't understand that. Can you please rephrase?")



    import re

print("Welcome to ChatBot!")

while True:
    user_input = input("You: ").lower()

    if re.search(r"hello|hi", user_input):
        print("ChatBot: Hello! How can I assist you today?")
    elif re.search(r"how are you", user_input):
        print("ChatBot: I'm doing well, thanks! How about you?")
    elif re.search(r"what is your name", user_input):
        print("ChatBot: My name is ChatBot, nice to meet you!")
    elif re.search(r"goodbye|bye", user_input):
        print("ChatBot: Goodbye! It was nice chatting with you.")
        break
    elif re.search(r"thanks|thank you", user_input):
        print("ChatBot: You're welcome!")
    else:
        print("ChatBot: I didn't understand that. Can you please rephrase?")