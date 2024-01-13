package com.mobileapp.lecture17exer;

import static java.lang.Character.toLowerCase;

import android.util.Log;

import androidx.lifecycle.ViewModel;

public class GameViewModel extends ViewModel{
    public int livesLeft = 8;
    boolean gameWon = false;
    boolean gameLost = false;
    int lives = 8;
    String correctWord = "Activity";
    StringBuilder blankWord = new StringBuilder("_ _ _ _ _ _ _ _");
    String guesses = "";

    public void makeGuess(char c){
        c = toLowerCase(c);
        correctWord = correctWord.toLowerCase();
        int index = correctWord.indexOf(c);
        if(index == -1){
            livesLeft--;
            guesses += c;
            if(livesLeft <= 0){
                gameLost = true;
            }

        }else {
            int foundIndex = -1;
            for (int i = 0; i < correctWord.length(); i++) {
                if (correctWord.charAt(i) == c) {
                    foundIndex = i;
                    blankWord.setCharAt(foundIndex*2, c);
                }
            }
            Log.d("DEBUG", blankWord.toString());
            if(blankWord.toString().equals("A c t i v i t y")){
                gameWon = true;
            }
        }
    }

}

