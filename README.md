The program will prompt for input with 'You: '. The user can type any sentence. The bot will respond based on the keywords in the 'rules.txt' file. The bot's logic uses strstr(), so it can find a keyword *inside* a longer sentence. The program will end when the user type "bye" in the sentence.

Example 1: 
Welcome to the SimpleBot! Type 'bye' to exit.
You: hello there
Bot: Hi there! I'm a chatbot built by IITJ students.
You: tell me about c language
Bot: C is the powerful language this bot is written in!
You: bye
Bot: Goodbye! Have a great day.
Chat session ended.

Example 2:

Welcome to the SimpleBot! Type 'bye' to exit.
You: Who made this?
Bot: I was created by Group 63 for their B.Tech first-year project.
You: what is group 63
Bot: That's our team! This bot was proudly created by the members of Group 63.
You: what course is this for?
Bot: This bot was built for the 'Introduction to Computer Science' course.
You: bye
Bot: Goodbye! Have a great day.
Chat session ended.

Example 3:

Welcome to the SimpleBot! Type 'bye' to exit.
You: what is the weather today?
Bot: Sorry, I don't understand that. Please try asking in a different way.
You: bye
Bot: Goodbye! Have a great day.
Chat session ended.
