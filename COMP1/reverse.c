char* reverse(char *string) {

    int size = 0;
    char temp;
    int i;

    while(string[size] != '\0') {
        size++;
    }

    for(i = 0; i < size/2; i++) {
        temp = string[i];
        string[i] = string[size - (i + 1)];
        string[size - (i + 1)] = temp;
    }


    return string;
}