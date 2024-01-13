package com.mobileapp.lecture17exer;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.mobileapp.lecture17exer.databinding.FragmentGameBinding;

import org.w3c.dom.Text;
import java.util.Arrays;

public class GameFragment extends Fragment {
    private GameViewModel gameViewModel;
    private FragmentGameBinding binding;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        binding = FragmentGameBinding.inflate(inflater, container, false);
        View view = binding.getRoot();
        Button submitButton = binding.button;
        TextView numLives = binding.numLivesText;
        EditText guess = binding.editTextText;
        TextView guessingWord = binding.wordToGuess;
        TextView guessList = binding.textView5;

        gameViewModel = new ViewModelProvider(this).get(GameViewModel.class);

        guessingWord.setText(gameViewModel.blankWord);
//        numLives.setText(gameViewModel.livesLeft);
        numLives.setText(Integer.toString(gameViewModel.livesLeft));


        submitButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String c = guess.getText().toString();
                gameViewModel.makeGuess(c.charAt(0));
                guessingWord.setText(gameViewModel.blankWord);
                guessList.setText(gameViewModel.guesses);
//                GameFragmentDirections.ActionGameFragmentToResultFragment action = GameFragmentDirections.actionGameFragmentToResultFragment(message);
//                int lives = gameViewModel.livesLeft;
                numLives.setText(Integer.toString(gameViewModel.livesLeft));
                if (gameViewModel.gameWon) {
                    String message = "You Won! The word was ACTIVITY.";
//                    GameFragmentDirections.ActionGameFragmentToResultFragment action = GameFragmentDirections.actionGameFragmentToResultFragment(message);
                    Navigation.findNavController(view).navigate(R.id.action_gameFragment_to_resultFragment);
//                    Navigation.findNavController(view).navigate(R.id.action_gameFragment_to_resultFragment);
                } else if (gameViewModel.gameLost) {
                    String message = "Sorry, you lost. The word was ACTIVITY.";
//                    GameFragmentDirections.ActionGameFragmentToResultFragment action = GameFragmentDirections.actionGameFragmentToResultFragment(message);
                    Navigation.findNavController(view).navigate(R.id.action_gameFragment_to_resultFragment);
                }
            }
        });
        // Inflate the layout for this fragment
        return view;
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        com.mobileapp.lecture17exer.databinding.FragmentGameBinding binding = null;
    }
}

