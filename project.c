#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256
#define MAX_RULES 50

typedef struct {
    char keyword[MAX_LEN];
    char response[MAX_LEN];
} Rule;

Rule rules[MAX_RULES];
int rule_count = 0;
char default_reply[MAX_LEN] = "Sorry, I can't seem to find a response to that.";

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int load_rules() {
    FILE *file = fopen("rules.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open rules.txt. Make sure the file exists in the same folder.\n");
        return 0;
    }

    char line[MAX_LEN];
    while (fgets(line, MAX_LEN, file) != NULL && rule_count < MAX_RULES) {
        line[strcspn(line, "\n")] = 0; 

        char *keyword = strtok(line, ":");
        char *reply = strtok(NULL, "\n");

        if (keyword != NULL && reply != NULL) {
            if (strcmp(keyword, "default") == 0) {
                strcpy(default_reply, reply);
            } else {
                strcpy(rules[rule_count].keyword, keyword);
                strcpy(rules[rule_count].response, reply);
                rule_count++;
            }
        }
    }
    fclose(file);
    return 1;
}

void reply(char *user_input) {
    int found_reply = 0;
    char input_lower[MAX_LEN];

    strcpy(input_lower, user_input);
    to_lowercase(input_lower);

    for (int i = 0; i < rule_count; i++) {
        char keyword_lower[MAX_LEN];
        strcpy(keyword_lower, rules[i].keyword);
        to_lowercase(keyword_lower);

        if (strstr(input_lower, keyword_lower) != NULL) {
            printf("Bot: %s\n", rules[i].response);
            found_reply = 1;
            break;
        }
    }

    if (!found_reply) {
        printf("Bot: %s\n", default_reply);
    }
}

int main() {
    if (!load_rules()) {
        return 1;
    }

    char user_input[MAX_LEN];
    printf("Welcome to the SimpleBot! Type 'bye' to exit.\n");

    while (1) {
        printf("You: ");
        if (!fgets(user_input, MAX_LEN, stdin)) {
            break;
        }
        user_input[strcspn(user_input, "\n")] = 0;

        char check_exit[MAX_LEN];
        strcpy(check_exit, user_input);
        to_lowercase(check_exit);

        if (strstr(check_exit, "bye") != NULL || strcmp(check_exit, "exit") == 0) {
            printf("Bot: Goodbye! Have a great day.\n");
            break;
        }

        reply(user_input);
    }

    printf("Chat session ended.\n");
    return 0;
}