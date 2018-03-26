void copyPaste(char choice, int SIZE, char pasted[]){
    if(choice = 'c'){
        printw("Enter text to copy (end with ';'): ");//prompt for copy text

        for(int i = 0; i <= SIZE - 1; i++){
            char input = getch();//get char from user
            if (input == ';' || i == SIZE - 1){//copy stopper
                printw("Copying finished.");
                pasted[i] = ';';//definate semicolon entered
                i = SIZE;//double assurance for falling out of loop
                break;//fall out of loop
            }
            else{
                pasted[i] = input;//char from user entered
            }
        }
    }//copy
    else if(choice = 'p'){
        for(int i = 0; i < SIZE - 1; i++){
            if(pasted[i] == ';'){//check for end line char
                i = SIZE;//double assurance for falling out of loop
                break;//stops at semicolon if you don't use entire array
            }
            else
                insertchar(pasted[i]);
        }//uses insertchar because that's technically happening anyway
    }//paste
    else{
        printw("Error with choice");
    }
}